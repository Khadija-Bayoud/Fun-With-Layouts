#ifndef BUGFORM_H
#define BUGFORM_H

#include <QWidget>
#include<QFormLayout>
#include<QLineEdit>
#include<QTextEdit>
#include<QComboBox>
#include<QPushButton>

class bugForm : public QWidget
{
public:
    explicit bugForm(QWidget *parent = nullptr);

protected:
    void createWidgets();
    void placeWidgets();
    void makeConnections();

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

#endif // BUGFORM_H
