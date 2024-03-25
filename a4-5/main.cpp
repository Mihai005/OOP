#include "UI.h"
#include <crtdbg.h>

int main()
{
	UI ui;
	ui.run();
	_CrtDumpMemoryLeaks();
	return 0;
}

// put layered architecture as parameter in the constructor