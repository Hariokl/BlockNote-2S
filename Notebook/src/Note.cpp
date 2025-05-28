#include "Note.h"
#include <QFile>
#include <QTextStream>
#include <stdexcept>

Note::Note(const QString& title) : title(title) {}

void Note::setTitle(const QString& title) {
    this->title = title;
}

QString Note::getTitle() const {
    return title;
}

void Note::addLine(const QString& line) {
    content.addLine(line);
}

void Note::insertLine(size_t index, const QString& line) {
    content.insertLine(index, line);
}

void Note::removeLine(size_t index) {
    content.removeLine(index);
}

void Note::editLine(size_t index, const QString& newLine) {
    content.editLine(index, newLine);
}

const std::vector<QString>& Note::getLines() const {
    return content.getLines();
}

size_t Note::getSymbolCount() const {
    return content.getSymbolCount();
}

void Note::saveToFile(const QString& filename) const {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        throw std::runtime_error("Cannot open file for writing");
    }

    QTextStream out(&file);
    for (const auto& line : content.getLines()) {
        out << line << "\n";
    }
}

void Note::loadFromFile(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw std::runtime_error("Cannot open file for reading");
    }

    content = Text(); // Reset content
    QTextStream in(&file);
    while (!in.atEnd()) {
        content.addLine(in.readLine());
    }
}
