#pragma once

#include <vector>
#include <cctype>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <random>
#include <memory>
#include <sstream>
#include <map>
#include <functional>
#include <set>

#include "../my_vector.hpp"
#include "device.hpp"

class DeviceGroup : public Device {
public:
	my_vector< std::unique_ptr< Device >, DeviceGroup > Devices;

	DeviceGroup( DeviceGroup * parent, const std::string & name = "" )
		: Device( parent, name, DeviceType::DeviceGroup ), Devices( this ) {}
};
