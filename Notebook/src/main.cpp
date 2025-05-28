#include <QApplication>
#include "NoteWidget.h"  // Uses NoteWidget for the GUI
#include "Note.h"        // Uses Note as the data model

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Note note("My Note");  // Creates a Note instance
    NoteWidget widget;     // Creates the GUI widget
    widget.loadNote(&note); // Connects model to view
    widget.show();         // Shows the GUI

    return app.exec();
}
