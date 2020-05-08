#ifndef MOTTAR_H
#define MOTTAR_H

#include <QWidget>

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

private:
    Ui::mottar *ui;

signals:
    void tilbake_0_motta_clicked();
    void x_0_motta_clicked();
};

#endif // MOTTAR_H
