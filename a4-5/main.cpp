#include "UI.h"
#include "Tests.h"

int main()
{
    {
		testAll();
		//UI ui;
		//ui.run();
	}
	
	_CrtDumpMemoryLeaks();

	return 0;
}

// put layered architecture as parameter in the constructor in the future