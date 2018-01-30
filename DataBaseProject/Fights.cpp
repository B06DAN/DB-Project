#include "Fights.h"
#include "ui_fights.h"
#include "QDebug"
#include "QTime"

fights::fights(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fights)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window
    | Qt::WindowMinimizeButtonHint
    | Qt::WindowMaximizeButtonHint);
}

fights::~fights()
{
    delete ui;
}

void fights::ShowTable(QSqlDatabase db)
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Players");
    query.exec();

    while(query.next()) {
        int id = query.value("Id").toInt();
        int age = query.value("Age").toInt();
        int weight = query.value("Weight").toInt();
        QString team = query.value("Team").toString();
        int points = query.value("Points").toInt();

        if(std::find_if(players.begin(), players.end(), [&id](const Player& p) { return p.m_id == id;}) == players.end())
        {
            Player player(id, age, weight, team, points);
            players.push_back(player);
        }
    }

    std::random_shuffle(players.begin( ), players.end( ));


    ui->table1_1->insertRow(0);
    ui->table1_2->insertRow(0);
    ui->table1_3->insertRow(0);
    ui->table2_1->insertRow(0);
    ui->table2_2->insertRow(0);
    ui->table2_3->insertRow(0);
    ui->table3_1->insertRow(0);
    ui->table3_3->insertRow(0);
    ui->table3_3->insertRow(0);


    for(int i=0; i<players.size(); i++)
    {

        int id = players.at(i).m_id;
        QString _id = QString::number(id);

        if(players.at(i).m_age >= 12 && players.at(i).m_age < 16 ){
            if(players.at(i).m_weight >= 40 && players.at(i).m_weight < 60){

                int columnCount = ui->table1_1->columnCount();
                ui->table1_1->insertColumn(columnCount);
                ui->table1_1->setItem(0, columnCount, new QTableWidgetItem(_id));
                players1_1.push_back(players.at(i));
            }else if(players.at(i).m_weight >= 60 && players.at(i).m_weight < 80){
                int columnCount = ui->table1_2->columnCount();
                ui->table1_2->insertColumn(columnCount);
                ui->table1_2->setItem(0, columnCount, new QTableWidgetItem(_id));
                players1_2.push_back(players.at(i));

            }else if(players.at(i).m_weight >= 80 && players.at(i).m_weight < 100){
                int columnCount = ui->table1_3->columnCount();
                ui->table1_3->insertColumn(columnCount);
                ui->table1_3->setItem(0, columnCount, new QTableWidgetItem(_id));
                players1_3.push_back(players.at(i));
            }
        }
        else if(players.at(i).m_age >= 16 && players.at(i).m_age < 20){
            if(players.at(i).m_weight >= 40 && players.at(i).m_weight < 60){
                int columnCount = ui->table2_1->columnCount();
                ui->table2_1->insertColumn(columnCount);
                ui->table2_1->setItem(0, columnCount, new QTableWidgetItem(_id));
                players2_1.push_back(players.at(i));
            }else if(players.at(i).m_weight >= 60 && players.at(i).m_weight < 80){
                int columnCount = ui->table2_2->columnCount();
                ui->table2_2->insertColumn(columnCount);
                ui->table2_2->setItem(0, columnCount, new QTableWidgetItem(_id));
                players2_2.push_back(players.at(i));
            }else if(players.at(i).m_weight >= 80 && players.at(i).m_weight < 100){
                int columnCount = ui->table2_3->columnCount();
                ui->table2_3->insertColumn(columnCount);
                ui->table2_3->setItem(0, columnCount, new QTableWidgetItem(_id));
                players2_3.push_back(players.at(i));
            }
        }else if(players.at(i).m_age >= 20 && players.at(i).m_age < 24){
            if(players.at(i).m_weight >= 40 && players.at(i).m_weight < 60){
                int columnCount = ui->table3_1->columnCount();
                ui->table3_1->insertColumn(columnCount);
                ui->table3_1->setItem(0, columnCount, new QTableWidgetItem(_id));
                players3_1.push_back(players.at(i));
            }else if(players.at(i).m_weight >= 60 && players.at(i).m_weight < 80){
                int columnCount = ui->table3_2->columnCount();
                ui->table3_2->insertColumn(columnCount);
                ui->table3_2->setItem(0, columnCount, new QTableWidgetItem(_id));
                players3_2.push_back(players.at(i));
            }else if(players.at(i).m_weight >= 80 && players.at(i).m_weight < 100){
                int columnCount = ui->table3_3->columnCount();
                ui->table3_3->insertColumn(columnCount);
                ui->table3_3->setItem(0, columnCount, new QTableWidgetItem(_id));
                players3_3.push_back(players.at(i));
            }
        }
    }

}

