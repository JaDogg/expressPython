#ifndef MAINVIEW_H
#define MAINVIEW_H
#define APP_NAME "PyRun Tester"

#include <cmath>
#include "Python.h"

// fremework
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>
#include <QMainWindow>
#include <QInputDialog>

// internal
#include "pythonsyntaxhighlighter.h"
#include "codeeditor.h"
#include "snippets.h"

namespace Ui {
class MainView;
}

class MainView : public QMainWindow {

    Q_OBJECT

public:
    explicit MainView(QWidget* parent = 0);
    ~MainView();
    QString GetInput();
    void SetInput(QString txt);
    QString GetOutput();
    void SetOutput(QString txt);
    QString GetCode();
    void SetCode(QString txt);
    void WriteOutput(QString output);
    void SetSnippets(Snippets* snip);
private slots:
    void on_btnRun_clicked();
    void on_fntCombo_currentFontChanged(const QFont& font);
    void on_cmbFontSize_currentIndexChanged(const QString& fontSize);
    void on_btnCodeClear_clicked();
    void on_btnInputClear_clicked();
    void on_btnOutputClear_clicked();
    void on_btnOutputOpen_clicked();
    void on_btnInputOpen_clicked();
    void on_btnCodeOpen_clicked();
    void on_btnOutputSave_clicked();
    void on_btnInputSave_clicked();
    void on_btnCodeSave_clicked();
    void on_btnCodeDatabase_clicked();
    void on_btnRunSnippet_clicked();
    void on_btnLoadSnippet_clicked();
    void on_btnRemoveSnippet_clicked();
    void on_btnAddSnippet_clicked();
    void on_btnAbout_clicked();

private:
    Ui::MainView* ui;
    PythonSyntaxHighlighter* m_highlighter;
    QString m_startme;
    Snippets* m_snip;
    void ChangeFontSize(QFont font, int size);
    void SetupHighlighter();
    void SaveFile(CodeEditor* codeEditor);
    void BrowseAndLoadFile(CodeEditor* codeEditor);
    QString LoadFile(const QString& fileName, bool& success);
    void LoadStartupScript();
    void LoadSnippetsToCombo();
    void RunPythonCode(const QString& code);
};

#endif // MAINVIEW_H
