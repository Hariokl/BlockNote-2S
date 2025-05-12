#pragma once
#include <string>
#include <vector>

class Text {
public:
    void addLine(const std::string& line);
    void insertLine(size_t index, const std::string& line);
    void removeLine(size_t index);
    void editLine(size_t index, const std::string& newLine);

    const std::vector<std::string>& getLines() const;
    size_t getSymbolCount() const;

private:
    std::vector<std::string> lines;
};
