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

//Hilfsvector, welcher in der Print Funktion benötigt wird
const vector<string> Liwanze::ves{ "ndef", "amer", "apac", "amea" };

// Konstruktor für den ersten Teil der Aufgabe
Liwanze::Liwanze(const string& conname, Region conregion = ndef)
	:name{ conname }, loc{ conregion }, connects_to{}, connected_from{}
{
	if (name == "")
	{
		throw runtime_error{ "Objekt name ist Leerer String" };
	}
}

// Erweiterter Konstruktor, für den weiterführenden Teil der Aufgabe
Liwanze::Liwanze(const string& name, Region region, vector<string> connects_to, vector<string> connected_from)
	:name{ name }, loc{ region }, connects_to{ connects_to }, connected_from{ connected_from }
{
	if (name == "")
	{
		throw runtime_error{ "Objekt name ist Leerer String" };
	}
}

// Kopierkonstruktor, braucht man hier nicht unbedingt, muss nicht unbedingt mit Gettern gefüllt werden
Liwanze::Liwanze(const Liwanze& other)
	:Liwanze{other.name, other.get_loc(), other.get_connects_to(), other.get_connected_from() }
{
	if (name == "")
	{
		throw runtime_error{ "Objekt name ist Leerer String" };
	}
}


// Getter für name
string Liwanze::get_name() const
{
	return name;
}

// Getter für Location
Liwanze::Region Liwanze::get_loc() const
{
	return loc;
}

// Getter für connects_to
vector<string> Liwanze::get_connects_to() const
{
	return this->connects_to;
}

// Getter für connected_from
vector<string> Liwanze::get_connected_from() const
{
	return this->connected_from;
}

// Print Funktion für eine Liwanze
void Liwanze::print() const
{
	
	cout << "Name der Liwanze: " << this->get_name() << endl << "Diese Linwanze kommt aus : " << ves.at(this->get_loc()) << endl;
	this->print_tierone();
	cout << endl;
	

}

// Checkt ob eine eingehende Verbindung existiert
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

// Checkt ob eine ausgehende Verbindung existiert
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

// Verbindung von und zu Liwanze ausdrucken
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

// Push_back Verbindung zu
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

// Push_back Verbindung von
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

// Printet ausgehenden Verbindungen zu einer Liwanze
void Liwanze::print_connects() const
{
	for (auto& n : connects_to)
	{
		cout << n << ", ";
	}
	cout << endl;


}

// Printet eingehenden Verbindungen zu einer Liwanze
void Liwanze::print_connected() const
{
	for (auto& n : connected_from)
	{
		cout << n << ", ";
	}
	cout << endl;


}

// Gibt Größe des vectors connects_to zurück, quasi Getter für connects.size()
int Liwanze::size_connects() const
{
	return static_cast<int>(connects_to.size());
}

// Gibt Größe des vectors connected_from zurück, quasi Getter für connected.size()
int Liwanze::size_connected() const
{
	return static_cast<int>(connected_from.size());
}


//Support funktionen
// Gibt alle Liwanzen aus dem vector lVec aus
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

// Liwanze in den Vector push_back und überprüfung ob der Name bereits im Vector existiert
void add_Liwanze(vector<Liwanze>& liVec)
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

		for (auto& n : liVec)
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
			liVec.push_back({ liname, Liwanze::ndef });
			cout << endl;
			print_members(liVec);
			continue;
		default:
			cout << "Diese Liwanze existiert bereits, versuchen sie es erneut!" << endl;
			continue;

		}

	}







}

//make_connection wurde hier überladen, um es entweder mit 2 Liwanzen Typen aufzurufen oder mit 2 int Werten und Vector
//stellt Verbindungen zwischen den Liwanzen her und speichert diese dann in lvec
void make_connection(Liwanze& a, Liwanze& b)
{
	a.addconn_to(b.get_name());
	b.addconn_from(a.get_name());

}

//stellt Verbindungen zwischen den Liwanzen her und speichert diese dann in lvec
void make_connection(int a, int b, vector<Liwanze>& lVec)
{
	lVec.at(a).addconn_to(lVec.at(b).get_name());
	lVec.at(b).addconn_from(lVec.at(a).get_name());

}

//Initialisiert die ersten Verbindungen zwischen den Liwanzen
void init_connections(vector<Liwanze>&  lVec)
{
	make_connection(lVec.at(2), lVec.at(4));
	make_connection(lVec.at(0), lVec.at(1));
	make_connection(lVec.at(0), lVec.at(5));
	make_connection(lVec.at(0), lVec.at(4));
	make_connection(lVec.at(1), lVec.at(0));
	make_connection(lVec.at(1), lVec.at(4));
	make_connection(lVec.at(5), lVec.at(0));
	make_connection(lVec.at(3), lVec.at(4));


}

//Gibt das entstandene Netzwerk ink. Verbindungen grafisch gut sichtbar aus
void print_network(vector<Liwanze>&  lVec)
{


	cout << std::setw(20) << std::setfill(' ') << "";

	for (auto& n : lVec)
	{
		cout << std::setw(20) << std::setfill(' ') << n.get_name() << "";
	}
	cout << endl;

	for (auto& n : lVec)
	{
		cout << std::setw(20) << std::setfill(' ') << n.get_name();
		for (auto& n2 : lVec)
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

// Stellt Verbindungen zwischen den Liwanzen her und überprüft ob die Namen der zu verbindenden Liwanzen existert
void user_addconn(vector<Liwanze>& lVec)
{
	string sLiwanzA{};
	string sLiwanzB{};
	bool boolLiwanzeA{false};
	bool boolLiwanzeB{false};
	//Liwanze* a{ nullptr };
	//Liwanze* b{ nullptr };
	int iLiwanzA{};
	int iLiwanzB{};


	
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
	
		// Überprüfung ob die Liwanze existiert	
		for (int i{}; i < lVec.size(); i++ )
		{
			if (lVec.at(i).get_name() == sLiwanzA)
			{
				iLiwanzA = i;
				boolLiwanzeA = true;
			}


		}
		
		if (boolLiwanzeA == false)
		{
			cout << "Diese Liwanze existiert nicht! Bitte nochmal versuchen ";
			continue;
		}
		
		// Ab hier beginnt die Eingabe einer zweiten Liwanze
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

		// Überprüfung ob die Liwanze existiert
		for (int i{}; i < lVec.size(); i++)
		{
			if (lVec.at(i).get_name() == sLiwanzB)
			{
				iLiwanzB = i;
				boolLiwanzeB = true;
			}

		}
		if (boolLiwanzeB == false)
		{
			cout << "Diese Liwanze existiert nicht! Bitte nochmal versuchen ";
			continue;
		}

		// Ruft make_connextion auf, und verbindet damit die vorher eingegbenen Liwanzen
		make_connection(lVec.at(iLiwanzA), lVec.at(iLiwanzB));

		// Nach der Herstellung der Verbindung, wird es noch mal ausgegeben
		cout << lVec.at(iLiwanzA).get_name() << ":" << endl;
		lVec.at(iLiwanzA).print_tierone();

		cout << lVec.at(iLiwanzB).get_name() << ":" << endl;
		lVec.at(iLiwanzB).print_tierone();

		boolLiwanzeA = false;
		boolLiwanzeB = false;


		//a = nullptr;
		//b = nullptr;

		

	}


}