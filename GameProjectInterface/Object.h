#ifndef OBJECT_H
#define OBJECT_H

#include "Entity.h"
#include "string"

class Object : public Entity
{
public:
    Object(const QString& name, const QString& description,
           const int& weight,const int& length)
        : Entity{name,description}, weight_{weight},length_{length}
    {}

    Object() = default;

    int get_weight(){return weight_;}
    int get_length(){return length_;}
    int get_width(){return width_;}


    void set_weight(const int& weight){weight_ = weight;}
    void set_length(const int& length){length_ = length;}
    void set_width(const int& width){width_ = width;}



private:
    int weight_,length_,width_;
};



#endif // OBJECT_H
