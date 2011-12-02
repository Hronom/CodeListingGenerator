QT       += core gui network

TARGET = CodeListingGenerator
TEMPLATE = app

CONFIG(debug, debug|release) {
    LIBS += -L$$PWD/NewVersionChecker/debug -lNewVersionChecker
    PRE_TARGETDEPS += $$PWD/NewVersionChecker/debug/libNewVersionChecker.a
}

CONFIG(release, debug|release) {
    LIBS += -L$$PWD/NewVersionChecker/release -lNewVersionChecker
    PRE_TARGETDEPS += $$PWD/NewVersionChecker/release/libNewVersionChecker.a
    #DEFINES += QT_NO_DEBUG_OUTPUT
}

INCLUDEPATH += $$PWD/NewVersionChecker/include/

SOURCES += main.cpp\
    MainWizard.cpp \
    SelectingSourcesPage.cpp \
    SelectingFilesPage.cpp \
    ChooseFilesOrderPage.cpp \
    SaveListingFilePage.cpp \
    FinishPage.cpp

HEADERS  += \
    MainWizard.h \
    SelectingSourcesPage.h \
    SelectingFilesPage.h \
    ChooseFilesOrderPage.h \
    SaveListingFilePage.h \
    FinishPage.h

FORMS    += \
    MainWizard.ui \
    SelectingSourcesPage.ui \
    SelectingFilesPage.ui \
    ChooseFilesOrderPage.ui \
    SaveListingFilePage.ui \
    FinishPage.ui

RESOURCES += \
    CodeListingGenerator.qrc

RC_FILE = CodeListingGenerator.rc

CODEC = Windows-1251
CODECFORSRC = Windows-1251
CODECFORTR = Windows-1251

TRANSLATIONS = CodeListingGenerator_en_EN.ts

























































