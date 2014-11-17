#include "Room.h"
#include <iostream>

void Room:: get_directions()
{
    enum Directions : char  { North = 1, West = 2, South = 3, East = 4 };

    for(size_t i{0}; i != 4 ;++i)
    {
      if(exits[i] != 0)
       {
          switch(i)
                {
                  case North:
                  std::cout << "Du kan gå norrut\n";
                  break;
                  case West:
                  std::cout << "Du kan gå västerut\n";
                  break;
                  case South:
                  std::cout << "Du kan gå söderut\n";
                  break;
                  case East:
                  std::cout << "Du kan gå österut\n";
                  break;
               }
       }

    }

}
