#include "UI.h"

int main()
{
	cout << "Choose Repository type: \n";
	cout << "1. CSV\n";
	cout << "2. HTML\n";
	cout << "Option: ";
	string option;
	getline(cin, option);
	if (option == "1")
	{
		RepositoryFileCSV repo = RepositoryFileCSV("AdoptedDogs.csv");
		Service service = Service(&repo);
		UI ui = UI(service);
		ui.run();
	}
	else if (option == "2")
	{
		RepositoryFileHTML repo = RepositoryFileHTML("AdoptedDogs.html");
		Service service = Service(&repo);
		UI ui = UI(service);
		ui.run();
	}
	else
	{
		cout << "Invalid option!\n";
		return 0;
	}
}



/*
Husky,Rex,1,https://shelter/link1.com
Golden Retriever,Max,2,https://shelter/link2.com
Labrador,Bella,3,https://shelter/link3.com
Pug,Luna,4,https://shelter/link4.com
Beagle,Charlie,5,https://shelter/link5.com
Poodle,Lucy,6,https://shelter/link6.com
Dalmatian,Daisy,7,https://shelter/link7.com
German Shepherd,Rocky,8,https://shelter/link8.com
Chihuahua,Bailey,9,https://shelter/link9.com
Pomeranian,Sadie,10,https://shelter/link10.com
*/