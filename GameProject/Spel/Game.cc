#include "Game.h"
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
    string line;
    ifstream input_from_file{file_to_read};

    if(input_from_file.is_open())
    {
        while(getline(input_from_file,line))
        {

            if(line == "Room:")
            {
                create_rooms(line,input_from_file);
            }
            else
            {
                continue;
            }
        }

    input_from_file.close();

    }

    else
        cerr << "Unable to open file\n";


}


void Game::create_rooms(const string &input,ifstream& input_from_file)
{
    int counter{0};
    vector<string> entity_buffer;
    vector<int> exits;

    while(getline(input_from_file,line))
    {
        if(line == "{")
            ++counter;
        else if(line == "}")
            --counter;

        if(line == "Name:")
        {
          line.erase(line.begin()+6); //Alltid en specifik längd.
          entity_buffer.push_back(line);
        }

        if(line == "Description:")
        {
          line.erase(line.begin()+13); //Alltid en specifik längd.
          entity_buffer.push_back(line);
        }



        if(line == "N")
        {

        }






        if(line == "Item:")
        {

        }

        if(line == "Person:")
        {

        }


        if(line == "Merchant:")
        {

        }







        if(counter == 0)
            return;

    }

}
