#pragma once
#include <QString>
#include <vector>

class Text {
public:
    void addLine(const QString& line);
    void insertLine(size_t index, const QString& line);
    void removeLine(size_t index);
    void editLine(size_t index, const QString& newLine);

    const std::vector<QString>& getLines() const;
    size_t getSymbolCount() const;

private:
    std::vector<QString> lines;
};
