#include "eloksering_send.h"
#include "ui_eloksering_send.h"

eloksering_send::eloksering_send(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::eloksering_send)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);  // start alltid på side 1 - SEND

    QPixmap pix0("C:/Users/Kirisan/Pictures/PVR_local/tePVRlogo.png"); //481x94
    ui->logo_tepvr_0->setPixmap(pix0);
    ui->logo_tepvr_1->setPixmap(pix0);
    ui->logo_tepvr_2->setPixmap(pix0);
    ui->logo_tepvr_3->setPixmap(pix0);
    ui->logo_tepvr_4->setPixmap(pix0);
    ui->logo_tepvr_5->setPixmap(pix0);
}

eloksering_send::~eloksering_send()
{
    delete ui;
}

void eloksering_send::on_eloksal_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void eloksering_send::on_gundersen_galvano_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void eloksering_send::on_hydal_alu_profiler_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
void eloksering_send::on_teloks_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
void eloksering_send::on_nct_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

// Tilleggs widgets: --------------------------------------------------------------------------------------------------------

void eloksering_send::on_tilbake_1_eloksal_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void eloksering_send::on_tilbake_0_eloksering_bedrifter_clicked()
{
    emit tilbake_0_eloksering_bedrifter_clicked();
}

void eloksering_send::on_tilbake_2_gundersen_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void eloksering_send::on_tilbake_3_hydal_alu_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void eloksering_send::on_tilbake_4_teloks_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void eloksering_send::on_tilbake_5_nct_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


