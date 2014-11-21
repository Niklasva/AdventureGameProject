#ifndef ITEM
#define ITEM
#include "Object.h"
class Item : public Object
{

public:
    Item(const QString& name,const QString& description,
         const int& weight,const int& length,const bool& pickup,
         const bool& possible_to_sell,
	 const bool& throwable,const int& value
	)
	: Object{name,description,weight,length}, pickup_{pickup},possible_to_sell_{possible_to_sell},
	  throwable_{throwable}, value_{value}
	{}

    Item() = default;

    // Övriga konstruktorer är implicita

    bool is_throwable(){return throwable_;}

    void set_value(const int& value){value_ = value;}
    void set_pickable(const bool& pickup){pickup_ = pickup;}
    void set_possible_to_sell(const bool& sellable){possible_to_sell_ = sellable;}
    void set_throwable(const bool& throwable){throwable_ = throwable;}

private:
    bool pickup_;
    bool possible_to_sell_;
    bool throwable_;
    int value_;
};
#endif
