#include <QtGui/QApplication>
#include <QTextCodec>
#include "MainWizard.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1251"));//��������� ������ ���������
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));//��������� ������ ���������
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));//��������� ������ ��������� ��� Tr

    QApplication xApp(argc, argv);
    MainWizard xMainWizard;
    xMainWizard.show();

    return xApp.exec();
}
