import QtQuick 2.0
import QtQuick.Controls 1.3

import CuteHMI.Modbus 1.0

/*!
  \qmltype CoilItem
  \inqmlmodule CuteHMI.Modbus
  \since CuteHMI.Modbus 1.0
  \brief Modbus coil item.

  Coil item is intended to interact with \a parent item in which it can be placed. It is provided as a supplement to CoilController to bypass
  limitations of QML Designer and make it possible to work in QML "design" mode directly. In addition it provides its own visuals to show
  \a controller.busy status.
  */
Item
{
	id: root

	anchors.verticalCenter: parent.verticalCenter
	anchors.horizontalCenter: parent.horizontalCenter

	property alias device: coilController.device
	property alias address: coilController.address
	property alias busy: coilController.busy
	property alias busyIndicator: busyIndicator
	property alias controller: coilController

	ExtBusyIndicator
	{
		id: busyIndicator

		running: coilController.busy
		centerIn: parent
	}

	CoilController
	{
		id: coilController

		delegate: root.parent
		device: root.device
		address: root.address
	}
}
