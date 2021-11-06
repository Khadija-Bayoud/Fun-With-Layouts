#include "dialog2.h"
#include<QHBoxLayout>
#include<QVBoxLayout>

Dialog2::Dialog2(QWidget *parent) : QWidget(parent)
{
    createWidgets();
    placeWidgets();
    makeConnections();
}

void Dialog2::createWidgets(){

    this->setWindowTitle("NestedLayout test");

    name = new QLabel("Name:");
    edit = new QLineEdit();

    search = new QPushButton("Search");
    close = new QPushButton("Close");

    b1 = new QCheckBox("Match case");
    b2 = new QCheckBox("Search backward");

}

void Dialog2::placeWidgets(){
    auto mainLayout = new QHBoxLayout();
    auto topLeftLayout = new QHBoxLayout();
    auto leftLayout = new QVBoxLayout();
    auto rightLayout = new QVBoxLayout();

    topLeftLayout->addWidget(name);
    topLeftLayout->addWidget(edit);

    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(b1);
    leftLayout->addWidget(b2);

    rightLayout->addWidget(search);
    rightLayout->addWidget(close);
    rightLayout->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::Expanding));

    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    this->setLayout(mainLayout);
}

void Dialog2::makeConnections(){
    connect(close, &QPushButton::clicked, this, exit);
}
