import QtQuick 2.11
import QtQuick.Layouts 1.1
//import QtQuick.Window 2.11
import QtQuick.Controls.Material 2.12
import QtQuick.Controls
import Tour 1.0

//import "Controller.js" as Controller

Window {
    id: window
    visible: true
    width: 800
    height: 600
    //    minimumHeight: 200
    //    minimumWidth: 300
    title: qsTr("Knight's tour")

    Getter{
        id: getter
    }
    VictoryDialog{
        id:vd
    }
    MenuModel{
        id:model
    }
    CreateBoardDialog{
        id:createDial
//        mainMenu{}
//        instantiator.model: getter.getDimensions()
//        mainMenu.contentItem: ListView{
//            model:getter.getDimensions()
//        }
        onAccepted: {
            board.model.changeBoard(createDial.size);
//            board.model.clear();
        }
        Component.onCompleted: {
            createDial.instantiator.model = model

        }
    }
    ColumnLayout{
        id:col
        anchors.fill: parent
        Layout.alignment: Qt.AlignHCenter
        //        Layout.fillWidth: true
        //        Layout.fillHeight: true
        GroupBox{
            id:gb
            //            anchors.fill: parent
            Layout.column:0
            Layout.alignment: Qt.AlignCenter
            Layout.fillWidth: true
            Layout.fillHeight: true
            Rectangle{
                id:rect

                anchors.fill: parent
                //                Layout.fillWidth: true
                //        Layout.alignment:
                //        anchors.top: window.top
                //        anchors.bottom: row.top
                //        anchors.horizontalCenter: window.horizontalCenter
                //        height:(window.width > window.height ? window.height : window.width) - row.height
                //        width: rect.height
                //        anchors.centerIn: parent

                //                color: "black"
                Board{
                    id:board
                    height:(rect.width > rect.height ? rect.height : rect.width)
                    width: (rect.width > rect.height ? rect.height : rect.width)
                    anchors.horizontalCenter: rect.horizontalCenter
                    //                    anchors.fill: parent
                    anchors.margins: 5

                    Component.onCompleted: {

                        board.model = getter.getBoard();
//                        createDial.mainMenu.contentData = board.model.dimensions;
                        //        Controller.createCells(board)
                    }
                    Connections{
                        target: board.model
                        ignoreUnknownSignals: true
                        function onVictory(){
                            vd.open();
                        }
                    }
                }
            }
        }

        GroupBox{
            Layout.column: 1
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter
            RowLayout {
                Layout.alignment: Qt.AlignHCenter
                id:row
                Layout.minimumHeight: 32

                //        anchors.right: parent.right
                //        anchors.left: parent.left
                //        anchors.bottom: parent.bottom
                anchors.margins: 8
                spacing: 8

                //                MenuBar{
                //                    height: row.height
                //                    width: 100
                //                    Menu{
                //                        width: 100
                //                        title: qsTr("&Count")
                //                        Action {
                //                            text: qsTr("5")
                //                            onTriggered: agregator.setSize(5);
                //                        }
                //                        Action {
                //                            text: qsTr("6")
                //                            onTriggered: agregator.setSize(6);
                //                        }
                //                        Action {
                //                            text: qsTr("7")
                //                            onTriggered: agregator.setSize(7);
                //                        }
                //                    }
                //                }

                //                        Rectangle{
                //                        TextEdit{
                //                            height: parent.height
                //                            anchors.centerIn:  parent
                //                            width:50
                //                            text: "count"
                //                        }
                //                        }

                RoundButton{
                    height: row.height
                    text: qsTr("New game")
                    Material.background: "burlywood"
                    Material.foreground: "black"
                    Layout.alignment: Qt.AlignHCenter
                    radius: 5
                    onClicked: {
                        createDial.open();

                    }
                }
                RoundButton{
                    height: row.height
                    text: qsTr("Back")
                    Material.background: "burlywood"
                    Material.foreground: "black"
                    Layout.alignment: Qt.AlignHCenter
                    radius: 5
                    onClicked: {
                        board.model.back();
                    }
                }
                RoundButton{
                    height: row.height
                    text: qsTr("Forward")
                    Material.background: "burlywood"
                    Material.foreground: "black"
                    Layout.alignment: Qt.AlignHCenter
                    radius: 5
                    onClicked: {
                        board.model.forward();
                    }
                }



//                InfoField {
//                    height: row.height
//                    caption:window.width + ":" + window.height + "/" + gb.width + ":" + gb.height + "/" + rect.width + ":" + rect.height + "/" + board.width + ":" + board.height + "/"
//                    //                    caption:"/" + rect.width + ":" + rect.height + "/" + board.width + ":" + board.height + "/"

//                    //            onClicked: Controller.stop();
//                    //            visible: canvas.playingState
//                }
                //                CustomButton {
                //                    height: row.height
                //                    caption: qsTr("New Game")
                //                    onClicked: {
                //                        board.model.clear();
                //                    }
                //                    //            visible: !canvas.playingState
                //                }

                //                CustomButton {
                //                    height: row.height
                //                    caption: qsTr("Save")
                //                    onClicked: Controller.save();
                //                    //            visible: canvas.playingState
                //                }

                //                CustomButton {
                //                    height: row.height
                //                    caption: qsTr("Find")
                //                    onClicked: {
                //                        Controller.find();
                //                    }
                //                    visible: true
                //                }

                //                CustomButton {
                //                    id:prev
                //                    height: row.height
                //                    caption: qsTr("Prev")
                //                    onClicked: {
                //                        Controller.prev();
                //                        window.update();
                //                    }
                //                    //            visible: canvas.historyState
                //                    //            enabled: window.hasPrevResult
                //                }

                //                InfoField {
                //                    height: row.height
                //                    caption: "/"
                //                    //            onClicked: Controller.stop();
                //                    //            visible: canvas.playingState
                //                }


                //                CustomButton {
                //                    id:next
                //                    height: row.height
                //                    caption: qsTr("Next")
                //                    onClicked: {
                //                        Controller.next();
                //                        window.update();
                //                    }
                //                    //            visible: canvas.historyState
                //                    //            enabled: window.hasNextResult
                //                }
            }
        }
    }



}
