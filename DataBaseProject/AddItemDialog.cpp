#include "additemdialog.h"
#include "ui_additemdialog.h"
#include "QMessageBox"

AddItemDialog::AddItemDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItemDialog)
{
    ui->setupUi(this);
}

AddItemDialog::~AddItemDialog()
{
    delete ui;
}

/*void AddItemDialog::SetPlayerData(const QString& id, const QString& age, const QString& weight, const QString& team, const QString& points)
{
    ui->idLineEdit->setText(id);
    ui->ageLineEdit->setText(age);
    ui->weightLineEdit->setText(weight);
    ui->teamLineEdit->setText(team);
    ui->pointsLineEdit->setText(points);
}*/

Player* AddItemDialog::CreatePlayer()
{

    QString id = ui->idLineEdit->text();
    QString age = ui->ageLineEdit->text();
    QString weight = ui->weightLineEdit->text();
    QString team = ui->teamLineEdit->text();
    QString points = ui->pointsLineEdit->text();

    Player* player = new Player(id.toInt(), age.toInt(), weight.toInt(), team, points.toInt());
    return player;
}

void AddItemDialog::showEvent(QShowEvent*)
{
    ui->idLineEdit->setText("");
    ui->ageLineEdit->setText("");
    ui->weightLineEdit->setText("");
    ui->teamLineEdit->setText("");
    ui->pointsLineEdit->setText("");
}

void AddItemDialog::accept()
{
    bool id = true;
    bool age = true;
    bool weight = true;
    bool points = true;

    int input = ui->idLineEdit->text().toInt(&id);
    if(!id)
    {
        QMessageBox::warning(this, tr("add item error"), tr("Id should be a number!"));
    }

    input = ui->ageLineEdit->text().toInt(&age);
    if(!age)
    {
        QMessageBox::warning(this, tr("add item error"), tr("Age should be a number!"));
    }

    input = ui->weightLineEdit->text().toInt(&weight);
    if(!weight)
    {
        QMessageBox::warning(this, tr("add item error"), tr("Weight should be a number!"));
    }

    input = ui->pointsLineEdit->text().toInt(&points);
    if(!points)
    {
        QMessageBox::warning(this, tr("add item error"), tr("Points should be a number!"));
    }

    if(id && age && weight && points)
    {
        QDialog::accept();
    }
}
