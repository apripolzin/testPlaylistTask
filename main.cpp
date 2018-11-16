#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "playlistmodel.h"
#include "playlist.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

   // qmlRegisterType<PlayListModel>("PlayListModel", 1, 0, "PlayListModel");

    PlayList playList;
    PlayListModel model;
    model.setPlayList(&playList);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("PlayListModel"), &model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
