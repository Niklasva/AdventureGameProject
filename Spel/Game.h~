#include <sstream>
#include <typeinfo>
#include <Player.h>
#include <Entity.h>


#ifndef ENITY
#define ENITY
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
  void read_file(fstream& ss);
  //För att läsa filen
  //Då kommer vi få saker i rumvektorn.
  void read_entity(fstream& ss);
  // Kommer att ta emot en filströmreferens 
  // för att läsa in de olika entiteterna som finns i textfilen. 
  // Intern logik i create_room och create_object kommer sedan användas 
  // för att skapa objekten i fråga emedan programmet läser textfilen. 
  std::vector<Room> rooms_;    
};

#endif;
