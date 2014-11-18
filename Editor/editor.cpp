#include "editor.h"
#include "ui_editor.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>

int current_merchant_item_ = 0;
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
    ui->items_for_sale_tab->setEnabled(p.get_merchant());
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
    // Byt till persorow();nfliken
    if (ui->tabWidget->currentIndex() != 2)
        ui->tabWidget->setCurrentIndex(2);

    current_person_id_ = index.row();
    current_person_ = &current_room_->get_person(current_person_id_);
    load_NPC(*current_person_);
    ui->edit_name->setReadOnly(false);
    ui->edit_description->setReadOnly(false);
    ui->edit_recieved_dialog->setReadOnly(false);
    ui->edit_dialog->setReadOnly(false);
    ui->edit_hair->setReadOnly(false);
    ui->edit_width->setReadOnly(false);
    ui->edit_wants->setReadOnly(false);
    ui->edit_weight->setReadOnly(false);
    ui->edit_height->setReadOnly(false);
    ui->checkbox_Merchant->setCheckable(true);
}

void Editor::on_button_npc_clicked()
{
    Person_Editor temp{"Namnlös person", "","","","","", 0, 0, 0, false};
    current_room_->add_person(temp);
    ui->list_npcs->addItem(temp.get_name());
    // Byt till personfliken
    if (ui->tabWidget->currentIndex() != 2)
        ui->tabWidget->setCurrentIndex(2);

    current_person_id_ = ui->list_npcs->count() - 1;
    current_person_ = &current_room_->get_person(current_person_id_);
    ui->list_npcs->setCurrentRow(current_person_id_);

    ui->edit_name->setReadOnly(false);
    ui->edit_description->setReadOnly(false);
    ui->edit_recieved_dialog->setReadOnly(false);
    ui->edit_dialog->setReadOnly(false);
    ui->edit_hair->setReadOnly(false);
    ui->edit_width->setReadOnly(false);
    ui->edit_wants->setReadOnly(false);
    ui->edit_weight->setReadOnly(false);
    ui->edit_height->setReadOnly(false);
    ui->checkbox_Merchant->setCheckable(true);

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

void Editor::add_room(Room_Editor room)
{
    rooms.push_back(room);
    QString room_name {"Rum "};
    room_name.append(QString::number(rooms.size()));
    room_name.append(": ");
    room_name.append(room.get_name());
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
    ui->items_for_sale_tab->setEnabled(ui->checkbox_Merchant->checkState());
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

void Editor::load_person_item(const Item_Editor& item)
{
    ui->edit_item_name_2->setText(item.get_name());
    ui->edit_item_description_2->setText(item.get_description());
    ui->spinbox_item_value_2->setValue(item.get_value());
    ui->spinBox_item_length_2->setValue(item.get_length());
    ui->spinBox_item_weight_2->setValue(item.get_weight());
    ui->spinBox_item_width_2->setValue(item.get_width());
    ui->checkbox_item_pickable_2->setChecked(item.get_pickable());
    ui->checkbox_item_sellable_2->setChecked(item.get_sellable());
    ui->checkbox_item_throwable_2->setChecked(item.get_throwable());
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
        if (current_item_ == ui->list_items->count() && ui->list_items->count() > 1)
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

void Editor::on_button_remove_npc_clicked()
{
    if (ui->list_npcs->count() > 0)
    {
        current_room_->delete_person(current_person_id_);
        delete ui->list_npcs->currentItem();
        if (current_person_id_ == ui->list_npcs->count() && ui->list_npcs->count() > 1)
            load_NPC(current_room_->get_person(current_person_id_ - 1));
    }
}

void Editor::on_spinBox_item_weight_valueChanged(int arg1)
{

    current_room_->get_item(current_item_).set_weight(arg1);
}

void Editor::on_spinBox_item_length_valueChanged(int arg1)
{
    current_room_->get_item(current_item_).set_length(arg1);
}

void Editor::on_spinBox_item_width_valueChanged(int arg1)
{
    current_room_->get_item(current_item_).set_width(arg1);
}

void Editor::on_button_merchant_add_item_clicked()
{
    Item_Editor item{"", "", 0, 0, 0, 0, false, false, false};
    current_person_->add_item(item);
    current_merchant_item_ = ui->list_merchant_items->count();
    ui->list_merchant_items->addItem(current_person_->get_back_item().get_name());
    load_person_item(current_person_->get_item(current_merchant_item_));
    ui->list_merchant_items->setCurrentRow(current_merchant_item_);

    // Gör så att det går att skriva om användaren har lagt till ett föremål
    ui->edit_item_description_2->setReadOnly(false);
    ui->edit_item_name_2->setReadOnly(false);
    ui->checkbox_item_pickable_2->setCheckable(true);
    ui->checkbox_item_sellable_2->setCheckable(true);
    ui->checkbox_item_throwable_2->setCheckable(true);
    ui->spinbox_item_value_2->setReadOnly(false);
    ui->edit_item_name_2->setFocus();
}

void Editor::on_menu_save_triggered()
{
    QFileDialog dialog;
    dialog.setDefaultSuffix(".bisys");
    QString filename = dialog.getSaveFileName(this, tr("Spara fil"), "~/", tr("Textäventyrsredigerarfiler (*.bisys *.bisysslor)"));
    save(filename);
}

void Editor::on_menu_load_triggered()
{
    QFileDialog dialog;
    dialog.setDefaultSuffix(".bisys");
    QString filename = dialog.getOpenFileName(this, tr("Öppna fil"), "~/", tr("Textäventyrsredigerarfiler (*.bisys *.bisysslor)"));
    load(filename);
}

int Editor::save(QString filename)
{
    QFile file(filename);

    if (!file.open(QFile::Append | QFile::Text))
    {
        qDebug() << "Could not open file for writing";
        return 1;
    }
    file.resize(0);
    QTextStream out(&file);
    for (size_t i {0}; i < rooms.size(); ++i)
    {
        out << "// Room " << i+1 << "\nRoom:\n{\n";                        // Inledning
        out << "\tName: " << rooms.at(i).get_name() << "\n";               // Utskrift av namn
        out << "\tDescription: " << rooms.at(i).get_description() << "\n"; // Utskrift av beskrivning

        for (Person_Editor s : rooms.at(i).get_persons())                  // Utskrift av person
        {
            out << s.print_person();
        }

        for (Item_Editor s : rooms.at(i).get_items())                      // Utskrift av person
        {
            out << s.print_item();
        }

        out << "\n\tExits:\n\t{\n";                                         // -- Riktingar --
        out << "\t\tN: " << rooms.at(i).get_north() << "\n";                // Utskrift av north
        out << "\t\tS: " << rooms.at(i).get_south() << "\n";                // Utskrift av south
        out << "\t\tW: " << rooms.at(i).get_west() << "\n";                 // Utskrift av west
        out << "\t\tE: " << rooms.at(i).get_east() << "\n\t}\n";            // Utskrift av east och avslut av riktningar
        out << "\n}\n\n";                                                   // Avslut
    }

    file.close();
    return 0;
}

int Editor::load(QString filename)
{
    Room_Editor temp_room;          // Rummet som läsas in
    Person_Editor temp_person;      // Person som skall läsas in
    Item_Editor temp_item;          // Föremålet som skall läsas in
    QFile file(filename);           // Filen som skall läsas in (bestäms av användaren)
    QString is_reading {"Nothing"}; // is_reading förklarar för programmet vad som skall laddas. T.ex. om en person eller ett rum skall laddas in

    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        while ( !in.atEnd() )
        {
           QString line = in.readLine();
           line.replace("\t", ""); // Plocka bort inledande tab
           if (line.startsWith("//") || line.isEmpty()) // Hoppa över rad vid kommentarer
                   continue;
           else if (line == "Room:")
               is_reading = "Room";

           else if (line == "Item:")
               is_reading = "Item";
           else if (line == "Person:")
               is_reading = "Person";
           else if (line == "Merchant:")
               is_reading = "Merchant";
           else if (line == "Exits:")
               is_reading = "Exits";

           if (is_reading == "Room")
           {
               if (line.startsWith("Name"))
               {
                   temp_room.set_name(line.split(": ").last());
               }
               else if (line.startsWith("Description"))
                   temp_room.set_description(line.split(": ").last());
               else if (line == "}")
               {
                   add_room(temp_room);
                   is_reading = "Nothing";
               }
           }
           else if (is_reading == "Person")
           {
               if (line.startsWith("Name"))
                   temp_person.set_name(line.split(": ").last());
               else if (line.startsWith("Description"))
                   temp_person.set_description(line.split(": ").last());
               else if (line.startsWith("Dialog"))
                   temp_person.set_dialog(line.split(": ").last());
               else if (line.startsWith("Recieved item dialog"))
                   temp_person.set_recieved_item_dialog(line.split(": ").last());
               else if (line.startsWith("Hair"))
                   temp_person.set_haircolour(line.split(": ").last());
               else if (line.startsWith("Height"))
                   temp_person.set_length(line.split(": ").last().toInt());
               else if (line.startsWith("Width"))
                   temp_person.set_width(line.split(": ").last().toInt());
               else if (line.startsWith("Weight"))
                   temp_person.set_weight(line.split(": ").last().toInt());
               else if (line.startsWith("Wants"))
                   temp_person.set_wanted_item_name(line.split(": ").last());
               else if (line == "}")
               {
                   temp_room.add_person(temp_person);
                   is_reading = "Room";
               }
           }
           else if (is_reading == "Merchant")
           {
               temp_person.set_merchant(true);
               if (line.startsWith("Name"))
                   temp_person.set_name(line.split(": ").last());
               else if (line.startsWith("Description"))
                   temp_person.set_description(line.split(": ").last());
               else if (line.startsWith("Dialog"))
                   temp_person.set_dialog(line.split(": ").last());
               else if (line.startsWith("Recieved item dialog"))
                   temp_person.set_recieved_item_dialog(line.split(": ").last());
               else if (line.startsWith("Hair"))
                   temp_person.set_haircolour(line.split(": ").last());
               else if (line.startsWith("Height"))
                   temp_person.set_length(line.split(": ").last().toInt());
               else if (line.startsWith("Width"))
                   temp_person.set_width(line.split(": ").last().toInt());
               else if (line.startsWith("Weight"))
                   temp_person.set_weight(line.split(": ").last().toInt());
               else if (line.startsWith("Wants"))
                   temp_person.set_wanted_item_name(line.split(": ").last());
               else if (line == "}")
               {
                   temp_room.add_person(temp_person);
                   is_reading = "Room";
               }
           }
           else if (is_reading == "Item")
           {
               if (line.startsWith("Name"))
                   temp_item.set_name(line.split(": ").last());
               else if (line.startsWith("Description"))
                   temp_item.set_description(line.split(": ").last());
               else if (line.startsWith("Height"))
                   temp_item.set_length(line.split(": ").last().toInt());
               else if (line.startsWith("Width"))
                   temp_item.set_width(line.split(": ").last().toInt());
               else if (line.startsWith("Value"))
                  temp_item.set_value(line.split(": ").last().toInt());
               else if (line.startsWith("Throwable"))
                   temp_item.set_throwable(line.split(": ").last().toInt());
               else if (line.startsWith("Sellable"))
                   temp_item.set_sellable(line.split(": ").last().toInt());
               else if (line.startsWith("Pickable"))
                   temp_item.set_pickable(line.split(": ").last().toInt());
               else if (line == "}")
               {
                   temp_room.add_item(temp_item);
                   is_reading = "Room";
               }
           }
           else if (is_reading == "Exits")
           {
               if (line.startsWith("N"))
               {
                   temp_room.set_north(line.split(": ").last().toInt());
               }
               else if (line.startsWith("S"))
               {
                   temp_room.set_south(line.split(": ").last().toInt());
               }
               else if (line.startsWith("W"))
               {
                   temp_room.set_west(line.split(": ").last().toInt());
               }
               else if (line.startsWith("E"))
               {
                   temp_room.set_east(line.split(": ").last().toInt());
               }
               else if (line.endsWith("}"))
               {
                   is_reading = "Room";
               }

           }
        }
        file.close();
     }
    return 0;
}



void Editor::on_edit_item_name_2_textChanged(const QString &arg1)
{
    current_person_->get_item(current_merchant_item_).set_name(arg1);
    ui->list_merchant_items->item(current_merchant_item_)->setText(arg1);
}

void Editor::on_button_merchant_remove_item_clicked()
{
    if (ui->list_merchant_items->count() > 0)
    {
        current_person_->delete_item(current_merchant_item_);
        delete ui->list_merchant_items->currentItem();
        if (current_merchant_item_ == ui->list_merchant_items->count() && ui->list_merchant_items->count() > 1)
            load_item(current_person_->get_item(current_merchant_item_ - 1));
    }
}

void Editor::on_edit_item_description_2_textChanged()
{
    current_person_->get_item(current_merchant_item_).set_description(ui->edit_item_description_2->toPlainText());
}

void Editor::on_spinbox_item_value_2_valueChanged(int arg1)
{
    current_person_->get_item(current_merchant_item_).set_value(arg1);
}

void Editor::on_list_merchant_items_doubleClicked(const QModelIndex &index)
{
    current_merchant_item_ = index.row();
    load_person_item(current_person_->get_item(current_merchant_item_));
    ui->list_merchant_items->setCurrentRow(current_merchant_item_);
}


void Editor::on_checkbox_item_pickable_2_clicked(bool checked)
{
    current_person_->get_item(current_merchant_item_).set_pickable(checked);
}

void Editor::on_checkbox_item_throwable_2_clicked(bool checked)
{
    current_person_->get_item(current_merchant_item_).set_throwable(checked);
}

void Editor::on_checkbox_item_sellable_2_clicked(bool checked)
{
    current_person_->get_item(current_merchant_item_).set_sellable(checked);
}

void Editor::on_spinBox_item_weight_2_valueChanged(int arg1)
{
    current_person_->get_item(current_merchant_item_).set_weight(arg1);
}

void Editor::on_spinBox_item_length_2_valueChanged(int arg1)
{
    current_person_->get_item(current_merchant_item_).set_length(arg1);
}

void Editor::on_spinBox_item_width_2_valueChanged(int arg1)
{
    current_person_->get_item(current_merchant_item_).set_width(arg1);
}
