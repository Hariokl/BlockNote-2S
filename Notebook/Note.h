#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Text.h"

class Note {
public:
    Note(const std::string& title);

    void setTitle(const std::string& title);
    std::string getTitle() const;

    void addLine(const std::string& line);
    void insertLine(size_t index, const std::string& line);
    void removeLine(size_t index);
    void editLine(size_t index, const std::string& newLine);

    const std::vector<std::string>& getLines() const;
    size_t getSymbolCount() const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

private:
    std::string title;
    Text content;
};
