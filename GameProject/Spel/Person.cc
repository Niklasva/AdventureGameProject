#include "Person.h"
#include <algorithm>




bool Person:: wanted_item(Item& item)
{

  if(item.get_name() == wanted_item_name_)
  {
    //recieved_item_dialog_
    return true;
  }
  else
   {
      return false;
   }
}
