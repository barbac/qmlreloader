#ifndef RELOADER_H
#define RELOADER_H

#include <QObject>

class QtQuick2ApplicationViewer;
class QTimer;

class Reloader : public QObject
{
    Q_OBJECT
public:
    explicit Reloader(QtQuick2ApplicationViewer *viewer, const QString &path,
                      QObject *parent = 0);
    ~Reloader();

signals:

public slots:
    void timeIt();
    void reload();

private:
    QString m_mainFile;
    QTimer *m_timer;
    QtQuick2ApplicationViewer *m_viewer;

};

#endif // RELOADER_H
