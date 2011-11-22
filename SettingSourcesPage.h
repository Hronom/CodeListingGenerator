#ifndef SETTINGSOURCESPAGE_H
#define SETTINGSOURCESPAGE_H

#include <QWizardPage>

namespace Ui {
class SettingSourcesPage;
}

class SettingSourcesPage : public QWizardPage
{
    Q_OBJECT
private:
    Ui::SettingSourcesPage *mUI;

public:
    explicit SettingSourcesPage(QWidget *xParent = 0);
    ~SettingSourcesPage();

private slots:
    void on_toolButton_clicked();
};

#endif // SETTINGSOURCESPAGE_H
