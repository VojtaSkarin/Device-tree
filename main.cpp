#include "components/device.hpp"
#include "components/led_panel.hpp"
#include "components/door.hpp"
#include "components/speaker.hpp"
#include "components/card_reader.hpp"
#include "components/device_group.hpp"

#include "create_tree.hpp"
#include "change_tree.hpp"
#include "interactive_mode.hpp"

int main( void ) {
	std::unique_ptr< Device > tree = CreateTree();

	ChangeTree( static_cast< DeviceGroup & > ( * tree ) );

	std::cout << "Interactive mode" << std::endl;

	InterActiveMode( * tree, 0 );
	
	return EXIT_SUCCESS;
}