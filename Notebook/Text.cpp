#include "Text.h"
#include <numeric>
#include <stdexcept>

void Text::addLine(const std::string& line) {
    lines.push_back(line);
}

void Text::insertLine(size_t index, const std::string& line) {
    if (index > lines.size()) {
        throw std::out_of_range("Invalid line index");
    }
    lines.insert(lines.begin() + index, line);
}

void Text::removeLine(size_t index) {
    if (index >= lines.size()) {
        throw std::out_of_range("Invalid line index");
    }
    lines.erase(lines.begin() + index);
}

void Text::editLine(size_t index, const std::string& newLine) {
    if (index >= lines.size()) {
        throw std::out_of_range("Invalid line index");
    }
    lines[index] = newLine;
}

const std::vector<std::string>& Text::getLines() const {
    return lines;
}

size_t Text::getSymbolCount() const {
    return std::accumulate(lines.begin(), lines.end(), 0,
        [](size_t total, const std::string& line) {
            return total + line.size();
        });
}
