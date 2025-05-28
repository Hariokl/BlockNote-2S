#include <QApplication>
#include "NoteWidget.h"
#include "Note.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Note note("My Note");
    NoteWidget widget;
    widget.loadNote(&note);
    widget.show();

    return app.exec();
}
