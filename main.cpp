#include <cmath>
#include "Python.h"

#include "UI/mainview.h"
#include <QApplication>

static Snippets* snip;
static MainView* mainView;
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

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
