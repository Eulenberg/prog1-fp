#include "fp.h"

#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>


using std::string;
using std::vector;
using std::runtime_error;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;




int main() try
{
	char userinput{};
	vector<Liwanze> vL{};


	
	vL.push_back({ "Joey", Liwanze::amer });	// 0
	vL.push_back({ "Johnny", Liwanze::amer });	// 1
	vL.push_back({ "DeeDee", Liwanze::emea });	// 2 
	vL.push_back({ "Tommy", Liwanze::emea });	// 3
	vL.push_back({ "Suzy", Liwanze::apac });	// 4
	vL.push_back({ "Sheena", Liwanze::amer });	// 5

	

	init_connections(vL);

	print_members(vL);
	print_network(vL);
	
	while (true)
	{
		cout << "Was wollen sie machen? (1 =Liwanze erstellen, 2=Verbindung erstellen, q= beenden):";
		cin >> userinput;
		if (!cin)
		{
			throw runtime_error("bad cin");
		}
		if (userinput == 'q' || userinput == 'Q')
		{
			break;
		}
		switch (userinput)
		{
		case '1':
			add_Liwanze(vL);
			print_network(vL);
			continue;
		case '2':
			user_addconn(vL);
			print_network(vL);
			continue;

		default:
			cout << "Bitte erneut auswählen!";
			continue;

		}
		
	}
	

}



catch (runtime_error& e)
{
	cerr << "Ausnahme (runtime_error):" << e.what() << endl;
	return -1;
}
catch (std::exception& e)
{
	cerr << "Ausnahme (std::exception):" << e.what() << endl;
	return -2;

}
catch (...)
{
	cerr << "Unbekannte Ausnahme" << endl;
	return -3;
}