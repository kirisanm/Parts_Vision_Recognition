#include "sender.h"
#include "ui_sender.h"

sender::sender(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sender)
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

    //Home ikon i venstre hjørne, x_0_send
    QPixmap pix("C:/Users/Kirisan/Pictures/PVR_local/x_home.png");
    QIcon ButtonIcon(pix);
    ui->x_0_send->setIcon(ButtonIcon);
    ui->x_0_send->setIconSize(pix.rect().size());
    ui->x_0_send->setFixedSize(pix.rect().size());

    ui->stackedWidget->insertWidget(6, &_Vaatlakk);                     //setter inn vaatlakkering.cpp i index 6, side 7
    ui->stackedWidget->insertWidget(7, &_Pulverlakk);                   //setter inn pulverlakkering.cpp i index 7, side 8
    ui->stackedWidget->insertWidget(8, &_Offshorelakk);                 //setter inn offshore_lakkering.cpp i index 8, side 9
    ui->stackedWidget->insertWidget(9, &_Eloks);                        //Setter inn eloksering.cpp i index 9, side 10
    ui->stackedWidget->insertWidget(10, &_Kromater);                    //Setter inn kromatering.cpp i index 10, side 11
    ui->stackedWidget->insertWidget(11, &_Elzink);                      //Setter inn elzink.cpp i index 11, side 12
    ui->stackedWidget->insertWidget(12, &_Hardforkrom);                 //Setter inn hardforkromming.cpp i index 12, side 13
    ui->stackedWidget->insertWidget(13, &_ElektroFornikling);           //Setter inn elektrolytisk_fornikling.cpp i index 13, side 14
    ui->stackedWidget->insertWidget(14, &_Fosfat);                      //Setter inn fosfatering.cpp i index 14, side 15

    //Lakkering
    connect(&_Vaatlakk, SIGNAL(tilbake_0_vaat_bedrifter_clicked()), this, SLOT(tilbake_0_vaat_bedrifter()));
    connect(&_Pulverlakk, SIGNAL(tilbake_0_pulver_bedrifter_clicked()), this, SLOT(tilbake_0_pulver_bedrifter()));
    connect(&_Offshorelakk, SIGNAL(tilbake_0_offshore_bedrifter_clicked()), this, SLOT(tilbake_0_offshore_bedrifter()));

    //elektrokjemisk_metode
    connect(&_Eloks, SIGNAL(tilbake_0_eloksering_bedrifter_clicked()), this, SLOT(tilbake_0_eloksering_bedrifter()));
    connect(&_Kromater, SIGNAL(tilbake_0_kromatering_bedrifter_clicked()), this, SLOT(tilbake_0_kromatering_bedrifter()));
    connect(&_Elzink, SIGNAL(tilbake_0_elzink_bedrifter_clicked()), this, SLOT(tilbake_0_elzink_bedrifter()));
    connect(&_Hardforkrom, SIGNAL(tilbake_0_hardforkromming_bedrifter_clicked()), this, SLOT(tilbake_0_hardforkromming_bedrifter()));
    connect(&_ElektroFornikling, SIGNAL(tilbake_0_elektrolytisk_fornikling_bedrifter_clicked()), this, SLOT(tilbake_0_elektrolytisk_fornikling_bedrifter()));

    //kjemisk_metode
    connect(&_Fosfat, SIGNAL(tilbake_0_fosfatering_bedrifter_clicked()), this, SLOT(tilbake_0_fosfatering_bedrifter()));
}

sender::~sender()
{
    delete ui;
}

// lakkeringsvindu-------------------------------------------------------------------------------
void sender::on_lakkering_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); //index 1, side 2 - Lakkering
}

    void sender::on_vaatlakkering_clicked()
    {
        ui->stackedWidget->setCurrentIndex(6);
    }

    void sender::tilbake_0_vaat_bedrifter()
    {
        ui->stackedWidget->setCurrentIndex(1);
    }

    void sender::on_pulverlakkering_clicked()
    {
        ui->stackedWidget->setCurrentIndex(7);
    }

    void sender::tilbake_0_pulver_bedrifter()
    {
        ui->stackedWidget->setCurrentIndex(1);
    }

    void sender::on_offshore_lakkering_clicked()
    {
        ui->stackedWidget->setCurrentIndex(8);
    }

    void sender::tilbake_0_offshore_bedrifter()
    {
        ui->stackedWidget->setCurrentIndex(1);
    }

//elektrokjemisk metode vindu-------------------------------------------------------------------------------
void sender::on_elektrokjemisk_metode_clicked()
{
    ui->stackedWidget->setCurrentIndex(2); //index 2, side 3 - Elektrokjemisk metode
}

    void sender::on_eloksering_alu_clicked()
    {
        ui->stackedWidget->setCurrentIndex(9);
    }
    void sender::tilbake_0_eloksering_bedrifter()
    {
        ui->stackedWidget->setCurrentIndex(2); //index 2, side 3 i sender.cpp - Elektrokjemisk metode
    }

    void sender::on_kromatering_clicked()
    {
        ui->stackedWidget->setCurrentIndex(10);
    }
    void sender::tilbake_0_kromatering_bedrifter()
    {
        ui->stackedWidget->setCurrentIndex(2);
    }

    void sender::on_elzink_clicked()
    {
        ui->stackedWidget->setCurrentIndex(11);
    }
    void sender::tilbake_0_elzink_bedrifter()
    {
        ui->stackedWidget->setCurrentIndex(2);
    }

    void sender::on_hardforkromming_clicked()
    {
        ui->stackedWidget->setCurrentIndex(12);
    }
    void sender::tilbake_0_hardforkromming_bedrifter()
    {
        ui->stackedWidget->setCurrentIndex(2);
    }

    void sender::on_elektrolytisk_fornikling_clicked()
    {
        ui->stackedWidget->setCurrentIndex(13);
    }
    void sender::tilbake_0_elektrolytisk_fornikling_bedrifter()
    {
        ui->stackedWidget->setCurrentIndex(2);
    }

//kjemisk metode vindu-------------------------------------------------------------------------------
void sender::on_kjemisk_metode_clicked()
{
    ui->stackedWidget->setCurrentIndex(3); //index 3, side 4 - Kjemisk metode
}
    void sender::on_fosfatering_clicked()
    {
        ui->stackedWidget->setCurrentIndex(14);
    }
    void sender::tilbake_0_fosfatering_bedrifter()
    {
        ui->stackedWidget->setCurrentIndex(3);
    }

void sender::on_herding_clicked()
{
    ui->stackedWidget->setCurrentIndex(4); //index 4, side 5 - Herding
}

void sender::on_annet_clicked()
{
    ui->stackedWidget->setCurrentIndex(5); //index5, side 6 - Annet
}


// Tilleggs widgets: --------------------------------------------------------------------------------------------------------
void sender::on_x_0_send_clicked()
{
    emit x_0_send_clicked(); // avslutter og tilbake til hjem (index 0, side 1 i main).
}

void sender::on_tilbake_0_send_clicked()
{
    emit tilbake_0_send_clicked(); //ett hakk tilbake (index 0, side 1 i sender) - Destinasjon: SEND og MOTTA
}

void sender::on_tilbake_1_lakk_send_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void sender::on_tilbake_2_elkj_send_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void sender::on_tilbake_3_kj_send_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void sender::on_tilbake_4_herd_send_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void sender::on_tilbake_5_annet_send_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}




