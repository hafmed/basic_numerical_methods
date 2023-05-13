#include <QApplication>
#include <QTranslator>
#include "basic_numerical_methods.h"

int main(int argc, char *argv[])
{
#if QT_VERSION >= 0x050600
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling); // DPI support
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps); //HiDPI pixmaps
#endif
    QApplication app(argc, argv);
    QApplication::setApplicationName("Basic Numerical Methods");
    QApplication::setOrganizationName("HAFIANE Mohamed");
    QCoreApplication::setOrganizationName("hafsoftdz");
    QCoreApplication::setApplicationVersion(__VERSION__);
    QPixmap pixmap = QPixmap (":/icons/basic_numerical_methods.png");


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

