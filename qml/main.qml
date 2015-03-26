import QtQuick 2.0
import com.syberos.basewidgets 1.0

CPageStackWindow {
    initialPage:CPage{
        width:parent.width
        height:parent.height

        Rectangle {
            anchors.centerIn: parent

            Row {
                id:row_1
                spacing: 10
                anchors.centerIn: parent

                function sendMsg() {
                        console.log("sendMsg Button clicked");
                        client.sendMsg();
                }

                CButton{
                        text: "Send a Msg"
                        onClicked: row_1.sendMsg()
                }

                Text {
                    text: qsTr("Hello World")
                    id: maintext
                }

                Connections {
                   target: monitor
                   onChangText : maintext.text = "get a message from server..."
                }
            }
        }
    }
}

