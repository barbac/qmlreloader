#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;
    viewer.setTitle("tst_reloader");
    viewer.setMainQmlFile(QStringLiteral("qml/qmlreloader/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
