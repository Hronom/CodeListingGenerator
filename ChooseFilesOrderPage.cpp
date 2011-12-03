#include "ChooseFilesOrderPage.h"
#include "ui_ChooseFilesOrderPage.h"

ChooseFilesOrderPage::ChooseFilesOrderPage(QWidget *xParent): QWizardPage(xParent), mUI(new Ui::ChooseFilesOrderPage)
{
    mUI->setupUi(this);
}

ChooseFilesOrderPage::~ChooseFilesOrderPage()
{
    delete mUI;
}

void ChooseFilesOrderPage::setFilesList(QStringList xFilesList)
{
    mUI->listWidget->clear();
    mUI->listWidget->addItems(xFilesList);
}

QStringList ChooseFilesOrderPage::getFilesList()
{
    QStringList xFilesList;

    for(int i=0; i<mUI->listWidget->count(); i++)
        xFilesList.append(mUI->listWidget->item(i)->text());

    return xFilesList;
}

void ChooseFilesOrderPage::on_upArrowButton_clicked()
{
    int xCurrentRow = mUI->listWidget->currentRow();

    if(xCurrentRow >= 0 && xCurrentRow - 1 >= -1)
    {
        QListWidgetItem *xCurrentItem =  mUI->listWidget->takeItem(xCurrentRow);
        mUI->listWidget->insertItem(xCurrentRow - 1, xCurrentItem);
        mUI->listWidget->setCurrentItem(xCurrentItem);
    }
}

void ChooseFilesOrderPage::on_downArrowButton_clicked()
{
    int xCurrentRow = mUI->listWidget->currentRow();

    if(xCurrentRow >= 0 && xCurrentRow + 1 <= mUI->listWidget->count()-1)
    {
        QListWidgetItem *xCurrentItem =  mUI->listWidget->takeItem(xCurrentRow);
        mUI->listWidget->insertItem(xCurrentRow + 1, xCurrentItem);
        mUI->listWidget->setCurrentItem(xCurrentItem);
    }
}
