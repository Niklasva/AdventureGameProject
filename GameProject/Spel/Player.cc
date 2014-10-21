#include "Player.h"
#include <algorithm>
using namespace std;
void decide_direction(const string& input);
void decide_what_to_give(const string& input);
void decide_what_to_pick(const string& input);
void decide_what_to_talk(const string& input);
void decide_what_to_look(const string& input);

void Player::read_input(string input,Game& G) //Str
{
    transform(input.begin(), input.end(), input.begin(), std::ptr_fun <int, int> ( std::toupper ) );//Oj vad det blev fulhack

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
        decide_direction(input);
    }

    else if(input == "GE")
    {
        cout << "Nu ger vi ett objekt till" << input << endl;
        decide_what_to_give(input);

    }

    else if(input == "PRATA")
    {
       cout << "Nu vi prata" << input << endl;
        decide_what_to_talk(input);
    }

    else if(input == "PLOCKA UPP")
    {
        decide_what_to_pick(input);

    }
    else if(input == "TITTA")
    {
        decide_what_to_look(input);

    }
    else
    {
        cerr << "Nu blev jag förvirrad\n";
        cerr << "Det blev bara fel känner\n";

    }
}

    void decide_direction(const string& input)
    {
	//Här skall vi kolla så att vi får rimliga riktningar.
	return;
    }

    void decide_what_to_give(const string& input)
    {


	return;
    }

    void decide_what_to_talk(const string& input)
    {
	//Beroende på om personen finns eller ej och massa andra paramtetrar..

	return;
    }

    void decide_what_to_pick(const string& input)
    {
	//Det här är följer samma mönster

	return;
    }

    void decide_what_to_look(const string& input)
    {

	if(input == "TITTA")
	{
	    //Då skall vi skriva ut beskrivningar på precist allt.

	}


	return;
    }
