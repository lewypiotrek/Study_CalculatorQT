#include "calculator.h"
#include "ui_calculator.h"
#include <iostream>

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);

   first = true;
   math= false;

   leftS = "0";
   rightS = "0";

   left = 0;
   right = 0;

   result = 0;


}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::InsertValue(double value)
{
    if(first == true)
    {
        if(left == 0)
        {
            left = value;
            leftS = QString::number(value);
            UpdateDisplay();
        }
        else if (left != 0)
        {
            leftS = leftS + QString::number(value);
            left = leftS.toInt();
            UpdateDisplay();
        }

        math = true;
    }
    else
    {
        if(right == 0)
        {
            right = value;
            rightS = QString::number(value);
            UpdateDisplay();
        }
        else if (right != 0)
        {
            leftS = leftS + QString::number(value);
            right = leftS.toInt();
            UpdateDisplay();
        }
    }


}

void Calculator::UpdateDisplay()
{
    if(first == true)
    {
        ui->lcdNumber->display(leftS);
    }
    else
    {
        ui->lcdNumber->display(rightS);
    }

}

void Calculator::UpdateResult()
{
    resultS = QString::number(result);
    ui->lcdNumber->display(resultS);
    left = 0;
    right = 0;
    leftS= "0";
    rightS= "0";
    first = true;
    math = false;
}

void Calculator::SetDisplay(QString value)
{
     ui->lcdNumber->display(value);
}


// ------ CALCULATION ------

// RESULT Button
void Calculator::on_pushButton_16_clicked()
{

    first = true;

    if(math)
    {
        try{

            switch(operation)
            {

            case 0: // add
                result = left + right;
                UpdateResult();
                break;

            case 1: // subtract
                result = left - right;
                UpdateResult();
                break;

            case 2: // multiplication
                result = left*right;
                UpdateResult();
                break;

            case 3: // division
                if(left ==0 || right == 0)
                {
                   QString error = "Wrong variables! You're trying to divide by 0";
                   throw error;
                }
                result =left/right;
                UpdateResult();
                break;

            case 4: // exponent
                if( right == 0)
                {
                    result = 1;
                    UpdateResult();
                    break;
                }
                else
                {
                    result = left;
                    for(int i = 0; i < right-1; i++)
                    {
                        result = result * left;
                    }
                    UpdateResult();
                    break;
                }

            case 5: // modulo
                result = (int)left % (int)right;
                UpdateResult();
                break;

            case 6: // factorial
                result = 1;
                for(int i = (int)left; i > 1; i--)
                {
                    result*=i;
                }
                UpdateResult();
                break;



           }//switch
        }//try
        catch(QString &e)
        {
            QMessageBox error;
            error.setText(e);
            error.exec();
        }
    }
}
// ------ ------ ------ ------ ------ ------


// ------ NUMBERS DRIVER ------
void Calculator::on_pushButton_clicked()
{
    InsertValue(1);
}

void Calculator::on_pushButton_2_clicked()
{
    InsertValue(2);
}

void Calculator::on_pushButton_3_clicked()
{
    InsertValue(3);
}

void Calculator::on_pushButton_4_clicked()
{
    InsertValue(4);
}

void Calculator::on_pushButton_5_clicked()
{
    InsertValue(5);
}

void Calculator::on_pushButton_6_clicked()
{
    InsertValue(6);
}

void Calculator::on_pushButton_7_clicked()
{
    InsertValue(7);
}

void Calculator::on_pushButton_8_clicked()
{
    InsertValue(8);
}

void Calculator::on_pushButton_9_clicked()
{
    InsertValue(9);
}

void Calculator::on_pushButton_10_clicked()
{
    InsertValue(0);
}
// ------ ------ ------ ------ ------ ------


// ------ OPERATIONS DRIVER ------

// CLEAR
void Calculator::on_pushButton_11_clicked()
{
    first = true;
    left = 0;
    leftS ="0";
    right = 0;
    rightS = "0";
    UpdateDisplay();
}
// ADD
void Calculator::on_buttonAdd_clicked()
{
    if(math)
    {
        operation = add;
        first = false;
        UpdateDisplay();
    }
}
// SUBTRACT
void Calculator::on_pushButton_13_clicked()
{
    if(math)
    {
        operation = subtract;
        first = false;
        UpdateDisplay();
    }
}
// MULTIPLICATION
void Calculator::on_pushButton_14_clicked()
{
    if(math)
    {
        operation = multiplication;
        first = false;
        UpdateDisplay();
    }
}
// DIVISION
void Calculator::on_pushButton_15_clicked()
{
    if(math)
    {
        operation = division;
        first = false;
        UpdateDisplay();
    }
}
// EXPONENT
void Calculator::on_pushButton_19_clicked()
{
    if(math)
    {
        operation = exponent;
        first = false;
        UpdateDisplay();
    }
}
// MODULO
void Calculator::on_pushButton_18_clicked()
{
    if(math)
    {
        operation = modulo;
        first = false;
        UpdateDisplay();
    }

}
// FACTORIAL
void Calculator::on_pushButton_17_clicked()
{
    if(math)
    {
        operation = factorial;
        first = false;
        UpdateDisplay();
    }
}
// CONVERT
void Calculator::on_comboBox_activated(const QString &arg1)
{
    if( arg1 == "BIN")
        ui->lcdNumber->setMode(ui->lcdNumber->Bin);
    else if(arg1 == "DEC")
        ui->lcdNumber->setMode(ui->lcdNumber->Dec);
    else if (arg1 == "HEX")
        ui->lcdNumber->setMode(ui->lcdNumber->Hex);
    else if (arg1 == "OCT")
        ui->lcdNumber->setMode(ui->lcdNumber->Oct);

}
// SIGN CHANGE
void Calculator::on_pushButton_12_clicked()
{
    if (first)
    {
        left = left*(-1);
        leftS = QString::number(left);
        UpdateDisplay();

    }
    else
    {
        right = right*(-1);
        rightS = QString::number(right);
        UpdateDisplay();
    }
}
