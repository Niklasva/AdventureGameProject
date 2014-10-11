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
  // Likas� de �vriga konstruktorerna l�ter vi kompilatorn genera.
 private:
  void create_rooms();
  //F�r att skapa rummen
  void create_object();
  //F�r att skapa objekten
  void read_file(std::ifstream& ss);
  //F�r att l�sa filen
  //D� kommer vi f� saker i rumvektorn.
  void read_entity(std::ifstream& ss);
  // Kommer att ta emot en filstr�mreferens
  // f�r att l�sa in de olika entiteterna som finns i textfilen.
  // Intern logik i create_room och create_object kommer sedan anv�ndas
  // f�r att skapa objekten i fr�ga emedan programmet l�ser textfilen.
  void get_help();
  //Funktion jag skapade 2014-10-11 //John

  std::vector<Room> rooms_;
};


#endif;
