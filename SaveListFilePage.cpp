#include "SaveListFilePage.h"
#include "ui_SaveListFilePage.h"
#include <QFileDialog>

SaveListFilePage::SaveListFilePage(QWidget *xParent): QWizardPage(xParent), mUI(new Ui::SaveListFilePage)
{
    mUI->setupUi(this);
    this->registerField("SaveFilePath*", mUI->lineEdit);
}

SaveListFilePage::~SaveListFilePage()
{
    delete mUI;
}

void SaveListFilePage::on_browseButton_clicked()
{    
    mUI->lineEdit->setText(QFileDialog::getSaveFileName(this,
                                                        tr("Сохранить файл листинга"),
                                                        "Листинг кода.txt",
                                                        tr("Текстовые файлы (*.txt)")));
}
