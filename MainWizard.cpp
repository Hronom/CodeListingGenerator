#include "MainWizard.h"
#include "ui_MainWizard.h"
#include "AboutMyProgram.h"

MainWizard::MainWizard(QWidget *xParent) : QWizard(xParent), mUI(new Ui::MainWizard)
{
    this->setButtonText(QWizard::NextButton, tr("Далее"));
    this->setButtonText(QWizard::BackButton, tr("Назад"));
    this->setButtonText(QWizard::CancelButton, tr("Отмена"));
    this->setButtonText(QWizard::HelpButton, tr("О программе"));
    this->setButtonText(QWizard::FinishButton, tr("Финиш"));

    mUI->setupUi(this);

    mSelectingSourcesPage = new SelectingSourcesPage(this);
    mSelectingFilesPage = new SelectingFilesPage(this);
    mChooseFilesOrderPage = new ChooseFilesOrderPage(this);
    mChooseListingFormatPage = new ChooseListingFormatPage(this);
    mSaveListingFilePage = new SaveListingFilePage(this);
    mFinishPage = new FinishPage(this);

    this->setPage(1, mSelectingSourcesPage);
    this->setPage(2, mSelectingFilesPage);
    this->setPage(3, mChooseFilesOrderPage);
    this->setPage(4, mChooseListingFormatPage);
    this->setPage(5, mSaveListingFilePage);
    this->setPage(6, mFinishPage);

    connect(this,SIGNAL(helpRequested()),this,SLOT(helpButton_clicked()));
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
        mChooseFilesOrderPage->setFilesList(mSelectingFilesPage->getFilesList());
        return 3;
    case 3:
        return 4;
    case 4:
        return 5;
    case 5:
        mFinishPage->setFilesList(mChooseFilesOrderPage->getFilesList());
        mFinishPage->setFormatedString(mChooseListingFormatPage->getFormatedString());
        return 6;
    default:
        return -1;
    }
}

void MainWizard::helpButton_clicked()
{
    AboutMyProgram *xAboutMyProgram;
    xAboutMyProgram = new AboutMyProgram(this);
    xAboutMyProgram->setAttribute(Qt::WA_DeleteOnClose, true);
    xAboutMyProgram->show();
}
