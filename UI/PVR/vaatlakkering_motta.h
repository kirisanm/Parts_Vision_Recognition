#ifndef VAATLAKKERING_MOTTA_H
#define VAATLAKKERING_MOTTA_H

#include <QWidget>

namespace Ui {
class vaatlakkering_motta;
}

class vaatlakkering_motta : public QWidget
{
    Q_OBJECT

public:
    explicit vaatlakkering_motta(QWidget *parent = nullptr);
    ~vaatlakkering_motta();

private slots:
    void on_tilbake_0_vaat_bedrifter_clicked();
    void on_bilskadesenteret_ringerike_clicked();
    void on_lyseng_billakkering_clicked();
    void on_tilbake_1_vaat_bilskade_clicked();
    void on_tilbake_2_vaat_lyseng_clicked();

private:
    Ui::vaatlakkering_motta *ui;

signals:
    void tilbake_0_vaat_bedrifter_clicked();
};

#endif // VAATLAKKERING_MOTTA_H
