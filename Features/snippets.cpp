#include "Features/snippets.h"
#include <iostream>
#include <QDataStream>

Snippets::Snippets(QObject *parent) : QObject(parent), m_snippets(nullptr) {
    bool success;
    LoadSnippets(success);
}

void Snippets::LoadSnippets(bool &success) {
    success = false;
    QFile file(SNIPPETS_FILE);

    QMap<QString, QString> data = QMap<QString, QString>();

    if (file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);
        in >> data;
        file.close();
    }

    if (data.isEmpty()) {
        data.insert(tr("Hello World"), tr("print ('Hello World')"));
    }

    m_snippets = new QMap<QString, QString>(data);

    success = true;
}

void Snippets::SaveSnippets(bool &success) {
    success = false;
    if (m_snippets != nullptr) {

        QFile file(SNIPPETS_FILE);
        if (!file.open(QIODevice::WriteOnly)) {
            return;
        }
        QDataStream out(&file);
        out << *m_snippets;
        file.close();
        success = true;
    }
}

void Snippets::AddSnippet(const QString &name, const QString &code,
                          bool &success) {
    success = false;
    if (m_snippets != nullptr) {
        success = true;
        m_snippets->insert(name, code);
    }
}

void Snippets::RemoveSnippet(const QString &name, bool &success) {
    success = false;
    if (m_snippets != nullptr && m_snippets->contains(name)) {
        success = (m_snippets->remove(name) > 0);
    }
}

QString Snippets::GetSnippet(const QString &name, bool &success) {
    success = false;
    if (m_snippets != nullptr && m_snippets->contains(name)) {
        success = true;
        return m_snippets->value(name);
    }
    return QString();
}

bool Snippets::OkToInsert(const QString &name) {
    return (m_snippets != nullptr && !m_snippets->contains(name));
}

QList<QString> Snippets::GetKeys(bool &success) {
    success = false;
    if (m_snippets != nullptr) {
        success = true;
        return m_snippets->keys();
    }
    return QList<QString>();
}

Snippets::~Snippets() {
    if (m_snippets != nullptr) {
        bool success;
        SaveSnippets(success); // save on the destructor
        if (!success) {
            std::cerr << "Writing Snippets to Database on save failed" << std::endl;
        }
        delete m_snippets;
    }
}
