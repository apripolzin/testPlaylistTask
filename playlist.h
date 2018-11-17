#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QVector>

class QString;

class PlayListItem {
public:
    enum PlayListItemType {
        Type_Usb, Type_Bta
    };
    PlayListItem(QString description = "empty description", PlayListItemType type = Type_Usb);
    void play();
    void stop();
    bool isPlaying() const;

    QString description() const;
    PlayListItemType itemType() const;

private:
    bool m_isPlaying;
    QString m_description;
    PlayListItemType m_itemType;
};

typedef QVector<PlayListItem> PlayList;

#endif // PLAYLIST_H
