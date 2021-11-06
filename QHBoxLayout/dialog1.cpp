#include "dialog1.h"
#include"QHBoxLayout"

Dialog1::Dialog1(QWidget *parent) : QWidget(parent)
{   
    createWidget();
    placeWidget();
    makeConnexion();
}

void Dialog1::createWidget(){

     label = new QLabel("Name");
     name = new QLineEdit();
     search = new QPushButton("Search");
     this->setWindowTitle("HBoxLayout test");
}

void Dialog1::placeWidget(){

    auto layout = new QHBoxLayout();
    this->setLayout(layout);
    layout->addWidget(label);
    layout->addWidget(name);
    layout->addWidget(search);
}

void Dialog1::makeConnexion(){

}
