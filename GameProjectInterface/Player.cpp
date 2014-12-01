#include "Player.h"
#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>
#include <string> //Ber till C++ gudarna att detta inte ger buggar.
#include <QString>


using namespace std;
void set_location(const QString& new_location, Game& G, Room& room);


QString Player::read_input(QString& input, Game& G)
{
    input = input.toUpper();
    QStringList input_list = input.split(QRegExp("\\s"));
    qDebug() <<  input_list;

    QString command, arg;

    command = input_list[0];
    input_list.removeAt(0);
    for (QString s : input_list)
    {
        if (s != "MED" && s != "PÅ" && s != "TILL" && s != "ÅT" && s != "UPP")
        {
            arg.append(s);
            arg.append(" ");
        }
    }
    arg.resize(arg.size() - 1);

    qDebug() << command << "\t" << arg;

    if (output_ != "")
        output_.append("<br>");

    output_.append(">" + input +"<br>");


    if((command == "ÄVENTYRSKORG") ||  (command == "TITTA På  äVENTYRSKORG") || (command == "INVENTORY"))
    {
        vector<QString> buffer;
        for(auto i: inventory_)
        {
            buffer.push_back(i.get_name()+"<br>");
        }

        std::sort(buffer.begin(),buffer.end());


        QString contents{"Föremål i äventyrskorgen:<br>"};

        for(auto i: buffer)
        {
            contents = contents + i;
        }
        output_.append(contents);

    }
    else if(command == "GÅ" || command == "GO") //fulhackadet har inga gränser... Det här är väl inte fulhack?
    {
        output_.append(decide_direction(arg, G));
    }

    else if(command == "GE")
    {
        QStringList qsl {input.split(" TILL ")};
        QString person_to_give_to {qsl.last()};
        QString item_to_give{qsl.first()};
        item_to_give.replace(command + " ", "");
        qDebug() << "Ge " << item_to_give << " till " << person_to_give_to;
        output_.append(give(item_to_give, person_to_give_to, G));
    }

    else if(command == "PRATA")
    {
        output_.append(talk(arg,G));
    }

    else if(command == "PLOCKA" || command == "TA" || command == "TAKE")
    {
        output_.append(take(arg, G));
    }
    else if(command == "TITTA")
    {
        output_.append(look(arg,G));
    }
    else if(command == "HJÄLP")
    {
        output_ = G.get_help();
    }
    else
    {
        output_.append( "Nu blev jag förvirrad<br> Felaktigt kommando<br>");
    }

    return output_;
}

QString Player::decide_direction(QString& arg, Game& G)
{
    auto room  = G.get_room(location_); // Vi hamnar i rätt rum.
    room.get_directions();

    if(arg == "NORTH" || arg == "SOUTH"
            || arg == "WEST" || arg == "EAST"
            || arg == "ÖST" || arg == "VÄST"
            || arg == "SYD" || arg == "NORR")
    {
        return set_location(arg,G,room);
    }
    else
        return "null";
}

QString Player::give(QString& item_to_give,const QString& person_to_give_to,Game& G)
{
    if(inventory_.empty())
    {
        return "Du har inga föremål, det var tråkigt";
    }

    Item tmp_item;
    QString output;
    auto room  = G.get_room(location_);
    auto person_vector = room.get_persons(); //Person vector kommer nu vara vektorn med de personer som finns i rummet vi �r i.

    for(unsigned int i{0}; i < inventory_.size(); ++i)
    {
        if(inventory_.at(i).get_name().toUpper() == item_to_give)
        {
            if(inventory_.at(i).is_throwable())
            {
                tmp_item = inventory_.at(i); //Provar med defaultkonstruktorn.
                inventory_.erase(inventory_.begin()+i);
                //cout << "Du ger " << item_to_give << " till " << person_to_give_to << endl;
                output.append("Du ger" + item_to_give + " till " + person_to_give_to);

            }
            else
            {
                output.append(item_to_give + " går inte att bara kasta bort eller ge bort.<br>");
                break;
            }
        }
    }
    bool  can_give_away {tmp_item.is_throwable()};

    if(can_give_away)
    {
        for(Person p : person_vector) //search for persons in room
        {
            if(p.get_name() == person_to_give_to) //om input �r namn
            {
                if(p.wanted_item(tmp_item)) //If the persons wants the item.
                {
                    output.append(p.get_name() + " säger: " + p.get_recieved_item_dialog());
                }
                else
                {
                    output.append("Så knasigt det kan bli");
                }
            }
        }
    }
    return output;
}

QString Player::talk(QString& person_to_talk_with, Game& G)
{
    //Beroende p� om personen finns eller ej och massa andra paramtetrar..

    auto room  = G.get_room(location_);
    auto person_vector = room.get_persons(); //Person vector kommer nu vara vektorn med de personer som finns i rummet vi �r i.
    bool found = false;

    for(auto i: person_vector)
    {
        if(i.get_name().toUpper() == person_to_talk_with)
        {
            return (person_to_talk_with + " säger:<br>" + i.get_dialog());
            found = true;
            break;
        }
    }

    if(!found)
    {
        return "Personen finns inte det var tråkigt";
    }

    return "ojsan hoppsan vad tokigt det blev";
}

