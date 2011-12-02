#include "MainWizard.h"
#include "ui_MainWizard.h"
#include <QMessageBox>
#include <QPushButton>

MainWizard::MainWizard(QWidget *xParent) : QWizard(xParent), mUI(new Ui::MainWizard)
{
    this->setButtonText(QWizard::NextButton, tr("�����"));
    this->setButtonText(QWizard::CancelButton, tr("������"));
    this->setButtonText(QWizard::HelpButton, tr("� ���������"));
    this->setButtonText(QWizard::FinishButton, tr("�����"));

    mUI->setupUi(this);

    mNewVersionChecker = new NewVersionChecker(this);
    connect(mNewVersionChecker, SIGNAL(versionChecked(QString,QString)),this,SLOT(versionChecked(QString,QString)));
    connect(mNewVersionChecker, SIGNAL(versionNotChecked(QString)),this,SLOT(versionNotChecked(QString)));

    mSelectingSourcesPage = new SelectingSourcesPage(this);
    mSelectingFilesPage = new SelectingFilesPage(this);
    mChooseFilesOrderPage = new ChooseFilesOrderPage(this);
    mSaveListingFilePage = new SaveListingFilePage(this);
    mFinishPage = new FinishPage(this);

    this->setPage(1, mSelectingSourcesPage);
    this->setPage(2, mSelectingFilesPage);
    this->setPage(3, mChooseFilesOrderPage);
    this->setPage(4, mSaveListingFilePage);
    this->setPage(5, mFinishPage);

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
        mFinishPage->setFilesList(mChooseFilesOrderPage->getFilesList());
        return 5;
    default:
        return -1;
    }
}

void MainWizard::versionChecked(QString xCurrentVersion, QString xDownloadLink)
{
    if(xCurrentVersion == "0.0.1")
        QMessageBox::information(this,
                                 tr("�������� ������� ����� ������ ���������"),
                                 tr("� ��� ��������� ������ ���������"));
    else
    {
        QString xString;
        xString.append("<p>");
        xString.append(tr("�������� ����� ������ ���������"));
        xString.append("</p>");

        xString.append("<p>");
        xString.append(tr("�������� ������:"));
        xString.append(" "+xCurrentVersion);
        xString.append("</p>");

        xString.append("<p>");
        xString.append(tr("������ ��� ����������:"));
        xString.append(" <a href='");
        xString.append(xDownloadLink);
        xString.append("'>");
        xString.append(xDownloadLink);
        xString.append("</a>");
        xString.append("</p>");

        QMessageBox::information(this,tr("�������� ������� ����� ������ ���������"),xString);
    }
}

void MainWizard::versionNotChecked(QString xError)
{
    QMessageBox::information(this,
                             tr("�������� ������� ����� ������ ���������"),
                             tr("�� ������� ��������� ������� ����� ������ ���������")+"<br>"+tr("������:")+" "+xError);
}

void MainWizard::helpButton_clicked()
{
    QString xString;
    xString.append("<p><b>Code Listing Generator 0.0.1</b></p>");

    xString.append("<p>");
    xString.append(tr("���� ���������:"));
    xString.append(" <a href='http://hronom.github.com/CodeListingGenerator/'>http://hronom.github.com/CodeListingGenerator</a>");
    xString.append("</p>");

    xString.append("<p>");
    xString.append(tr("�����:"));
    xString.append(" Hronom");
    xString.append("</p>");

    xString.append("<p> Email: <a href='mailto:hronom@gmail.com'>hronom@gmail.com</a></p>");
    xString.append("<p> Blog: <a href='http://hronom.blogspot.com/'>http://hronom.blogspot.com</a></p>");

    QMessageBox *xMessageBox;
    xMessageBox = new QMessageBox(this);
    xMessageBox->setWindowTitle(tr("� ���������"));
    xMessageBox->setIconPixmap(QPixmap(":/main/CodeListingGenerator.png"));
    xMessageBox->setAttribute(Qt::WA_DeleteOnClose, true);
    xMessageBox->setInformativeText(xString);

    QPushButton *xCheckVersionButton;
    xCheckVersionButton = new QPushButton(xMessageBox);
    xCheckVersionButton->setText(tr("��������� ������� ����� ������"));
    connect(xCheckVersionButton,SIGNAL(clicked()),this,SLOT(checkVersionButton_clicked()));
    xMessageBox->addButton(xCheckVersionButton, QMessageBox::ActionRole);
    xMessageBox->addButton(QMessageBox::Ok);

    xMessageBox->show();
}

void MainWizard::checkVersionButton_clicked()
{
    QString xLink = "https://github.com/downloads/Hronom/CodeListingGenerator/currentVersion";
    mNewVersionChecker->checkVersion(xLink);
}
