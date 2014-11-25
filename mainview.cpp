#include "emb.h"
#include "mainview.h"
#include "ui_mainview.h"

MainView::MainView(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainView)
{
    emb::mainView = this;
    ui->setupUi(this);
    SetupHighlighter();
    LoadStartupScript();

}

void MainView::SetSnippets(Snippets* snip)
{
    m_snip = snip;
    LoadSnippetsToCombo();
}

void MainView::SetupHighlighter()
{
    m_highlighter = new PythonSyntaxHighlighter(ui->txtCode->document());

    int pos = ui->fntCombo->findText("Courier New");
    if (pos != -1) {
        ui->fntCombo->setCurrentIndex(pos);
    }
    ui->cmbFontSize->setCurrentIndex(6); // select 12pt

    ChangeFontSize(ui->fntCombo->currentFont(), ui->cmbFontSize->currentText().toInt());

    ui->txtCode->setFocus();
}

void MainView::LoadStartupScript()
{
    bool success;
    m_startme = LoadFile(":/data/startme.py", success);

    if (!success) {
        QMessageBox::warning(this, tr(APP_NAME), tr("Loading startup script failed"));
    }
}
MainView::~MainView()
{
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
    PyImport_AppendInittab("emb", emb::PyInit_emb);
    PyImport_AppendInittab("lseba", emb::PyInit_Lseba);
    Py_Initialize();
    PyImport_ImportModule("emb");
    //no need to import lseba, it is imported in startme.py
    std::string buffer;
    {
        // switch sys.stdout to custom handler
        emb::stdout_write_type write = [&buffer](std::string s) {
            buffer += s;
            emb::mainView->WriteOutput(QString::fromStdString(s));
        };
        emb::set_stdout(write);
        PyRun_SimpleString(m_startme.toStdString().c_str());
        PyRun_SimpleString(code.toStdString().c_str());
        emb::reset_stdout();
    }
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
    m_snip->SaveSnippets(success);
    if (success) {
        QMessageBox::information(this, tr(APP_NAME), tr("Snippets database saved."));
    } else {
        QMessageBox::critical(this, tr(APP_NAME), tr("Snippets database saving failed."));
    }
}

void MainView::on_btnRunSnippet_clicked()
{
    bool success;
    QString code = m_snip->GetSnippet(ui->cmbSnippets->currentText(), success);
    if (success) {
        RunPythonCode(code);
    }
}

void MainView::on_btnLoadSnippet_clicked()
{
    bool success;
    QString code = m_snip->GetSnippet(ui->cmbSnippets->currentText(), success);
    if (success) {
        ui->txtCode->setPlainText(code);
    }
}

void MainView::on_btnRemoveSnippet_clicked()
{
    bool success;
    m_snip->RemoveSnippet(ui->cmbSnippets->currentText(), success);
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

    m_snip->AddSnippet(text, ui->txtCode->toPlainText(), ok);

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
    QList<QString> keys = m_snip->GetKeys(success);
    if (success) {
        ui->cmbSnippets->addItems(QStringList(keys));
    }
}
