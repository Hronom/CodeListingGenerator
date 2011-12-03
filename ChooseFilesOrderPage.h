#ifndef CHOOSEFILESORDERPAGE_H
#define CHOOSEFILESORDERPAGE_H

#include <QWizardPage>

namespace Ui {
    class ChooseFilesOrderPage;
}

class ChooseFilesOrderPage : public QWizardPage
{
    Q_OBJECT
private:
    Ui::ChooseFilesOrderPage *mUI;

public:
    explicit ChooseFilesOrderPage(QWidget *xParent = 0);
    ~ChooseFilesOrderPage();

    void setFilesList(QStringList xFilesList);
    QStringList getFilesList();

private slots:
    void on_upArrowButton_clicked();
    void on_downArrowButton_clicked();
};

#endif // CHOOSEFILESORDERPAGE_H
