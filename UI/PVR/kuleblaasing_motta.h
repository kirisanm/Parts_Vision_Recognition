#ifndef KULEBLAASING_MOTTA_H
#define KULEBLAASING_MOTTA_H

#include <QWidget>

namespace Ui {
class kuleblaasing_motta;
}

class kuleblaasing_motta : public QWidget
{
    Q_OBJECT

public:
    explicit kuleblaasing_motta(QWidget *parent = nullptr);
    ~kuleblaasing_motta();

private slots:
    void on_tilbake_0_kuleblaasing_bedrifter_clicked();

private:
    Ui::kuleblaasing_motta *ui;

signals:
    void tilbake_0_kuleblaasing_bedrifter_clicked();
};

#endif // KULEBLAASING_MOTTA_H
