<h1 align="center">Fun With Layouts</h1>

<p align="center">
  <img align="center" width="70%" height="60%" src="https://user-images.githubusercontent.com/72691265/140589171-2bfe87fc-c738-442e-b0d5-9f2cfecd1139.png"/>
</p>

## Table of content 
  * [Getting Started](#getting-started)
     * [About the homework](#about-the-homework)
     * [Requirements](#requirements)
  * [Experimenting with QHBoxLayout](#experimenting-with-qhboxlayout)
  * [Nested Layouts](#nested-layouts)
  * [Bug report Form](#bug-report-form)
  * [Grid Layout](#grid-layout)
  * [Conclusion](#conclusion)   
  
  ## Getting Started
  
  ### About the homework
  
  Qt includes a set of layout management classes that are used to describe how widgets are laid out in an application's user interface. These layouts automatically position   and resize widgets when the amount of space available for them changes, ensuring that they are consistently arranged and that the user interface as a whole remains usable. Check the   full documentation [here](https://doc.qt.io/qt-5/layout.html). <br>
The goal of this homework is to apply the gained knowledge in C++ to create and manipulate forms.
  
  ### Requirements
  
  This homework requires installing and configuring the QtCreator. It is an Integrated Development Environment (IDE) that assists you in all stages (writing, compilation,    debugging). <br>
Follow the instructions in the [installation guide](https://doc.qt.io/qt-5/gettingstarted.html) choosing your operating system. <br>
If you want to test your configuration:
1. Launch QtCreator.
2. Create a new project.
3. Specify ```No Qt project``
4. For the configuration choose ```cmake```
5. If you use ```git```, you can choose it to manage your program versions.
6. Build your program.
7. Read and understand the contents of the ```CMakeLists.txt``` configuration file.

## Experimenting with QHBoxLayout

This part requires creating the following window :
<p align="center">
  <img align="center" src="https://user-images.githubusercontent.com/72691265/140609388-a95dca42-2b4c-4215-ad1c-797f43f7fd06.png">
</p>

Here is the Code : <br>
```dialog1.h```
```cpp
#include <QWidget>
#include<QLineEdit>
#include<QLabel>
#include<QPushButton>

class Dialog1 : public QWidget
{
public:
    explicit Dialog1(QWidget *parent = nullptr);

protected:
    void createWidget();
    void placeWidget();
    void makeConnexion();

protected:
    QLineEdit* name;
    QLabel* label;
    QPushButton* search;
};
```
```dialog1.cpp```
```cpp
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

void Dialog1::makeConnexion(){}
```

```main.cpp```
```cpp
#include <QApplication>
#include"dialog1.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog1* diag = new Dialog1();
    diag->show();

    return a.exec();
}
```

## Nested Layouts
Just as widgets can contain other widgets, layouts can be used to provide different levels of grouping for widgets. Here, we want to display a label alongside a line edit at the top-left of a window, above two checkBox buttons, and display two pushButtons at the top-right of the window, as follow.

<p align="center">
  <img align="center" src="https://user-images.githubusercontent.com/72691265/140610460-439a00e3-0f15-4519-80c6-19a2b95753a7.png">
</p>

```dialog2.h```
```cpp
//include, constructor and methods go here.
protected:
    QLineEdit* edit;

    QLabel* name;

    QCheckBox* b1;
    QCheckBox* b2;

    QPushButton* search;
    QPushButton* close;
};
```
```dialog2.cpp```
```cpp
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
```

## Bug Report Form
The goal of this part is to create a form to report a Bug problem as follow :
<p align="center">
  <img align="center" src="https://user-images.githubusercontent.com/72691265/140612096-33e375ed-b878-456e-bb19-b0b556fb56e7.png">
</p>

```bugform.h```
```cpp
protected:
    QFormLayout* formLayout;

    QLineEdit* name;
    QLineEdit* company;
    QLineEdit* phone;
    QLineEdit* email;
    QLineEdit* bug;
    QTextEdit* summary;

    QComboBox* reproducibility;

    QPushButton* reset;
    QPushButton* submit;
    QPushButton* cancel;
};
```
```bugform.cpp```
```cpp
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
void bugForm::makeConnections(){}
```

## Grid Layout
As a final task in this homework, we will visit an important layout, the [QGridLayout](https://doc.qt.io/qt-5/qgridlayout.html) , to create the following calculator:
<p align="center">
  <img align="center" src="https://user-images.githubusercontent.com/72691265/140612550-43631b18-1e3e-4bed-8b47-82d7436af069.png">
</p>

```calculator.h```
```cpp
protected:
    QVBoxLayout *layout;        //main layout for the button
    QGridLayout* grid;
    QLCDNumber* number;

    QVector<QPushButton*> digits;  //Vector for the digits
    QVector<QPushButton*> operations; //operation buttons
    QPushButton *enter; // enter button
};
```
```calculator.cpp```
```cpp
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

void Calculator::makeConnections(){}
```
## Conclusion
To sum up, understanding layouts management is fundamental when it comes to creating user-friendly, engaging designs, particularly in the realms of web design and advertising. <br>
In this lab, we have only created the forms. In the next lab, we will implement functional windows. :fire: :fire: :fire: :octocat:
