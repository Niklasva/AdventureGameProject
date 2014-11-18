#ifndef ITEM_EDITOR_H
#define ITEM_EDITOR_H
#include <QString>
class Item_Editor
{
public:
    Item_Editor(QString name = "", QString description = "", int weight = 0, int length = 0, int width = 0, int value = 0, bool sellable = false, bool pickable = false, bool throwable = false)
        : name_{name}, description_{description},
          weight_{weight}, length_{length}, width_{width},
          value_{value}, sellable_{sellable}, throwable_{throwable}, pickable_{pickable}
    {}
    Item_Editor(const Item_Editor&) = default;
    Item_Editor(Item_Editor&&) = default;
    Item_Editor& operator=(const Item_Editor&) = default;
    Item_Editor& operator=(Item_Editor&&) = default;

    ~Item_Editor() = default;

    QString get_name() const {return name_;}
    QString get_description() const {return description_;}
    int get_weight() const {return weight_;}
    int get_length() const {return length_;}
    int get_width() const {return width_;}
    int get_value() const {return value_;}
    bool get_sellable() const {return sellable_;}
    bool get_throwable() const {return throwable_;}
    bool get_pickable() const {return pickable_;}


    void set_name(QString name) {name_ = name;}
    void set_description(QString description) {description_ = description;}
    void set_weight(int weight) {weight_ = weight;}
    void set_length(int length) {length_ = length;}
    void set_width(int width) {width_ = width;}
    void set_value(int value) {value_ = value;}
    void set_sellable(bool sellable) {sellable_ = sellable;}
    void set_pickable(bool pickable) {pickable_ = pickable;}
    void set_throwable(bool throwable) {throwable_ = throwable;}


    QString print_item();

private:
    QString name_, description_;
    int weight_, length_, width_, value_;
    bool sellable_, throwable_, pickable_;

};


#endif // ITEM_EDITOR_H
