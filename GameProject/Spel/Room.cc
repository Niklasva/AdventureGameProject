#include "Room.h"
#include <iostream>

void Room:: get_directions()
{


    enum Directions : char  { North = 0, South = 1, West = 2, East = 3};
    bool no_exit{false};
    for(size_t i{0}; i != 4 ;++i)
    {
       if(exits_[i] != 0)
        {
          switch(i)
                {
                  case North:
                    std::cout << "Du kan gå norrut\n";
                    break;
                  case South:
                    std::cout << "Du kan gå söderut\n";
                    break;
                  case West:
                    std::cout << "Du kan gå västerut\n";
                    break;
                  case East:
                    std::cout << "Du kan gå österut\n";
                    break;
               }
      }

    }

}
