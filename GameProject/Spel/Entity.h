#ifndef ENTITY
#define ENTITY
#include <vector>
#include <QString>
class Entity
{
 public:

  Entity(const QString& name, const QString& description):
   description_{description}, name_{name}
   {}
  Entity() = default;

  QString get_description() const {return description_;}
  QString get_name() const {return name_;}

  void set_name(const QString& name){name_ = name;}
  void set_description(const QString& description){description_ = description;}

 private:
     QString description_,name_;
};
#endif
