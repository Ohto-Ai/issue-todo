#include "IssuePannel.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IssuePannel w;
    w.show();
    return a.exec();
}
