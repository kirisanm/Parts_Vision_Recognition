#ifndef SLIPING_MOTTA_H
#define SLIPING_MOTTA_H

#include <QWidget>

namespace Ui {
class sliping_motta;
}

class sliping_motta : public QWidget
{
    Q_OBJECT

public:
    explicit sliping_motta(QWidget *parent = nullptr);
    ~sliping_motta();

private slots:
    void on_tilbake_0_sliping_bedrifter_clicked();

    void on_thune_clicked();
    void on_tilbake_1_sliping_thune_clicked();

private:
    Ui::sliping_motta *ui;

signals:
    void tilbake_0_sliping_bedrifter_clicked();
};

#endif // SLIPING_MOTTA_H
