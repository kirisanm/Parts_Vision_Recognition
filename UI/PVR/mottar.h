#ifndef MOTTAR_H
#define MOTTAR_H

#include <QWidget>

#include <vaatlakkering_motta.h>
#include <pulverlakkering_motta.h>
#include <offshore_lakkering_motta.h>
#include <eloksering_motta.h>
#include <kromatering_motta.h>

namespace Ui {
class mottar;
}

class mottar : public QWidget
{
    Q_OBJECT

public:
    explicit mottar(QWidget *parent = nullptr);
    ~mottar();

private slots:
    void on_tilbake_0_motta_clicked();
    void on_x_0_motta_clicked();

    void on_lakkering_clicked();
    void on_elektrokjemisk_metode_clicked();
    void on_kjemisk_metode_clicked();
    void on_herding_clicked();
    void on_annet_clicked();

    void on_tilbake_1_lakk_motta_clicked();
    void on_tilbake_2_elkj_motta_clicked();
    void on_tilbake_3_kj_motta_clicked();
    void on_tilbake_4_herding_motta_clicked();
    void on_tilbake_5_annet_motta_clicked();

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


private:
    Ui::mottar *ui;
    class vaatlakkering_motta _Vaatlakk;                             //objekt for våtlakkering
    class pulverlakkering_motta _Pulverlakk;                         //objekt for pulverlakkering
    class offshore_lakkering_motta _Offshorelakk;                    //objekt for offshore lakkering

    class eloksering_motta _Eloks;                                   //objekt for eloksering (elektrokjemisk metode)
    class kromatering_motta _Kromater;                                   //objekt for kromatering (elektrokjemisk metode)

signals:
    void tilbake_0_motta_clicked();
    void x_0_motta_clicked();
};

#endif // MOTTAR_H
