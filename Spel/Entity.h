#ifndef ENTITY
#define ENTITY
#include <vector>
#include <string>
class Entity
{
public:
Entity(const std::string& name, const std::string& description):
    description_{description}, name_{name}
    {}
    ~Entity() = default;

    // Övriga konstruktorer är implicita.
    std::string get_description() const {return description_;}
    std::string get_name() const {return name_;}
private:
    const std::string name_,description_;
};
#endif
