#ifndef NITRERING_MOTTA_H
#define NITRERING_MOTTA_H

#include <QWidget>

namespace Ui {
class nitrering_motta;
}

class nitrering_motta : public QWidget
{
    Q_OBJECT

public:
    explicit nitrering_motta(QWidget *parent = nullptr);
    ~nitrering_motta();

private slots:
    void on_tilbake_0_nitrering_bedrifter_clicked();

    void on_thune_produkter_raufoss_clicked();
    void on_tilbake_1_nitrering_thune_clicked();

    void on_bodycote_clicked();
    void on_tilbake_2_nitrering_bodycote_clicked();

private:
    Ui::nitrering_motta *ui;

signals:
    void tilbake_0_nitrering_bedrifter_clicked();
};

#endif // NITRERING_MOTTA_H
