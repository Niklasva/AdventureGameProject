#include "Game.h"
using namespace std;

int main(int argc,char* argv[])
{
    cerr << "GAME STARTED" << endl;
    Game G;
    cerr << "GAME CREATED" << endl;
    Player P;
    cerr << "PLAYER CREATED" << endl;
    cout << endl;
    cout << "Välkommen till spelet!" << endl;
    for(int i{0}; i < 10;++i)
	cout << '\n';
    string str{};
    while(getline(cin,str))
    {
       // P.read_input(str); //commandos are now always lowercase.

    }
}
