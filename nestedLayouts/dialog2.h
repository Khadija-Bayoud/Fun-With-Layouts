#ifndef DIALOG2_H
#define DIALOG2_H

#include <QWidget>
#include<QLineEdit>
#include<QLabel>
#include<QPushButton>
#include<QCheckBox>

class Dialog2 : public QWidget
{
public:
    explicit Dialog2(QWidget *parent = nullptr);

protected:
    void createWidgets();
    void placeWidgets();
    void makeConnections();

protected:
    QLineEdit* edit;

    QLabel* name;

    QCheckBox* b1;
    QCheckBox* b2;

    QPushButton* search;
    QPushButton* close;
};

#endif // DIALOG2_H
