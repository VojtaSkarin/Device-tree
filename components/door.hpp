#pragma once

#include "device.hpp"

enum class DoorState : int {
	Locked = 1,
	Open = 2,
	OpenForTooLong = 4,
	OpenedForcibly = 8
};

extern const std::map< DoorState, std::string > DoorStateToStringMap;

std::ostream & operator<<( std::ostream & s, DoorState state );

DoorState & operator|=( DoorState & left, DoorState right );

DoorState operator|( DoorState left, DoorState right );

DoorState & operator&=( DoorState & left, DoorState right );

DoorState operator&( DoorState left, DoorState right );

class Door : public Device {
	constexpr static auto setter = [] ( Property< DoorState, Door > & state, int position ) {
		return [ & state, position ] ( bool &, bool flag ) {
			if ( flag ) {
				state = state | static_cast< DoorState >( 1 << position );
			} else {
				state = state & static_cast< DoorState >( ~( 1 << position ) );
			}
		};
	};
	
	constexpr static auto getter = [] ( Property< DoorState, Door > & state, int position ) {
		return [ & state, position ] ( bool ) {
			return ( static_cast< int >( static_cast< DoorState >( state ) ) &
				( 1 << position ) ) > 0;
		};
	};
	
public:
	Property< DoorState, Door > State;

	Property< bool, Door > Locked;

	Property< bool, Door > Open;

	Property< bool, Door > OpenForTooLong;

	Property< bool, Door > OpenedForcibly;

	Door( DeviceGroup * parent, const std::string & name = "",
		DoorState state = static_cast< DoorState >( 0 ) )
		: Device( parent, name, DeviceType::Door ),
		 State( this, state ),
		 Locked         ( this, false, setter( State, 0 ), getter( State, 0 ) ),
		 Open           ( this, false, setter( State, 1 ), getter( State, 1 ) ),
		 OpenForTooLong ( this, false, setter( State, 2 ), getter( State, 2 ) ),
		 OpenedForcibly ( this, false, setter( State, 3 ), getter( State, 3 ) )
		 {}

	std::string GetCurrentState() const override;
};