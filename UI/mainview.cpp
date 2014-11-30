#include <functional>
#include "PythonAccess/emb.h"
#include "UI/mainview.h"
#include "ui_mainview.h"
#include <QSettings>
#define SAVE_STATE_VERSION 1
#define KEY_DOCK_LOCATIONS "DOCK_LOCATIONS"
#define KEY_GEOMETRY "GEOMETRY"
#define KEY_INPUTBOX "INPUTBOX"
#define KEY_CODEBOX "CODEBOX"
#define KEY_OUTPUTBOX "OUTPUTBOX"
#define KEY_FONT "FONT"
#define KEY_FONTSIZE "FONTSIZE"

MainView::MainView(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainView)
{
    emb::setMainView(this);
    ui->setupUi(this);
    SetupHighlighter();
    LoadStartupScript();
    LoadSettings();
}
void MainView::LoadSettings()
{

    QSettings settings;
    this->restoreState(settings.value(KEY_DOCK_LOCATIONS).toByteArray(), SAVE_STATE_VERSION);
    this->restoreGeometry(settings.value(KEY_GEOMETRY).toByteArray());
    this->SetCode(settings.value(KEY_CODEBOX, QString()).toString());
    this->SetInput(settings.value(KEY_INPUTBOX, QString()).toString());
    this->SetOutput(settings.value(KEY_OUTPUTBOX, QString()).toString());

    QString font = settings.value(KEY_FONT, tr("Courier New")).toString();
    int sizeIndex = settings.value(KEY_FONTSIZE, 6).toInt(); // select 12pt

    int pos = ui->fntCombo->findText(font);
    if (pos != -1) {
        ui->fntCombo->setCurrentIndex(pos);
    }
    if (sizeIndex >= 0){
        ui->cmbFontSize->setCurrentIndex(sizeIndex);
    }

    ChangeFontSize(ui->fntCombo->currentFont(), ui->cmbFontSize->currentText().toInt());
}
void MainView::SetSnippets(Snippets* snip)
{
    mSnippets = snip;
    LoadSnippetsToCombo();
}

void MainView::SetupHighlighter()
{
    mHighlighter = new PythonSyntaxHighlighter(ui->txtCode->document());
    ui->txtCode->setFocus();
}

void MainView::LoadStartupScript()
{
    bool success;
    mStartMe = LoadFile(":/data/startme.py", success);

    if (!success) {
        QMessageBox::warning(this, tr(APP_NAME), tr("Loading startup script failed"));
    }
}
MainView::~MainView()
{
    QSettings settings;
    settings.setValue(KEY_DOCK_LOCATIONS, this->saveState(SAVE_STATE_VERSION));
    settings.setValue(KEY_GEOMETRY, this->saveGeometry());
    settings.setValue(KEY_CODEBOX, this->GetCode());
    settings.setValue(KEY_INPUTBOX, this->GetInput());
    settings.setValue(KEY_OUTPUTBOX, this->GetOutput());
    settings.setValue(KEY_FONT, ui->fntCombo->currentText());
    settings.setValue(KEY_FONTSIZE, ui->cmbFontSize->currentIndex());
    delete ui;
}

QString MainView::LoadFile(const QString& fileName, bool& success)
{
    success = false;

    QFile file(fileName);

    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr(APP_NAME),
                             tr("Cannot read file %1:\n%2.")
                                 .arg(fileName)
                                 .arg(file.errorString()));
        return QString();
    }

    QTextStream in(&file);

    QApplication::setOverrideCursor(Qt::WaitCursor);
    QString text = in.readAll();
    QApplication::restoreOverrideCursor();
    in.flush();
    file.close();

    success = true;
    return text;
}

void MainView::BrowseAndLoadFile(CodeEditor* codeEditor)
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (fileName.isEmpty()) {
        return;
    }
    bool success;
    QString text = LoadFile(fileName, success);
    if (success) {
        codeEditor->setPlainText(text);
    }
}

void MainView::SaveFile(CodeEditor* codeEditor)
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr(APP_NAME),
                             tr("Cannot write file %1:\n%2.")
                                 .arg(fileName)
                                 .arg(file.errorString()));
        return;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << codeEditor->toPlainText();
    QApplication::restoreOverrideCursor();
}

QString MainView::GetInput()
{
    return ui->txtInput->toPlainText();
}
void MainView::SetInput(QString txt)
{
    ui->txtInput->setPlainText(txt);
}
QString MainView::GetOutput()
{
    return ui->txtOutput->toPlainText();
}
void MainView::SetOutput(QString txt)
{
    ui->txtOutput->setPlainText(txt);
}
QString MainView::GetCode()
{
    return ui->txtCode->toPlainText();
}
void MainView::SetCode(QString txt)
{
    ui->txtCode->setPlainText(txt);
}
void MainView::WriteOutput(QString output)
{
    QString txt = ui->txtOutput->toPlainText();
    txt.append(output);
    ui->txtOutput->setPlainText(txt);
}

