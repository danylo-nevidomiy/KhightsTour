import QtQuick 2.1
import QtQuick.Layouts 1.1
import QtQuick.Window 2.1
import QtQuick.Controls

import "Controller.js" as Controller

Window {
    id: window
    visible: true
    width: Controller.windowWidth
    height: Controller.windowHeight
    minimumWidth: 640
    minimumHeight: 480
    signal update()
    title: qsTr("Knight's tour")
    property bool hasNextResult: false
    property bool hasPrevResult: false
    property int current: 0
    property int count: 0
    Board{
        id:board
    }
    Connections {
     target: agregator
//     ignoreUnknownSignals: true
     function onHasNextResultChanged(state){
         window.hasNextResult = state;
     }
    }
    Connections {
     target: agregator
//     ignoreUnknownSignals: true
     function onHasPrevResultChanged(state){
         window.hasPrevResult = state;
     }
    }
    Connections {
     target: agregator
//     ignoreUnknownSignals: true
     function onCurrentChanged(cur){
         window.current = cur;
     }
    }
    Connections {
     target: agregator
//     ignoreUnknownSignals: true
     function onResultCountChanged(c){
         window.count = c;
     }
    }
    Connections {
     target: agregator
//     ignoreUnknownSignals: true
     function onSizeChanged(size){
         Controller.count = size;
         Controller.reCreateCells(board);
     }
    }
    Row {
        height: 32
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 8
        spacing: 8

        MenuBar{
            height: parent.height
            width: 100
        Menu{
            width: 100
        title: qsTr("&Count")
        Action {
            text: qsTr("5")
            onTriggered: agregator.setSize(5);
        }
        Action {
            text: qsTr("6")
            onTriggered: agregator.setSize(6);
        }
        Action {
            text: qsTr("7")
            onTriggered: agregator.setSize(7);
        }
        }
        }

//        Rectangle{
//        TextEdit{
//            height: parent.height
//            anchors.centerIn:  parent
//            width:50
//            text: "count"
//        }
//        }

        CustomButton {
            height: parent.height
            caption: qsTr("Load")
            onClicked: Controller.load();
//            visible: !canvas.playingState
        }

        CustomButton {
            height: parent.height
            caption: qsTr("Save")
            onClicked: Controller.save();
//            visible: canvas.playingState
        }

        CustomButton {
            height: parent.height
            caption: qsTr("Find")
            onClicked: {
                Controller.find();
            }
            visible: true
        }

        CustomButton {
            id:prev
            height: parent.height
            caption: qsTr("Prev")
            onClicked: {
                Controller.prev();
                window.update();
            }
//            visible: canvas.historyState
            enabled: window.hasPrevResult
        }

        InfoField {
            height: parent.height
            caption: current + "/" + count
//            onClicked: Controller.stop();
//            visible: canvas.playingState
        }


        CustomButton {
            id:next
            height: parent.height
            caption: qsTr("Next")
            onClicked: {
                Controller.next();
                window.update();
            }
//            visible: canvas.historyState
            enabled: window.hasNextResult
        }
    }
}
