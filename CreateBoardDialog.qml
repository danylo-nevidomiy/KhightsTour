import QtQuick 2.0
//import Qt.labs.platform
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Dialogs
import QtQml

Dialog {
    id:dial
    title: qsTr("New Board")
    modal: Qt.ApplicationModal
    property int size: 5
//    property list<int> intList: [0,1]
    property alias mainMenu: menu
    property alias instantiator: instant
    contentItem:
        MenuBar{
        height: row.height
        width: 100
        Menu{
            id:menu
            width: 100
            title: qsTr("&Count")
            Repeater{
                id:instant

                        MenuItem{
                            text: display.toString()
                        }
//                        onObjectAdded: menu.insertItem(index, object)
                    }
//            contentData: dial.dim
            delegate:
            Action {
                text: display.toString()
//                onTriggered: size = 5;
            }
        }
    }
    standardButtons: Dialog.Ok | Dialog.Cancel

//    onAccepted:{
////        this.result =
//    }
    onRejected: {
        this.close();
    }

}
