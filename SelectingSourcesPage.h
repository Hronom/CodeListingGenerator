#ifndef SELECTINGSOURCESPAGE_H
#define SELECTINGSOURCESPAGE_H

#include <QWizardPage>

namespace Ui {
class SelectingSourcesPage;
}

class SelectingSourcesPage : public QWizardPage
{
    Q_OBJECT
private:
    Ui::SelectingSourcesPage *mUI;

public:
    explicit SelectingSourcesPage(QWidget *xParent = 0);
    ~SelectingSourcesPage();

private slots:
    void on_toolButton_clicked();
};

#endif // SELECTINGSOURCESPAGE_H
