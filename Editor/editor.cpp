#include "editor.h"
#include "ui_editor.h"
#include <QDebug>

Editor::Editor(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::Editor)
{
    ui->setupUi(this);
    Room_Editor r {"Test", "test", 0, 0, 0,0};
    rooms.push_back(r);
    Person_Editor p1{"Armen", "test","DU ÄR VÄRDELÖS!","Bisysslor?","hej1","hej2", 10, 10, 10, true};
    Person_Editor p2{"Granntant Åsa", "Åsa_test","Kakor?","Tack! Har du något skvaller?","hej3","hej4", 5, 5, 10, false};
    rooms[0].add_person(p1);
    rooms[0].add_person(p2);
    ui->combobox_rooms->addItem(rooms[0].get_name());
    load_Room(rooms[0]);

    ui->combo_E->addItem("Ingen utgång");
    ui->combo_W->addItem("Ingen utgång");
    ui->combo_S->addItem("Ingen utgång");
    ui->combo_N->addItem("Ingen utgång");
    for (int i {0}; i < ui->combobox_rooms->count(); i++)
    {
        ui->combo_E->addItem(ui->combobox_rooms->itemText(i));
        ui->combo_W->addItem(ui->combobox_rooms->itemText(i));
        ui->combo_S->addItem(ui->combobox_rooms->itemText(i));
        ui->combo_N->addItem(ui->combobox_rooms->itemText(i));
    }
}


Editor::~Editor()
{
    delete ui;
}


void Editor::load_NPC(const Person_Editor p)
{
    ui->edit_name->setText(p.get_name());
    ui->edit_description->setPlainText(p.get_description());
    ui->edit_dialog->setPlainText(p.get_dialog());
    ui->edit_recieved_dialog->setPlainText(p.get_recieved_item_dialog());
    ui->edit_hair->setText(p.get_haircolour());
    ui->edit_wants->setText(p.get_wanted_item_name());
    ui->edit_weight->setValue(p.get_weight());
    ui->edit_height->setValue(p.get_length());
    ui->edit_width->setValue(p.get_width());
    ui->checkbox_Merchant->setChecked(p.get_merchant());
}
void Editor::load_Room(Room_Editor & room)
{
    ui->list_npcs->clear();
    for (Person_Editor s : room.get_persons())
    {
        ui->list_npcs->addItem(s.get_name());
    }
    ui->list_items->clear();
    for (Item_Editor s : room.get_items())
    {
        ui->list_items->addItem(s.get_name());
    }

    current_room_ = &room;
    ui->edit_room_name->setText(current_room_->get_name());
    ui->edit_room_description->setText(current_room_->get_description());
    load_exits();
}

void Editor::on_list_npcs_doubleClicked(const QModelIndex &index)
{
    // Byt till personfliken
    if (ui->tabWidget->currentIndex() != 2)
        ui->tabWidget->setCurrentIndex(2);

    current_person_id_ = index.row();
    current_person_ = &current_room_->get_person(current_person_id_);
    load_NPC(*current_person_);
}

void Editor::on_button_npc_clicked()
{
    Person_Editor temp{"Namnlös person", "","","","","", 0, 0, 0, false};
    current_room_->add_person(temp);
    ui->list_npcs->addItem(temp.get_name());
    // Byt till personfliken
    if (ui->tabWidget->currentIndex() != 2)
        ui->tabWidget->setCurrentIndex(2);
    ui->edit_name->setFocus();
}

void Editor::on_button_new_room_clicked()
{
    Room_Editor temp {"", "", 0, 0, 0, 0};
    rooms.push_back(temp);
    QString room_name {"Rum "};
    room_name.append(QString::number(rooms.size()));
    room_name.append(": ");
    room_name.append(temp.get_name());
    ui->combobox_rooms->addItem(room_name);
    ui->combobox_rooms->setCurrentIndex(ui->combobox_rooms->count() - 1);

    ui->combo_E->addItem(room_name);
    ui->combo_W->addItem(room_name);
    ui->combo_S->addItem(room_name);
    ui->combo_N->addItem(room_name);

    load_Room(rooms.back());
    // Byt till rumfliken
    if (ui->tabWidget->currentIndex() != 0)
        ui->tabWidget->setCurrentIndex(0);
    ui->edit_room_name->setFocus();
}



// -- START: Funktioner som sparar värdena som användaren skriver in --
void Editor::on_edit_description_textChanged()
{
    current_person_->set_description(ui->edit_description->toPlainText());
}

void Editor::on_edit_dialog_textChanged()
{
    current_person_->set_dialog(ui->edit_dialog->toPlainText());
}

void Editor::on_edit_recieved_dialog_textChanged()
{
    current_person_->set_recieved_item_dialog(ui->edit_recieved_dialog->toPlainText());
}

void Editor::on_edit_hair_textChanged(const QString &arg1)
{
    current_person_->set_haircolour(arg1);
}

void Editor::on_edit_name_textChanged(const QString &arg1)
{
    ui->list_npcs->item(current_person_id_)->setText(arg1);
    current_person_->set_name(arg1);
}


void Editor::on_edit_width_valueChanged(int arg1)
{
    current_person_->set_width(arg1);
}

void Editor::on_edit_wants_textChanged(const QString &arg1)
{
    current_person_->set_wanted_item_name(arg1);
}

void Editor::on_edit_weight_valueChanged(int arg1)
{
    current_person_->set_weight(arg1);
}

void Editor::on_edit_height_valueChanged(int arg1)
{
    current_person_->set_length(arg1);
}

void Editor::on_checkbox_Merchant_clicked()
{
    current_person_->set_merchant(ui->checkbox_Merchant->checkState());
}

