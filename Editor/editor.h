#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>
#include "person_editor.h"
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
    std::vector<Person_Editor> personer;
private slots:

    void on_list_npcs_doubleClicked(const QModelIndex &index);

    void on_edit_description_textChanged();


    void on_edit_dialog_textChanged();

    void on_edit_recieved_dialog_textChanged();

    void on_button_npc_clicked();

    void on_edit_name_textChanged(const QString &arg1);

private:
    Ui::Editor *ui;
    void load_NPC(const Person_Editor p);
    int current_person_;
};

#endif // EDITOR_H
