#include "Note.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

Note::Note(const std::string& title) : title(title) {}

void Note::setTitle(const std::string& title) {
    this->title = title;
}

std::string Note::getTitle() const {
    return title;
}

void Note::addLine(const std::string& line) {
    content.addLine(line);
}

void Note::insertLine(size_t index, const std::string& line) {
    content.insertLine(index, line);
}

void Note::removeLine(size_t index) {
    content.removeLine(index);
}

void Note::editLine(size_t index, const std::string& newLine) {
    content.editLine(index, newLine);
}

const std::vector<std::string>& Note::getLines() const {
    return content.getLines();
}

size_t Note::getSymbolCount() const {
    return content.getSymbolCount();
}

void Note::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        throw std::runtime_error("Cannot open file for writing: " + filename);
    }

    for (const auto& line : content.getLines()) {
        file << line << "\n";
    }
}

void Note::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Cannot open file for reading: " + filename);
    }

    content = Text(); // Сбрасываем содержимое
    std::string line;
    while (std::getline(file, line)) {
        content.addLine(line);
    }
}
