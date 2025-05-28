#pragma once
#include <QString>
#include <vector>
#include <memory>
#include "Text.h"

class Note {
public:
    Note(const QString& title);

    void setTitle(const QString& title);
    QString getTitle() const;

    void addLine(const QString& line);
    void insertLine(size_t index, const QString& line);
    void removeLine(size_t index);
    void editLine(size_t index, const QString& newLine);

    const std::vector<QString>& getLines() const;
    size_t getSymbolCount() const;

    void saveToFile(const QString& filename) const;
    void loadFromFile(const QString& filename);

private:
    QString title;
    Text content;
};
