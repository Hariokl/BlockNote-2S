#pragma once
#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include "Note.h"

class NoteWidget : public QWidget {
    Q_OBJECT

public:
    explicit NoteWidget(QWidget* parent = nullptr);
    void loadNote(Note* note);
    void saveNote();

private slots:
    void onAddLine();
    void onRemoveLine();
    void onSaveToFile();
    void onLoadFromFile();
    void updateContent();

private:
    Note* currentNote;
    QLineEdit* titleEdit;
    QTextEdit* contentEdit;
    QPushButton* addButton;
    QPushButton* removeButton;
    QPushButton* saveFileButton;
    QPushButton* loadFileButton;

    void setupUI();
    void updateUI();
};
