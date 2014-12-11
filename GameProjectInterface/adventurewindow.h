#ifndef ADVENTUREWINDOW_H
#define ADVENTUREWINDOW_H
#include "Game.h"
#include <QMainWindow>

namespace Ui {
class AdventureWindow;
}



class AdventureWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdventureWindow(QWidget *parent = 0);
    ~AdventureWindow();



    Ui::AdventureWindow *ui;

    void set_game(const Game& G){ G_ = G;}
    void set_player(const Player& P){P_ = P;}
    Player get_player(){return P_;}
    Game   get_game(){return G_;}

    Player P_;
    Game G_;


private slots:

    void on_lineEdit_returnPressed();
    void help();
    void clear();
    void on_menu_load_triggered();
    void on_inventory_list_itemDoubleClicked(QListWidgetItem *item);
};

#endif // ADVENTUREWINDOW_H
