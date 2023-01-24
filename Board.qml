import QtQuick 2.0

import "Controller.js" as Controller

Rectangle{
    id:board
    anchors.centerIn: parent
    width: Controller.boardWidth
    height: Controller.boardHeight
    color: "#90652C"
    Component.onCompleted: {
        Controller.createCells(board)
    }
}
