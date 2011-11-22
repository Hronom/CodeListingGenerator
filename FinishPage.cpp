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
    QFile xListingFile;
    xListingFile.setFileName(this->field("SaveFilePath").toString());
    xListingFile.open(QIODevice::WriteOnly);
    QTextStream xFileStream(&xListingFile);

    for(int i=0; i<mStringList.count(); i++)
    {
        QFileInfo xFileInfo(mStringList[i]);
        QFile xSourceFile(mStringList[i]);

        xSourceFile.open(QIODevice::ReadOnly);
        if(i != 0) xFileStream<<endl;
        xFileStream<<xFileInfo.fileName().toAscii();
        xFileStream<<endl;
        xFileStream<<xSourceFile.readAll();
        xSourceFile.close();
    }

    xListingFile.close();
}

void FinishPage::setFilesList(QStringList xStringList)
{
    mStringList = xStringList;
}
