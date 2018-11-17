import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3


Frame {
    implicitHeight: 250
    implicitWidth: 250

    ListView {
        anchors.fill: parent
        model: PlayListModel
        spacing: 2

        delegate: Rectangle {
            width: parent.width
            height: 40
            border.color: "black"
            radius: 4
            color: {
                if (model.playing === "playing") {
                    return "lightblue"
                }
                return "white"
            }
            RowLayout {
                anchors.fill: parent
                Image {
                    Layout.margins: 2
                    source: {
                        if (model.type === "USB") {
                            return "qrc:/images/usb.png"
                        }
                        return "qrc:/images/bta.png"
                    }
                } //Image
                Text {
                    font.bold: true
                    font.pixelSize: 14
                    Layout.fillWidth: true
                    text: model.type + " -> " + model.description
                    horizontalAlignment: Text.AlignHCenter
                } //Text
                Image {
                    Layout.margins: 2
                    source: {
                        if (model.playing === "playing") {
                            return "qrc:/images/play.png"
                        }
                        return "qrc:/images/stop.png"
                    }
                } //Image
            } //RowLayout
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (model.playing === "playing") {
                        model.playing = "stopped"
                    }
                    else if (model.playing === "stopped") {
                        model.playing = "playing"
                    }
                }
            } //MouseArea
        } //Rectangle
    } //ListView
}//Frame
