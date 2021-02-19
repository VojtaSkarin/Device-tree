#pragma once

#include "device.hpp"

enum class SoundState {
	None,
	Music,
	Alarm
};

extern const std::map< SoundState, std::string > SoundStateToStringMap;

std::ostream & operator<<( std::ostream & s, SoundState state );

class Speaker : public Device {
public:
	Property< SoundState, Speaker > Sound;

	Property< double, Speaker > Volume;
	
	Speaker( DeviceGroup * parent, const std::string & name = "",
		SoundState state = SoundState::None, double volume = 0 )
		: Device( parent, name, DeviceType::Speaker ), Sound( this, state ),
		  Volume( this, volume ) {}

	std::string GetCurrentState() const override;
};