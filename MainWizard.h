#ifndef MAINWIZARD_H
#define MAINWIZARD_H

#include <QWizard>
#include "SelectingSourcesPage.h"
#include "SelectingFilesPage.h"
#include "ChooseFilesOrderPage.h"
#include "SaveListingFilePage.h"
#include "FinishPage.h"
#include "NewVersionChecker.h"

namespace Ui {
class MainWizard;
}

class MainWizard : public QWizard
{
    Q_OBJECT
private:
    Ui::MainWizard *mUI;

    NewVersionChecker *mNewVersionChecker;

    SelectingSourcesPage *mSelectingSourcesPage;
    SelectingFilesPage *mSelectingFilesPage;
    ChooseFilesOrderPage *mChooseFilesOrderPage;
    SaveListingFilePage *mSaveListingFilePage;
    FinishPage *mFinishPage;

public:
    explicit MainWizard(QWidget *xParent = 0);
    ~MainWizard();

    int nextId() const;

private slots:
    void versionChecked(QString xCurrentVersion, QString xDownloadLink);
    void versionNotChecked(QString xError);

    void helpButton_clicked();
    void checkVersionButton_clicked();
};

#endif // MAINWIZARD_H
