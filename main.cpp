#include <cmath>
#include "Python.h"

#include "UI/mainview.h"
#include <QApplication>
#include <QDebug>

//snippet storage is static cause
//it it should be only created once
static Snippets *snip;

//main view is static so it can be shared
//and only created once
static MainView *mainView;

int main(int argc, char *argv[]) {

    //need to set program details
    QCoreApplication::setOrganizationName("Bhathiya Perera");
    QCoreApplication::setOrganizationDomain("simpll.info");
    QCoreApplication::setApplicationName("expressPython");

    //non modified arguments must be passed
    QApplication app(argc, argv);

    if (argc > 1) {
        QMessageBox msgBox;
        QString text = "";
        for(int i = 0; i < argc; i++) {
            text.append(argv[i]);
            text.append(" ");
        }
        msgBox.setText(text);
        msgBox.exec();
    }

    wchar_t name[] = L"expressPython";
    Py_SetProgramName(name);

    snip = new Snippets();
    mainView = new MainView();
    mainView->SetSnippets(snip);
    mainView->show();

    int result = app.exec();

    delete snip;
    delete mainView;

    return result;
}
