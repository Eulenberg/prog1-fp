#pragma once
#ifndef FP_H
#define FP_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using std::string;
using std::vector;


class Liwanze
{
public:

	//Enum Region
	enum Region
	{
		//Wenn enum verädert wird static member auch ändern
		ndef = 0, amer, apac, emea
	};
	
	//Konstruktor
	Liwanze() = delete;
	Liwanze(string name, Region region);
	Liwanze(string name, Region region, vector<string> connects_to, vector<string> connected_from);
	Liwanze(const Liwanze& other);
	


	//Public Member Funktionen
	string get_name() const;
	Region get_loc() const;
	vector<string> get_connects_to() const;
	vector<string> get_connected_from() const;


	void print() const;
	bool connects(string) const;
	bool connected(string) const;
	void print_tierone() const;
	bool addconn_to(string);
	bool addconn_from(string);
	void print_connects() const;
	void print_connected() const;
	int size_connects() const;
	int size_connected() const;

	static const vector<string>ves;

private:

//DatenMember
	const string name;
	Region loc{ ndef };
	vector<string> connects_to;
	vector<string> connected_from;










};

void print_members(vector<Liwanze>&  lVec);
void add_Liwanze(vector<Liwanze>& lvac);
void make_connection(Liwanze& a, Liwanze& b);
void init_connections(vector<Liwanze>&  lvac);
void print_network(vector<Liwanze>&  lvac);
void user_addconn(vector<Liwanze>& lvac);




#endif // !FP_H



