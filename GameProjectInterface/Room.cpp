#include "Room.h"
#include <iostream>

QString Room:: get_directions()
{
    QString possible_directions_to_traverse;
    //Kanske snarare bör genera en vektor med boolska utryck.
    enum Directions : char  { North = 0, South = 1, West = 2, East = 3};
    bool no_exit{false};
    for(size_t i{0}; i != 4 ;++i)
    {
        if(exits_[i] != 0)
        {
            switch(i)
            {
            case North:
                possible_directions_to_traverse.append("Du kan gå norrut\n");
                break;
            case South:
                possible_directions_to_traverse.append("Du kan gå söderut\n");
                break;
            case West:
                possible_directions_to_traverse.append("Du kan gå västerut\n");
                break;
            case East:
                possible_directions_to_traverse.append("Du kan gå österut\n");
                break;
            }
        }

    }
    return possible_directions_to_traverse;
}

