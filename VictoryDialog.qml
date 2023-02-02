import QtQuick 2.0
import Qt.labs.platform 1.1
import QtQuick.Controls 2.12

MessageDialog{
    id:md
    buttons: MessageDialog.Ok
    text: "Congratulations! You are win!!!"
    onAccepted:{
        md.close();
    }
}
