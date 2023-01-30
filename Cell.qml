import QtQuick 2.0

//import "Controller.js" as Controller

Rectangle {
    id:cell
    property alias internalText: text
//    x: size * col
//    y: size * row
//    color: (col + row) % 2 ? "#90652C" : "#DEB887"
    color: "#DEB887"
    border.color: "black"
    border.width: 1
    radius: 5
    Text{
        id:text
        text: "1"
        font.bold: true
        anchors.centerIn: cell
        font.pointSize : cell.height * 0.6
    }

    Component.onCompleted: {
//        window.update.connect(Controller.show(cell, Controller.currentShow))
    }
//    Connections {
//     target: window
//     ignoreUnknownSignals: true
//     function onUpdate(){
//         Controller.show(cell, Controller.currentShow)
//     }
//    }
//    Connections {
//     target: agregator
//     ignoreUnknownSignals: true
//     function onSizeChanged(size){
//         cell.destroy();
//     }
//    }
}
