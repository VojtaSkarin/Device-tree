#include "led_panel.hpp"

std::string LedPanel::GetCurrentState() const {
	std::stringstream s;

	s << Device::GetCurrentState();
	s << "; Message: " << Message << std::endl;

	return s.str();
}