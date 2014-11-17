#include <QCoreApplication>
#include "Spel/Game.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
  QCoreApplication a(argc, argv);
  string input{""};

  cerr << "GAME STARTED" << endl;
  Game G;
  G.read_file("spelfil.txt");
  cerr << "GAME CREATED" << endl;
  Player P;
  cerr << "PLAYER CREATED" << endl;
  cout << endl;
  cout << "Välkommen till spelet!" << endl;
  cout << endl;

  while(cin >> input)
  {
      P.read_input(input,G); //commandos are now always UPPERCASE.
      input.clear();
   }

  return a.exec();
}
