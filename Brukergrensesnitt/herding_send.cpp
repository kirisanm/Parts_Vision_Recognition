#include "herding_send.h"
#include "ui_herding_send.h"

herding_send::herding_send(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::herding_send)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);  // start alltid på side 1 - SEND

    QPixmap pix0("C:/Users/Kirisan/Pictures/PVR_local/tePVRlogo.png"); //481x94
    ui->logo_tepvr_0->setPixmap(pix0);
    ui->logo_tepvr_1->setPixmap(pix0);
    ui->logo_tepvr_2->setPixmap(pix0);
}

herding_send::~herding_send()
{
    delete ui;
}

void herding_send::on_thune_produkter_raufoss_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void herding_send::on_bodycote_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

// Tilleggs widgets: --------------------------------------------------------------------------------------------------------
void herding_send::on_tilbake_0_herding_bedrifter_clicked()
{
    emit tilbake_0_herding_bedrifter_clicked();
}

void herding_send::on_tilbake_1_herding_thune_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void herding_send::on_tilbake_2_herding_bodycote_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

