#ifndef ITEM
#define ITEM
#include "Object.h"
class Item : public Object
{

public:
    Item(const std::string& name,const std::string& description,
         const int& weight,const int& length,const bool& pickup,
         const bool& possible_to_sell,
        const bool& throwable,const int& value
	)
	: Object{name,description,weight,length}, pickup_{pickup},possible_to_sell_{possible_to_sell},
	throwable_{throwable}, value_{value}
	{}

    ~Item() = default;

    // Övriga konstruktorer är implicita

private:
    const bool pickup_;
    const bool possible_to_sell_;
    const bool throwable_;
    const int value_;
};
#endif
