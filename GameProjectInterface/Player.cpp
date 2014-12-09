#include "Player.h"
#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>
#include <string> //Ber till C++ gudarna att detta inte ger buggar.
#include <QString>


using namespace std;

QString Player::read_input(QString& input, Game& G)
{
    input = input.toUpper();
    QStringList input_list = input.split(QRegExp("\\s"));
    qDebug() <<  input_list;
    QString output_;
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
        output_.append("<br><br>");

    output_.append("<br><b>>" + input +"</b><br>");


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
        output_.append(set_location(arg, G, G.get_room(location_)));
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
    else if(command == "KOMBINERA")
    {
        QStringList qsl {input.split(" MED ")};
        QString first_item{qsl.first()};
        QString second_item {qsl.last()};
        first_item.replace(command + " ", "");
        output_.append(combine_items(first_item, second_item));
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
    else if(command == "KASTA" || command == "SLÄNG")
    {
        output_.append(toss(arg,G));
    }
    else if(command == "HJÄLP")
    {
        output_ = G.get_help();
    }

    else if((command == "HANDLA" || command == "KÖP") && arg != "")
    {
        QStringList qsl {input.split(" AV ")};
        QString merchant {qsl.last()};
        QString item_to_buy{qsl.first()};
        item_to_buy.replace(command + " ", "");
        output_.append(trade(item_to_buy, merchant, G.get_room(location_)));
    }

    else if((command == "SÄLJ" || command == "AVYTTRA" ) && arg != "")
    {
        QStringList qsl {input.split(" TILL ")}; //Lista med Qsträngar.
        QString merchant {qsl.last()};
        QString item_to_sell{qsl.first()};
        item_to_sell.replace(command + " ", "");
        output_.append(sale(item_to_sell, merchant, G.get_room(location_)));
    }


    else if(command == "PENNINGPUNG" || command == "PENGAR" || command == "CASHMONEY" || command == "MONEY")
    {
        QString money_as_a_string {QString::number(money_)};
        output_.append("Du har " + money_as_a_string + " $ på fickan\n"); // se över
    }


    else
    {
        output_.append( "Nu blev jag förvirrad<br> Felaktigt kommando<br>");
    }

    return output_;
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
    std::vector<Person> person_vector = room.get_persons(); //Person vector kommer nu vara vektorn med de personer som finns i rummet vi är i.
    int i {0};
    while (i < inventory_.size())
    {
        if(inventory_.at(i).get_name().toUpper() == item_to_give)
        {
            tmp_item = inventory_.at(i);
            break;
        }
        ++i;
    }

    for(size_t p{0}; p < person_vector.size(); ++p)
    {
        if(person_vector.at(p).get_name().toUpper() == person_to_give_to) //om input är ett namn på en person i rummet
        {
            qDebug() << person_vector.at(p).get_item_event();
            if(person_vector.at(p).wanted_item(tmp_item)) // Kolla om personen vill ha föremålet
            {
                G.get_room(location_).get_persons().at(p).set_item_event(true); // Flippa bool fan
                output.append(person_vector.at(p).get_name() + " säger: " + person_vector.at(p).get_recieved_item_dialog() + "<br>");
                if (person_vector.at(p).get_item().get_name() != "")
                {
                    inventory_.erase(inventory_.begin()+i);
                    inventory_.push_back(person_vector.at(p).get_item());
                    output.append("och ger dig sin " + person_vector.at(p).get_item().get_name().toLower() + ".");
                }
            }
            else
            {
                output.append("Men " + person_vector.at(p).get_name() + " vill inte ha din " + tmp_item.get_name().toLower());
            }
            qDebug() << person_vector.at(p).get_item_event();
        }
    }
    return output;
}

QString Player::talk(QString& person_to_talk_with, Game& G)
{
    vector<Person> person_vector = G.get_room(location_).get_persons();
    bool found = false;
    vector<Merchant> merchant_vector = G.get_room(location_).get_merchants();



    for(size_t p{0}; p < person_vector.size();++p)
    {
        Person* i = &person_vector.at(p);
        if(i->get_name().toUpper() == person_to_talk_with)
        {
            qDebug() << i->get_item_event();
            if (!i->get_item_event() && i->get_wanted_item_name() == "" && i->has_item())
            {
                G.get_room(location_).get_persons().at(p).set_item_event(true);
                qDebug() << i->get_item_event();
                inventory_.push_back(i->get_item());
                return (person_to_talk_with + " säger:<br>" + i->get_dialog());
            }
            else if(i->get_item_event() == true)
            {
                return (person_to_talk_with + " säger:<br>" + i->get_recieved_item_dialog());
            }
            else if (i->get_item_event() == false)
            {
                return (person_to_talk_with + " säger:<br>" + i->get_dialog());
            }

            found = true;
            break;
        }
    }

    //En egen uppsättning.
    for(auto i: merchant_vector)
    {
        if(i.get_name().toUpper() == person_to_talk_with)
        {

            QString sales_items {""};
            for(auto j: i.get_items_for_sale())
            {
                sales_items = j.get_name() + "," + sales_items;
            }

            sales_items = person_to_talk_with + " säger: Hej. Jag säljer följande föremål:" +  sales_items + "\n\n";

            return (sales_items + person_to_talk_with + " säger:<br>" + i.get_dialog());
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
    bool success{false};

    std::cerr << thing_to_pick_up.toStdString() << endl;

    for(size_t i{0}; i < item_vector.size();++i)
    {
        if(item_vector.at(i).get_name().toUpper() == thing_to_pick_up)
        {
            inventory_.push_back(item_vector.at(i));
            G.get_room(location_).remove_item(i);
            success = true;
        }
    }

    if(success)
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
    std::vector<Merchant> merchant_vector = room.get_merchants();


    if(thing_to_look_at == "")   // När inget argument är inmatat, generellt titta
    {

        output = "<b>" + room.get_name() +"</b><br>" + room.get_description();
        bool persons_exits{false};

        if(!person_vector.empty())
        {
            output = output + "<br>I rummet finns:<br>";
            persons_exits = true;
        }

        bool merchants_exists{false};
        if(!merchant_vector.empty())
        {
            output = output + "<br>I rummet finns följande handelsmän:<br>";
            merchants_exists = true;
        }

        if(persons_exits)
            for(auto i: person_vector)
            {
                output =  output + i.get_name() + "<br>";
            }

        if(merchants_exists)
        {
            for(auto i: merchant_vector)
            {
                output = output + i.get_name() + "<br>";
            }

        }

        if(!item_vector.empty())
        {
            output = output + "<br>Följande föremål:<br>";
        }

        for(auto i: item_vector)
        {
            output = output + i.get_name() + "<br>";
        }

        output = output + "<br>Utgångar finns som leder mot:<br>";


        for(int i{0};i < G.rooms_.size();++i) // Loop through all rooms.
        {
            //Rum är nuvarande rum, deklarerat högre upp.
            //Rum id kommer vara möjliga rumskoder från rummet i fråga.
            for(int j: room.get_room_ids())
            {
                if(j == i && i != 0)
                {
                    if (i == room.n_ && i != 0)
                    {
                        output = output + "Norr: ";
                    }
                    else if (i == room.s_ && i != 0)
                    {
                        output = output + "Syd: ";
                    }
                    else if (i == room.e_ && i != 0)
                    {
                        output = output + "Öst: ";
                    }
                    else if (i == room.w_ && i != 0)
                    {
                        output = output + "Väst: ";
                    }

                    output = output + G.rooms_.at(i).get_name() + "<br>";
                }
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

        for (Item i : inventory_)
        {
            if (thing_to_look_at == i.get_name().toUpper())
            {
                output.append(i.get_description() + "<br>");
                found = true;
                break;
            }
        }

        if(found == false)
        {
            output.append("Objektet hittades inte det var inte så bra, vill du ha hjälp mata in HELP eller HJäLP i dialogrutan<br>");
        }
    }
    return output;
}

QString Player::toss(QString& item_name, Game& G)
{
    QString output;
    for (size_t i {0}; i < inventory_.size(); ++i)
    {
        if(inventory_.at(i).get_name().toUpper() == item_name)
        {
            if (inventory_.at(i).is_throwable())
            {
                output.append("Du slänger iväg " + inventory_.at(i).get_name() + "<br>");
                G.get_room(location_).set_item(inventory_.at(i));
                inventory_.erase(inventory_.begin() + i);
            }
            else
            {
                output.append(inventory_.at(i).get_name() + " går inte att kasta.");
            }
        }
        else
        {
            output.append("Du har inte " + item_name.toLower());
        }
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
            if (R.get_key(0) == "")
            {
                location_  = exits.at(0);
                output.append(look(nothing, G));
                return output;
            }
            else
            {
                for (Item i : inventory_)
                {
                    if (i.get_name() == R.get_key(0))
                    {
                        location_  = exits.at(0);
                        output.append(look(nothing, G));
                        return output;
                    }
                }
                return ("Du behöver en " + R.get_key(0) + " för att passera.");
            }
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
            if (R.get_key(1) == "")
            {
                location_  = exits.at(1);
                output.append(look(nothing, G));
                return output;
            }
            else
            {
                for (Item i : inventory_)
                {
                    if (i.get_name() == R.get_key(1))
                    {
                        location_  = exits.at(1);
                        output.append(look(nothing, G));
                        return output;
                    }
                }
                return ("Du behöver en " + R.get_key(1) + " för att passera.");
            }
        }
        else
        {
            return "Du kan inte gå söderut dummerjöns<br>";
        }
    }
    else if(new_location == "VÄSTERUT" || new_location == "VÄST")
    {
        if(exits.at(2) != 0)
        {
            if (R.get_key(2) == "")
            {
                location_  = exits.at(2);
                output.append(look(nothing, G));
                return output;
            }
            else
            {
                for (Item i : inventory_)
                {
                    if (i.get_name() == R.get_key(2))
                    {
                        location_  = exits.at(2);
                        output.append(look(nothing, G));
                        return output;
                    }
                }
                return ("Du behöver en " + R.get_key(2) + " för att passera.");
            }
        }
        else
        {
            return "Du kan inte gå väst dummerjöns<br>";
        }
    }
    else if(new_location == "ÖSTERUT" || new_location == "ÖST")
    {
        if(exits.at(3) != 0)
        {
            if (R.get_key(3) == "")
            {
                location_  = exits.at(3);
                output.append(look(nothing, G));
                return output;
            }
            else
            {
                for (Item i : inventory_)
                {
                    if (i.get_name() == R.get_key(3))
                    {
                        location_  = exits.at(3);
                        output.append(look(nothing, G));
                        return output;
                    }
                }
                return ("Du behöver en " + R.get_key(3) + " för att passera.");
            }
        }
        else
        {
            return "Du kan inte gå österut dummerjöns<br>";
        }
    }
    else
    {
        for (size_t i {0}; i < exits.size(); ++i)
        {
            if (new_location == G.rooms_.at(exits.at(i)).get_name().toUpper())
            {
                if (R.get_key(i) == "")
                {
                    location_  = exits.at(i);
                    output.append(look(nothing, G));
                    return output;
                }
                else
                {
                    for (Item p : inventory_)
                    {
                        if (p.get_name() == R.get_key(i))
                        {
                            location_  = exits.at(i);
                            output.append(look(nothing, G));
                            return output;
                        }
                    }
                    return ("Du behöver en " + R.get_key(i) + " för att passera.");
                }
            }
        }

    }
    return "Ledsen kompis";
}

QString Player::combine_items(QString& first_item, QString& second_item)
{
    if (inventory_.empty())
        return "Du har inget i äventyrskorgen";
    for (size_t i{0}; i < inventory_.size(); ++i)
    {
        if (inventory_.at(i).get_name().toUpper() == first_item && inventory_.at(i).is_throwable())
        {
            Item temp_item = inventory_.at(i);
            for (size_t j {0}; j < inventory_.size(); ++j)
            {
                if (inventory_.at(j).get_name().toUpper() == second_item && inventory_.at(j).is_throwable())
                {
                    Item temp_item2 = inventory_.at(j);
                    Item combined_item;
                    combined_item.set_name(temp_item.get_name() + temp_item2.get_name().toLower());
                    combined_item.set_description(temp_item.get_description() + "<br>" + temp_item2.get_description());
                    combined_item.set_length(temp_item.get_length() + temp_item2.get_length());
                    combined_item.set_value(temp_item.get_value() + temp_item2.get_value());
                    combined_item.set_weight(temp_item.get_weight() + temp_item2.get_weight());
                    combined_item.set_width(temp_item.get_width() + temp_item2.get_width());

                    inventory_.erase(inventory_.begin() + i);
                    inventory_.erase(inventory_.begin() + j);
                    inventory_.push_back(combined_item);

                    return "";


                }
            }
        }

    }
    return "Det gick inte.";
}



QString Player::trade(QString& item_to_buy, QString& person_to_buy_from, Room& room)
{
    Merchant* m;
    for(size_t i{0}; i < room.get_merchants().size();++i)
    {
        m = &room.get_merchants().at(i);

        if(m->get_name().toUpper() == person_to_buy_from)
        {
            for(size_t j{0}; j < m->get_items_for_sale().size(); ++j)
            {
                if(m->get_items_for_sale().at(j).get_name().toUpper() == item_to_buy) //Om vi lyckats lokalisera föremålet som vi vill köpa.
                {
                    if(money_ >= m->get_items_for_sale().at(j).get_price()) // i detta läge går det att köpa.
                    {
                        money_ -= m->get_items_for_sale().at(j).get_price();
                        inventory_.push_back(m->get_item(j));
                        m->remove_item(j);
                        for (Item i : m->get_items_for_sale())
                            qDebug() << i.get_name();
                        return ("Du handlade " + item_to_buy + "");
                    }

                }
            }
        }
    }
    return "Du lyckades inte köpa " + item_to_buy;
}


QString Player::sale(QString& item_to_sell,QString& person_to_sell_to,Room& room)
{
    Merchant* merchant_pointer;

    for(size_t i{0}; i < room.get_merchants().size();++i)
    {
        merchant_pointer = &room.get_merchants().at(i); //m kommer att peka på den nuvarande handelsmannen.

        if(merchant_pointer->get_name().toUpper() == person_to_sell_to)
        {
            for(size_t j{0}; j < inventory_.size(); ++j) //Loopa igenom spelarens inventory.
            {
                if(inventory_.at(j).get_name().toUpper() == item_to_sell) //Föremålet vi vill sälja
                {

                    money_ += inventory_.at(j).get_price(); // Spelaren säljer sitt föremål
                    merchant_pointer->add_item(inventory_.at(j));
                    inventory_.erase(inventory_.begin()+j);
                    return ("Du sålde " + item_to_sell + "");
                }
            }
        }
    }

    return "Du lyckades inte sälja " + item_to_sell;

}



