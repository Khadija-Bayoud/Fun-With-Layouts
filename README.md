<h1 align="center">Homework Fun With Layout</h1>

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
  
  Qt includes a set of layout management classes that are used to describe how widgets are laid out in an application's user interface. These layouts automatically position   and   resize widgets when the amount of space available for them changes, ensuring that they are consistently arranged and that the user interface as a whole remains usable. Check the   full documentation [here](https://doc.qt.io/qt-5/layout.html). <br>
The goal of this homework is to apply the gained knowledge in C++ to create and manipulate forms.
  
  ### Requirements
  
  This homework requires installing and configuring the QtCreator. It is an Integrated Development Environment (IDE) that assists you in all stages (writing, compilation,    debugging). <br>
Follow the instructions in the [installation guide](https://doc.qt.io/qt-5/gettingstarted.html) choosing your operating system. <br>
If you want to test your configuration:
1. Launch QtCreator.
2. Create a new project.
3. Specify ```No Qt project```
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

































  
