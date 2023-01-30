import QtQuick 2.0
import Tour 1.0

GridView{
    id:board

    cellHeight: height/board.model.size
    cellWidth: width/board.model.size

    interactive: false

    delegate: Item {
        id: _backgroundDelegate
        width: board.cellWidth
        height: board.cellHeight



        Cell{
            anchors.fill: _backgroundDelegate
            anchors.margins: 5

            internalText.text: display.toString()

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    board.model.step(index)
                }
            }
//            height: board.cellHeight
//            width: board.cellWidth
            //        size: board.width<board.height ? board.width/5 : board.height/5
            //        width: board.width/5
            //        height: board.height/5
        }
    }

    Getter{
        id: getter
    }
    Component.onCompleted: {

        board.model = getter.getBoard();
        //        Controller.createCells(board)
    }
}
