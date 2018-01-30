#ifndef PLAYER_H
#define PLAYER_H
#include<QString>

class Player
{
public:
    QString m_id;
    int m_points;
    int m_age;
    int m_weight;
    QString m_team;


    Player(QString id, int age, int weight, QString team, int points);


};

#endif // PLAYER_H
