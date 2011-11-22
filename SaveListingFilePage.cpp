#include "SaveListingFilePage.h"
#include "ui_SaveListingFilePage.h"
#include <QFileDialog>

SaveListingFilePage::SaveListingFilePage(QWidget *xParent): QWizardPage(xParent), mUI(new Ui::SaveListingFilePage)
{
    mUI->setupUi(this);
    this->registerField("SaveFilePath*", mUI->lineEdit);
}

SaveListingFilePage::~SaveListingFilePage()
{
    delete mUI;
}

void SaveListingFilePage::on_browseButton_clicked()
{    
    mUI->lineEdit->setText(QFileDialog::getSaveFileName(this,
                                                        tr("Сохранить файл листинга"),
                                                        "Листинг кода.txt",
                                                        tr("Текстовые файлы (*.txt)")));
}
