#include "calculator.h"

Calculator::Calculator(QWidget *parent) : QWidget(parent)
{
    createWidgets();
    placeWidgets();
    makeConnections();
}

void Calculator::createWidgets(){

    this->setWindowTitle("NumericKeypad");

    //Creating the layouts
    layout = new QVBoxLayout();
    layout->setSpacing(2);

    //grid layout
    grid = new QGridLayout();

    //LCD number
    number = new QLCDNumber();
    number->setDigitCount(9);
    number->setMinimumHeight(80);

    //creating the buttons
    for(int i=0; i < 10; i++)
    {
        digits.push_back(new QPushButton(QString::number(i)));
        digits.back()->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        digits.back()->resize(sizeHint().width(), sizeHint().height());
    }

    //enter button
    enter = new QPushButton("Enter",this);
    enter->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    enter->resize(sizeHint().width(), sizeHint().height());

    //operatiosn buttons
    operations.push_back(new QPushButton("+"));
    operations.push_back(new QPushButton("-"));
    operations.push_back(new QPushButton("*"));
    operations.push_back(new QPushButton("/"));
}

void Calculator::placeWidgets(){

    layout->addWidget(number);
    layout->addLayout(grid);


    //adding the buttons
    for(int i=1; i <10; i++)
        grid->addWidget(digits[i], (i-1)/3, (i-1)%3);


    //Adding the operations
    for(int i=0; i < 4; i++)
        grid->addWidget(operations[i], i, 4);


    //Adding the 0 button
    grid->addWidget(digits[0], 3, 0);
    grid->addWidget(enter, 3, 1, 1,2);

    this->setLayout(layout);
}

void Calculator::makeConnections(){

}
