#include "Player.h"
#include <algorithm>
#include <vector>
#include <iterator>



using namespace std;
void decide_direction(const string& input);
void decide_what_to_give(const string& input);
void decide_what_to_pick(const string& input);
void decide_what_to_talk(const string& input);
void decide_what_to_look(const string& input);
void set_location(const string& new_location,Game& G,Room& room);



void to_uppercase(string& input)
{

    transform(input.begin(), input.end(), input.begin(), std::ptr_fun <int, int> ( std::toupper ) );//Oj vad det blev fulhack
    return;
}

void Player::read_input(string input,Game& G) //Str

{
    to_uppercase(input);

    cout << "Du matade in följande kommandon " << input << " \n";

    if (input == "HELP" || input == "HJÄLP")
    {
        cerr << "Du bad om hjälp\n";
        G.get_help(); //Läser den externa hjälpfilen
    }


    else if((input == "ÄVENTYRSKORG") ||  (input == "TITTA PÅ  ÄVENTYRSKORG") || (input == "INVENTORY"))
    {

     cout << "Hej du anropade äventyrskorgen\n";
     for(auto i: inventory_)
        {
          cout << i.get_name() << i.get_description() << endl; //Arv och get funktioner. mysigt
        }

    }
    else if(input == "GÅ") //fulhackadet har inga gränser...
    {
        cout << "Nu kommer vi att gå " << input << "\n";
        decide_direction(input,G);
    }

    else if(input == "GE")
    {
        string person_to_give_to;
        cout << "Till vem vill du ge\n";
        cin >> person_to_give_to;
        cout << "Vad vill du ge\n";
        string item_to_give;
        cin >> item_to_give;
        cout << "Nu ger vi " << item_to_give << " till " << person_to_give_to << endl;
        decide_what_to_give(item_to_give,person_to_give_to,G);
    }

    else if(input == "PRATA")
    {
        cout << "Nu vi " << input << endl;
        decide_what_to_talk(input,G);
    }

    else if(input == "PLOCKA UPP")
    {
        decide_what_to_pick(input,G);
    }
    else if(input == "TITTA")
    {
        decide_what_to_look(input,G);
    }
    else
    {
        cerr << "Nu blev jag förvirrad\n";
        cerr << "Det blev bara fel känner\n";

    }
}




