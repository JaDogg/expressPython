#ifndef SNIPPETS_H
#define SNIPPETS_H

#include <QObject>
#include <QMap>
#include <QList>
#include <QIODevice>
#include <QFile>
#include <QApplication>

#define SNIPPETS_FILE QApplication::applicationDirPath() + "/snippets.dat"

class Snippets : public QObject {
  Q_OBJECT
public:
  explicit Snippets(QObject *parent = 0);

  QString GetSnippet(const QString &name, bool &success);
  void RemoveSnippet(const QString &name, bool &success);
  void AddSnippet(const QString &name, const QString &code, bool &success);
  void SaveSnippets(bool &success);
  void LoadSnippets(bool &success);
  ~Snippets();
  QList<QString> GetKeys(bool &success);
signals:

public slots:

private:
  QMap<QString, QString> *m_Snippets;
};

#endif // SNIPPETS_H
