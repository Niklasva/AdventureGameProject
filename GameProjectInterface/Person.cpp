#include "Person.h"
#include <algorithm>


bool Person:: wanted_item(Item& item)
{

    if(item.get_name() == wanted_item_name_)
    {
        return true;
    }
    else
    {
        return false;
    }
}

