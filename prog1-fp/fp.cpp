#include "fp.h"

#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>



using std::string;
using std::vector;
using std::runtime_error;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

const vector<string> Liwanze::ves{ "ndef", "amer", "apac", "amea" };

Liwanze::Liwanze(string conname, Region conregion)
	:name{ conname }, loc{ conregion }, connects_to{}, connected_from{}
{
	if (name == "")
	{
		throw runtime_error{ "Objekt name ist Leerer String" };
	}
}

Liwanze::Liwanze(string name, Region region, vector<string> connects_to, vector<string> connected_from)
	:name{ name }, loc{ region }, connects_to{ connects_to }, connected_from{ connected_from }
{
	if (name == "")
	{
		throw runtime_error{ "Objekt name ist Leerer String" };
	}
}

Liwanze::Liwanze(const Liwanze& other)
	:Liwanze{other.get_name(), other.get_loc(), other.get_connects_to(), other.get_connected_from() }
{
	if (name == "")
	{
		throw runtime_error{ "Objekt name ist Leerer String" };
	}
}



string Liwanze::get_name() const
{
	return name;
}

Liwanze::Region Liwanze::get_loc() const
{
	return loc;
}

vector<string> Liwanze::get_connects_to() const
{
	return this->connects_to;
}

vector<string> Liwanze::get_connected_from() const
{
	return this->connected_from;
}

void Liwanze::print() const
{
	
	cout << "Name der Liwanze: " << this->get_name() << endl << "Diese Linwanze kommt aus : " << ves.at(this->get_loc()) << endl;
	this->print_tierone();
	cout << endl;
	

}

bool Liwanze::connects(string coname) const
{
	for (auto& n : this->connects_to)
	{
		if (n == coname)
		{
			return true;
		}
	}

	return false;
}

bool Liwanze::connected(string coname) const
{
	for (auto& n : this->connected_from)
	{
		if (n == coname)
		{
			return true;
		}
	}

	return false;
}

void Liwanze::print_tierone() const
{
	cout << "Diese Liwanze ist zu folgenden Liwazen verbunden:" << "(" << this->size_connects() << ")";
	for (auto& n : this->connects_to)
	{
		cout << n << ", ";
	}
	cout << endl;

	cout << "Diese Liwanze wird von folgenden Liwazen verbunden:" << "(" << this->size_connected() << ")";
	for (auto& n : this->connected_from)
	{
		cout << n << ", ";
	}
	cout << endl;

}

bool Liwanze::addconn_to(string coname)
{
	if (connects(coname))
	{
		cout << "Diese ausgehnde Verbindung existiert bereits." << endl;
		return false;
	}
	else
	{
		this->connects_to.push_back(coname);
		cout << "Die ausgehnde Verbindung wurde erstellt!." << endl;
		return true;
	}
}

bool Liwanze::addconn_from(string coname)
{
	if (connected(coname))
	{
		cout << "Diese eingehende Verbindung existiert bereits." << endl;
		return false;
	}
	else
	{
		connected_from.push_back(coname);
		cout << "Die eingehende Verbindung wurde  erstellt!." << endl;
		return true;
	}
}

void Liwanze::print_connects() const
{
	for (auto& n : connects_to)
	{
		cout << n << ", ";
	}
	cout << endl;


}

void Liwanze::print_connected() const
{
	for (auto& n : connected_from)
	{
		cout << n << ", ";
	}
	cout << endl;


}

int Liwanze::size_connects() const
{
	return static_cast<int>(connects_to.size());
}

int Liwanze::size_connected() const
{
	return static_cast<int>(connected_from.size());
}


