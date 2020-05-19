#ifndef POLERING_MOTTA_H
#define POLERING_MOTTA_H

#include <QWidget>

namespace Ui {
class polering_motta;
}

class polering_motta : public QWidget
{
    Q_OBJECT

public:
    explicit polering_motta(QWidget *parent = nullptr);
    ~polering_motta();

private slots:
    void on_tilbake_0_polering_bedrifter_clicked();

    void on_tronrud_clicked();
    void on_tilbake_1_polering_tronrud_clicked();

    void on_honefoss_clicked();
    void on_tilbake_2_polering_honefoss_clicked();

private:
    Ui::polering_motta *ui;

signals:
    void tilbake_0_polering_bedrifter_clicked();
};

#endif // POLERING_MOTTA_H
