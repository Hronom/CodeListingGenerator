#include "SelectingFilesPage.h"
#include "ui_SelectingFilesPage.h"
#include <QDir>
#include <QDirIterator>
#include <QLabel>

SelectingFilesPage::SelectingFilesPage(QWidget *xParent) : QWizardPage(xParent), mUI(new Ui::SelectingFilesPage)
{
    mUI->setupUi(this);
}

SelectingFilesPage::~SelectingFilesPage()
{
    delete mUI;
}

QStringList SelectingFilesPage::getFilesList()
{
    QStringList xFilesList;

    for(int i=0; i<mUI->listWidget_2->count(); i++)
        xFilesList.append(mUI->listWidget_2->item(i)->text());

    return xFilesList;
}

void SelectingFilesPage::initializePage()
{
    fillFilesList();
}

void SelectingFilesPage::fillFilesList()
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

void SelectingFilesPage::on_addExtensionButton_clicked()
{
    mUI->listWidget->addItem(mUI->lineEdit->text());
    mUI->lineEdit->setText("");

    fillFilesList();
}

void SelectingFilesPage::on_pushButton_clicked()
{
    QListWidgetItem *xListWidgetItem;
    xListWidgetItem = mUI->listWidget->takeItem(mUI->listWidget->currentRow());

    if(xListWidgetItem != 0)
    {
        delete xListWidgetItem;
        fillFilesList();
    }
}
