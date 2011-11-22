#include "SettingSourcesPage.h"
#include "ui_SettingSourcesPage.h"
#include <QFileDialog>
#include <QDir>

SettingSourcesPage::SettingSourcesPage(QWidget *xParent) : QWizardPage(xParent), mUI(new Ui::SettingSourcesPage)
{
    mUI->setupUi(this);
    this->registerField("FolderPath*", mUI->lineEdit);
    this->registerField("LookInSubDirs", mUI->checkBox);
}

SettingSourcesPage::~SettingSourcesPage()
{
    delete mUI;
}

void SettingSourcesPage::on_toolButton_clicked()
{
    mUI->lineEdit->setText((QFileDialog::getExistingDirectory(this, tr("Выбор директории исходников"), mUI->lineEdit->text(),QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks)));
}

