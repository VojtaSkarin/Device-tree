#include "card_reader.hpp"

std::string ReverseBytesAndPad( const std::string & s ) {
	const int SIZE = 16;
	std::string result( SIZE, '0' );

	for ( unsigned int i = 0; i < s.size(); i += 2 ) {
		result.at( result.size() - 2 - i ) = s.at( i );
		result.at( result.size() - 1 - i ) = s.at( i + 1 );
	}

	return result;
}

std::string CardReader::GetCurrentState() const {
	std::stringstream s;

	s << Device::GetCurrentState();
	s << "; AccessCardNumber: " << AccessCardNumber << std::endl;

	return s.str();
}