import QtQuick 2.1
import QtQuick.Layouts 1.1
import QtQuick.Window 2.1
//import QtQuick.Controls

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
    Board{

    }
    Component.onCompleted: {

    }
    Row {
        height: 32
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 8
        spacing: 8

        Button {
            height: parent.height
            caption: qsTr("Find")
            onClicked: Controller.find();
//            visible: !canvas.playingState
        }

        Button {
            height: parent.height
            caption: qsTr("Load")
            onClicked: Controller.load();
//            visible: !canvas.playingState
        }

        Button {
            height: parent.height
            caption: qsTr("Stop")
            onClicked: Controller.stop();
//            visible: canvas.playingState
        }

        Button {
            height: parent.height
            caption: qsTr("Save")
            onClicked: Controller.save();
//            visible: canvas.playingState
        }


        Button {
            height: parent.height
            caption: qsTr("Prev")
            onClicked: {
                Controller.prev();
                window.update();
            }
//            visible: canvas.historyState
            enabled: canvas.hasPrevMove
        }

        Button {
            height: parent.height
            caption: qsTr("Next")
            onClicked: {
                Controller.next();
                window.update();
            }
//            visible: canvas.historyState
            enabled: canvas.hasNextMove
        }
    }
}
