import QtQuick 2.5
import QtQuick.Controls 1.4
import Source 1.0
import QtQuick.Dialogs 1.2
ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hanoi")
    FileDialog {
        id: fileDialog
        title: "Please choose a save file"
        folder: shortcuts.home
        onAccepted: {
            source.save(fileDialog.fileUrl);
            visible=false;
        }
        Component.onCompleted: visible = false
    }
    Button{
        id: base;
        text:"Exit"
        width: parent.width/1.1;
        height: parent.height/20;
        anchors.top: save.bottom;
        anchors.horizontalCenter: save.horizontalCenter;
        onClicked: {
            Qt.quit();
        }
    }
    Button{
        id: save;
        text:"Save solution";
        width: base.width;
        height: base.height;
        anchors.top: numeric.bottom;
        anchors.horizontalCenter: numeric.horizontalCenter;
        onClicked: {
            fileDialog.visible=true;
        }
    }
    Button{
        id: start;
        text:"Start";
        width: base.width;
        height: base.height;
        anchors.top: parent.top;
        anchors.horizontalCenter: parent.horizontalCenter;
        onClicked: {
            source.start(spinBox.value);
        }
    }
    Rectangle{
        id: numeric;
        width:base.width;
        height: base.height;
        Label{
            text:"Disks value:";
            width: parent.width/2;
            height: parent.height;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;

        }
        SpinBox{
            id:spinBox;
            width: parent.width/2;
            height: parent.height;
            anchors.right: parent.right;
            value:3;
            maximumValue: 20;
        }
        anchors.top: start.bottom;
        anchors.horizontalCenter: start.horizontalCenter;
    }
    Source{
        id:source;
        onGenerated: {
            res.model=result;
        }
    }
    ListView{
        id:res;
        delegate: Rectangle {
            height: 40
            color: "#e6fcff"
            border.color: "#c1fafb"
            width: parent.width
            Text {
                text: modelData
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter

            }
            anchors.horizontalCenter: parent.horizontalCenter
        }
        width: parent.width;
        height: parent.height*0.7;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.bottom: parent.bottom;
    }
}
