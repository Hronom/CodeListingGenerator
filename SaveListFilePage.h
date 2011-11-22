#ifndef SAVELISTFILEPAGE_H
#define SAVELISTFILEPAGE_H

#include <QWizardPage>

namespace Ui {
    class SaveListFilePage;
}

class SaveListFilePage : public QWizardPage
{
    Q_OBJECT
private:
    Ui::SaveListFilePage *mUI;

public:
    explicit SaveListFilePage(QWidget *xParent = 0);
    ~SaveListFilePage();

private slots:
    void on_browseButton_clicked();
};

#endif // SAVELISTFILEPAGE_H
