#include "Player.h"
#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>
#include <string> //Ber till C++ gudarna att detta inte ger buggar.



using namespace std;
void decide_direction(const string& input);
void decide_what_to_give(const string& input);
void decide_what_to_pick(const string& input);
void decide_what_to_talk(const string& input);
void decide_what_to_look(const string& input);
void set_location(const string& new_location,Game& G,Room& room);



void Player::read_input(QString& input,Game& G) //Str
{

   //R to_uppercase(input);
    cout << "Du matade in följande kommandon " << input.toStdString() << endl;

    if (input == "HELP" || input == "HJÄLP")
    {
        cerr << "Du bad om hjälp\n";
        G.get_help(); //Löser den externa hj�lpfilen
    }


    else if((input == "ÄVENTYRSKORG") ||  (input == "TITTA På  äVENTYRSKORG") || (input == "INVENTORY"))
    {

     cout << "Hej du anropade äventyrskorgen\nFöljande föremål finns: ";
     for(auto i: inventory_)
        {
          cout << i.get_name().toStdString() << " "; //Arv och get funktioner. mysigt
        }
            cout << endl;
            return;

    }
    else if(input == "GÅ" || input == "GO") //fulhackadet har inga gränser...
    {
        cout << "Nu kommer vi att gå " << "\n";
        decide_direction(G);
    }

    else if(input == "GE")
    {
        string person_to_give_to;
        cout << "Till vem vill du ge\n";
        cin.ignore();
        getline(cin,person_to_give_to);
        cout << "Vad vill du ge\n";
        string item_to_give;
        getline(cin,item_to_give);
        decide_what_to_give(item_to_give,person_to_give_to,G);
    }

    else if(input == "PRATA")
    {
        cout << "Nu vi " << input.toStdString() << endl;
        decide_what_to_talk(input.toStdString(),G);
    }

    else if(input == "PLOCKA" || input == "TA" || input == "TAKE")
    {
        decide_what_to_pick(input.toStdString(),G);
    }
    else if(input == "TITTA")
    {
        decide_what_to_look(input.toStdString(),G);
    }
    else
    {
        cerr << "Nu blev jag förvirrad\n";
        cerr << "Det blev bara fel känner\n";

    }
}


