#include "NoteWidget.h"
#include <QLabel>
#include <QMessageBox>

NoteWidget::NoteWidget(QWidget* parent) : QWidget(parent), currentNote(nullptr) {
    setupUI();
}

void NoteWidget::setupUI() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // Title section
    QHBoxLayout* titleLayout = new QHBoxLayout();
    titleLayout->addWidget(new QLabel("Название:", this));
    titleEdit = new QLineEdit(this);
    titleLayout->addWidget(titleEdit);
    mainLayout->addLayout(titleLayout);

    // Content section
    contentEdit = new QTextEdit(this);
    mainLayout->addWidget(contentEdit);

    // Buttons
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    saveFileButton = new QPushButton("Сохранить файл", this);
    loadFileButton = new QPushButton("Открыть файл", this);

    buttonLayout->addWidget(saveFileButton);
    buttonLayout->addWidget(loadFileButton);
    mainLayout->addLayout(buttonLayout);

    // Connections
    connect(titleEdit, &QLineEdit::textEdited, this, &NoteWidget::updateContent);
    connect(contentEdit, &QTextEdit::textChanged, this, &NoteWidget::updateContent);
    connect(saveFileButton, &QPushButton::clicked, this, &NoteWidget::onSaveToFile);
    connect(loadFileButton, &QPushButton::clicked, this, &NoteWidget::onLoadFromFile);
}

void NoteWidget::loadNote(Note* note) {
    currentNote = note;
    updateUI();
}

void NoteWidget::updateUI() {
    if (!currentNote) return;

    titleEdit->setText(currentNote->getTitle());

    QString content;
    for (auto& line : currentNote->getLines()) {
        content += line + "\n";
    }
    contentEdit->setPlainText(content);
}

void NoteWidget::saveNote() {
    if (!currentNote) return;
    updateContent();
}

void NoteWidget::updateContent() {
    if (!currentNote) return;

    currentNote->setTitle(titleEdit->text());

    QStringList lines = contentEdit->toPlainText().split("\n");
    // currentNote->getLines().clear();
    for (QString& line : lines) {
        currentNote->addLine(line);
    }
}


void NoteWidget::onSaveToFile() {
    if (!currentNote) return;

    QString filename = QFileDialog::getSaveFileName(this, "Save Note", "", "Text Files (*.txt)");
    if (filename.isEmpty()) return;

    try {
        currentNote->saveToFile(filename);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}

void NoteWidget::onLoadFromFile() {
    if (!currentNote) return;

    QString filename = QFileDialog::getOpenFileName(this, "Load Note", "", "Text Files (*.txt)");
    if (filename.isEmpty()) return;

    try {
        currentNote->loadFromFile(filename);
        updateUI();
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}
