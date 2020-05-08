#ifndef SENDER_H
#define SENDER_H

#include <QWidget>
#include <vaatlakkering_send.h>
#include <pulverlakkering_send.h>
#include <offshore_lakkering_send.h>
#include <eloksering_send.h>
#include <kromatering_send.h>
#include <elzink_send.h>
#include <hardforkromming_send.h>
#include <elektrolytisk_fornikling_send.h>
#include <fosfatering_send.h>

namespace Ui {
class sender;
}

class sender : public QWidget
{
    Q_OBJECT

public:
    explicit sender(QWidget *parent = nullptr);
    ~sender();

private slots:
    //index 0, side 1:
    void on_x_0_send_clicked(); //avslutt (tilbake til hjem/logg inn) - mainwindow.cpp - KNAPP (x)
    void on_tilbake_0_send_clicked();

    void on_lakkering_clicked();
    void on_elektrokjemisk_metode_clicked();
    void on_kjemisk_metode_clicked();
    void on_herding_clicked();
    void on_annet_clicked();

    void on_tilbake_1_lakk_send_clicked();
    void on_tilbake_2_elkj_send_clicked();
    void on_tilbake_3_kj_send_clicked();
    void on_tilbake_4_herd_send_clicked();
    void on_tilbake_5_annet_send_clicked();

//Lakkeringsvindu---------------------------------------------------------------------------------------------------------------------
    void on_vaatlakkering_clicked();                                //Våtlakkering
    void tilbake_0_vaat_bedrifter();                                //tilbake fra våtlakkering til lakkering

    void on_pulverlakkering_clicked();                              //pulverlakkering
    void tilbake_0_pulver_bedrifter();                              //tilbake fra pulverlakkering til lakkering

    void on_offshore_lakkering_clicked();                           //Offshore lakkering
    void tilbake_0_offshore_bedrifter();                            //tilbake fra offshore lakkering til lakkering

//elektrokjemisk metode vindu---------------------------------------------------------------------------------------------------------
    void on_eloksering_alu_clicked();                               //eloksering
    void tilbake_0_eloksering_bedrifter();                          //tilbake fra eloksering til elektrokjemisk metode

    void on_kromatering_clicked();                                  //Kromatering
    void tilbake_0_kromatering_bedrifter();                         //tilbake fra kromatering til elektrokjemisk metode

    void on_elzink_clicked();                                       //Elektrolytisk forsinking (ELZINK)
    void tilbake_0_elzink_bedrifter();                              //tilbake fra elzink til elektrokjemisk metode

    void on_hardforkromming_clicked();                              //Hardforkromming
    void tilbake_0_hardforkromming_bedrifter();                     //tilbake fra hardforkromming til elektrokjemisk metode

    void on_elektrolytisk_fornikling_clicked();                     //Elektrolytisk fornikling
    void tilbake_0_elektrolytisk_fornikling_bedrifter();            //tilbake fra elektrolytisk fornikling til elektrokjemisk metode

//kjemisk metode vindu----------------------------------------------------------------------------------------------------------------

    void on_fosfatering_clicked();
    void tilbake_0_fosfatering_bedrifter();

private:
    Ui::sender *ui;
    class vaatlakkering_send _Vaatlakk;                                 //objekt for våtlakkering
    class pulverlakkering_send _Pulverlakk;                             //objekt for pulverlakkering
    class offshore_lakkering_send _Offshorelakk;                        //objekt for offshore lakkering

    class eloksering_send _Eloks;                                       //objekt for eloksering (elektrokjemisk metode)
    class kromatering_send _Kromater;                                   //objekt for kromatering (elektrokjemisk metode)
    class elzink_send _Elzink;                                          //objekt for elzink (elektrokjemisk metode)
    class hardforkromming_send _Hardforkrom;                            //objekt for hardforkromming (elektrokjemisk metode)
    class elektrolytisk_fornikling_send _ElektroFornikling;             //objekt for elektrolytisk fornikling (elektrokjemisk metode)

    class fosfatering_send _Fosfat;                                     //objekt for fosfatering (kjemisk metode)

signals:
    void x_0_send_clicked(); //avslutt (tilbake til hjem/logg inn) - mainwindow.cpp - SIGNAL
    void tilbake_0_send_clicked();
};

#endif // SENDER_H
