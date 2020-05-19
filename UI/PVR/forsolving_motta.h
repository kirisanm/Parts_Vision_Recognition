#ifndef FORSOLVING_MOTTA_H
#define FORSOLVING_MOTTA_H

#include <QWidget>

namespace Ui {
class forsolving_motta;
}

class forsolving_motta : public QWidget
{
    Q_OBJECT

public:
    explicit forsolving_motta(QWidget *parent = nullptr);
    ~forsolving_motta();

private slots:
    void on_tilbake_0_forsolving__bedrifter_clicked();

    void on_lie_clicked();
    void on_tilbake_1_forsolving_lie_clicked();

private:
    Ui::forsolving_motta *ui;

signals:
    void tilbake_0_forsolving_bedrifter_clicked();
};

#endif // FORSOLVING_MOTTA_H
