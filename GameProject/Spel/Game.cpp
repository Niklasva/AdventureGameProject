#include "Game.h"
#include <string>
#include <vector>

using namespace std;

void create_merchant(const string& input);
void create_item(const string& input);
void create_person(const string& input);




void Game::get_help()
{
    string line;
    ifstream helpfile ("HELPTEXT.txt");
    if (helpfile.is_open())
    {
        while (getline(helpfile,line))
        {
            cout << line << endl;
        }

        helpfile.close();
    }

    else
        cout << "Unable to open file \n";

    return;
}

void Game::read_file(const string& file_to_read)
{
        Room_Editor temp_room;          // Rummet som läsas in
        Person_Editor temp_person;      // Person som skall läsas in
        Item_Editor temp_item;          // Föremålet som skall läsas in
        QFile file(filename);           // Filen som skall läsas in (bestäms av användaren)
        QString is_reading {"Nothing"}; // is_reading förklarar för programmet vad som skall laddas. T.ex. om en person eller ett rum skall laddas in

        if (file.open(QIODevice::ReadOnly))
        {
            QTextStream in(&file);
            while ( !in.atEnd() )
            {
               QString line = in.readLine();
               line.replace("\t", ""); // Plocka bort inledande tab
               if (line.startsWith("//") || line.isEmpty()) // Hoppa över rad vid kommentarer
                       continue;
               else if (line == "Room:")
                   is_reading = "Room";

               else if (line == "Item:")
                   is_reading = "Item";
               else if (line == "Person:")
                   is_reading = "Person";
               else if (line == "Merchant:")
                   is_reading = "Merchant";
               else if (line == "Exits:")
                   is_reading = "Exits";

               if (is_reading == "Room")
               {
                   if (line.startsWith("Name"))
                   {
                       temp_room.set_name(line.split(": ").last());
                   }
                   else if (line.startsWith("Description"))
                       temp_room.set_description(line.split(": ").last());
                   else if (line == "}")
                   {
                       add_room(temp_room);
                       is_reading = "Nothing";
                   }
               }
               else if (is_reading == "Person")
               {
                   if (line.startsWith("Name"))
                       temp_person.set_name(line.split(": ").last());
                   else if (line.startsWith("Description"))
                       temp_person.set_description(line.split(": ").last());
                   else if (line.startsWith("Dialog"))
                       temp_person.set_dialog(line.split(": ").last());
                   else if (line.startsWith("Recieved item dialog"))
                       temp_person.set_recieved_item_dialog(line.split(": ").last());
                   else if (line.startsWith("Hair"))
                       temp_person.set_haircolour(line.split(": ").last());
                   else if (line.startsWith("Height"))
                       temp_person.set_length(line.split(": ").last().toInt());
                   else if (line.startsWith("Width"))
                       temp_person.set_width(line.split(": ").last().toInt());
                   else if (line.startsWith("Weight"))
                       temp_person.set_weight(line.split(": ").last().toInt());
                   else if (line.startsWith("Wants"))
                       temp_person.set_wanted_item_name(line.split(": ").last());
                   else if (line == "}")
                   {
                       //skapa person här.
                       temp_room.add_person(temp_person);
                       is_reading = "Room";
                   }
               }
               else if (is_reading == "Merchant")
               {
                   temp_person.set_merchant(true);
                   if (line.startsWith("Name"))
                       temp_person.set_name(line.split(": ").last());
                   else if (line.startsWith("Description"))
                       temp_person.set_description(line.split(": ").last());
                   else if (line.startsWith("Dialog"))
                       temp_person.set_dialog(line.split(": ").last());
                   else if (line.startsWith("Recieved item dialog"))
                       temp_person.set_recieved_item_dialog(line.split(": ").last());
                   else if (line.startsWith("Hair"))
                       temp_person.set_haircolour(line.split(": ").last());
                   else if (line.startsWith("Height"))
                       temp_person.set_length(line.split(": ").last().toInt());
                   else if (line.startsWith("Width"))
                       temp_person.set_width(line.split(": ").last().toInt());
                   else if (line.startsWith("Weight"))
                       temp_person.set_weight(line.split(": ").last().toInt());
                   else if (line.startsWith("Wants"))
                       temp_person.set_wanted_item_name(line.split(": ").last());
                   else if (line == "}")
                   {
                       temp_room.add_person(temp_person);
                       is_reading = "Room";
                   }
               }
               else if (is_reading == "Item")
               {
                   if (line.startsWith("Name"))
                       temp_item.set_name(line.split(": ").last());
                   else if (line.startsWith("Description"))
                       temp_item.set_description(line.split(": ").last());
                   else if (line.startsWith("Height"))
                       temp_item.set_length(line.split(": ").last().toInt());
                   else if (line.startsWith("Width"))
                       temp_item.set_width(line.split(": ").last().toInt());
                   else if (line.startsWith("Value"))
                      temp_item.set_value(line.split(": ").last().toInt());
                   else if (line.startsWith("Throwable"))
                       temp_item.set_throwable(line.split(": ").last().toInt());
                   else if (line.startsWith("Sellable"))
                       temp_item.set_sellable(line.split(": ").last().toInt());
                   else if (line.startsWith("Pickable"))
                       temp_item.set_pickable(line.split(": ").last().toInt());
                   else if (line == "}")
                   {
                       temp_room.add_item(temp_item);
                       is_reading = "Room";
                   }
               }
               else if (is_reading == "Exits")
               {
                   if (line.startsWith("N"))
                   {
                       temp_room.set_north(line.split(": ").last().toInt());
                   }
                   else if (line.startsWith("S"))
                   {
                       temp_room.set_south(line.split(": ").last().toInt());
                   }
                   else if (line.startsWith("W"))
                   {
                       temp_room.set_west(line.split(": ").last().toInt());
                   }
                   else if (line.startsWith("E"))
                   {
                       temp_room.set_east(line.split(": ").last().toInt());
                   }
                   else if (line.endsWith("}"))
                   {
                       is_reading = "Room";
                   }

               }
            }
            file.close();
         }
}


