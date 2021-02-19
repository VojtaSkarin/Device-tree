#pragma once

#include "device.hpp"

std::string ReverseBytesAndPad( const std::string & s );

class CardReader : public Device {
	constexpr static auto setter = [] ( std::string & value, const std::string & number ) {
		if ( number.size() % 2 == 1 || number.size() > 16 ||
			! std::all_of( number.begin(), number.end(), [] ( char c ) { return isxdigit( c ); } ) ) {

			std::stringstream s;
			s << "Number was " << number << std::endl;
			throw std::invalid_argument( s.str() );
		}
		value = ReverseBytesAndPad( number );
	};
	
public:
	Property< std::string, CardReader > AccessCardNumber;

	CardReader( DeviceGroup * parent, const std::string & name = "",
		const std::string & number = "" ) :
		Device( parent, name, DeviceType::CardReader ),
		AccessCardNumber( this, number, setter ) {}

	std::string GetCurrentState() const override;
};