#include <QApplication>
#include<bugform.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    bugForm* form= new bugForm();
    form->show();

    return a.exec();
}
