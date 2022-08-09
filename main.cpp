#include "loginwidget.h"

#include <QApplication>
#include"managegui.h"
int main(int argc, char *argv[])
{
    ManageGui *m_pManage = new ManageGui;
    QApplication a(argc, argv);
    LoginWidget w(m_pManage);
    w.show();
    return a.exec();
}
