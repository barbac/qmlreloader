#include <QFileSystemWatcher>
#include <QTimer>
#include <QQmlEngine>
#include <QFileInfo>
#include <QDir>

#include <QDebug>

#include "qtquick2applicationviewer.h"
#include "reloader.h"

Reloader::Reloader(QtQuick2ApplicationViewer *viewer, const QString &path,
                   QObject *parent)
    : QObject(parent)
    , m_viewer(viewer)
{
    QFileInfo info(path);
    m_mainFile = info.absoluteFilePath();
    QString dirPath = info.absolutePath();
    qDebug() << "FILE" << m_mainFile;
    qDebug() << "DIR" << dirPath;

    QFileSystemWatcher *pathWatcher = new QFileSystemWatcher(this);
    bool success = pathWatcher->addPath(m_mainFile);
    Q_ASSERT(success);
    pathWatcher->addPath(dirPath);
    connect(pathWatcher, SIGNAL(directoryChanged(QString)), this, SLOT(timeIt()));

    m_timer = new QTimer(this);
    m_timer->setInterval(300);
    m_timer->setSingleShot(true);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(reload()));
}

Reloader::~Reloader()
{
    //m_viewer->deleteLater();
}

void Reloader::timeIt()
{
    //This will prevent multiple reloads
    //since editors may delete and recreate files.
    if (m_timer->isActive())
        m_timer->stop();
    m_timer->start();
}

void Reloader::reload()
{
    qDebug() << "reloading";
    //The engines has a internal cache that prevents reloading.
    QQmlEngine *engine = m_viewer->engine();
    engine->trimComponentCache();
    engine->clearComponentCache();
    m_viewer->setSource(m_mainFile);
}
