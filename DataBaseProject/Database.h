#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <memory>

class Database
{

public:
    QSqlDatabase m_db;

    Database();

    static Database& GetInstance()
    {
        static Database * instance = 0;
        if(instance == 0)
        {
            instance = new Database();
        }
        return *instance;
    }

};

#endif // DATABASE_H
