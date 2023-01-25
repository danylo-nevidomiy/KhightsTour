import QtQuick 2.0

import "Controller.js" as Controller

Rectangle {
    id:cell
    property int size: Controller.cellSize
    property int col: 0
    property int row: 0
    property string number: " "
    width: size
    height: size
    x: size * col
    y: size * row
    color: (col + row) % 2 ? "#90652C" : "#DEB887"
    Text{
        id:text
        text: number
        anchors.centerIn: parent
        font.pointSize : parent.size * 0.6
    }

    MouseArea{
        anchors.fill: parent
        onClicked: Controller.step(parent)
    }
    Component.onCompleted: {
//        window.update.connect(Controller.show(cell, Controller.currentShow))
    }
    Connections {
     target: window
     ignoreUnknownSignals: true
     function onUpdate(){
         Controller.show(cell, Controller.currentShow)
     }
    }
}
