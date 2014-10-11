#include <ENTITY.h>

#ifndef OBJECT
#define OBJECT
class Object : Public Entity
{
public:
    Object(const std::string& name,
	   const std::string& description,
	   const std::string& weight,
	   const std::string& length)
	: Entity{name,description}, weight_{weight},length_{length}
	{}

    ~Object() = default;
    
    // Övriga konstruktorer är implicita.  
    /* std::string get_description() const {return description_;} */
    /* std::string get_name() const {return name_;} */

private:
    const int weight_,length_;
}
#endif
