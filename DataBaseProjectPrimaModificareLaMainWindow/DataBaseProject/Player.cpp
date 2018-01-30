#include "Player.h"


Player::Player(int id, int age, int weight, QString team, int points)
{
    m_id = id;
    m_points = points;
    m_age = age;
    m_weight = weight;
    m_team = team;
}
