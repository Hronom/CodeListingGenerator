#include "MainWizard.h"
#include "ui_MainWizard.h"
#include <QMessageBox>

MainWizard::MainWizard(QWidget *xParent) : QWizard(xParent), mUI(new Ui::MainWizard)
{
    mUI->setupUi(this);

    mSettingSourcesPage = new SettingSourcesPage(this);
    mSelectFilesPage = new SelectFilesPage(this);
    mChooseFilesOrderPage = new ChooseFilesOrderPage(this);
    mSaveListFilePage = new SaveListFilePage(this);
    mFinishPage = new FinishPage(this);

    this->setPage(1, mSettingSourcesPage);
    this->setPage(2, mSelectFilesPage);
    this->setPage(3, mChooseFilesOrderPage);
    this->setPage(4, mSaveListFilePage);
    this->setPage(5, mFinishPage);

    this->connect(this,SIGNAL(helpRequested()),this,SLOT(helpButton_clicked()));
}

MainWizard::~MainWizard()
{
    delete mUI;
}

int MainWizard::nextId() const
{
    switch(this->currentId())
    {
    case 1:
        return 2;
    case 2:
        mChooseFilesOrderPage->setFilesList(mSelectFilesPage->getFilesList());
        return 3;
    case 3:
        return 4;
    case 4:
        mFinishPage->setFilesList(mChooseFilesOrderPage->getFilesList());
        return 5;
    default:
        return -1;
    }
}

void MainWizard::helpButton_clicked()
{
    QString xString;
    xString.append("<b>Code Listing Generator 0.0.1</b>");
    xString.append("<hr>");
    xString.append(tr("Author: "));
    xString.append("Hronom");
    xString.append("<br>");
    xString.append("email: hronom@gmail.com");

    QMessageBox::about(this, tr("Справка"), xString);
}
