#include "FinishPage.h"
#include "ui_FinishPage.h"
#include <QFile>
#include <QFileInfo>
#include <QTextStream>

FinishPage::FinishPage(QWidget *xParent): QWizardPage(xParent), mUI(new Ui::FinishPage)
{
    mUI->setupUi(this);
}

FinishPage::~FinishPage()
{
    delete mUI;
}

void FinishPage::initializePage()
{
    bool xTry;
    QFile xListingFile;
    xListingFile.setFileName(this->field("SaveFilePath").toString());
    xTry = xListingFile.open(QIODevice::WriteOnly);

    for(int i=0; i<mStringList.count(); i++)
    {
        QFileInfo xFileInfo(mStringList[i]);
        QFile xSourceFile(mStringList[i]);

        xTry = xSourceFile.open(QIODevice::ReadOnly);
        QString xString = mFormatedString;
        xString.replace("%FileName", xFileInfo.baseName());
        xString.replace("%FileSuffix", xFileInfo.suffix());
        xString.replace("%FileContent", xSourceFile.readAll());
        xListingFile.write(xString.toAscii());
        xSourceFile.close();
    }

    xListingFile.close();

    if(xTry == true)
        mUI->label->setText("<b>"+tr("Работа завершена без ошибок.")+"</b>");
    else
        mUI->label->setText("<b>"+tr("Работа завершена с ошибками.")+"</b>");
}

void FinishPage::setFilesList(QStringList xStringList)
{
    mStringList = xStringList;
}

void FinishPage::setFormatedString(QString xString)
{
    mFormatedString = xString;
}
