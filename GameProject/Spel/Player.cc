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

    cout << "Du matade in f�ljande kommandon " << input << " \n";

    if (input == "HELP" || input == "HJ�LP")
    {
        cerr << "Du bad om hj�lp\n";
        G.get_help(); //L�ser den externa hj�lpfilen
    }


    else if((input == "�VENTYRSKORG") ||  (input == "TITTA P�  �VENTYRSKORG") || (input == "INVENTORY"))
    {

        cout << "Hej du anropade �ventyrskorgen\n";
     for(auto i: inventory_)
        {
          cout << i.get_name() << i.get_description() << endl; //Arv och get funktioner. mysigt
        }

    }
    else if(input == "G�") //fulhackadet har inga gr�nser...
    {
        cout << "Nu kommer vi att g� " << input << "\n";
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
        cerr << "Nu blev jag f�rvirrad\n";
        cerr << "Det blev bara fel k�nner\n";

    }
}

    void decide_direction(const string& input)
    {
	//H�r skall vi kolla s� att vi f�r rimliga riktningar.
	return;
    }

    void decide_what_to_give(const string& input)
    {


	return;
    }

    void decide_what_to_talk(const string& input)
    {
	//Beroende p� om personen finns eller ej och massa andra paramtetrar..

	return;
    }

    void decide_what_to_pick(const string& input)
    {
	//Det h�r �r f�ljer samma m�nster

	return;
    }

    void decide_what_to_look(const string& input)
    {

	if(input == "TITTA")
	{
	    //D� skall vi skriva ut beskrivningar p� precist allt.

	}


	return;
    }
