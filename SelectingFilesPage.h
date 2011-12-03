#ifndef SELECTINGFILESPAGE_H
#define SELECTINGFILESPAGE_H

#include <QWizardPage>
#include <QStringList>

namespace Ui {
    class SelectingFilesPage;
}

class SelectingFilesPage : public QWizardPage
{
    Q_OBJECT
private:
    Ui::SelectingFilesPage *mUI;

public:
    explicit SelectingFilesPage(QWidget *xParent = 0);
    ~SelectingFilesPage();

    QStringList getFilesList();

private:
    void initializePage();
    void fillFilesList();

private slots:
    void on_addExtensionButton_clicked(); 
    void on_pushButton_clicked();
};

#endif // SELECTINGFILESPAGE_H