void fights::on_back_clicked()
{
    ui->table1_1->setRowCount(0);
    ui->table1_1->setColumnCount(0);
    ui->table1_2->setRowCount(0);
    ui->table1_2->setColumnCount(0);
    ui->table1_3->setRowCount(0);
    ui->table1_3->setColumnCount(0);
    ui->table2_1->setRowCount(0);
    ui->table2_1->setColumnCount(0);
    ui->table2_2->setRowCount(0);
    ui->table2_2->setColumnCount(0);
    ui->table2_3->setRowCount(0);
    ui->table2_3->setColumnCount(0);
    ui->table3_1->setRowCount(0);
    ui->table3_1->setColumnCount(0);
    ui->table3_2->setRowCount(0);
    ui->table3_2->setColumnCount(0);
    ui->table3_3->setRowCount(0);
    ui->table3_3->setColumnCount(0);

    this->close();
}

void fights::PrepareForFights(std::vector<Player> &players)
{

    if(players.size() >= 16){
        players.erase(players.begin() + 16, players.end());
    }else if (players.size() >= 8){
        players.erase(players.begin() + 8, players.end());
    }else if (players.size() >= 4){
        players.erase(players.begin() + 4, players.end());
    }else if (players.size() >= 2){
        players.erase(players.begin() + 2, players.end());
    }
}

void fights::on_playRoundButton_clicked(QSqlDatabase db)
{
    PrepareForFights(players1_1);
    PrepareForFights(players1_2);
    PrepareForFights(players1_3);
    PrepareForFights(players2_1);
    PrepareForFights(players2_2);
    PrepareForFights(players2_3);
    PrepareForFights(players3_1);
    PrepareForFights(players3_2);
    PrepareForFights(players3_3);

    while(players1_1.size() > 1 || players1_2.size() > 1 || players1_3.size() > 1 || players2_1.size() > 1 || players2_2.size() > 1 || players2_3.size() > 1 || players3_1.size() > 1 || players3_2.size() > 1 || players3_3.size() > 1)
    {
    SimulateFight(db, players1_1);
    UpdateTable(players1_1);
    SimulateFight(db, players1_2);
    UpdateTable(players1_2);
    SimulateFight(db, players1_3);
    UpdateTable(players1_3);
    SimulateFight(db, players2_1);
    UpdateTable(players2_1);
    SimulateFight(db, players2_2);
    UpdateTable(players2_2);
    SimulateFight(db, players2_3);
    UpdateTable(players2_3);
    SimulateFight(db, players3_1);
    UpdateTable(players3_1);
    SimulateFight(db, players3_2);
    UpdateTable(players3_2);
    SimulateFight(db, players3_3);
    UpdateTable(players3_3);
    }
}

void fights::UpdatePoints(QSqlDatabase db, int id, int points)
{
    QSqlQuery query(db);
        query.prepare("UPDATE "
                      "     Players"
                      " SET"
                      "      points = (:points)"
                      " WHERE"
                      "      id = (:id)");
        query.bindValue(":points", points);
        query.bindValue(":id", id);
        query.exec();

}

void fights::SimulateFight(QSqlDatabase db, std::vector<Player> &players)
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    std::vector<Player> playersTemp;

    int random;
    int actualSize = players.size();
    int i = 0;
    if(actualSize > 1){
        while(i < actualSize){
            random = qrand() % 2;
            if(random == 0){
                UpdatePoints(db, players.at(i).m_id, players.at(i).m_points +2);
                UpdatePoints(db, players.at(i+1).m_id, players.at(i+1).m_points +1);

                playersTemp.push_back(players.at(i));
            }
            else{
                UpdatePoints(db, players.at(i).m_id, players.at(i).m_points +1);
                UpdatePoints(db, players.at(i+1).m_id, players.at(i+1).m_points +2);
                playersTemp.push_back(players.at(i+1));
            }
                i += 2;
         }
         players.clear();
         for(int i = 0 ; i < playersTemp.size(); i++)
         {
             players.push_back(playersTemp.at(i));
         }
    }else if (actualSize == 1){
        players.at(i).m_points += 2;
    }
}

