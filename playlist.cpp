#include "playlist.h"

PlayList::PlayList(QObject *parent) : QObject(parent)
{
    m_items << PlayListItem(false, "track1", PlayListItem::Type_Usb)
    << PlayListItem(false, "track2", PlayListItem::Type_Bta)
    << PlayListItem(false, "track3", PlayListItem::Type_Usb)
    << PlayListItem(false, "track3", PlayListItem::Type_Usb);
}

bool PlayList::setItemAt(int index, const PlayListItem &item)
{
    if (index < 0 || index > m_items.size()) {
        return false;
    }
    const PlayListItem &oldItem = m_items.at(index);
    if (oldItem.isPlaying == item.isPlaying) {
        return false;
    }
    m_items[index] = item;
    return true;
}

QVector<PlayListItem> PlayList::items() const
{
    return m_items;
}
