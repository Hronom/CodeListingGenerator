#include "ChooseListingFormatPage.h"
#include "ui_ChooseListingFormatPage.h"
#include <QTextDocument>

ChooseListingFormatPage::ChooseListingFormatPage(QWidget *xParent): QWizardPage(xParent), mUI(new Ui::ChooseListingFormatPage)
{
    mUI->setupUi(this);

    QString xString;
    xString.append("%FileName - " + tr("Имя файла") + "<br>");
    xString.append("%FileSuffix - " + tr("Расширение файла") + "<br>");
    xString.append("%FileContent - " + tr("Содержание файла"));

    mUI->noteLabel->setText(xString);
}

ChooseListingFormatPage::~ChooseListingFormatPage()
{
    delete mUI;
}

QString ChooseListingFormatPage::getFormatedString()
{
    return mUI->plainTextEdit->toPlainText();
}
