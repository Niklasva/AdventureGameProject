#include <QCoreApplication>
#include "Spel/Game.h"
#include <iostream>
#include <QTextStream>



void to_uppercase(std::string& input)
{

    transform(input.begin(), input.end(), input.begin(), std::ptr_fun <int, int> ( std::toupper ) );//Oj vad det blev fulhack
    return;
}

int main(int argc, char* argv[])
{
  QCoreApplication a(argc, argv);


  std::cerr << "GAME STARTED" << std::endl;
  Game G;
  QString i = "test.bisys";
  G.read_file(i);
  std::cerr << "GAME CREATED" << std::endl;
  Player P;
  std::cerr << "PLAYER CREATED" << std::endl;
  std::cout << std::endl;
  std::cout << "Välkommen till spelet!" << std::endl;
  std::cout << std::endl;
  std::string str;

  while(true)
  {
      std::cin >> str;
      to_uppercase(str);
      QString input(str.c_str());
      P.read_input(input,G);
      input.clear();
   }

  return a.exec();
}
