#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "reloader.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;
    viewer.setTitle("tst_reloader");
    QString path = QStringLiteral("../qmlreloader/qml/qmlreloader/main.qml");
    viewer.setMainQmlFile(path);
    viewer.showExpanded();

    Reloader reloader(&viewer, path);

    return app.exec();
}
