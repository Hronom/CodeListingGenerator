#ifndef SAVELISTINGFILEPAGE_H
#define SAVELISTINGFILEPAGE_H

#include <QWizardPage>

namespace Ui {
    class SaveListingFilePage;
}

class SaveListingFilePage : public QWizardPage
{
    Q_OBJECT
private:
    Ui::SaveListingFilePage *mUI;

public:
    explicit SaveListingFilePage(QWidget *xParent = 0);
    ~SaveListingFilePage();

private slots:
    void on_browseButton_clicked();
};

#endif // SAVELISTINGFILEPAGE_H
