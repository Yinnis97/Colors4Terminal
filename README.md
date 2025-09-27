# Colors4Terminal


## Note : This library is designed for personal use.

## If you want to use it anyway :

1. Download the **Colors4Terminal.h** file.	

2. Add it to your project.

3. Include the header in your code : **Colors4Terminal.h**.

4. Optional : Call **EnableVirtualTerminal()** at the start of your program.
	In most cases this isn't required, but it ensures compatibility.

5. Don't forget to use the namespace 'TCYK'.

6. Have Fun.


## Example

```cpp
#include <iostream>
#include "Colors4Terminal.h"

int main()
{
	TCYK::EnableVirtualTerminal();

	TCYK::ErrorMessage("Message");
	TCYK::ErrorMessage("Message in red", 1, 0);
	TCYK::ErrorMessage("Error is blinking", 0, 1);

	TCYK::WarningMessage("Message");
	TCYK::WarningMessage("Message in orange", 1, 0);
	TCYK::WarningMessage("Warning is blinking", 0, 1);

	TCYK::ColorRGBMessage("RGB", 0, 50, 150);

	std::cin.get();

	return 0;
}
``` 