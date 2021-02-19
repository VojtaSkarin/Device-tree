#include "device.hpp"

const std::vector< DeviceType > DeviceTypes = {
	DeviceType::LedPanel,
	DeviceType::Door,
	DeviceType::Speaker,
	DeviceType::CardReader,
	DeviceType::DeviceGroup
};

const std::map< DeviceType, std::string > DeviceTypeToStringMap = {
	{ DeviceType::LedPanel,    "LedPanel" },
	{ DeviceType::Door,        "Door" },
	{ DeviceType::Speaker,     "Speaker" },
	{ DeviceType::CardReader,  "CardReader" },
	{ DeviceType::DeviceGroup, "DeviceGroup" }
};

std::ostream & operator<<( std::ostream & o, DeviceType type ) {
	o << DeviceTypeToStringMap.at( type );
	return o;
}

int Device::GetNewId() {
		if ( IdPool.empty() ) {
			IdPool.insert( 0 );
			return 0;
		}

		int currentMax = * IdPool.rbegin();
		int newId = currentMax + 1;
		IdPool.insert( newId );
		return newId;
	}

std::string Device::GetCurrentState() const {
		std::stringstream s;
		s << "Id: " << Id << "; DeviceType: " << Type << "; Name: " << Name;
		return s.str();
	}

std::set< int > Device::IdPool;
Device::~Device() = default;