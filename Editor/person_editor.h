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

    QString get_name() const {return name_;}
    QString get_description() const {return description_;}
    bool get_merchant() const {return merchant_;}
    QString get_haircolour() const {return haircolour_;}
    QString get_dialog() const {return dialog_;}
    QString get_wanted_item_name() const {return wanted_item_name_;}
    QString get_recieved_item_dialog() const {return recieved_item_dialog_;}
    int get_weight() const {return weight_;}
    int get_length() const {return length_;}
    int get_width() const {return width_;}

    void set_name(QString name) {name_ = name;}
    void set_description(QString description) {description_ = description;}
    void set_merchant(bool merchant) {merchant_ = merchant;}
    void set_haircolour(QString haircolour) {haircolour_ = haircolour;}
    void set_dialog(QString dialog) {dialog_ = dialog;}
    void set_wanted_item_name(QString wanted_item_name) {wanted_item_name_ = wanted_item_name;}
    void set_recieved_item_dialog(QString recieved_item_dialog) {recieved_item_dialog_ = recieved_item_dialog;}
    void set_weight(int weight) {weight_ = weight;}
    void set_length(int length) {length_ = length;}
    void set_width(int width) {width_ = width;}

private:
    QString name_, description_;
    bool merchant_;
    QString haircolour_, dialog_, wanted_item_name_, recieved_item_dialog_;
    int weight_, length_, width_;
};

#endif // PERSON_EDITOR_H
