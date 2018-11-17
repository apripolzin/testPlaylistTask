#include "playlist.h"

#include <QDebug>

PlayListItem::PlayListItem(QString description, PlayListItem::PlayListItemType type)
    : m_isPlaying(false)
    , m_description(description)
    , m_itemType(type)
{}

void PlayListItem::play()
{
    qDebug() << "playing" << m_description;
    m_isPlaying = true;
}

void PlayListItem::stop()
{
    qDebug() << "stopping" << m_description;
    m_isPlaying = false;
}

bool PlayListItem::isPlaying() const
{
    return  m_isPlaying;
}

QString PlayListItem::description() const
{
    return  m_description;
}

PlayListItem::PlayListItemType PlayListItem::itemType() const
{
    return m_itemType;
}


