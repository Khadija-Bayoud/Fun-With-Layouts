#include "bugform.h"
#include<QVBoxLayout>
#include<QHBoxLayout>

bugForm::bugForm(QWidget *parent) : QWidget(parent)
{
    createWidgets();
    placeWidgets();
    makeConnections();
}

void bugForm::createWidgets(){

    this->setWindowTitle("Report Bug");

    formLayout = new QFormLayout;

    name = new QLineEdit();
    company = new QLineEdit();
    phone = new QLineEdit();
    email = new QLineEdit();
    bug = new QLineEdit();
    summary = new QTextEdit();

    reproducibility = new QComboBox();
    reproducibility->addItem("Always");
    reproducibility->addItem("Sometimes");
    reproducibility->addItem("Rarely");

    reset = new QPushButton("Reset");
    submit = new QPushButton("Submit Bug Report");
    cancel = new QPushButton("Don't Submit");

}

void bugForm::placeWidgets(){

    auto mainLayout = new QVBoxLayout();
    auto layout = new QHBoxLayout();

    formLayout->addRow("Name:", name);
    formLayout->addRow("Company:", company);
    formLayout->addRow("Phone:", phone);
    formLayout->addRow("Email:", email);
    formLayout->addRow("Problem Title:", bug);
    formLayout->addRow("Summary Information:", summary);
    formLayout->addRow("Reproducibility:", reproducibility);

    layout->addWidget(reset);
    layout->addSpacerItem(new QSpacerItem(200, 20, QSizePolicy::Expanding));
    layout->addWidget(submit);
    layout->addWidget(cancel);

    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(reproducibility);
    mainLayout->addLayout(layout);

    this->setLayout(mainLayout);
}

void bugForm::makeConnections(){

}
