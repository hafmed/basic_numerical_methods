#include <QApplication>
#include <QTranslator>
#include "basic_numerical_methods.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setApplicationName("basic_numerical_methods");
    QApplication::setOrganizationName("HAFIANE Mohamed");
    QPixmap pixmap = QPixmap (":/icons/basic_numerical_methods.png");
    //-----
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0) && QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#endif
    // Setup and load translator for localization
    //-----
    QTranslator translator;
    //QString locale = QLocale::system().name();
    QString locale = QString(QLocale::system().name()).left(2);
    if (locale.length() < 2) locale = "en";
    //qDebug()<<"locale="<<QLocale::system().name();
    if (locale!="fr")
    {
        locale="en";
        if(translator.load(QString(":/translations/qt_") + locale))
            app.installTranslator(&translator);
    }
    //-----
    basic_numerical_methods w;
    w.setWindowIcon(QIcon(pixmap));
    w.show();
    return app.exec();
}

