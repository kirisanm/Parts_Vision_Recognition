#include "traadskjaering_motta.h"
#include "ui_traadskjaering_motta.h"

traadskjaering_motta::traadskjaering_motta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::traadskjaering_motta)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);  // start alltid på side 1 - SEND

    QPixmap pix0("C:/Users/Kirisan/Pictures/PVR_local/tePVRlogo.png"); //481x94
    ui->logo_tepvr_0->setPixmap(pix0);
    ui->logo_tepvr_1->setPixmap(pix0);
    ui->logo_tepvr_2->setPixmap(pix0);

    ui->stackedWidget->insertWidget(0, &_GjenkjennMotta);
}

traadskjaering_motta::~traadskjaering_motta()
{
    delete ui;
}

void traadskjaering_motta::on_sandsje_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void traadskjaering_motta::on_mvp_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

// Tilleggs widgets: --------------------------------------------------------------------------------------------------------

void traadskjaering_motta::on_tilbake_0_traadskjaering_bedrifter_clicked()
{
    emit tilbake_0_traadskjaering_bedrifter_clicked();
}


void traadskjaering_motta::on_tilbake_1_traadskjaering_sandsje_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void traadskjaering_motta::on_tilbake_2_traadskjaering_mvp_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

