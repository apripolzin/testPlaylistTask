#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QObject>
#include <QString>
#include <QVector>

struct PlayListItem {
    enum PlayListItemType {
        Type_Usb, Type_Bta
    };
    PlayListItem(bool playing = false, QString desc = "no description", PlayListItemType type = Type_Usb)
        : isPlaying(playing)
        , description(desc)
        , itemType(type)
    {}
    bool isPlaying;
    QString description;
    PlayListItemType itemType;
};

class PlayList : public QObject
{
    Q_OBJECT
public:
    explicit PlayList(QObject *parent = nullptr);
    bool setItemAt(int index, const PlayListItem &item);

    QVector<PlayListItem> &items();

private:
    QVector<PlayListItem> m_items;
};

#endif // PLAYLIST_H
