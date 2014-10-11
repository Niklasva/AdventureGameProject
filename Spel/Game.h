#ifndef GAME
#define GAME
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <functional>
#include <exception>
#include "Player.h"
#include "Entity.h"

class Game
{
 public:
  Game() = default;
  ~Game() = default;
  //Koperingskonstruktor generas av kompilatorn.
  // Likaså de övriga konstruktorerna låter vi kompilatorn genera.
 private:
  void create_rooms();
  //För att skapa rummen
  void create_object();
  //För att skapa objekten
  void read_file(std::ifstream& ss);
  //För att läsa filen
  //Då kommer vi få saker i rumvektorn.
  void read_entity(std::ifstream& ss);
  // Kommer att ta emot en filströmreferens
  // för att läsa in de olika entiteterna som finns i textfilen.
  // Intern logik i create_room och create_object kommer sedan användas
  // för att skapa objekten i fråga emedan programmet läser textfilen.
  void get_help();
  //Funktion jag skapade 2014-10-11 //John

  std::vector<Room> rooms_;
};


#endif;
