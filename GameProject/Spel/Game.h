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
  void get_help();
  Room& get_room(const int& index){ return rooms_.at(index);} //Returnerar rum id?e

  void read_file(const std::string& file_to_read);
  //F�r att l�sa filen


  //Koperingskonstruktor generas av kompilatorn.
  // Likas� de �vriga konstruktorerna l�ter vi kompilatorn genera.
 private:
  void create_rooms(const std::string& input,std::ifstream& input_from_file);
  //F�r att skapa rummen
  void create_object(const std::string& input,std::ifstream& input_from_file);
  //F�r att skapa objekten


  //D� kommer vi f� saker i rumvektorn.
  void read_entity(std::ifstream& ss);
  // Kommer att ta emot en filstr�mreferens
  // f�r att l�sa in de olika entiteterna som finns i textfilen.
  // Intern logik i create_room och create_object kommer sedan anv�ndas
  // f�r att skapa objekten i fr�ga emedan programmet l�ser textfilen.

  std::vector<Room> rooms_;
};


#endif