QString Player::take(QString& thing_to_pick_up,Game& G)
{

    auto item_vector = G.get_room(location_).get_items();
    bool sucess{false};

    //ui-> textBrowser->setText("Vad vill du plocka upp<br>");

    //ui->lineEdit->clear();

    std::cerr << thing_to_pick_up.toStdString() << endl;

    for(size_t i{0}; i < item_vector.size();++i)
    {
        if(item_vector.at(i).get_name().toUpper() == thing_to_pick_up)
        {
            inventory_.push_back(item_vector.at(i));
            G.get_room(location_).remove_item(i);
            sucess = true;
        }
    }


    if(sucess)
    {
        return ("Du plockade upp " + thing_to_pick_up);
    }


    return "Detta gick inte bra alls.";
}

QString Player::look(QString& thing_to_look_at, Game& G)
{
    QString output;
    Item tmp_item;
    auto room  = G.get_room(location_);
    auto person_vector = room.get_persons(); //Person vector kommer nu vara vektorn med de personer som finns i rummet vi �r i.
    auto item_vector = room.get_items();      // Har rummets items.


    if(thing_to_look_at == "")   // När inget argument är inmatat, generellt titta
    {

        output = "<b>" + room.get_name() +"</b><br>" + room.get_description();
        bool persons_exits{false};

        if(!person_vector.empty())
        {
            output = output + "<br>I rummet finns:<br>";
            persons_exits = true;
        }

        if(persons_exits)
            for(auto i: person_vector)
            {
                output =  output + i.get_name() + "<br>";
            }
        bool items_exist{false};

        if(!item_vector.empty())
        {
            items_exist = true;
            output = output + "<br>Följande föremål:<br>";
        }

        for(auto i: item_vector)
        {
            output = output + i.get_name() + "<br>";
        }

        output = output + "<br>Utgångar finns som leder mot:<br>";


        for(int i{0};i < G.rooms_.size();++i)
        {
            int index{0};
            for(int j: room.get_room_ids())
            {

                if(j == i && i != 0)
                {
                    if (index == 1)
                        output = output + "Norr: ";
                    else if (index == 2)
                        output = output + "Syd: ";
                    else if (index == 3)
                        output = output + "Öst: ";
                    else if (index == 4)
                        output = output + "Väst: ";
                    output = output + G.rooms_.at(i).get_name() + "<br>";

                }
                ++index;
            }
        }

        return output;
        cerr << "Vi har tittat klart<br>";

    }
    else
    {
        bool found{false};

        for(auto i: person_vector)
        {
            if(i.get_name().toUpper() == thing_to_look_at)
            {
                output.append(i.get_description() + "<br>");
                found = true;
                break;
            }

        }

        for(Item i: item_vector)
        {
            if(i.get_name().toUpper() == thing_to_look_at)
            {
                output.append(i.get_description() + "<br>");
                found = true;
                break;
            }

        }

        if(found == false)
            output.append("Objektet hittades inte det var inte så bra, vill du ha hjälp mata in HELP eller HJäLP i dialogrutan<br>");
    }
    return output;
}

QString Player:: set_location(const QString& new_location, Game& G, Room& R)
{
    int new_room_id{0};
    QString output;
    QString nothing {""};

    vector<int> exits{R.get_room_ids()};



    cout << "Nu går vi till ";

    if(new_location == "NORRUT" || new_location == "NORR")
    {
        if(exits.at(0) != 0)
        {
            location_  = exits.at(0);
            output.append(look(nothing, G));
            return output;
        }
        else
        {
            return "Du kan inte gå NORRUT dummerjöns<br>";
        }
    }

    else if(new_location == "SÖDERUT" || new_location == "SYD")
    {
        if(exits.at(1) != 0)
        {
            location_ = exits.at(1);
            output.append(look(nothing, G));
            return output;
        }
        else
        {
            return "Du kan inte gå söderut din dummjöns <br>";
        }
    }
    else if(new_location == "VÄSTERUT" || new_location == "VÄST")
    {
        if(exits.at(2) != 0)
        {
            location_ = exits.at(2);
            output.append(look(nothing, G));
            return output;
        }
        else
        {
            return "Du kan inte gå väst in dummerjöns <br>";
        }
    }
    else if(new_location == "ÖSTERUT" || new_location == "ÖST")
    {
        if(exits.at(3) != 0)
        {
            location_ = exits.at(3);
            output.append(look(nothing, G));
            return output;
        }

        else
        {
            return "Du kan inte gå öst din dummerjöns<br>";
        }
    }
    else
    {
        return "Sorry kompis";
    }

}
