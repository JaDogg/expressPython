#include <functional>
#include "PythonAccess/emb.h"
#include "PythonAccess/pythonworker.h"
#include "UI/mainview.h"
#include "ui_mainview.h"
#include <QSettings>
#include <QStringListModel>

MainView::MainView(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainView) {
  ui->setupUi(this);
  SetupHighlighter();
  LoadResources();
  LoadSettings();
  SetupPython();
  m_tute = new XTute(this);
}

/**
 * @brief Setup python embedding
 */
void MainView::SetupPython() {
  emb::setMainView(this);
  PythonWorker* worker = new PythonWorker();
  emb::setWorker(worker);
  m_workerThread = new QThread();
  worker->moveToThread(m_workerThread);
  connect(m_workerThread, &QThread::finished, worker, &QObject::deleteLater);
  connect(this, &MainView::operate, worker, &PythonWorker::RunPython);
  connect(worker, &PythonWorker::WriteOutput, this, &MainView::WriteOutput);
  connect(worker, &PythonWorker::SetCode, this, &MainView::SetCode);
  connect(worker, &PythonWorker::SetInput, this, &MainView::SetInput);
  connect(worker, &PythonWorker::SetOutput, this, &MainView::SetOutput);
  connect(worker, &PythonWorker::StartPythonRun, this,
          &MainView::StartPythonRun);
  connect(worker, &PythonWorker::EndPythonRun, this, &MainView::EndPythonRun);
  connect(worker, &PythonWorker::SetSearchRegex, this,
          &MainView::SetSearchRegex);
  m_workerThread->start();
}
// Buttons to enable when you execute a python script
void MainView::StartPythonRun() {
  ui->btnRun->setEnabled(false);
  ui->btnRunSnippet->setEnabled(false);
  ui->btnRunSnippetFromCombo->setEnabled(false);
  ui->dwTutorial->setEnabled(false);
  ui->btnStopPython->setEnabled(true);
}
// End python script
void MainView::EndPythonRun() {
  if (m_markTute) {
    m_tute->Mark(m_markIndex, ui->txtOutput->toPlainText(), ui->lwTute, ui->pbTute);
    m_markTute = false;
    m_markIndex = -1;
  }

  ui->btnRun->setEnabled(true);
  ui->btnRunSnippet->setEnabled(true);
  ui->btnRunSnippetFromCombo->setEnabled(true);
  ui->dwTutorial->setEnabled(true);
  ui->btnStopPython->setEnabled(false);
}
// Util function: Confirm message box
bool MainView::Confirm(const QString &what) {
  QMessageBox msgBox(this);
  msgBox.setWindowTitle(tr(APP_NAME));
  msgBox.setText(what);
  msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
  msgBox.setDefaultButton(QMessageBox::No);
  if (msgBox.exec() == QMessageBox::Yes) {
    return true;
  }
  return false;
}
/**
 * @brief Load text box content and docking locations
 */
void MainView::LoadSettings() {
  QSettings settings;
  this->restoreState(settings.value(KEY_DOCK_LOCATIONS).toByteArray(),
                     SAVE_STATE_VERSION);
  this->restoreGeometry(settings.value(KEY_GEOMETRY).toByteArray());
  this->SetCode(settings.value(KEY_CODEBOX, QString()).toString());
  this->SetInput(settings.value(KEY_INPUTBOX, QString()).toString());
  this->SetOutput(settings.value(KEY_OUTPUTBOX, QString()).toString());
  ui->txtSnippet->setPlainText(
      settings.value(KEY_SNIPPETBOX, QString()).toString());
  ui->txtNotes->setPlainText(
      settings.value(KEY_NOTESBOX, QString()).toString());
  QString font = settings.value(KEY_FONT, tr("Courier New")).toString();
  int sizeIndex = settings.value(KEY_FONTSIZE, 6).toInt(); // select 12pt

  int pos = ui->fntCombo->findText(font);
  if (pos != -1) {
    ui->fntCombo->setCurrentIndex(pos);
  }
  if (sizeIndex >= 0) {
    ui->cmbFontSize->setCurrentIndex(sizeIndex);
  }

  ChangeFontSize(ui->fntCombo->currentFont(),
                 ui->cmbFontSize->currentText().toInt());
}

void MainView::SetSnippets(Snippets *snip) {
  m_snippets = snip;
  LoadSnippetsToCombo();
}

void MainView::SetupHighlighter() {
  m_highlighterCodeArea = new PythonSyntaxHighlighter(ui->txtCode->document());
  ui->txtCode->setFocus();
  m_highlighterSnippetArea =
      new PythonSyntaxHighlighter(ui->txtSnippet->document());
  SetCompleter(ui->txtCode);
}

