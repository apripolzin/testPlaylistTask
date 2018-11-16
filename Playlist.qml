import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Frame {
    implicitHeight: 250
    implicitWidth: 250

    clip: true

    ListView {
        anchors.fill: parent
        model: ListModel {
            id: model
            ListElement {
                type: "USB"
                description: "Track1"
                playing: "stopped"
            }

            ListElement {
                type: "BTA"
                description: "Track2"
                playing: "stopped"
            }

            ListElement {
                type: "USB"
                description: "Track3"
                playing: "stopped"
            }

            ListElement {
                type: "BTA"
                description: "Track4"
                playing: "stopped"
            }
        }

        delegate: RowLayout {
            id : delegate
            width: parent.width
            Image {
                source: {
                    if (model.type == "USB") {
                        return "qrc:/images/usb.png"
                    } // BTA
                    return "qrc:/images/bta.png"
                }
            }
            TextField {
                Layout.fillWidth: true
                text: model.description
                horizontalAlignment: Text.AlignHCenter
                readOnly: true
            }
            Image {
                source: {
                    if (model.playing == "playing") {
                        return "qrc:/images/play.png"
                    }
                    return "qrc:/images/stop.png"
                }
            }
        }
    }
}
