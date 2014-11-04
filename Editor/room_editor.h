#ifndef ROOM_EDITOR_H
#define ROOM_EDITOR_H

#include <vector>
#include <QString>
#include "person_editor.h"
#include "item_editor.h"

class Room_Editor
{
public:
    Room_Editor(QString name, QString description, int n, int s, int w, int e)
        : name_{name}, description_{description}, north_{n}, south_{s}, west_{w}, east_{e} {}

    void add_person(Person_Editor person) {persons_.push_back(person);}
    Person_Editor& get_person(size_t index) {return persons_.at(index);}
    void add_item(Item_Editor item) {items_.push_back(item);}
    Item_Editor& get_item(size_t index) {return items_.at(index);}
    std::vector<Person_Editor> get_persons() {return persons_;}

    void set_name(QString name) {}
    void set_description(QString description) {}
    void set_directions(int n, int s, int w, int e) {}
    QString get_name() const {return name_;}

private:
    std::vector<Person_Editor> persons_;
    std::vector<Item_Editor> items_;
    QString name_, description_;
    int north_, south_, west_, east_;

};

#endif // ROOM_EDITOR_H
