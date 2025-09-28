# Colors4Terminal

![Example](assets/Terminal.png)


## Note : This library is designed for personal use.

## If you want to use it anyway :

1. Download the **Colors4Terminal.h** file.	

2. Add it to your project.

3. Include the header in your code : **Colors4Terminal.h**.

4. Optional : Call **EnableVirtualTerminal()** at the start of your program.
	In most cases this isn't required, but it ensures compatibility.

5. Don't forget to use the namespace 'CFT'.

6. For more information just read the comments in the header file.


## Example

```cpp
#include <iostream>
#include "Colors4Terminal.h"

int main()
{
	CFT::EnableVirtualTerminal();

	CFT::ErrorMessage("Message");
	CFT::ErrorMessage("Message in red", 1, 0, 0);
	CFT::ErrorMessage("Error is blinking", 0, 0, 1);
	CFT::ErrorMessage("Error makes a bell sound", 0, 1, 0);

	CFT::WarningMessage("Message");
	CFT::WarningMessage("Message in orange", 1, 0);
	CFT::WarningMessage("Warning is blinking", 0, 1);

	CFT::ColorRGBMessage("RGB", 0, 50, 150);

	CFT::Color color_background{ 40,150,0 };
	CFT::Color color_text{ 100,0,250 };
	CFT::ColorAll("Color All", &color_background, &color_text);


	// Returning strings

	std::cout << CFT::ColorToTextString(&color_text) << "Example Text" << CFT::Default_Color_Code << std::endl;
	std::cout << CFT::ColorToBackgroundString(&color_text) << "Example Background" << CFT::Default_Color_Code << std::endl;
	
	std::cout << CFT::ANSI_CODE::Underline << "underline" << CFT::ANSI_CODE::DefaultColor << std::endl;
	std::cout << CFT::ANSI_CODE::Italic << "italic" << CFT::ANSI_CODE::DefaultColor << std::endl;
	std::cout << CFT::ANSI_CODE::CrossedOut << "crossed out" << CFT::ANSI_CODE::DefaultColor << std::endl;
	
	return 0;
}
``` 

