#include <QApplication>
#include"dialog1.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog1* diag = new Dialog1();
    diag->show();

    return a.exec();
}
