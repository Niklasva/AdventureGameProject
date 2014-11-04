#include "editor.h"
#include "ui_editor.h"
#include <QDebug>

Editor::Editor(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::Editor)
{
    ui->setupUi(this);
    Room_Editor r {"Rum 1: Test", "test", 0, 0, 0,0};
    rooms.push_back(r);
    Person_Editor p1{"Armen", "test","DU ÄR VÄRDELÖS!","Bisysslor?","hej1","hej2", 10, 10, 10, true};
    Person_Editor p2{"Granntant Åsa", "Åsa_test","Kakor?","Tack! Har du något skvaller?","hej3","hej4", 5, 5, 10, false};
    rooms[0].add_person(p1);
    rooms[0].add_person(p2);
    ui->combobox_rooms->addItem(rooms[0].get_name());
    load_Room(rooms[0]);
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
    current_room_ = &room;
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
}

void Editor::on_buttom_new_room_clicked()
{
    Room_Editor temp {"Nytt rum", "", 0, 0, 0, 0};
    rooms.push_back(temp);
    QString room_name {"Rum "};
    room_name.append(QString::number(rooms.size()));
    room_name.append(": ");
    room_name.append(temp.get_name());
    ui->combobox_rooms->addItem(room_name);
    ui->combobox_rooms->setCurrentIndex(ui->combobox_rooms->count() - 1);
    load_Room(temp);
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

// -- SLUT: Funktioner som sparar värdena som användaren skriver in --



void Editor::on_combobox_rooms_currentIndexChanged(int index)
{
    load_Room(rooms.at(index));
}
