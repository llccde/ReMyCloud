import QtQuick
import RMC 1.0
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Text {
        id: name
        text: MainAdapter.hello
    }
}
