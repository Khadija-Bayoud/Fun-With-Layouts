#include <QApplication>
#include"dialog2.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog2* dialog = new Dialog2();
    dialog->show();

    return a.exec();
}
