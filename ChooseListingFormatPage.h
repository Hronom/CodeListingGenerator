#ifndef CHOOSELISTINGFORMATPAGE_H
#define CHOOSELISTINGFORMATPAGE_H

#include <QWizardPage>

namespace Ui {
    class ChooseListingFormatPage;
}

class ChooseListingFormatPage : public QWizardPage
{
    Q_OBJECT
private:
    Ui::ChooseListingFormatPage *mUI;

public:
    explicit ChooseListingFormatPage(QWidget *xParent = 0);
    ~ChooseListingFormatPage();

    QString getFormatedString();
};

#endif // CHOOSELISTINGFORMATPAGE_H
