import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

//import PlayListModel 1.0

Frame {
    implicitHeight: 250
    implicitWidth: 250

    clip: true

    ListView {
        anchors.fill: parent
        model: PlayListModel

        delegate: RowLayout {
            id : delegate
            width: parent.width
            Image {
                source: {
                    if (model.type === "USB") {
                        return "qrc:/images/usb.png"
                    } // BTA
                    return "qrc:/images/bta.png"
                }
            }
            TextField {
                id : textField
                Layout.fillWidth: true
                text: model.description
                horizontalAlignment: Text.AlignHCenter
                readOnly: true
                MouseArea {
                    anchors.centerIn: parent
                    width: delegate.width
                    height: delegate.height
                    onClicked: {
                        if (model.playing === "playing") {
                            model.playing = "stopped"
                        }
                        else if (model.playing === "stopped") {
                            model.playing = "playing"
                        }
                    }
                }
            }
            Image {
                source: {
                    if (model.playing === "playing") {
                        return "qrc:/images/play.png"
                    }
                    return "qrc:/images/stop.png"
                }
            }
        }
    }
}
