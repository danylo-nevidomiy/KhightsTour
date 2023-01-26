import QtQuick 2.0

Rectangle {

    property alias caption:txt.text
    height: 64
    width: txt.width + 24
    radius: 8
    Text{
        id:txt
        anchors.centerIn: parent

        style: Text.Raised
        text:"0"
    }
}
