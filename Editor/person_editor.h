#ifndef PERSON_EDITOR_H
#define PERSON_EDITOR_H
#include <QString>

class Person_Editor
{
public:
    Person_Editor(QString name, QString description,QString dialog,
                  QString recieved_item_dialog,QString haircolour,
                  QString wanted_item_name,int weight, int length,
                  int width, bool merchant)
        : name_{name}, description_{description},dialog_{dialog},
          recieved_item_dialog_{recieved_item_dialog},
          haircolour_{haircolour},wanted_item_name_{wanted_item_name},
          weight_{weight},
          length_{length},
          merchant_{merchant},
          width_{width}
    {}

    Person_Editor(const Person_Editor&) = default;
    Person_Editor(Person_Editor&&) = default;
    Person_Editor& operator=(Person_Editor&) = default;
    ~Person_Editor() = default;

    QString name_;
    QString description_;
    bool merchant_;
    QString haircolour_;
    QString dialog_;
    QString wanted_item_name_;
    QString recieved_item_dialog_;
    int weight_;
    int length_;
    int width_;


private:
};

#endif // PERSON_EDITOR_H
