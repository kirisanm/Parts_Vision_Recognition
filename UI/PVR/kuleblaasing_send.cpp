#include "kuleblaasing_send.h"
#include "ui_kuleblaasing_send.h"

kuleblaasing_send::kuleblaasing_send(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kuleblaasing_send)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);  // start alltid på side 1 - SEND

    QPixmap pix0("C:/Users/Kirisan/Pictures/PVR_local/tePVRlogo.png"); //481x94
    ui->logo_tepvr_0->setPixmap(pix0);
}

kuleblaasing_send::~kuleblaasing_send()
{
    delete ui;
}

// Tilleggs widgets: --------------------------------------------------------------------------------------------------------
void kuleblaasing_send::on_tilbake_0_kuleblaasing_bedrifter_clicked()
{
    emit tilbake_0_kuleblaasing_bedrifter_clicked();
}
