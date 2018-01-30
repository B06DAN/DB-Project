#ifndef ADDITEMDIALOG_H
#define ADDITEMDIALOG_H

#include <QDialog>
#include "Player.h"
#include "PlayerManager.h"

namespace Ui {
class AddItemDialog;
}

class AddItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddItemDialog(QWidget *parent = 0);
    ~AddItemDialog();
    //void SetPlayerData(const QString& id, const QString& age, const QString& weight, const QString& team, const QString& points);
    Player* CreatePlayer();

protected:
    void showEvent(QShowEvent*) override;
    void accept() override;

private:
    Ui::AddItemDialog *ui;
};

#endif // ADDITEMDIALOG_H
