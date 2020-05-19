#ifndef GALVANISERING_MOTTA_H
#define GALVANISERING_MOTTA_H

#include <QWidget>

namespace Ui {
class galvanisering_motta;
}

class galvanisering_motta : public QWidget
{
    Q_OBJECT

public:
    explicit galvanisering_motta(QWidget *parent = nullptr);
    ~galvanisering_motta();

private slots:
    void on_tilbake_0_galvanisering_bedrifter_clicked();

    void on_br_berntsen_clicked();
    void on_tilbake_1_galvanisering_br_berntsen_clicked();

    void on_gundersen_galvano_clicked();
    void on_tilbake_2_galvanisering_gundersen_clicked();

    void on_duozink_clicked();
    void on_tilbake_3_galvanisering_duozink_clicked();

private:
    Ui::galvanisering_motta *ui;

signals:
    void tilbake_0_galvanisering_bedrifter_clicked();
};

#endif // GALVANISERING_MOTTA_H
