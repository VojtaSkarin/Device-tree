#pragma once

#include <iostream>
#include <unistd.h>

#include "device.hpp"
#include "led_panel.hpp"
#include "door.hpp"
#include "speaker.hpp"
#include "card_reader.hpp"
#include "device_group.hpp"

#include "create_tree.hpp"

void ChangeRandomAddDevice( DeviceGroup & group );

void ChangeRandomRemoveDevice( DeviceGroup & group );

void ChangeRandomMoveDevice( DeviceGroup & group );

void ChangeRandomName( DeviceGroup & group );

void ChangeRandomAttributeLedPanel( LedPanel & panel );

void ChangeRandomAttributeDoor( Door & door );

void ChangeRandomAttributeSpeaker( Speaker & speaker );

void ChangeRandomAttributeCardReader( CardReader & reader );

void ChangeRandomAttribute( DeviceGroup & group );

void ChangeTree( DeviceGroup & group );