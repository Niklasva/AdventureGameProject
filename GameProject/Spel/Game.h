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
  //För att läsa filen


  //Koperingskonstruktor generas av kompilatorn.
  // Likaså de övriga konstruktorerna låter vi kompilatorn genera.
 private:
  void create_rooms(const std::string& input,std::ifstream& input_from_file);
  //För att skapa rummen
  void create_object(const std::string& input,std::ifstream& input_from_file);
  //För att skapa objekten


  //Då kommer vi få saker i rumvektorn.
  void read_entity(std::ifstream& ss);
  // Kommer att ta emot en filströmreferens
  // för att läsa in de olika entiteterna som finns i textfilen.
  // Intern logik i create_room och create_object kommer sedan användas
  // för att skapa objekten i fråga emedan programmet läser textfilen.

  std::vector<Room> rooms_;
};


#endif
