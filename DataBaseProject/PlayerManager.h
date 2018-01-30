#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include<QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <vector>
#include "Player.h"
#include "Database.h"
#include "Ranking.h"
#include "Fights.h"

class PlayerManager
{
public:
    PlayerManager();
    void CreateTable(QSqlDatabase db);
    void InsertPlayer(QSqlDatabase db, Player*);
    void UpdatePoints(QSqlDatabase db, int id, int points);
    void RemovePlayer(QSqlDatabase db, int id);
    Player ShowPlayers(QSqlDatabase db);
    std::vector<Player> GetPlayers(QSqlDatabase db);
    Ranking *ranking;
    fights *_fights;
};

#endif // PLAYERMANAGER_H
