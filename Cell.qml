import QtQuick 2.0

//import "Controller.js" as Controller

Rectangle {
    id:cell
    property alias internalText: text
//    x: size * col
//    y: size * row
//    color: (col + row) % 2 ? "#90652C" : "#DEB887"
//    color: "#DEB887"
//    border.color: "black"
//    border.width: 1
//    radius: 5
    Text{
        id:text
        text: "1"
//        font.bold: true
        anchors.centerIn: cell
        font.pointSize: getPointSize(cell.height * 0.4)
    }

    function getPointSize(size)
    {
        return size === 0 ? 1 : size;
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
