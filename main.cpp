#include <QtGui/QApplication>
#include <QTextCodec>
#include "MainWizard.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1251"));//установка нужной кодировки
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));//установка нужной кодировки
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));//установка нужной кодировки для Tr

    QApplication xApp(argc, argv);
    MainWizard xMainWizard;
    xMainWizard.show();

    return xApp.exec();
}
