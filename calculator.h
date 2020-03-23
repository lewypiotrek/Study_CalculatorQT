#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

public:
    void InsertValue(double value);
    void UpdateDisplay();
    void UpdateResult();
    void SetDisplay(QString value);

private slots:
    void on_pushButton_clicked();

    void on_buttonAdd_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_17_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_12_clicked();

    void on_pushButton_20_clicked();

private:
    Ui::Calculator *ui;

private:
    QString rightS, leftS, resultS;
    double right,left,result;
    bool first,math, commaL, commaR;
    int operation;

    enum operations{
        add = 0,
        subtract = 1,
        multiplication = 2,
        division = 3,
        exponent = 4,
        modulo =5,
        factorial = 6

    };


};

#endif // CALCULATOR_H
