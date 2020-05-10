#ifndef KULEBLAASING_SEND_H
#define KULEBLAASING_SEND_H

#include <QWidget>

namespace Ui {
class kuleblaasing_send;
}

class kuleblaasing_send : public QWidget
{
    Q_OBJECT

public:
    explicit kuleblaasing_send(QWidget *parent = nullptr);
    ~kuleblaasing_send();

private slots:
    void on_tilbake_0_kuleblaasing_bedrifter_clicked();

private:
    Ui::kuleblaasing_send *ui;

signals:
    void tilbake_0_kuleblaasing_bedrifter_clicked();
};

#endif // KULEBLAASING_SEND_H
