#pragma once

#include "interactive/interactive_mode.hpp"

std::string RandomName( std::string && name );

std::unique_ptr< Device > RandomDevice( int depth = 0, DeviceGroup * parent = nullptr );

void RandomFillDeviceGroup( DeviceGroup & group, int depth = 0 );

std::unique_ptr< Device > CreateTree();