#include "kuleblaasing_motta.h"
#include "ui_kuleblaasing_motta.h"

kuleblaasing_motta::kuleblaasing_motta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kuleblaasing_motta)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);  // start alltid på side 1 - SEND

    QPixmap pix0("C:/Users/Kirisan/Pictures/PVR_local/tePVRlogo.png"); //481x94
    ui->logo_tepvr_0->setPixmap(pix0);
}

kuleblaasing_motta::~kuleblaasing_motta()
{
    delete ui;
}


// Tilleggs widgets: --------------------------------------------------------------------------------------------------------
void kuleblaasing_motta::on_tilbake_0_kuleblaasing_bedrifter_clicked()
{
    emit tilbake_0_kuleblaasing_bedrifter_clicked();
}