void Player::decide_direction(Game& G)
{

      auto room  = G.get_room(location_); // Vi hamnar i rätt rum.
      room.get_directions();
      //Spelaren skall kunna välja rum.
      cout << "Var vill du gå :";

      string room_to_go_to;
      std::cin >> room_to_go_to;

      transform(room_to_go_to.begin(), room_to_go_to.end(),
                room_to_go_to.begin(), std::ptr_fun <int, int> ( std::toupper ) );



     if(room_to_go_to == "NORTH" || room_to_go_to == "SOUTH"
             || room_to_go_to == "WEST" || room_to_go_to == "EAST"
             || room_to_go_to == "ÖST" || room_to_go_to == "VÄST"
             || room_to_go_to == "SYD" || room_to_go_to == "NORR")
        {
            set_location(room_to_go_to,G,room);
        }
      return;
 }

    void Player::decide_what_to_give(const string& item_to_give,const string& person_to_give_to,Game& G)
    {

       if(inventory_.empty())
       {
           cerr << "Du har inga föremål, det var tråkigt\n";
           return;
       }

      Item tmp_item;
      auto room  = G.get_room(location_);
      auto person_vector = room.get_persons(); //Person vector kommer nu vara vektorn med de personer som finns i rummet vi �r i.

      for(unsigned int i{0}; i < inventory_.size(); ++i)
      {
        if(inventory_.at(i).get_name().toStdString() == item_to_give)
            {
            if(inventory_.at(i).is_throwable())
                {
                    tmp_item = inventory_.at(i); //Provar med defaultkonstruktorn.
                    inventory_.erase(inventory_.begin()+i);
                    cout << "Du ger " << item_to_give << " till " << person_to_give_to << endl;
                }
             else
                {
                   cerr << item_to_give << " går inte att bara kasta bort eller ge bort.\n";
                   break;
                }
            }
      }


    bool  can_give_away {tmp_item.is_throwable()};

 if(can_give_away)
      {
        for(Person p : person_vector) //search for persons in room
          {
            if(p.get_name().toStdString() == person_to_give_to) //om input �r namn
            {
                if(p.wanted_item(tmp_item)) //If the persons wants the item.
                {
                    cout << p.get_name().toStdString() << " säger: " << p.get_recieved_item_dialog().toStdString() << endl;
                }
                else
                {
                     cout << "Så knasigt det kan bli";
                }

            }

          }
        }
          return;
    }



    void Player::decide_what_to_talk(const string& input,Game& G)
    {
        //Beroende p� om personen finns eller ej och massa andra paramtetrar..

        auto room  = G.get_room(location_);
        auto person_vector = room.get_persons(); //Person vector kommer nu vara vektorn med de personer som finns i rummet vi �r i.

        string person_to_talk_with;

        cout << "Vem vill du prata med \n";
        cin.ignore();
        getline(cin,person_to_talk_with);
        bool found = false;

        for(auto i: person_vector)
        {
            if(i.get_name().toStdString() == person_to_talk_with)
            {
                cout << person_to_talk_with << " säger: " << i.get_dialog().toStdString() << " \n";
                found = true;
                break;
            }
        }

        if(!found)
        {
            cerr << "Personen finns inte det var tr�kigt\n";

        }

        return;
    }

    void Player::decide_what_to_pick(const string& input,Game& G)
    {

       auto item_vector = G.get_room(location_).get_items();
       bool sucess{false};

       cout << "Vad vill du plocka upp\n";
       string thing_to_pick_up{""};
       cin.ignore();
       getline(cin,thing_to_pick_up);

       for(size_t i{0}; i < item_vector.size();++i)
       {
         if(item_vector.at(i).get_name().toStdString() == thing_to_pick_up)
            {
                inventory_.push_back(item_vector.at(i));
                G.get_room(location_).remove_item(i);
                sucess = true;
            }
       }


       if(sucess)
       {
           cout << "Du plockade upp: " << thing_to_pick_up << endl;
       }


        return;
    }

    void Player::decide_what_to_look(const string& input,Game& G)
    {

        Item tmp_item;
        auto room  = G.get_room(location_);
        auto person_vector = room.get_persons(); //Person vector kommer nu vara vektorn med de personer som finns i rummet vi �r i.
        auto item_vector = room.get_items();      // Har rummets items.

        if(input == "TITTA")
        {
            cout << "Du befinner dig i " << room.get_name().toStdString() << ". " << room.get_description().toStdString() << endl;
            cout << "I övrigt finns : ";


            if(!person_vector.empty())
                cout << " Följande personer: ";
            else
                cout << " Inga personer\n ";


            for(auto i: person_vector)
            {
                cout << i.get_name().toStdString() << " ";
                cout << endl;
            }


            cout << "och\n";

            if(!item_vector.empty())
                cout << " Följande föremål : ";
            else
                cout << " Inga föremål\n ";


             for(auto i: item_vector)
            {
                 cout <<  i.get_name().toStdString() << ", ";

            }

            cout << "i övrigt finns ingenting intressant\n";

            cout << "Utgångar finns som leder mot: ";

            for(size_t i{0};i < G.rooms_.size();++i)
            {

                for(auto j: room.get_room_ids())
                {
                    if(j == i && i != 0)
                    {
                        cout << G.rooms_.at(i).get_name().toStdString() << ", ";

                    }

                }

            }

            cout << endl;

        }

        else if(input == "TITTA På")
        {
            cout << "På vad vill du titta ?\n";
            string thing_to_look_at{""};
            cin.ignore();
            getline(cin,thing_to_look_at);

            bool found{false};

           for(auto i: person_vector)
           {
               if(i.get_name().toStdString() == thing_to_look_at)
               {
                   cout << i.get_description().toStdString() << " \n";
                    bool found = true;
                   break;
               }

           }

           for(auto i: item_vector)
           {
               if(i.get_name().toStdString() == thing_to_look_at)
               {
                   cout << i.get_description().toStdString() << " \n";
                   bool found = true;
                   break;
               }

           }

            if(found == false)
                cerr << "Objektet hittades inte det var inte så bra, vill du ha hjälp mata in HELP eller HJäLP i dialogrutan\n";
        }
        return;
    }


void where_we_are(Game& G,const int& index)
{
    cout << G.get_room(index).get_name().toStdString() << endl;
}




 void Player:: set_location(const string& new_location,Game& G,Room& R)
 {
    int new_room_id{0};

    vector<int> exits{R.get_room_ids()};



    cout << "Nu går vi till ";

    if(new_location == "NORTH" || new_location == "NORR")
    {
       if(exits.at(0) != 0)
        {
           location_  = exits.at(0);
           where_we_are(G,location_);
       }
       else
       {
          cout << "Du kan inte gå NORRUT dummerjöns\n";
       }
    }

    else if(new_location == "SOUTH" || new_location == "SYD")
    {
        if(exits.at(1) != 0)
        {
            location_ = exits.at(1);
            where_we_are(G,location_);
        }
        else
        {
            cout << "Du kan inte gå söderut din dummjöns \n";
        }
    }
    else if(new_location == "WEST" || new_location == "VÄST")
    {
        if(exits.at(2) != 0)
        {
            location_ = exits.at(2);
            where_we_are(G,location_);
        }
        else
        {
            cout << "Du kan inte gå väst in dummerjöns \n";
        }
    }
    else if(new_location == "EAST" || new_location == "ÖST")
    {
        if(exits.at(3) != 0)
        {
            location_ = exits.at(3);
            where_we_are(G,location_);
        }
        else
        {
            cout << "Du kan inte gå öst din dummerjöns\n";
        }
    }

}

