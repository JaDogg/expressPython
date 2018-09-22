#ifndef QCODELINEEDIT_H
#define QCODELINEEDIT_H

#include <QPlainTextEdit>
#include <QObject>

QT_BEGIN_NAMESPACE
class QPaintEvent;
class QResizeEvent;
class QSize;
class QWidget;
QT_END_NAMESPACE

class CodeLineEdit : public QPlainTextEdit {
    Q_OBJECT
  private:
    void keyPressEvent(QKeyEvent *event);
    QSize sizeHint() const;
    void wheelEvent(QWheelEvent *e);
    void dragEnterEvent(QDragEnterEvent *e);
    void dragLeaveEvent(QDragLeaveEvent *e);
    void dragMoveEvent(QDragMoveEvent *e);
    void dropEvent(QDropEvent *e);
    void mouseMoveEvent(QMouseEvent *e);

  public:
    CodeLineEdit(QWidget *parent = 0);
};

#endif // QCODELINEEDIT_H
