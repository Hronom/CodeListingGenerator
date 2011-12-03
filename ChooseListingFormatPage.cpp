#include "ChooseListingFormatPage.h"
#include "ui_ChooseListingFormatPage.h"
#include <QTextDocument>

ChooseListingFormatPage::ChooseListingFormatPage(QWidget *xParent): QWizardPage(xParent), mUI(new Ui::ChooseListingFormatPage)
{
    mUI->setupUi(this);

    QString xString;
    xString.append("%FileName - " + tr("��� �����") + "<br>");
    xString.append("%FileSuffix - " + tr("���������� �����") + "<br>");
    xString.append("%FileContent - " + tr("���������� �����"));

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
