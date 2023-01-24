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
    minimumWidth: 480
    minimumHeight: 480
    title: qsTr("Knight's tour")
    Board{

    }
    Component.onCompleted: {

    }
}
