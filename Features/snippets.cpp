#include "Features/snippets.h"
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
        data.insert(tr("API Help"), tr(
                                        "# Full API\n"
                                        "# ---------------------------\n"
                                        "# get method's have no parameters and others have one\n"
                                        "#\n"
                                        "# get_input   - get input textbox's text\n"
                                        "# set_input   - set input textbox's text\n"
                                        "# get_output  - get output textbox's text\n"
                                        "# set_output  - get output textbox's text\n"
                                        "# get_code    - get code textbox's text\n"
                                        "# set_code    - set code textbox's text\n"
                                        "# write_output- append to output box\n"
                                        "# get_apppath - get exe path\n\n"
                                        "# API Help/Code Sample\n"
                                        "# ---------------------------\n"
                                        "\n"
                                        "# get text from input box\n"
                                        "# parameters - none\n"
                                        "txt = get_input()\n"
                                        "\n"
                                        "# change output box's text\n"
                                        "# parameters - string\n"
                                        "set_output(\"\")\n"
                                        "\n"
                                        "# append to output box\n"
                                        "# does not add a new line\n"
                                        "# parameters - string\n"
                                        "write_output(\"Hi You,\\n\")\n"
                                        "\n"
                                        "# get_apppath() -> get exe path\n"
                                        "print (\"expressPython.exe is at :\", get_apppath())\n\n"));
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
        if (!success) {
            std::cerr << "Writing Snippets to Database on save failed" << std::endl;
        }
        delete m_Snippets;
    }
}
