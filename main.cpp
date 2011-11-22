#include <QtGui/QApplication>
#include <QTextCodec>
#include <QLocale>
#include <QTranslator>
#include "MainWizard.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1251"));//установка нужной кодировки
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));//установка нужной кодировки
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));//установка нужной кодировки для Tr

    QApplication xApp(argc, argv);
    xApp.setApplicationName("CodeListingGenerator");
    xApp.setApplicationVersion("0.0.1");

    QString xLocale = QLocale::system().name();
    QTranslator xTranslator;
    xTranslator.load(QString("CodeListingGenerator_") + xLocale);
    xApp.installTranslator(&xTranslator);

    MainWizard xMainWizard;
    xMainWizard.show();

    return xApp.exec();
}
