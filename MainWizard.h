#ifndef MAINWIZARD_H
#define MAINWIZARD_H

#include <QWizard>
#include "SettingSourcesPage.h"
#include "SelectFilesPage.h"
#include "ChooseFilesOrderPage.h"
#include "SaveListFilePage.h"
#include "FinishPage.h"

namespace Ui {
    class MainWizard;
}

class MainWizard : public QWizard
{
    Q_OBJECT
private:
    Ui::MainWizard *mUI;

    SettingSourcesPage *mSettingSourcesPage;
    SelectFilesPage *mSelectFilesPage;
    ChooseFilesOrderPage *mChooseFilesOrderPage;
    SaveListFilePage *mSaveListFilePage;
    FinishPage *mFinishPage;

public:
    explicit MainWizard(QWidget *xParent = 0);
    ~MainWizard();

    int nextId() const;

private slots:
    void helpButton_clicked();
};

#endif // MAINWIZARD_H
