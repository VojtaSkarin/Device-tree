#include "door.hpp"

const std::map< DoorState, std::string > DoorStateToStringMap = {
	{ DoorState::Locked,         "Locked" },
	{ DoorState::Open,           "Open" },
	{ DoorState::OpenForTooLong, "OpenForTooLong" },
	{ DoorState::OpenedForcibly, "OpenedForcibly" },
};

std::ostream & operator<<( std::ostream & s, DoorState state ) {
	if ( state == static_cast< DoorState >( 0 ) ) {
		s << "None";
		return s;
	}
	
	bool flag = false;

	for ( int i = 1; i <= 8; i <<= 1 ) {
		if ( ( static_cast< int >( state ) & i ) > 0 ) {
			if ( flag ) {
				s << ", ";
			}

			s << DoorStateToStringMap.at( static_cast< DoorState >( i ) );
			flag = true;
		}
	}

	return s;
}

DoorState & operator|=( DoorState & left, DoorState right ) {
	left = static_cast< DoorState >(
		static_cast< int >( left ) | static_cast< int >( right )
	);
	return left;
}

DoorState operator|( DoorState left, DoorState right ) {
	left |= right;
	return left;
}

DoorState & operator&=( DoorState & left, DoorState right ) {
	left = static_cast< DoorState >(
		static_cast< int >( left ) & static_cast< int > ( right )
	);
	return left;
}

DoorState operator&( DoorState left, DoorState right ) {
	left &= right;
	return left;
}

std::string Door::GetCurrentState() const {
	std::stringstream s;

	s << Device::GetCurrentState();
	s << "; State: " << State << std::endl;

	return s.str();
}