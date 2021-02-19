#pragma once

#include <iostream>

#include "components/device.hpp"
#include "components/led_panel.hpp"
#include "components/door.hpp"
#include "components/speaker.hpp"
#include "components/card_reader.hpp"
#include "components/device_group.hpp"

#include "read.hpp"
#include "interactive_mode.hpp"
#include "interactive_change_property.hpp"

void InterActiveAddDoor( DeviceGroup & group );

void InterActiveAddSpeaker( DeviceGroup & group );

void InterActiveAddCardReader( DeviceGroup & group );

void InterActiveAddDeviceGroup( DeviceGroup & group );

void InterActiveAddDevice( DeviceGroup & group, int depth );

void InterActiveDeleteDevice( DeviceGroup & group );

void InterActiveMoveDevice( DeviceGroup & group );
