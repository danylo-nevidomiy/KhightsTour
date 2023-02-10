import QtQuick 2.11
import QtQuick.Layouts 1.1
//import QtQuick.Window 2.11
import QtQuick.Controls.Material 2.12
import QtQuick.Controls
import Tour 1.0

Window {
    id: window
    visible: true
    width: 800
    height: 600
    title: qsTr("Knight's tour")

    Getter{
        id: getter
    }
    InfoDialog{
        id:vd
        title: qsTr("You are win!")
        contentItem: Text{
            text: "Congratulations! You are win!!!"
        }
    }
    InfoDialog{
        id:aboutPage
        title: qsTr("Knight`s Tour")
        contentItem: Text{
            text: "Knight`s Tour Game"
        }
    }
    MenuModel{
        id:model
    }
    CreateBoardDialog{
        id:createDial

        onAccepted: {
            board.model = getter.changeBoard(createDial.size);
        }
        Component.onCompleted: {
            createDial.instantiator.model = model

        }
    }
    ColumnLayout{
        id:col
        anchors.fill: parent
        Layout.alignment: Qt.AlignHCenter

        GroupBox{
            id:gb
            Layout.column:0
            Layout.alignment: Qt.AlignCenter
            Layout.fillWidth: true
            Layout.fillHeight: true
            Rectangle{
                id:rect
                anchors.fill: parent
                Board{
                    id:board
                    height:(rect.width > rect.height ? rect.height : rect.width)
                    width: (rect.width > rect.height ? rect.height : rect.width)
                    anchors.horizontalCenter: rect.horizontalCenter
                    anchors.margins: 5
                    Component.onCompleted: {
                        board.model = getter.getBoard();
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

                anchors.margins: 8
                spacing: 8

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
                RoundButton{
                    height: row.height
                    text: qsTr("About")
                    Material.background: "burlywood"
                    Material.foreground: "black"
                    Layout.alignment: Qt.AlignHCenter
                    radius: 5
                    onClicked: {
                        aboutPage.open();
                    }
                }

            }
        }
    }



}
