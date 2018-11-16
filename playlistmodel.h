#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include <QAbstractListModel>

class PlayListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit PlayListModel(QObject *parent = nullptr);
    enum {
        PlayingRole = Qt::UserRole,
        DescriptionRole,
        TypeRole,
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

private:
};

#endif // PLAYLISTMODEL_H
