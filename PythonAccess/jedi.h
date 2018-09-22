#ifndef JEDI_H
#define JEDI_H

#include <QObject>
#include <QMap>
#include <QList>
#include <QIODevice>
#include <QFile>
#include <QApplication>
#include <QListWidget>
#include <QProgressBar>
#include <QTextStream>
#include <QPixmap>
#include <QIcon>
#include <QDebug>


class Jedi : public QObject {
    Q_OBJECT
  public:
    explicit Jedi(QObject* parent=nullptr);
    void SetJediGetCode(QString jediCode);
    QStringList AutoComplete(const QString& code, long row, long col);
  private:
    QString jediCode;
};

#endif // JEDI_H
