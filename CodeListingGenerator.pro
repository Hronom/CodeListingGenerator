QT       += core gui

TARGET = CodeListingGenerator
TEMPLATE = app


SOURCES += main.cpp\
    MainWizard.cpp \
    SettingSourcesPage.cpp \
    SelectFilesPage.cpp \
    ChooseFilesOrderPage.cpp \
    SaveListFilePage.cpp \
    FinishPage.cpp

HEADERS  += \
    MainWizard.h \
    SettingSourcesPage.h \
    SelectFilesPage.h \
    ChooseFilesOrderPage.h \
    SaveListFilePage.h \
    FinishPage.h

FORMS    += \
    MainWizard.ui \
    SettingSourcesPage.ui \
    SelectFilesPage.ui \
    ChooseFilesOrderPage.ui \
    SaveListFilePage.ui \
    FinishPage.ui

RESOURCES += \
    CodeListingGenerator.qrc

CODEC = Windows-1251
CODECFORSRC = Windows-1251

OTHER_FILES +=






















































