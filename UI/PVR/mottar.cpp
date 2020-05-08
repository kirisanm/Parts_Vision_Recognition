#include "mottar.h"
#include "ui_mottar.h"

mottar::mottar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mottar)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);  // start alltid på side 1 - MOTTA

    QPixmap pix0("C:/Users/Kirisan/Pictures/PVR_local/tePVRlogo.png"); //481x94
    ui->logo_tepvr_0->setPixmap(pix0);
    ui->logo_tepvr_1->setPixmap(pix0);
    ui->logo_tepvr_2->setPixmap(pix0);
    ui->logo_tepvr_3->setPixmap(pix0);
    ui->logo_tepvr_4->setPixmap(pix0);
    ui->logo_tepvr_5->setPixmap(pix0);

    //Home ikon i venstre hjørne, x_0_send
    QPixmap pix("C:/Users/Kirisan/Pictures/PVR_local/x_home.png");
    QIcon ButtonIcon(pix);
    ui->x_0_motta->setIcon(ButtonIcon);
    ui->x_0_motta->setIconSize(pix.rect().size());
    ui->x_0_motta->setFixedSize(pix.rect().size());
}

mottar::~mottar()
{
    delete ui;
}

void mottar::on_lakkering_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);  //index 1 = side 2
}

void mottar::on_elektrokjemisk_metode_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);  //index 1 = side 3
}

void mottar::on_kjemisk_metode_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);  //index 1 = side 4
}

void mottar::on_herding_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);  //index 1 = side 5
}

void mottar::on_annet_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);  //index 1 = side 6
}

// Tilleggs widgets: --------------------------------------------------------------------------------------------------------
void mottar::on_tilbake_0_motta_clicked()
{
    emit tilbake_0_motta_clicked();
}

void mottar::on_x_0_motta_clicked()
{
    emit x_0_motta_clicked();
}

void mottar::on_tilbake_1_lakk_motta_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);  //tilbake til index 0, side 1
}

void mottar::on_tilbake_2_elkj_motta_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);  //tilbake til index 0, side 1
}

void mottar::on_tilbake_3_kj_motta_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);  //tilbake til index 0, side 1
}

void mottar::on_tilbake_4_herding_motta_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);  //tilbake til index 0, side 1
}

void mottar::on_tilbake_5_annet_motta_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);  //tilbake til index 0, side 1
}
