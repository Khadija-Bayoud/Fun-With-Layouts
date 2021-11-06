#ifndef DIALOG1_H
#define DIALOG1_H

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

#endif // DIALOG1_H
