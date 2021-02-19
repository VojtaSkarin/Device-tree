#pragma once

#include <iostream>

#include "../components/device.hpp"
#include "../components/led_panel.hpp"
#include "../components/door.hpp"
#include "../components/speaker.hpp"
#include "../components/card_reader.hpp"
#include "../components/device_group.hpp"

#include "../read.hpp"

void InterActiveDeviceChangeId( Device & device );

void InterActiveDeviceChangeName( Device & device );

void InterActiveLedPanelChangeMessage( LedPanel & panel );

void InterActiveAddLedPanel( DeviceGroup & group );

void InterActiveDoorChangeLockedState( Door & door );

void InterActiveDoorChangeOpenState( Door & door );

void InterActiveDoorChangeOpenForTooLongState( Door & door );

void InterActiveDoorChangeOpenedForciblyState( Door & door );

void InterActiveSpeakerChangeSoundState( Speaker & speaker );

void InterActiveSpeakerChangeVolume( Speaker & speaker );

void InterActiveCardReaderChangeAccessCardNumber( CardReader & reader );