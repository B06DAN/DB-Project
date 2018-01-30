#include "Ranking.h"
#include "ui_ranking.h"
#include <QDebug>
#include "QMessageBox"

Ranking::Ranking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ranking)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window
    | Qt::WindowMinimizeButtonHint
    | Qt::WindowMaximizeButtonHint);
}

Ranking::~Ranking()
{
    delete ui;
}


void Ranking::UpdateTable(QSqlDatabase db) //ii pune in vector
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

        if(std::find_if(players.begin(), players.end(), [&id](const Player& p) { return p.m_id == id; } ) == players.end())
        {
            Player player(id, age, weight, team, points);
            qDebug() << player.m_id << " " << player.m_age << " " << player.m_weight << " " << player.m_team << " " << player.m_points << endl;

            players.push_back(player);
        }
    }

    std::sort( players.begin( ), players.end( ), [ ]( const Player& p1, const Player& p2 )
    {
       return p1.m_points > p2.m_points;
    });

    for(int i=0; i<players.size(); i++)
    {
        //qDebug() << players.at(i).m_points << " ";

        int id = players.at(i).m_id;
        QString _id = QString::number(id);
        int age = players.at(i).m_age;
        QString _age = QString::number(age);
        int weight = players.at(i).m_weight;
        QString _weight = QString::number(weight);
        int points = players.at(i).m_points;
        QString _points = QString::number(points);

        if(players.at(i).m_age >= 12 && players.at(i).m_age < 16 ){
            if(players.at(i).m_weight >= 40 && players.at(i).m_weight < 60){
                int rowCount = ui->table1_1->rowCount();
                ui->table1_1->insertRow(rowCount);
                ui->table1_1->setItem(rowCount, 0, new QTableWidgetItem(_id));
                ui->table1_1->setItem(rowCount, 1, new QTableWidgetItem(_age));
                ui->table1_1->setItem(rowCount, 2, new QTableWidgetItem(_weight));
                ui->table1_1->setItem(rowCount, 3, new QTableWidgetItem(players.at(i).m_team));
                ui->table1_1->setItem(rowCount, 4, new QTableWidgetItem(_points));
            }else if(players.at(i).m_weight >= 60 && players.at(i).m_weight < 80){
                int rowCount = ui->table1_2->rowCount();
                ui->table1_2->insertRow(rowCount);
                ui->table1_2->setItem(rowCount, 0, new QTableWidgetItem(_id));
                ui->table1_2->setItem(rowCount, 1, new QTableWidgetItem(_age));
                ui->table1_2->setItem(rowCount, 2, new QTableWidgetItem(_weight));
                ui->table1_2->setItem(rowCount, 3, new QTableWidgetItem(players.at(i).m_team));
                ui->table1_2->setItem(rowCount, 4, new QTableWidgetItem(_points));
            }else if(players.at(i).m_weight >= 80 && players.at(i).m_weight < 100){
                int rowCount = ui->table1_3->rowCount();
                ui->table1_3->insertRow(rowCount);
                ui->table1_3->setItem(rowCount, 0, new QTableWidgetItem(_id));
                ui->table1_3->setItem(rowCount, 1, new QTableWidgetItem(_age));
                ui->table1_3->setItem(rowCount, 2, new QTableWidgetItem(_weight));
                ui->table1_3->setItem(rowCount, 3, new QTableWidgetItem(players.at(i).m_team));
                ui->table1_3->setItem(rowCount, 4, new QTableWidgetItem(_points));
            }else  {
                QMessageBox::warning(this, tr("Error"), tr("No category for this person"));
            }
        }
        else if(players.at(i).m_age >= 16 && players.at(i).m_age < 20){
            if(players.at(i).m_weight >= 40 && players.at(i).m_weight < 60){
                int rowCount = ui->table2_1->rowCount();
                ui->table2_1->insertRow(rowCount);
                ui->table2_1->setItem(rowCount, 0, new QTableWidgetItem(_id));
                ui->table2_1->setItem(rowCount, 1, new QTableWidgetItem(_age));
                ui->table2_1->setItem(rowCount, 2, new QTableWidgetItem(_weight));
                ui->table2_1->setItem(rowCount, 3, new QTableWidgetItem(players.at(i).m_team));
                ui->table2_1->setItem(rowCount, 4, new QTableWidgetItem(_points));
            }else if(players.at(i).m_weight >= 60 && players.at(i).m_weight < 80){
                int rowCount = ui->table2_2->rowCount();
                ui->table2_2->insertRow(rowCount);
                ui->table2_2->setItem(rowCount, 0, new QTableWidgetItem(_id));
                ui->table2_2->setItem(rowCount, 1, new QTableWidgetItem(_age));
                ui->table2_2->setItem(rowCount, 2, new QTableWidgetItem(_weight));
                ui->table2_2->setItem(rowCount, 3, new QTableWidgetItem(players.at(i).m_team));
                ui->table2_2->setItem(rowCount, 4, new QTableWidgetItem(_points));
            }else if(players.at(i).m_weight >= 80 && players.at(i).m_weight < 100){
                int rowCount = ui->table2_3->rowCount();
                ui->table2_3->insertRow(rowCount);
                ui->table2_3->setItem(rowCount, 0, new QTableWidgetItem(_id));
                ui->table2_3->setItem(rowCount, 1, new QTableWidgetItem(_age));
                ui->table2_3->setItem(rowCount, 2, new QTableWidgetItem(_weight));
                ui->table2_3->setItem(rowCount, 3, new QTableWidgetItem(players.at(i).m_team));
                ui->table2_3->setItem(rowCount, 4, new QTableWidgetItem(_points));
            }else  {
                QMessageBox::warning(this, tr("Error"), tr("No category for this person"));
            }
        }else if(players.at(i).m_age >= 20 && players.at(i).m_age < 24){
            if(players.at(i).m_weight >= 40 && players.at(i).m_weight < 60){
                int rowCount = ui->table3_1->rowCount();
                ui->table3_1->insertRow(rowCount);
                ui->table3_1->setItem(rowCount, 0, new QTableWidgetItem(_id));
                ui->table3_1->setItem(rowCount, 1, new QTableWidgetItem(_age));
                ui->table3_1->setItem(rowCount, 2, new QTableWidgetItem(_weight));
                ui->table3_1->setItem(rowCount, 3, new QTableWidgetItem(players.at(i).m_team));
                ui->table3_1->setItem(rowCount, 4, new QTableWidgetItem(_points));
            }else if(players.at(i).m_weight >= 60 && players.at(i).m_weight < 80){
                int rowCount = ui->table3_2->rowCount();
                ui->table3_2->insertRow(rowCount);
                ui->table3_2->setItem(rowCount, 0, new QTableWidgetItem(_id));
                ui->table3_2->setItem(rowCount, 1, new QTableWidgetItem(_age));
                ui->table3_2->setItem(rowCount, 2, new QTableWidgetItem(_weight));
                ui->table3_2->setItem(rowCount, 3, new QTableWidgetItem(players.at(i).m_team));
                ui->table3_2->setItem(rowCount, 4, new QTableWidgetItem(_points));
            }else if(players.at(i).m_weight >= 80 && players.at(i).m_weight < 100){
                int rowCount = ui->table3_3->rowCount();
                ui->table3_3->insertRow(rowCount);
                ui->table3_3->setItem(rowCount, 0, new QTableWidgetItem(_id));
                ui->table3_3->setItem(rowCount, 1, new QTableWidgetItem(_age));
                ui->table3_3->setItem(rowCount, 2, new QTableWidgetItem(_weight));
                ui->table3_3->setItem(rowCount, 3, new QTableWidgetItem(players.at(i).m_team));
                ui->table3_3->setItem(rowCount, 4, new QTableWidgetItem(_points));
            }else  {
                QMessageBox::warning(this, tr("Error"), tr("No category for this person"));
            }
        }else {
            QMessageBox::warning(this, tr("Error"), tr("No category for this person"));
        }
    }
}                               //problema cu Player Inserted

void Ranking::on_Cancel_clicked()
{
    ui->table1_1->setRowCount(0);
    ui->table1_2->setRowCount(0);
    ui->table1_3->setRowCount(0);
    ui->table2_1->setRowCount(0);
    ui->table2_2->setRowCount(0);
    ui->table2_3->setRowCount(0);
    ui->table3_1->setRowCount(0);
    ui->table3_2->setRowCount(0);
    ui->table3_3->setRowCount(0);

    this->close();
}
