#include "speaker.hpp"

const std::map< SoundState, std::string > SoundStateToStringMap {
	{ SoundState::None,  "None" },
	{ SoundState::Music, "Music" },
	{ SoundState::Alarm, "Alarm" }
};

std::ostream & operator<<( std::ostream & s, SoundState state ) {
	s << SoundStateToStringMap.at( state );
	return s;
}

std::string Speaker::GetCurrentState() const {
	std::stringstream s;

	s << Device::GetCurrentState();
	s << "; Sound: " << Sound << "; Volume: " << Volume << std::endl;

	return s.str();
}