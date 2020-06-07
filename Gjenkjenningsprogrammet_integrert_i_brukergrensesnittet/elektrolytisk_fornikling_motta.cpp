#include "elektrolytisk_fornikling_motta.h"
#include "ui_elektrolytisk_fornikling_motta.h"

elektrolytisk_fornikling_motta::elektrolytisk_fornikling_motta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::elektrolytisk_fornikling_motta)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);  // start alltid på side 1 - SEND

    QPixmap pix0("C:/Users/Kirisan/Pictures/PVR_local/tePVRlogo.png"); //481x94
    ui->logo_tepvr_0->setPixmap(pix0);
    ui->logo_tepvr_1->setPixmap(pix0);
    ui->logo_tepvr_2->setPixmap(pix0);
    ui->logo_tepvr_3->setPixmap(pix0);
    ui->stackedWidget->insertWidget(0, &_GjenkjennMotta);
}

elektrolytisk_fornikling_motta::~elektrolytisk_fornikling_motta()
{
    delete ui;
}

void elektrolytisk_fornikling_motta::on_honefoss_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void elektrolytisk_fornikling_motta::on_gundersen_galvano_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void elektrolytisk_fornikling_motta::on_norsk_everit_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

// Tilleggs widgets: --------------------------------------------------------------------------------------------------------
void elektrolytisk_fornikling_motta::on_tilbake_0_elektrolytisk_fornikling_bedrifter_clicked()
{
    emit tilbake_0_elektrolytisk_fornikling_bedrifter_clicked();
}

void elektrolytisk_fornikling_motta::on_tilbake_1_elektrolytisk_fornikling_honefoss_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void elektrolytisk_fornikling_motta::on_tilbake_2_elektrolytisk_fornikling_gundersen_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void elektrolytisk_fornikling_motta::on_tilbake_3_elektrolytisk_fornikling_norsk_everit_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
