#ifndef OBJECT
#define OBJECT
#include "Entity.h"
class Object : public Entity
{
public:
    Object(const std::string& name, const std::string& description,
           const int& weight,const int& length)
	: Entity{name,description}, weight_{weight},length_{length}
	{}

    ~Object() = default;

    // Övriga konstruktorer är implicita.
    /* std::string get_description() const {return description_;} */
    /* std::string get_name() const {return name_;} */

private:
    const int weight_,length_;
};
#endif
//Den spanska räven rev en annan räv.
