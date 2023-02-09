import QtQuick 2.0
//import Qt.labs.platform
import QtQuick.Layouts
import QtQuick.Controls 2.12
import QtQuick.Dialogs
import QtQml
import Tour 1.0

Dialog {
    id:dial
    title: qsTr("New Board")
    modal: Qt.ApplicationModal
    property int size: 5
//    property list<int> intList: [0,1]
    property alias mainMenu: menu
    property alias instantiator: instant
    Getter{
        id: getter
    }
    contentItem:
        MenuBar{
        height: row.height
        width: 100
        Menu{
            id:menu
            width: 100
            title: qsTr("&Count")
            Instantiator{
                id:instant
//                model: getter.getDimensions()
                       delegate: MenuItem{
                           id: mitem
                            text: model.text
                            onTriggered: {
                                console.log(model.text);
                                dial.size = model.text
                                menu.title = model.text
                            }
                        }
                        onObjectAdded: function(index, object) {
                            menu.insertItem(instant.count, object);
                        }
                    Component.onCompleted: {
//                        instant.model = getter.getDimensions();
                    }
                    }
//            contentData: dial.dim
//            delegate:
//            Action {
//                text: display.toString()
////                onTriggered: size = 5;
//            }
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
