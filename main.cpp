#include <cmath>
#include "Python.h"

#include "UI/mainview.h"
#include <QApplication>

//snippet storage is static cause
//it it should be only created once
static Snippets *snip;

//main view is static so it can be shared 
//and only created once
static MainView *mainView;

int main(int argc, char *argv[]) {
  
  //need to set program details 
  QCoreApplication::setOrganizationName("Bhathiya");
  QCoreApplication::setOrganizationDomain("simpll.info");
  QCoreApplication::setApplicationName("expressPython");

  //non modified arguments must be passed
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
