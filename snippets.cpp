#include "snippets.h"
#include <iostream>

Snippets::Snippets(QObject* parent)
    : QObject(parent)
    , m_Snippets(nullptr)
{
    bool success;
    LoadSnippets(success);
}

void Snippets::LoadSnippets(bool& success)
{
    success = false;
    QFile file(SNIPPETS_FILE);

    QMap<QString, QString> data = QMap<QString, QString>();

    if (file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);
        in >> data;
        file.close();
    }

    if (data.isEmpty()) {
        //TODO Add More Snippets
        data.insert(tr("Data Dump Example 01"), tr("dump(['Hello', 'World'])"));
    }

    m_Snippets = new QMap<QString, QString>(data);

    success = true;
}

void Snippets::SaveSnippets(bool& success)
{
    success = false;
    if (m_Snippets != nullptr) {

        QFile file(SNIPPETS_FILE);
        if (!file.open(QIODevice::WriteOnly)) {
            return;
        }
        QDataStream out(&file);
        out << *m_Snippets;
        file.close();
        success = true;
    }
}

void Snippets::AddSnippet(const QString& name, const QString& code, bool& success)
{
    success = false;
    if (m_Snippets != nullptr) {
        success = true;
        m_Snippets->insert(name, code);
    }
}

void Snippets::RemoveSnippet(const QString& name, bool& success)
{
    success = false;
    if (m_Snippets != nullptr && m_Snippets->contains(name)) {
        success = (m_Snippets->remove(name) > 0);
    }
}

QString Snippets::GetSnippet(const QString& name, bool& success)
{
    success = false;
    if (m_Snippets != nullptr && m_Snippets->contains(name)) {
        success = true;
        return m_Snippets->value(name);
    }
    return QString();
}

QList<QString> Snippets::GetKeys(bool& success)
{
    success = false;
    if (m_Snippets != nullptr) {
        success = true;
        return m_Snippets->keys();
    }
    return QList<QString>();
}

Snippets::~Snippets()
{
    if (m_Snippets != nullptr) {
        bool success;
        SaveSnippets(success); // save on the destructor
        //TODO cerr
        delete m_Snippets;
    }
}
