#ifndef PERSON_H
#define PERSON_H
#include "Item.h"
#include <QString>


class Person : public Object
{
public:
    Person(const QString& name,
           const QString& description,
           const int& weight,
           const int& length,
           const bool& can_carry,
           const QString& haircolour,
           const QString& dialog,
           const QString& wanted_item_name_,
           const QString& recieved_item_dialog)
        : Object{name,description,weight,length},
          can_carry_{can_carry}, haircolour_{haircolour},
          dialog_{dialog}, wanted_item_name_{wanted_item_name_},
          recieved_item_dialog_{recieved_item_dialog}
    {}

    Person() = default;

    QString get_dialog(){return dialog_;}
    QString get_recieved_item_dialog(){return recieved_item_dialog_;}

    void set_dialog(const QString& dialog){dialog_ = dialog;}
    void set_received_item_dialog(const QString& item_dialog){recieved_item_dialog_ = item_dialog;}
    void set_haircolour(const QString& haircolour){haircolour_ = haircolour;}
    void set_wanted_item_name(const QString& item_name){wanted_item_name_ = item_name;}
    void set_item(Item& item) {item_ = item;}

    bool wanted_item(Item&);
    QString& get_wanted_item_name() {return wanted_item_name_;}



    bool get_item_event() {return item_event_;}
    Item& get_item() {return item_;}
    void set_item_event(bool item_event) {item_event_ = item_event;}
    bool has_item() {return (item_.get_name() != "");}



private:
    bool can_carry_;
    QString haircolour_;
    QString dialog_;
    QString wanted_item_name_;
    QString recieved_item_dialog_;
    Item item_;
    bool item_event_ {false};
};



#endif // PERSON_H
