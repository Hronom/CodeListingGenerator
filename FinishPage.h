#ifndef FINISHPAGE_H
#define FINISHPAGE_H

#include <QWizardPage>

namespace Ui {
class FinishPage;
}

class FinishPage : public QWizardPage
{
    Q_OBJECT
private:
    Ui::FinishPage *mUI;
    QStringList mStringList;
    QString mFormatedString;

public:
    explicit FinishPage(QWidget *xParent = 0);
    ~FinishPage();

    void initializePage();
    void setFilesList(QStringList xStringList);
    void setFormatedString(QString xString);
};

#endif // FINISHPAGE_H
