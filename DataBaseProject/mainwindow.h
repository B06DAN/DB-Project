#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "PlayerManager.h"
#include "Ranking.h"

class AddItemDialog;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    PlayerManager *m_playerManager;

private slots:
    void onAddItem();
    void on_AddPlayer_clicked();
    void on_ShowRanks_clicked();
    void on_Simulate_clicked();


    void on_simulareLupta_clicked();

private:
    Ui::MainWindow *ui;
    AddItemDialog *m_addItem;
    QSqlDatabase m_db;
    bool isConnected;
    bool tableShowed = false;
    Ranking *m_ranking;
};

#endif // MAINWINDOW_H
