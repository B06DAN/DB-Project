#ifndef FIGHTS_H
#define FIGHTS_H

#include <QDialog>
#include <QSqlDatabase>
#include <QVariant>
#include <QSqlQuery>
#include <algorithm>
#include "Player.h"


namespace Ui {
class fights;
}

class fights : public QDialog
{
    Q_OBJECT

public:
    explicit fights(QWidget *parent = 0);
    ~fights();
    Ui::fights *ui;
    void ShowTable(QSqlDatabase db);
    std::vector<Player> players;
    std::vector<Player> players1_1;
    std::vector<Player> players1_2;
    std::vector<Player> players1_3;
    std::vector<Player> players2_1;
    std::vector<Player> players2_2;
    std::vector<Player> players2_3;
    std::vector<Player> players3_1;
    std::vector<Player> players3_2;
    std::vector<Player> players3_3;
    void SimulateFight(QSqlDatabase db, std::vector<Player> &players);
    void on_playRoundButton_clicked(QSqlDatabase db);
    void PrepareForFights(std::vector<Player> &players);
    void UpdatePoints(QSqlDatabase db, int id, int points);
private slots:
    void on_back_clicked();
    void UpdateTable(std::vector<Player> &players);
private:

};

#endif // FIGHTS_H
