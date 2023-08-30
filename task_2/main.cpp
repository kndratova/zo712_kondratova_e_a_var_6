#include "widget.h"
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    ::Widget myWidget;
    myWidget.show();

    return app.exec();
}
