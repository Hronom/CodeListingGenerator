#include <QtGui/QApplication>
#include <QTextCodec>
#include <QLocale>
#include <QTranslator>
#include "MainWizard.h"
#include "GlobalDefinitions.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1251"));//установка нужной кодировки
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));//установка нужной кодировки
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));//установка нужной кодировки для Tr

    QApplication xApp(argc, argv);
    xApp.setApplicationName(program_name);
    xApp.setApplicationVersion(program_version);

    QString xLocale = QLocale::system().name();
    QTranslator xTranslator;
    xTranslator.load(QString("CodeListingGenerator_") + xLocale);
    xApp.installTranslator(&xTranslator);

    MainWizard xMainWizard;
    xMainWizard.show();

    return xApp.exec();
}
