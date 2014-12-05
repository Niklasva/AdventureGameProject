#ifndef ROOM_H
#define ROOM_H
#include "Entity.h"
#include "Person.h"
#include "Merchant.h"
#include <vector>
#include <iterator>
#include <algorithm>

class Merchant;
class Person;
class Object;

class Room : public  Entity
{
public:
    Room(const QString& name, const QString& description)
        : Entity {name, description}{}

    Room() = default;

    void set_item(const Item& o) { items_.push_back(o); }
    void set_person(const Person& p){ persons_.push_back(p);}
    void set_merchant(const Merchant& m){merchants_.push_back(m);}
    void remove_item(const int& index){items_.erase(items_.begin()+index);}
    void remove_person(const int& index){persons_.erase(persons_.begin() + index);}
    QString get_directions();

    const std::vector<int>& get_room_ids() {return exits_;}
    std::vector<Person>& get_persons() {return persons_;}
    std::vector<Merchant>& get_merchants(){return merchants_;}
    std::vector<Item>& get_items(){return items_;}

    Person& get_person(const int& index){ return persons_.at(index); }
    Item& get_item(const int& index){return items_.at(index); }
    Merchant& get_merchant(const int& index) {return merchants_.at(index);}


    void set_north(const int& N = 0){n_ = N;}
    void set_west(const int& W = 0){w_ = W;}
    void set_south(const int& S = 0){s_ = S;}
    void set_east(const int& E = 0){e_ = E;}

    void set_north_key(QString key) {keys_[0] = key;}
    void set_south_key(QString key) {keys_[1] = key;}
    void set_west_key(QString key) {keys_[2] = key;}
    void set_east_key(QString key) {keys_[3] = key;}

    std::vector<QString> get_keys() {return keys_;}
    QString get_key(int i) {return keys_[i];}

    void init_directions(){exits_.at(0) = n_; exits_.at(1) = s_; exits_.at(2) = w_; exits_.at(3) = e_;}

    int  n_,w_,s_,e_;
private:
    std::vector<Item> items_;
    std::vector<Person> persons_;
    std::vector<Merchant> merchants_;
    std::vector<int> exits_ = {n_,s_,w_,e_};
    std::vector<QString> keys_ {"","","",""};
};




#endif // ROOM_H