void MainView::RunPythonCode(const QString& code)
{
    PyImport_AppendInittab("emb", emb::PyInitEmbConnect);
    PyImport_AppendInittab("expressApi", emb::PyInitApiConnection);
    Py_Initialize();
    PyImport_ImportModule("emb");

    emb::StdOutWriteType write = [](std::string s) {
        emb::getMainView()->WriteOutput(QString::fromStdString(s));
    };

    emb::SetStdout(write);
    PyRun_SimpleString(mStartMe.toStdString().c_str());
    PyRun_SimpleString(code.toStdString().c_str());
    emb::ResetStdOut();
    Py_Finalize();
}

void MainView::on_btnRun_clicked()
{
    RunPythonCode(ui->txtCode->toPlainText());
}

void MainView::ChangeFontSize(QFont font, int fontSize)
{
    QFont sized(font);
    sized.setPointSize(fontSize);
    sized.setFixedPitch(true);
    ui->txtCode->setFont(sized);
    ui->txtInput->setFont(sized);
    ui->txtOutput->setFont(sized);
}

void MainView::on_fntCombo_currentFontChanged(const QFont& font)
{
    ChangeFontSize(font, ui->cmbFontSize->currentText().toInt());
}

void MainView::on_cmbFontSize_currentIndexChanged(const QString& fontSize)
{
    ChangeFontSize(ui->fntCombo->currentFont(), fontSize.toInt());
}

void MainView::on_btnCodeClear_clicked()
{
    ui->txtCode->clear();
}

void MainView::on_btnInputClear_clicked()
{
    ui->txtInput->clear();
}

void MainView::on_btnOutputClear_clicked()
{
    ui->txtOutput->clear();
}

void MainView::on_btnOutputOpen_clicked()
{
    BrowseAndLoadFile(ui->txtOutput);
}

void MainView::on_btnInputOpen_clicked()
{
    BrowseAndLoadFile(ui->txtInput);
}

void MainView::on_btnCodeOpen_clicked()
{
    BrowseAndLoadFile(ui->txtCode);
}

void MainView::on_btnOutputSave_clicked()
{
    SaveFile(ui->txtOutput);
}

void MainView::on_btnInputSave_clicked()
{
    SaveFile(ui->txtInput);
}

void MainView::on_btnCodeSave_clicked()
{
    SaveFile(ui->txtCode);
}

void MainView::on_btnCodeDatabase_clicked()
{
    bool success;
    mSnippets->SaveSnippets(success);
    if (success) {
        QMessageBox::information(this, tr(APP_NAME), tr("Snippets database saved."));
    } else {
        QMessageBox::critical(this, tr(APP_NAME), tr("Snippets database saving failed."));
    }
}

void MainView::on_btnRunSnippet_clicked()
{
    bool success;
    QString code = mSnippets->GetSnippet(ui->cmbSnippets->currentText(), success);
    if (success) {
        RunPythonCode(code);
    }
}

void MainView::on_btnLoadSnippet_clicked()
{
    bool success;
    QString code = mSnippets->GetSnippet(ui->cmbSnippets->currentText(), success);
    if (success) {
        ui->txtCode->setPlainText(code);
    }
}

void MainView::on_btnRemoveSnippet_clicked()
{
    bool success;
    mSnippets->RemoveSnippet(ui->cmbSnippets->currentText(), success);
    if (success) {
        QMessageBox::information(this, tr(APP_NAME), tr("Snippet removed."));
    } else {
        QMessageBox::critical(this, tr(APP_NAME), tr("Snippet removal failed."));
    }
    LoadSnippetsToCombo();
}

void MainView::on_btnAddSnippet_clicked()
{
    if (ui->txtCode->toPlainText().isEmpty()) {
        return;
    }

    bool ok;
    QString text = QInputDialog::getText(this, tr(APP_NAME),
                                         tr("Snippet name:"),
                                         QLineEdit::Normal, tr(""), &ok);
    if (!ok || text.isEmpty()) {
        return;
    }

    mSnippets->AddSnippet(text, ui->txtCode->toPlainText(), ok);

    if (ok) {
        QMessageBox::information(this, tr(APP_NAME), tr("Snippet added."));
    } else {
        QMessageBox::critical(this, tr(APP_NAME), tr("Snippet adding failed."));
    }
    LoadSnippetsToCombo();
}

void MainView::on_btnAbout_clicked()
{
    QMessageBox::about(this, tr(APP_NAME), tr("<b>" APP_NAME "</b><br />"
                                              "Written by Bhathiya Perera<br />"
                                              "<br />"
                                              "This Project Depends on<br />"
                                              "Qt5.3, Python<br />"
                                              "Frankie Simon's Python Syntax Highlight Code<br />"
                                              "Mateusz Loskot's Embedding Code<br />"
                                              "<br />"));
}

void MainView::LoadSnippetsToCombo()
{
    ui->cmbSnippets->clear();
    bool success;
    QList<QString> keys = mSnippets->GetKeys(success);
    if (success) {
        ui->cmbSnippets->addItems(QStringList(keys));
    }
}
