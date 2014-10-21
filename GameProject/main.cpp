#include <QCoreApplication>
#include "Spel/Game.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
  QCoreApplication a(argc, argv);


  cerr << "GAME STARTED" << endl;
  Game G;
  cerr << "GAME CREATED" << endl;
  Player P;
  cerr << "PLAYER CREATED" << endl;
  cout << endl;
  cout << "Välkommen till spelet!" << endl;
  for(int i{0}; i < 10;++i)
    cout << '\n';
  string input{};

  int number_of_items{0};

  cout << "Mata in vad du vill ha i äventyrskorgen" << endl;
  cin >> number_of_items;

  vector<Item> tmp;
  for(int j{0}; j < number_of_items;++j)
  {
    Item i{"txt","txt",4,4,true,true,true,4};
    P.put_inventory(i);
  }

    cin.sync();


  while(cin >> input)
  {
      P.read_input(input,G); //commandos are now always UPPERCASE.
      input.clear();
   }

  return a.exec();
}
