#pragma once

#include <memory>

#include "device.hpp"
#include "led_panel.hpp"
#include "door.hpp"
#include "speaker.hpp"
#include "card_reader.hpp"
#include "device_group.hpp"

#include "read.hpp"
#include "interactive_change_property.hpp"
#include "interactive_change_structure.hpp"

void PrintTree( const Device & device, int depth = 0 );

void printDevice( const Device * device );

void printTree( const Device * device );

void InterActiveSelectDevice( DeviceGroup & group, int depth );

void InterActiveLedPanel( LedPanel & panel );

void InterActiveDoor( Door & door );

void InterActiveSpeaker( Speaker & speaker );

void InterActiveCardReader( CardReader & reader );

void InterActiveDeviceGroup( DeviceGroup & group, int depth );

void InterActiveMode( Device & device, int depth );