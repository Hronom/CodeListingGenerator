#include "AboutMyProgram.h"
#include "ui_AboutMyProgram.h"

AboutMyProgram::AboutMyProgram(QWidget *xParent) : QDialog(xParent), mUI(new Ui::AboutMyProgram)
{
    mUI->setupUi(this);

    mUI->programName->setText(tr("Имя программы:")+" Code Listing Generator");
    mUI->programVersion->setText(tr("Версия программы:")+" 0.0.1");
    mUI->programSite->setText(tr("Сайт программы:")+" <a href='http://hronom.github.com/CodeListingGenerator/'>http://hronom.github.com/CodeListingGenerator</a>");

    mUI->programAuthor->setText(tr("Автор:") + " Hronom");
    mUI->authorEmail->setText("Email: <a href='mailto:hronom@gmail.com'>hronom@gmail.com</a>");
    mUI->authorBlog->setText("Blog: <a href='http://hronom.blogspot.com/'>http://hronom.blogspot.com</a>");

    mNewVersionChecker = new NewVersionChecker(this);
    connect(mNewVersionChecker, SIGNAL(versionChecked(QString,QString)),this,SLOT(versionChecked(QString,QString)));
    connect(mNewVersionChecker, SIGNAL(versionNotChecked(QString)),this,SLOT(versionNotChecked(QString)));
}

AboutMyProgram::~AboutMyProgram()
{
    delete mUI;
}

void AboutMyProgram::versionChecked(QString xCurrentVersion, QString xDownloadLink)
{
    if(xCurrentVersion == "0.0.1")
        mUI->actualVersion->setText(tr("У вас последняя версия программы"));
    else
    {
        QString xString;
        xString.append(tr("Актуальная версия:"));
        xString.append(" " + xCurrentVersion + " ");
        xString.append(" <a href='");
        xString.append(xDownloadLink);
        xString.append("'>");
        xString.append(tr("скачать"));
        xString.append("</a>");

        mUI->actualVersion->setText(xString);
    }

    mUI->checkVersionButton->setDisabled(false);
}

void AboutMyProgram::versionNotChecked(QString xError)
{
    mUI->actualVersion->setText(tr("Не удалось проверить наличие новой версии программы.")+"<br>"+tr("Ошибка:")+" "+xError);
    mUI->checkVersionButton->setDisabled(false);
}

void AboutMyProgram::on_checkVersionButton_clicked()
{
    mUI->checkVersionButton->setDisabled(true);
    QString xLink = "https://github.com/downloads/Hronom/CodeListingGenerator/currentVersion";
    mNewVersionChecker->checkVersion(xLink);
    mUI->actualVersion->setText(tr("Проверка наличия новой версии..."));
}