void MainView::SetCompleter(CodeEditor *editor) {
  completer = new QCompleter(this);

  QFile file(":/data/Features/autocomplete.txt");
  if (!file.open(QFile::ReadOnly))
    return;

  // QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
  QStringList words;

  while (!file.atEnd()) {
    QByteArray line = file.readLine();
    if (!line.isEmpty())
      words << line.trimmed();
  }

  // QApplication::restoreOverrideCursor();
  QStringListModel *model = new QStringListModel(words, completer);

  completer->setModel(model);
  completer->setModelSorting(QCompleter::CaseSensitivelySortedModel);
  completer->setCaseSensitivity(Qt::CaseInsensitive);
  completer->setCompletionMode(QCompleter::PopupCompletion);
  completer->setWrapAround(false);
  completer->popup()->setStyleSheet("background-color: black; color: white");

  editor->setCompleter(completer);
}

void MainView::LoadResources() {
  bool success = false;

  m_startMe = LoadFile(STARTUP_SCRIPT_FILE, success, false);

  if (!success) {
    m_startMe = LoadFile(":/data/startme.py", success);
  }
  if (!success) {
    QMessageBox::critical(this, tr(APP_NAME), tr("Loading startup script failed"));
    qApp->quit();
  }
  m_about = LoadFile(":/data/About.htm", success);
  if (!success) {
    m_about = tr(APP_NAME " Written by Bhathiya Perera");
  }
}
MainView::~MainView() {
  QSettings settings;
  settings.setValue(KEY_DOCK_LOCATIONS, this->saveState(SAVE_STATE_VERSION));
  settings.setValue(KEY_GEOMETRY, this->saveGeometry());
  settings.setValue(KEY_CODEBOX, this->GetCode());
  settings.setValue(KEY_INPUTBOX, this->GetInput());
  settings.setValue(KEY_OUTPUTBOX, this->GetOutput());
  settings.setValue(KEY_SNIPPETBOX, ui->txtSnippet->toPlainText());
  settings.setValue(KEY_NOTESBOX, ui->txtNotes->toPlainText());
  settings.setValue(KEY_FONT, ui->fntCombo->currentText());
  settings.setValue(KEY_FONTSIZE, ui->cmbFontSize->currentIndex());
  m_workerThread->quit();
  m_workerThread->wait();
  delete m_workerThread;
  delete ui;
  delete m_tute;
}

