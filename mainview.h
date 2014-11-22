#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include "pythonsyntaxhighlighter.h"

namespace Ui {
class MainView;
}

class MainView : public QMainWindow {
    Q_OBJECT

public:
    explicit MainView(QWidget* parent = 0);
    ~MainView();

    QString GetInput();
    void SetOutput(QString output);
    void WriteOutput(QString output);
private slots:
    void on_btnRun_clicked();

    void on_fntCombo_currentFontChanged(const QFont& font);

    void on_cmbFontSize_currentIndexChanged(const QString& fontSize);

    void on_btnCodeClear_clicked();

    void on_btnInputClear_clicked();

    void on_btnOutputClear_clicked();

private:
    Ui::MainView* ui;
    PythonSyntaxHighlighter* highlighter;
    void ChangeFontSize(QFont font, int size);
    QString m_startme;
};

#endif // MAINVIEW_H
