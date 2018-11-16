#include <QDebug>

#include "playlistmodel.h"
#include "playlist.h"

PlayListModel::PlayListModel(QObject *parent)
    : QAbstractListModel(parent)
    , m_playList(nullptr)
{
}

int PlayListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return m_playList->items().size();

    // FIXME: Implement me!
}

QVariant PlayListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const int row = index.row();
    const PlayListItem &item = m_playList->items().at(row);

    switch (role) {
    case PlayingRole: {
        if (item.isPlaying) {
            return QVariant(QStringLiteral("playing"));
        }
        return QVariant(QStringLiteral("stopped"));
    }
    case DescriptionRole:
        return QVariant(item.description);
    case TypeRole:{
        if (item.itemType == PlayListItem::Type_Usb) {
            return QVariant(QStringLiteral("USB"));
        }
        if (item.itemType == PlayListItem::Type_Bta) {
            return QVariant(QStringLiteral("BTA"));
        }

    }
    }

    // FIXME: Implement me!
    return QVariant();
}

bool PlayListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        qDebug() << "Set Data from cpp" << index.row() << value << role;
        PlayListItem &item = m_playList->items()[index.row()];
        item.isPlaying = !item.isPlaying;
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags PlayListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}

QHash<int, QByteArray> PlayListModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[PlayingRole] = "playing";
    names[DescriptionRole] = "description";
    names[TypeRole] = "type";
    return names;
}

void PlayListModel::setPlayList(PlayList *list)
{
    m_playList = list;
}