QString MainView::LoadFile(const QString &fileName, bool &success,
                           const bool showMessage) {
  success = false;

  QFile file(fileName);

  if (!file.open(QFile::ReadOnly | QFile::Text)) {
    if (showMessage) {
      QMessageBox::warning(this, tr(APP_NAME), tr("Cannot read file %1:\n%2.")
                                                   .arg(fileName)
                                                   .arg(file.errorString()));
    }
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

void MainView::BrowseAndLoadFile(CodeEditor *codeEditor, const bool isPython) {

  QString fileName = QFileDialog::getOpenFileName(
      this, tr("Open"), QApplication::applicationDirPath(),
      ((isPython) ? FILETYPES_PYTHON : FILETYPES_OTHER));
  if (fileName.isEmpty()) {
    return;
  }
  bool success;
  QString text = LoadFile(fileName, success);
  if (success) {
    codeEditor->setPlainText(text);
  }
}

void MainView::SaveFile(CodeEditor *codeEditor, const bool isPython) {
  QString fileName = QFileDialog::getSaveFileName(
      this, tr("Save"), QApplication::applicationDirPath(),
      ((isPython) ? FILETYPES_PYTHON : FILETYPES_OTHER));
  if (fileName.isEmpty()) {
    return;
  }

  QFile file(fileName);
  if (!file.open(QFile::WriteOnly | QFile::Text)) {
    QMessageBox::warning(
        this, tr(APP_NAME),
        tr("Cannot write file %1:\n%2.").arg(fileName).arg(file.errorString()));
    return;
  }

  QTextStream out(&file);
  QApplication::setOverrideCursor(Qt::WaitCursor);
  out << codeEditor->toPlainText();
  QApplication::restoreOverrideCursor();
}

QString MainView::GetInput() { return ui->txtInput->toPlainText(); }
void MainView::SetInput(QString txt) { ui->txtInput->setPlainText(txt); }
QString MainView::GetOutput() { return ui->txtOutput->toPlainText(); }
void MainView::SetOutput(QString txt) { ui->txtOutput->setPlainText(txt); }
QString MainView::GetCode() { return ui->txtCode->toPlainText(); }
void MainView::SetCode(QString txt) { ui->txtCode->setPlainText(txt); }

void MainView::SetSearchRegex(QString txt) {
  m_highlighterCodeArea->SetSearchRegEx(txt);
  m_highlighterCodeArea->rehighlight();
}

void MainView::WriteOutput(QString output) {
  QString txt = ui->txtOutput->toPlainText();
  txt.append(output);
  ui->txtOutput->setPlainText(txt);
}

void MainView::RunPythonCode(const QString &code) {
  m_markTute = false;
  m_markIndex = -1;
  emit operate(m_startMe, code);
}

void MainView::on_btnRun_clicked() {
  if (ui->chkClearOut->isChecked()) {
      ui->txtOutput->clear();
  }
  RunPythonCode(ui->txtCode->toPlainText());
}

void MainView::ChangeFontSize(QFont font, int fontSize) {
  QFont sized(font);
  sized.setPointSize(fontSize);
  sized.setFixedPitch(true);
  ui->txtCode->setFont(sized);
  ui->txtInput->setFont(sized);
  ui->txtOutput->setFont(sized);
  ui->txtSnippet->setFont(sized);
  ui->txtNotes->setFont(sized);
}

void MainView::on_fntCombo_currentFontChanged(const QFont &font) {
  ChangeFontSize(font, ui->cmbFontSize->currentText().toInt());
}

void MainView::on_cmbFontSize_currentIndexChanged(const QString &fontSize) {
  ChangeFontSize(ui->fntCombo->currentFont(), fontSize.toInt());
}

void MainView::on_btnCodeClear_clicked() {
  if (Confirm(tr("Are you sure you want to clear code ?"))) {
    ui->txtCode->clear();
  }
}

void MainView::on_btnInputClear_clicked() {
  if (Confirm(tr("Are you sure you want to clear input ?"))) {
    ui->txtInput->clear();
  }
}

void MainView::on_btnOutputClear_clicked() {
  if (Confirm(tr("Are you sure you want to clear output ?"))) {
    ui->txtOutput->clear();
  }
}

void MainView::on_btnOutputOpen_clicked() { BrowseAndLoadFile(ui->txtOutput); }

void MainView::on_btnInputOpen_clicked() { BrowseAndLoadFile(ui->txtInput); }

void MainView::on_btnCodeOpen_clicked() {
  if (!ui->txtCode->toPlainText().isEmpty() &&
      Confirm(tr("Would you like to save code ?"))) {
    on_btnCodeSave_clicked();
  }
  BrowseAndLoadFile(ui->txtCode, true);
}

void MainView::on_btnOutputSave_clicked() { SaveFile(ui->txtOutput); }

void MainView::on_btnInputSave_clicked() { SaveFile(ui->txtInput); }

void MainView::on_btnCodeSave_clicked() { SaveFile(ui->txtCode, true); }

void MainView::on_btnCodeDatabase_clicked() {
  bool success;
  m_snippets->SaveSnippets(success);
  if (success) {
    QMessageBox::information(this, tr(APP_NAME),
                             tr("Snippets database saved."));
  } else {
    QMessageBox::critical(this, tr(APP_NAME),
                          tr("Snippets database saving failed."));
  }
}

void MainView::on_btnRunSnippet_clicked() {
  if (!Confirm(
          "Are you sure you want to run this snippet (from snippet area) ?")) {
    return;
  }

  RunPythonCode(ui->txtSnippet->toPlainText());
}

void MainView::on_btnLoadSnippet_clicked() {
  if (!Confirm("Are you sure you want to load snippet to snippet area ?")) {
    return;
  }

  bool success;
  QString code =
      m_snippets->GetSnippet(ui->cmbSnippets->currentText(), success);
  if (success) {
    ui->txtSnippet->setPlainText(code);
  }
}

void MainView::on_btnRemoveSnippet_clicked() {
  if (!Confirm("Are you sure you want to delete the selected snippet ?")) {
    return;
  }

  bool success;
  m_snippets->RemoveSnippet(ui->cmbSnippets->currentText(), success);
  if (success) {
    QMessageBox::information(this, tr(APP_NAME), tr("Snippet removed."));
  } else {
    QMessageBox::critical(this, tr(APP_NAME), tr("Snippet removal failed."));
  }
  LoadSnippetsToCombo();
}

void MainView::on_btnAddSnippet_clicked() {
  if (ui->txtSnippet->toPlainText().isEmpty()) {
    return;
  }

  bool ok = false;
  QString text = QInputDialog::getText(this, tr(APP_NAME), tr("Snippet name:"),
                                       QLineEdit::Normal, tr(""), &ok);
  if (!ok || text.isEmpty()) {
    return;
  }

  if (!m_snippets->OkToInsert(text)) {
    ok = Confirm(tr("This snippet already exists, do you want to overwrite ?"));
  }

  if (!ok) {
    return;
  }

  m_snippets->AddSnippet(text, ui->txtSnippet->toPlainText(), ok);

  if (ok) {
    QMessageBox::information(this, tr(APP_NAME), tr("Snippet added."));
  } else {
    QMessageBox::critical(this, tr(APP_NAME), tr("Snippet adding failed."));
  }
  LoadSnippetsToCombo();
}

void MainView::on_btnAbout_clicked() {
  QMessageBox::about(this, tr(APP_NAME), m_about);
}

void MainView::LoadSnippetsToCombo() {
  ui->cmbSnippets->clear();
  bool success;
  QList<QString> keys = m_snippets->GetKeys(success);
  if (success) {
    ui->cmbSnippets->addItems(QStringList(keys));
  }
}

void MainView::on_btnUpdateSnippet_clicked() {
  if (ui->txtSnippet->toPlainText().isEmpty()) {
    return;
  }

  if (!Confirm("Are you sure you want to overwrite selected snippet ?")) {
    return;
  }

  bool ok;

  m_snippets->AddSnippet(ui->cmbSnippets->currentText(),
                         ui->txtSnippet->toPlainText(), ok);

  if (ok) {
    QMessageBox::information(this, tr(APP_NAME), tr("Snippet updated."));
  } else {
    QMessageBox::critical(this, tr(APP_NAME), tr("Snippet updating failed."));
  }
  LoadSnippetsToCombo();
}

void MainView::on_btnSnippetClear_clicked() {
  if (Confirm(tr("Are you sure you want to clear snippet area ?"))) {
    ui->txtSnippet->clear();
  }
}

void MainView::on_btnSnippetSave_clicked() { SaveFile(ui->txtSnippet, true); }

void MainView::on_btnSnippetOpen_clicked() {
  if (!ui->txtSnippet->toPlainText().isEmpty() &&
      Confirm(tr("Would you like to save current snippet ?"))) {
    on_btnSnippetSave_clicked();
  }
  BrowseAndLoadFile(ui->txtSnippet, true);
}

void MainView::on_btnRunSnippetFromCombo_clicked() {
  if (!Confirm(
          "Are you sure you want to run this snippet (from combo-box) ?")) {
    return;
  }
  bool success;
  QString code =
      m_snippets->GetSnippet(ui->cmbSnippets->currentText(), success);
  if (success) {
    RunPythonCode(code);
  }
}

// =========================================================================
// NOTES
// =========================================================================
void MainView::on_btnNotesOpen_clicked()
{
    if (!ui->txtNotes->toPlainText().isEmpty() &&
        Confirm(tr("Would you like to save notes ?"))) {
      on_btnNotesSave_clicked();
    }

    BrowseAndLoadFile(ui->txtNotes, true);
}

void MainView::on_btnNotesSave_clicked()
{
    SaveFile(ui->txtNotes);
}

void MainView::on_btnNotesClear_clicked()
{
    if (Confirm(tr("Are you sure you want to clear notes ?"))) {
      ui->txtNotes->clear();
    }
}

void MainView::on_btnTuteOpen_clicked()
{
    if (!Confirm(tr("Are you sure you want to load a tute, this will reset current progress (if any) ?"))) {
        return;
    }

    QString fileName = QFileDialog::getOpenFileName(
        this, tr("Open"), QApplication::applicationDirPath(), FILETYPES_TUTE);
    if (fileName.isEmpty()) {
      return;
    }
    m_tute->Load(fileName);

    if (!m_tute->IsLoaded()) {
        QMessageBox::warning(this, tr(APP_NAME), tr("Cannot read file %1").arg(fileName));
        return;
    }

    m_tute->InitList(ui->lwTute, ui->pbTute);
}

void MainView::on_btnTuteLoad_clicked()
{
    if (!Confirm(tr("Are you sure you want to load a question, this will reset current progress (if any) ?"))) {
        return;
    }

    int index = ui->lwTute->currentRow();
    if (index < 0 || index >= ui->lwTute->count()) {
        return;
    }
    m_tute->LoadQuestion(index, ui->txtInput, ui->txtNotes, ui->txtCode);
}

void MainView::on_btnTuteMark_clicked()
{
    int index = ui->lwTute->currentRow();
    if (index < 0 || index >= ui->lwTute->count()) {
        return;
    }
    // Reset input before marking
    m_tute->SetInput(index, ui->txtInput);

    ui->txtOutput->clear();
    m_markTute = true;
    m_markIndex = index;

    emit operate(m_startMe, ui->txtCode->toPlainText());
}

void MainView::on_btnStopPython_clicked()
{
    PythonWorker p;
    p.StopPython();
}
