import QtQuick 2.0
//import Qt.labs.platform 1.1
import QtQuick.Controls 2.12
import QtQuick.Dialogs


Dialog{
    id:md
    x: (parent.width - width) / 2
    y: (parent.height - height) / 2
//    implicitWidth: 100
//    implicitHeight: 50
    standardButtons: Dialog.Ok
    onAccepted:{
        md.close();
    }
}
