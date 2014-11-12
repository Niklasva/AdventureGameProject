#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>
#include "person_editor.h"
#include "room_editor.h"
#include "item_editor.h"
#include <vector>
#include <QString>
#include <QList>


namespace Ui {
class Editor;
}

class Editor : public QMainWindow
{
    Q_OBJECT

public:
    explicit Editor(QWidget *parent = 0);
    ~Editor();
private slots:

    void on_list_npcs_doubleClicked(const QModelIndex &index);

    void on_edit_description_textChanged();

    void on_edit_dialog_textChanged();

    void on_edit_recieved_dialog_textChanged();

    void on_button_npc_clicked();

    void on_edit_name_textChanged(const QString &arg1);

    void on_edit_hair_textChanged(const QString &arg1);

    void on_edit_width_valueChanged(int arg1);

    void on_edit_wants_textChanged(const QString &arg1);

    void on_edit_weight_valueChanged(int arg1);

    void on_edit_height_valueChanged(int arg1);

    void on_checkbox_Merchant_clicked();

    void on_button_new_room_clicked();

    void on_combobox_rooms_currentIndexChanged(int index);

    void on_edit_room_name_textChanged(const QString &arg1);

    void on_edit_room_description_textChanged();

    void on_combo_N_currentIndexChanged(int index);

    void on_combo_S_currentIndexChanged(int index);

    void on_combo_W_currentIndexChanged(int index);

    void on_combo_E_currentIndexChanged(int index);

    void on_button_item_clicked();

    void on_list_items_doubleClicked(const QModelIndex &index);

    void on_edit_item_name_textChanged(const QString &arg1);

    void on_edit_item_description_textChanged();

    void on_spinbox_item_value_valueChanged(int arg1);

    void on_checkbox_item_sellable_clicked();

    void on_checkbox_item_pickable_clicked();

    void on_checkbox_item_throwable_clicked();

    void on_button_remove_item_clicked();

    void on_button_delete_room_clicked();

private:
    Ui::Editor *ui;
    void load_NPC(const Person_Editor p);
    void load_Room(Room_Editor & room);
    void load_exits();
    void load_item(const Item_Editor& item);
    Person_Editor* current_person_;
    Room_Editor* current_room_;
    int current_item_;
    int current_person_id_;
    std::vector<Person_Editor> personer;
    std::vector<Room_Editor> rooms;
};

#endif // EDITOR_H
