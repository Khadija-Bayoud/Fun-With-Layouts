#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include<QGridLayout>
#include<QLCDNumber>
#include<QPushButton>
#include <QVector>

class Calculator : public QWidget
{
public:
    explicit Calculator(QWidget *parent = nullptr);

protected:
    void createWidgets();
    void placeWidgets();
    void makeConnections();

protected:

    QVBoxLayout *layout;        //main layout for the button
    QGridLayout* grid;
    QLCDNumber* number;

    QVector<QPushButton*> digits;  //Vector for the digits
    QVector<QPushButton*> operations; //operation buttons
    QPushButton *enter; // enter button
};

#endif // CALCULATOR_H