void Player::decide_direction(const string& input,Game& G)
{
	//Här skall vi kolla så att vi får rimliga riktningar.

      auto room  = G.get_room(location_);
      room.get_directions();
      //Spelaren skall kunna välja rum.
      cout << "Var vill du gå";
      string room_to_go_to;
      cin >> room_to_go_to;
      to_uppercase(room_to_go_to);
     if(room_to_go_to == "NORR" || room_to_go_to == "ÖST" || room_to_go_to == "VÄST" || room_to_go_to == "SYD")
        {
          set_location(room_to_go_to,G,room);
        }
      return;
 }



    void Player::decide_what_to_give(const string& item_to_give,const string& person_to_give_to,Game& G)
    {

       bool cant_give_away = false;
       if(inventory_.empty())
       {
           cerr << "Du har inga föremål, det var tråkigt\n";
           return;
       }
      vector<Item> buffer; //Since the members are const direct copying is not permitted.
      auto room  = G.get_room(location_);
      auto person_vector = room.get_persons(); //Person vector kommer nu vara vektorn med de personer som finns i rummet vi är i.

      for(unsigned int i{0}; i < inventory_.size(); ++i)
      {
        if(inventory_.at(i).get_name() == item_to_give)
            {
            if(inventory_.at(i).is_throwable())
                {
                    Item correct_item = inventory_.at(i); //Provar med defaultkonstruktorn.
                    buffer.push_back(correct_item);
                    cant_give_away = true;
                }
             else
                {
                   cerr << "Detta g?r inte att bara kasta bort eller ge bort.\n";
                   break;
                }
            }
      }


 if(cant_give_away = false)
      {
        for(Person p : person_vector) //search for persons in room
          {
            if(p.get_name() == person_to_give_to) //om input är namn
            {
                if(!buffer.empty() && p.wanted_item(buffer.at(0))) //If the persons wants the item.
                {

                    for(size_t i{0}; i < inventory_.size(); ++i)
                    {
                        if(inventory_.at(i).get_name() == item_to_give)
                        {
                           inventory_.erase(inventory_.begin()+i); // the player gave away his item.
                        }
                    }
                }
                else
                {
                     //fel.
                }

            }

          }
        }
          return;
    }



    void Player::decide_what_to_talk(const string& input,Game& G)
    {
        //Beroende på om personen finns eller ej och massa andra paramtetrar..

        auto room  = G.get_room(location_);
        auto person_vector = room.get_persons(); //Person vector kommer nu vara vektorn med de personer som finns i rummet vi är i.

        string person_to_talk_with;

        cout << "Vem vill du prata med \n";
        cin >> person_to_talk_with;
        bool found = false;

        for(auto i: person_vector)
        {
            if(i.get_name() == person_to_talk_with)
            {
                cout << i.get_dialog() << " \n";
                found = true;
                break;
            }
        }

        if(!found)
        {
            cerr << "Personen finns inte det var tråkigt\n";

        }

        return;
    }

    void Player::decide_what_to_pick(const string& input,Game& G)
    {
       auto room  = G.get_room(location_);
       auto item_vector = room.get_items();
       cout << "Vad vill du plocka upp\n";
       string thing_to_pick_up;
       cin >> thing_to_pick_up;

       for(size_t i{0}; i < item_vector.size();++i)
       {
         if(item_vector.at(i).get_name() == thing_to_pick_up)
            {
                inventory_.push_back(item_vector.at(i));
                room.remove_item(i);
                return;
            }
       }
        return;
    }

    void Player::decide_what_to_look(const string& input,Game& G)
    {

        auto room  = G.get_room(location_);
        auto person_vector = room.get_persons(); //Person vector kommer nu vara vektorn med de personer som finns i rummet vi är i.
        auto item_vector = room.get_items();      // Har rummets items.
        if(input == "TITTA")
        {
            for(auto i: person_vector)
                cout << i.get_description() << " ";

             for(auto i: item_vector)
                 cout << i.get_description() << " ";
        }

        else if(input == "TITTA PÅ")
        {
            cout << "På vad vill du titta ?\n";
            string thing_to_look_at{""};
            cin >> thing_to_look_at;
            bool found{false};


           for(auto i: person_vector)
           {
               if(i.get_name() == thing_to_look_at)
               {
                   cout << i.get_description() << " \n";
                    bool found = true;
                   break;
               }

           }

           for(auto i: item_vector)
           {
               if(i.get_name() == thing_to_look_at)
               {
                   cout << i.get_description() << " \n";
                   bool found = true;
                   break;
               }

           }

            if(found == false)
                cerr << "Objektet hittades inte det var inte så bra, vill du ha hjälp mata in HELP eller HJÄLP i dialogrutan\n";

        }
        return;
    }


enum locations {NORR,SYD,VAEST,OEST}; //För att bestämma var vi skall gå.
locations hasch(std::string const& s)
    {
        if(s == "NORR")
            return NORR;
        if(s == "SYD")
            return SYD;
        if(s == "VAEST")
            return VAEST;
        if(s == "OEST")
            return OEST;
    }


 void Player:: set_location(const string& new_location,Game& G,Room& R)
 {
    //Vi vet new_location är Norr,väst söder,öster..
    int new_room_id{0};

    vector<int> exits{R.get_room_ids()}; //vektorn håller alla möjliga utgångar.

      switch (hasch(new_location))
       {
        case NORR:
          if(exits.at(0) != 0)
            location_  = exits.at(0);
          else
          {
              cout << "Dit kan du ju inte din dummerjöns\n";
          }
        break;
        case SYD:
           if(exits.at(1) != 0)
             location_ = exits.at(1);
           else
           {
               cout << "Dit kan du ju inte din dummerjöns\n";
           }
        break;
        case VAEST:
           if(exits.at(2) != 0)
            location_ = exits.at(2);
           else
           {
               cout << "Dit kan du ju inte din dummerjöns\n";
           }

        break;
        case OEST:
            if(exits.at(3) != 0)
             location_ = exits.at(3);
            else
            {
                cout << "Dit kan du ju inte  din dummerjöns\n";
            }
        break;
        }
 }













