#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "additemdialog.h"
#include "Database.h"
#include<QSqlError>
#include "Ranking.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_addItem = new AddItemDialog(this);
    connect(ui->actionAddItems, &QAction::triggered, this, &MainWindow::onAddItem);

    m_db = QSqlDatabase::addDatabase("QPSQL");
    m_db.setHostName("horton.elephantsql.com");
    m_db.setDatabaseName("hgyojooo");
    m_db.setUserName("hgyojooo");
    m_db.setPassword("nn8EKmmjdWlZIjOVPgK6lnRcK8enIt-K");

    m_db.open();

    qDebug() << "status" << m_db.isOpen();
//    if(isConnected = m_db.open())
//    {
//        ui->connectionStatus->setText("Status: Connected");
//    }
 //   qDebug()<< "last error" << m_db.lastError();
    m_playerManager = new PlayerManager();
    m_playerManager->CreateTable(m_db);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAddItem()
{
    int res = m_addItem->exec();

    if(res == QDialog::Accepted)
    {
        m_playerManager->InsertPlayer(m_db, m_addItem->CreatePlayer());
    }
}

void MainWindow::on_AddPlayer_clicked()
{
    int res = m_addItem->exec();

    if(res == QDialog::Accepted)
    {
        m_playerManager->InsertPlayer(m_db, m_addItem->CreatePlayer());
        qDebug() << "Player Inserted";
    }
    else
    {
        qDebug() << "Insert canceled";
    }

}

void MainWindow::on_ShowRanks_clicked()
{

    //int a = 14;
    //m_playerManager->RemovePlayer(m_db, a);
    m_playerManager->ranking->UpdateTable(m_db);
    m_playerManager->ranking->exec();

}


void MainWindow::on_Simulate_clicked()
{
    m_playerManager->_fights->ShowTable(m_db);
    m_playerManager->_fights->on_playRoundButton_clicked(m_db);
}

void MainWindow::on_simulareLupta_clicked()
{
    m_playerManager->_fights->exec();
}
