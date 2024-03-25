#include "UI.h"
#include "Domain.h"
#include "DynamicVector.h"
#include "Repository.h"

int main()
{
	{
		Dog d = Dog();
		d.testDomain();
		DynamicVector v = DynamicVector();
		v.testDynamicVector();
		Repository r = Repository();
		r.testRepository();
		Service s = Service();
		s.testService();
	
		UI ui;
		ui.run();
	}

	_CrtDumpMemoryLeaks();

	return 0;
}

// put layered architecture as parameter in the constructor in the future