void fights::UpdateTable(std::vector<Player> &players)
{
    std::random_shuffle(players.begin( ), players.end( ));
    bool createOnce = true;
    int var2 = 0;

    if(players.size() >= 1){
       for(int i=0; i<players.size(); i++)
       {
            int id = players.at(i).m_id;
            QString _id = QString::number(id);
            int rowCount ;
            qDebug() << "Player size in for  " << players.size();

            if(players.at(i).m_age >= 12 && players.at(i).m_age < 16 ){
                if(players.at(i).m_weight >= 40 && players.at(i).m_weight < 60){
                    if(createOnce){
                        rowCount = ui->table1_1->rowCount();
                        ui->table1_1->insertRow(rowCount);
                        createOnce = false;
                    }
                    qDebug() << "id : " << _id;
                    qDebug() << "var1 " << rowCount;
                    qDebug() << "var2 " << var2;

                    ui->table1_1->setItem(rowCount, var2, new QTableWidgetItem(_id));
                    var2++;

                }else if(players.at(i).m_weight >= 60 && players.at(i).m_weight < 80){
                    if(createOnce){
                        rowCount = ui->table1_2->rowCount();
                        ui->table1_2->insertRow(rowCount);
                        createOnce = false;
                    }
                    ui->table1_2->setItem(rowCount, var2, new QTableWidgetItem(_id));
                    var2++;
                }else if(players.at(i).m_weight >= 80 && players.at(i).m_weight < 100){
                    if(createOnce){
                        rowCount = ui->table1_3->rowCount();
                        ui->table1_3->insertRow(rowCount);
                        createOnce = false;
                    }
                    ui->table1_3->setItem(rowCount, var2, new QTableWidgetItem(_id));
                    var2++;
                }
            }
            else if(players.at(i).m_age >= 16 && players.at(i).m_age < 20){
                if(players.at(i).m_weight >= 40 && players.at(i).m_weight < 60){
                    if(createOnce){
                        rowCount = ui->table2_1->rowCount();
                        ui->table2_1->insertRow(rowCount);
                        createOnce = false;
                    }
                    ui->table2_1->setItem(rowCount, var2, new QTableWidgetItem(_id));
                    var2++;
                }else if(players.at(i).m_weight >= 60 && players.at(i).m_weight < 80){
                    if(createOnce){
                        rowCount = ui->table2_2->rowCount();
                        ui->table2_2->insertRow(rowCount);
                        createOnce = false;
                    }
                    ui->table2_2->setItem(rowCount, var2, new QTableWidgetItem(_id));
                    var2++;
                }else if(players.at(i).m_weight >= 80 && players.at(i).m_weight < 100){
                    if(createOnce){
                        rowCount = ui->table2_3->rowCount();
                        ui->table2_3->insertRow(rowCount);
                        createOnce = false;
                    }
                    ui->table2_3->setItem(rowCount, var2, new QTableWidgetItem(_id));
                    var2++;
                }
            }else if(players.at(i).m_age >= 20 && players.at(i).m_age < 24){
                if(players.at(i).m_weight >= 40 && players.at(i).m_weight < 60){
                    if(createOnce){
                        rowCount = ui->table3_1->rowCount();
                        ui->table3_1->insertRow(rowCount);
                        createOnce = false;
                    }
                    ui->table3_1->setItem(rowCount, var2, new QTableWidgetItem(_id));
                    var2++;
                }else if(players.at(i).m_weight >= 60 && players.at(i).m_weight < 80){
                    if(createOnce){
                        int rowCount = ui->table3_2->rowCount();
                        ui->table3_2->insertRow(rowCount);
                        createOnce = false;
                    }
                    ui->table3_2->setItem(rowCount, var2, new QTableWidgetItem(_id));
                    var2++;
                }else if(players.at(i).m_weight >= 80 && players.at(i).m_weight < 100){
                    if(createOnce){
                        int rowCount = ui->table3_3->rowCount();
                        ui->table3_3->insertRow(rowCount);
                        createOnce = false;
                    }
                    ui->table3_3->setItem(rowCount, var2, new QTableWidgetItem(_id));
                    var2++;
                }
            }
        }
       if(players.size() == 1){
        players.clear();
       }
    }

}

