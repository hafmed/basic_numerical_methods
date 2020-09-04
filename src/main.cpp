#include <QApplication>

#include "basic_numerical_methods.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setApplicationName("basic_numerical_methods");
    QApplication::setOrganizationName("HAFIANE Mohamed");
    QPixmap pixmap = QPixmap (":/icons/basic_numerical_methods.png");
    basic_numerical_methods w;
    w.setWindowIcon(QIcon(pixmap));
    w.show();
    return app.exec();
}

