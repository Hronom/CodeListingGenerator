#ifndef SELECTFILESPAGE_H
#define SELECTFILESPAGE_H

#include <QWizardPage>
#include <QStringList>

namespace Ui {
    class SelectFilesPage;
}

class SelectFilesPage : public QWizardPage
{
    Q_OBJECT
private:
    Ui::SelectFilesPage *mUI;

public:
    explicit SelectFilesPage(QWidget *xParent = 0);
    ~SelectFilesPage();

    QStringList getFilesList();

private:
    void initializePage();
    void fillFilesList();

private slots:
    void on_addExtensionButton_clicked(); 
    void on_pushButton_clicked();
};

#endif // SELECTFILESPAGE_H
