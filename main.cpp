#include <cmath>
#include "Python.h"

#include "UI/mainview.h"
#include <QApplication>

static Snippets* snip;
static MainView* mainView;
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    wchar_t c_s[] = L"PyRun";
    Py_SetProgramName(c_s);
    snip = new Snippets();
    mainView = new MainView();
    mainView->SetSnippets(snip);
    mainView->show();

    int result = app.exec();

    delete snip;
    delete mainView;

    return result;
}
