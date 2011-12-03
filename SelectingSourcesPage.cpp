#include "SelectingSourcesPage.h"
#include "ui_SelectingSourcesPage.h"
#include <QFileDialog>
#include <QDir>

SelectingSourcesPage::SelectingSourcesPage(QWidget *xParent) : QWizardPage(xParent), mUI(new Ui::SelectingSourcesPage)
{
    mUI->setupUi(this);
    this->registerField("FolderPath*", mUI->lineEdit);
    this->registerField("LookInSubDirs", mUI->checkBox);
}

SelectingSourcesPage::~SelectingSourcesPage()
{
    delete mUI;
}

void SelectingSourcesPage::on_toolButton_clicked()
{
    mUI->lineEdit->setText((QFileDialog::getExistingDirectory(this, tr("Выбор директории исходников"), mUI->lineEdit->text(),QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks)));
}