//Support funktionen
void print_members(vector<Liwanze>&  lVec)
{
	cout << "Dies ist eine Liste aller Lizanzen: " << endl;
	for (auto& n : lVec)
	{
		n.print();
	}
	cout << endl;
	cout << endl;
}
void add_Liwanze(vector<Liwanze>& lvac)
{
	string liname{};
	bool namefree{ true };

	
	while (true)
	{
		namefree = true;
		cout << "Sie können nun eigene Liwanzen anlegen: (Beenden mit \'q\' oder \'Q\')" << endl;
		cout << "Geben Sie einen Namen ein: ";
		cin >> liname;
		if (!cin)
		{

			throw runtime_error("bad cin");
		}

		if (liname == "q" || liname == "Q")
		{
			break;
		}

		for (auto& n : lvac)
		{
			if (n.get_name() == liname)
			{
				namefree = false;
			}
		}

	/*	if (namefree == true)
		{
			lvac.push_back({ liname, Liwanze::ndef });

		}
		else
		{
			cout << "Diese Liwanze existiert bereits, versuchen sie es erneut!" << endl;

		}*/

		switch (namefree)
		{
		case true:
			lvac.push_back({ liname, Liwanze::ndef });
			cout << endl;
			print_members(lvac);
			continue;
		default:
			cout << "Diese Liwanze existiert bereits, versuchen sie es erneut!" << endl;
			continue;

		}

	}







}
void make_connection(Liwanze& a, Liwanze& b)
{
	a.addconn_to(b.get_name());
	b.addconn_from(a.get_name());

}
void init_connections(vector<Liwanze>&  lvac)
{
	make_connection(lvac.at(2), lvac.at(4));
	make_connection(lvac.at(0), lvac.at(1));
	make_connection(lvac.at(0), lvac.at(5));
	make_connection(lvac.at(0), lvac.at(4));
	make_connection(lvac.at(1), lvac.at(0));
	make_connection(lvac.at(1), lvac.at(4));
	make_connection(lvac.at(5), lvac.at(0));
	make_connection(lvac.at(3), lvac.at(4));


}
void print_network(vector<Liwanze>&  lvac)
{


	cout << std::setw(20) << std::setfill(' ') << "";

	for (auto& n : lvac)
	{
		cout << std::setw(20) << std::setfill(' ') << n.get_name() << "";
	}
	cout << endl;

	for (auto& n : lvac)
	{
		cout << std::setw(20) << std::setfill(' ') << n.get_name();
		for (auto& n2 : lvac)
		{
			if (n.connects(n2.get_name()))
			{
				cout << std::setw(20) << std::setfill(' ') << "x";
			}
			else
			{
				cout << std::setw(20) << std::setfill(' ') << "  ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void user_addconn(vector<Liwanze>& lvac)
{
	string sLiwanzA{};
	string sLiwanzB{};
	bool stringA{false};
	bool stringB{false};
	Liwanze* a{ nullptr };
	Liwanze* b{ nullptr };


	
	while (true)
	{
		cout << "Sie können nun eigene Liwanzen verbinden: (Beenden mit \'q\' oder \'Q\')" << endl;
		cout << "Geben sie den ersten Namen ein: ";
		cin >> sLiwanzA;
		if (!cin)
		{
			throw runtime_error("bad cin");
		}
		if (sLiwanzA == "q" || sLiwanzA == "Q")
		{
			break;
		}
	
			
		for (auto& n : lvac)
		{
			if (n.get_name() == sLiwanzA)
			{
				a = &n;
				stringA = true;
			}


		}
		if (stringA == false)
		{
			cout << "Diese Liwanze existiert nicht! Bitte nochmal versuchen ";
			continue;
		}
		

		cout << "Geben sie den zweiten Namen ein: ";
		cin >> sLiwanzB;
		if (!cin)
		{
			throw runtime_error("bad cin");
		}
		if (sLiwanzB == "q" || sLiwanzB == "Q")
		{
			break;
		}

		
		for (auto& n : lvac)
		{
			if (n.get_name() == sLiwanzB)
			{
				b = &n;
				stringB = true;
			}

		}
		if (stringB == false)
		{
			cout << "Diese Liwanze existiert nicht! Bitte nochmal versuchen ";
			continue;
		}

		make_connection(*a, *b);
		cout << a->get_name() << ":" << endl;
		a->print_tierone();

		cout << b->get_name() << ":" << endl;
		b->print_tierone();

		

	}


}