#include <QDebug>

#include "playlistmodel.h"

PlayListModel::PlayListModel(QObject *parent)
    : QAbstractListModel(parent)
    , m_playList(nullptr)
{
}

int PlayListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    if (m_playList) {
        return m_playList->size();
    }

    return 0;
}

QVariant PlayListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const int row = index.row();
    const PlayListItem &item = m_playList->at(row);

    switch (role) {
    case PlayingRole: {
        if (item.isPlaying()) {
            return QVariant(QStringLiteral("playing"));
        }
        return QVariant(QStringLiteral("stopped"));
    }
    case DescriptionRole:
        return QVariant(item.description());
    case TypeRole:
        if (item.itemType() == PlayListItem::Type_Usb) {
            return QVariant(QStringLiteral("USB"));
        }
        if (item.itemType() == PlayListItem::Type_Bta) {
            return QVariant(QStringLiteral("BTA"));
        }
    }

    return QVariant();
}

bool PlayListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        if (!value.canConvert<QString>()){
            return false;
        }
        const QString &command = value.toString();
        if (command == "playing")
        {
            //Stop track if playing another
            for (int row = 0; row < m_playList->size(); ++row) {
                PlayListItem &track = (*m_playList)[row];
                if (track.isPlaying()) {
                    track.stop();
                    const QModelIndex &changedIndex = this->index(row);
                    emit dataChanged(changedIndex, changedIndex, QVector<int>() << role);
                }
            }
        }

        const int row = index.row();
        PlayListItem &track = m_playList->data()[row];
        if (track.isPlaying()){
            track.stop();
        } else if (!track.isPlaying()) {
            track.play();
        }
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags PlayListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
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
