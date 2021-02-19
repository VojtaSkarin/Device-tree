#pragma once

#include "device.hpp"

class LedPanel : public Device {
public:
	Property< std::string, LedPanel > Message;

	LedPanel( DeviceGroup * parent, const std::string & name = "",
		const std::string & message = "" )
		: Device( parent, name, DeviceType::LedPanel ), Message( this, message ) {}

	std::string GetCurrentState() const override;
};