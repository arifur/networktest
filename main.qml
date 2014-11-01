import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    objectName: "appWindow"
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Text {
        objectName: "text"
        text: qsTr("Hello World")
        font.pixelSize: 16
        anchors.centerIn: parent
    }
}
