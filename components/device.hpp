#pragma once

#include <set>
#include <stdexcept>
#include <string>
#include <sstream>
#include <map>

#include "../property_readonly.hpp"
#include "../property.hpp"

class DeviceGroup;

enum class DeviceType {
	LedPanel,
	Door,
	Speaker,
	CardReader,
	DeviceGroup
};

extern const std::vector< DeviceType > DeviceTypes;

extern const std::map< DeviceType, std::string > DeviceTypeToStringMap;

std::ostream & operator<<( std::ostream & o, DeviceType type );

class Device {
	static std::set< int > IdPool;

	constexpr static auto IdSetter = [] ( auto & value, const auto & newValue ) {
		auto & IdPool = Device::IdPool;
		
		auto it = IdPool.find( newValue );

		if ( it != IdPool.end() ) {
			throw std::invalid_argument( "Id is already used" );
		}

		it = IdPool.find( value );
		IdPool.erase( it );

		IdPool.insert( newValue );
		value = newValue;
	};

	static int GetNewId();

public:
	PropertyReadOnly< DeviceGroup * > Parent;

	PropertyReadOnly< DeviceType > Type;

	Property< int, Device > Id;

	Property< std::string, Device > Name;

	Device( DeviceGroup * parent, const std::string & name, DeviceType type )
		: Parent( parent ), Type( type ), Id( this, GetNewId(), IdSetter ),
		  Name( this, name ) {}

	virtual ~Device() = 0;

	virtual std::string GetCurrentState() const;
};
