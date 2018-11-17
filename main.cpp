#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "playlistmodel.h"
#include "playlist.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // Hardcode tracks
    PlayList playList = PlayList() << PlayListItem("track1", PlayListItem::Type_Usb)
                                   << PlayListItem("track2", PlayListItem::Type_Bta)
                                   << PlayListItem("track3", PlayListItem::Type_Usb)
                                   << PlayListItem("track4", PlayListItem::Type_Bta)
                                   << PlayListItem("track5", PlayListItem::Type_Bta)
                                   << PlayListItem("track6", PlayListItem::Type_Usb);
    PlayListModel model;
    model.setPlayList(&playList);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("PlayListModel"), &model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
