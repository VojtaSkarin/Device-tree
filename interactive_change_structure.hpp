#pragma once

#include <iostream>

#include "device.hpp"
#include "led_panel.hpp"
#include "door.hpp"
#include "speaker.hpp"
#include "card_reader.hpp"
#include "device_group.hpp"

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
