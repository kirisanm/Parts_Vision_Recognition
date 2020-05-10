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

    ui->stackedWidget->insertWidget(6, &_Vaatlakk);                     //setter inn vaatlakkering.cpp i index 6, side 7
    ui->stackedWidget->insertWidget(7, &_Pulverlakk);                   //setter inn pulverlakkering.cpp i index 7, side 8
    ui->stackedWidget->insertWidget(8, &_Offshorelakk);                 //setter inn offshore_lakkering.cpp i index 8, side 9
    ui->stackedWidget->insertWidget(9, &_Eloks);                        //Setter inn eloksering.cpp i index 9, side 10
    ui->stackedWidget->insertWidget(10, &_Kromater);                    //Setter inn kromatering.cpp i index 10, side 11

    connect(&_Vaatlakk, SIGNAL(tilbake_0_vaat_bedrifter_clicked()), this, SLOT(tilbake_0_vaat_bedrifter()));
    connect(&_Pulverlakk, SIGNAL(tilbake_0_pulver_bedrifter_clicked()), this, SLOT(tilbake_0_pulver_bedrifter()));
    connect(&_Offshorelakk, SIGNAL(tilbake_0_offshore_bedrifter_clicked()), this, SLOT(tilbake_0_offshore_bedrifter()));

    //elektrokjemisk_metode
    connect(&_Eloks, SIGNAL(tilbake_0_eloksering_bedrifter_clicked()), this, SLOT(tilbake_0_eloksering_bedrifter()));
    connect(&_Kromater, SIGNAL(tilbake_0_kromatering_bedrifter_clicked()), this, SLOT(tilbake_0_kromatering_bedrifter()));
}

mottar::~mottar()
{
    delete ui;
}

// lakkeringsvindu-------------------------------------------------------------------------------
void mottar::on_lakkering_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);  //index 1 = side 2
}
    void mottar::on_vaatlakkering_clicked()
    {
        ui->stackedWidget->setCurrentIndex(6);
    }
    void mottar::tilbake_0_vaat_bedrifter()
    {
        ui->stackedWidget->setCurrentIndex(1);
    }

    void mottar::on_pulverlakkering_clicked()
    {
        ui->stackedWidget->setCurrentIndex(7);
    }
    void mottar::tilbake_0_pulver_bedrifter()
    {
        ui->stackedWidget->setCurrentIndex(1);
    }

    void mottar::on_offshore_lakkering_clicked()
    {
        ui->stackedWidget->setCurrentIndex(8);
    }
    void mottar::tilbake_0_offshore_bedrifter()
    {
        ui->stackedWidget->setCurrentIndex(1);
    }

//elektrokjemisk metode vindu-------------------------------------------------------------------------------
void mottar::on_elektrokjemisk_metode_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);  //index 1 = side 3
}
    void mottar::on_eloksering_alu_clicked()
    {
        ui->stackedWidget->setCurrentIndex(9);
    }
    void mottar::tilbake_0_eloksering_bedrifter()
    {
        ui->stackedWidget->setCurrentIndex(2); //index 2, side 3 i mottar.cpp - Elektrokjemisk metode
    }

    void mottar::on_kromatering_clicked()
    {
        ui->stackedWidget->setCurrentIndex(10);
    }
    void mottar::tilbake_0_kromatering_bedrifter()
    {
        ui->stackedWidget->setCurrentIndex(2);
    }

//kjemisk metode vindu-------------------------------------------------------------------------------
void mottar::on_kjemisk_metode_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);  //index 1 = side 4
}

//herding vindu-------------------------------------------------------------------------------
void mottar::on_herding_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);  //index 1 = side 5
}

//annet vindu-------------------------------------------------------------------------------
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
