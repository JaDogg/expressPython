#include "Python.h"
#include <QMessageBox>
#include <QTextStream>
#include "mainview.h"
#include "ui_mainview.h"

MainView::MainView(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainView)
{
    ui->setupUi(this);
    highlighter = new PythonSyntaxHighlighter(ui->txtCode->document());
    int pos = ui->fntCombo->findText("Courier New");
    if (pos != -1) {
        ui->fntCombo->setCurrentIndex(pos);
    }
    ui->cmbFontSize->setCurrentIndex(6); // select 12pt

    ChangeFontSize(ui->fntCombo->currentFont(), ui->cmbFontSize->currentText().toInt());

    // Load the startup script
    QFile inputFile(":/data/startme.py");
    inputFile.open(QIODevice::ReadOnly);
    QTextStream in(&inputFile);
    m_startme = in.readAll();
    inputFile.close();

    ui->txtCode->setFocus();
}

MainView::~MainView()
{
    delete ui;
}

QString MainView::GetInput()
{
    return ui->txtInput->toPlainText();
}

void MainView::SetOutput(QString output)
{
    ui->txtOutput->setPlainText(output);
}
void MainView::WriteOutput(QString output)
{
    QString txt = ui->txtOutput->toPlainText();
    ui->txtOutput->setPlainText(txt + output);
}

void MainView::on_btnRun_clicked()
{
    QString pycode(m_startme);
    pycode.append(ui->txtCode->toPlainText());
    PyRun_SimpleString(pycode.toStdString().c_str());
}


void MainView::ChangeFontSize(QFont font, int fontSize)
{
    QFont* sized = new QFont(font);
    sized->setPointSize(fontSize);
    sized->setFixedPitch(true);
    ui->txtCode->setFont(*sized);
    ui->txtInput->setFont(*sized);
    ui->txtOutput->setFont(*sized);
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
