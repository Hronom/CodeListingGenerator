#include "SelectFilesPage.h"
#include "ui_SelectFilesPage.h"
#include <QDir>
#include <QDirIterator>
#include <QLabel>

SelectFilesPage::SelectFilesPage(QWidget *xParent) : QWizardPage(xParent), mUI(new Ui::SelectFilesPage)
{
    mUI->setupUi(this);
}

SelectFilesPage::~SelectFilesPage()
{
    delete mUI;
}

QStringList SelectFilesPage::getFilesList()
{
    QStringList xFilesList;

    for(int i=0; i<mUI->listWidget_2->count(); i++)
        xFilesList.append(mUI->listWidget_2->item(i)->text());

    return xFilesList;
}

void SelectFilesPage::initializePage()
{
    fillFilesList();
}

void SelectFilesPage::fillFilesList()
{
    mUI->listWidget_2->clear();
    QString xDirectoryPath = this->field("FolderPath").toString();

    QStringList xFilesExtensions;
    for(int i = 0; i < mUI->listWidget->count(); i++)
        xFilesExtensions.append(mUI->listWidget->item(i)->text());

    QDirIterator xDirectoryWalker(xDirectoryPath, xFilesExtensions, QDir::Files | QDir::NoSymLinks, this->field("LookInSubDirs").toBool() == true? QDirIterator::Subdirectories : QDirIterator::NoIteratorFlags);
    while(xDirectoryWalker.hasNext())
    {
        xDirectoryWalker.next();
        mUI->listWidget_2->addItem(QDir::toNativeSeparators(xDirectoryWalker.fileInfo().absoluteFilePath()));
    }
}

void SelectFilesPage::on_addExtensionButton_clicked()
{
    mUI->listWidget->addItem(mUI->lineEdit->text());
    mUI->lineEdit->setText("");

    fillFilesList();
}

void SelectFilesPage::on_pushButton_clicked()
{
    mUI->listWidget->takeItem(mUI->listWidget->currentRow());
}
