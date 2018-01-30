#ifndef RANKING_H
#define RANKING_H

#include <QDialog>
#include <QSqlDatabase>
#include <QVariant>
#include <QSqlQuery>
#include <algorithm>
#include "Player.h"


namespace Ui {
class Ranking;
}

class Ranking : public QDialog
{
    Q_OBJECT

public:
    explicit Ranking(QWidget *parent = 0);
    ~Ranking();
    Ui::Ranking *ui;
    void UpdateTable(QSqlDatabase db);
    std::vector<Player> players;
private slots:
    void on_Cancel_clicked();
};

#endif // RANKING_H