void Editor::on_edit_room_name_textChanged(const QString &arg1)
{
    current_room_->set_name(arg1);
    current_person_->set_description(ui->edit_description->toPlainText());
    QString room_name {"Rum "};
    room_name.append(QString::number(ui->combobox_rooms->currentIndex() + 1));
    room_name.append(": ");
    room_name.append(arg1);
    ui->combobox_rooms->setItemText(ui->combobox_rooms->currentIndex(), room_name);
    ui->combo_N->setItemText(ui->combobox_rooms->currentIndex() + 1, room_name);
    ui->combo_S->setItemText(ui->combobox_rooms->currentIndex() + 1, room_name);
    ui->combo_W->setItemText(ui->combobox_rooms->currentIndex() + 1, room_name);
    ui->combo_E->setItemText(ui->combobox_rooms->currentIndex() + 1, room_name);
}

void Editor::on_combo_N_currentIndexChanged(int index)
{
    current_room_->set_north(index);
}

void Editor::on_combo_S_currentIndexChanged(int index)
{
    current_room_->set_south(index);
}

void Editor::on_combo_W_currentIndexChanged(int index)
{
    current_room_->set_west(index);
}

void Editor::on_combo_E_currentIndexChanged(int index)
{
    current_room_->set_east(index);
}

void Editor::on_combobox_rooms_currentIndexChanged(int index)
{
    load_Room(rooms.at(index));
    // Byt till rumfliken
    if (ui->tabWidget->currentIndex() != 0)
        ui->tabWidget->setCurrentIndex(0);

    ui->combo_N->setCurrentIndex(current_room_->get_north());
    ui->combo_S->setCurrentIndex(current_room_->get_south());
    ui->combo_W->setCurrentIndex(current_room_->get_west());
    ui->combo_E->setCurrentIndex(current_room_->get_east());
}

void Editor::on_edit_room_description_textChanged()
{
    current_room_->set_description(ui->edit_room_description->toPlainText());
}

// -- SLUT: Funktioner som sparar värdena som användaren skriver in --




void Editor::load_exits()
{
    ui->combo_N->setCurrentIndex(current_room_->get_north());
    ui->combo_S->setCurrentIndex(current_room_->get_south());
    ui->combo_W->setCurrentIndex(current_room_->get_west());
    ui->combo_E->setCurrentIndex(current_room_->get_east());
}

void Editor::on_button_item_clicked()
{
    Item_Editor item{"", "", 0, 0, 0, 0, false, false, false};
    current_room_->add_item(item);
    current_item_ = ui->list_items->count();
    ui->list_items->addItem(current_room_->get_back_item().get_name());
    load_item(current_room_->get_item(current_item_));
    if (ui->tabWidget->currentIndex() != 1)
        ui->tabWidget->setCurrentIndex(1);

    ui->list_items->setCurrentRow(current_item_);

    // Gör så att det går att skriva om användaren har lagt till ett föremål
    ui->edit_item_description->setReadOnly(false);
    ui->edit_item_name->setReadOnly(false);
    ui->checkbox_item_pickable->setCheckable(true);
    ui->checkbox_item_sellable->setCheckable(true);
    ui->checkbox_item_throwable->setCheckable(true);
    ui->spinbox_item_value->setReadOnly(false);
    ui->edit_item_name->setFocus();
}

void Editor::on_list_items_doubleClicked(const QModelIndex &index)
{
    // Byt till personfliken
    if (ui->tabWidget->currentIndex() != 1)
        ui->tabWidget->setCurrentIndex(1);
    current_item_ = index.row();
    load_item(current_room_->get_item(current_item_));
}

void Editor::load_item(const Item_Editor& item)
{
    ui->edit_item_name->setText(item.get_name());
    ui->edit_item_description->setText(item.get_description());
    ui->spinbox_item_value->setValue(item.get_value());
    ui->checkbox_item_pickable->setChecked(item.get_pickable());
    ui->checkbox_item_sellable->setChecked(item.get_sellable());
    ui->checkbox_item_throwable->setChecked(item.get_throwable());
}

void Editor::on_edit_item_name_textChanged(const QString &arg1)
{
    current_room_->get_item(current_item_).set_name(arg1);
    ui->list_items->item(current_item_)->setText(arg1);
}

void Editor::on_edit_item_description_textChanged()
{
    current_room_->get_item(current_item_).set_description(ui->edit_item_description->toPlainText());
}

void Editor::on_spinbox_item_value_valueChanged(int arg1)
{
    current_room_->get_item(current_item_).set_value(arg1);
}

void Editor::on_checkbox_item_sellable_clicked()
{
    current_room_->get_item(current_item_).set_sellable(ui->checkbox_item_sellable->checkState());
}

void Editor::on_checkbox_item_pickable_clicked()
{
    current_room_->get_item(current_item_).set_pickable(ui->checkbox_item_pickable->checkState());
}

void Editor::on_checkbox_item_throwable_clicked()
{
    current_room_->get_item(current_item_).set_throwable(ui->checkbox_item_throwable->checkState());
}

void Editor::on_button_remove_item_clicked()
{
    if (ui->list_items->count() > 0)
    {
        current_room_->delete_item(current_item_);
        delete ui->list_items->currentItem();
        if (current_item_ = ui->list_items->count() && ui->list_items->count() > 1)
            load_item(current_room_->get_item(current_item_ - 1));
    }
}

void Editor::on_button_delete_room_clicked()
{
    if (ui->combobox_rooms->count() > 1)
    {
    current_room_ = &rooms.at(ui->combobox_rooms->currentIndex() -1 );
    rooms.erase(rooms.begin() + ui->combobox_rooms->currentIndex());
    ui->combobox_rooms->removeItem(ui->combobox_rooms->currentIndex());
    }
}
