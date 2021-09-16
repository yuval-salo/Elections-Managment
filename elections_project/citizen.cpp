#include "citizen.h"
#include<string.h>
#include<iostream>



Citizen::Citizen(const char* name, const int id, const int bornYear, int district_num) :
	_id(id), _bornYear(bornYear), _district_number(district_num)
{
	setName(name);
	//cout << "citizen ctor  " <<_name << endl;

}

Citizen::~Citizen() {
	cout << "citizen dtor" << _name << endl;
	delete[] _name;
}

int Citizen::getId()const { return _id; }
int Citizen::getBornYear()const { return _bornYear; }
int Citizen::getDistrictNumber() const { return _district_number; }
const char* Citizen::getName()const { return _name; }
bool Citizen::had_Voted()const { return voted; }


bool Citizen::setBornYear(int bornYear) { _bornYear = bornYear; return true; }
bool Citizen::setDistrictNumber(int districtNumber) { _district_number = districtNumber; return true; }
bool Citizen::setName(const char* name)
{
	/*if (_name)
		delete[] _name;*/
	_name = new char[strlen(name) + 1];
	int i = 0;
	while (name[i] != '\0')
	{
		_name[i] = name[i];
		i++;
	}
	_name[i] = '\0';
	return true;
}
bool Citizen::setId(int id) { _id = id; return true; }
bool Citizen::setVote() {
	voted = true;



	cout << _name << "had voted!" << endl;
	return true;
}



const Citizen& Citizen::operator=(const Citizen& other)
{
	if (this != &other)
	{
		_id = other._id;
		_bornYear = other._bornYear;
		_district_number = other._district_number;
		_name = _strdup(other._name);
	}
	return *this;
}

ostream& operator<<(ostream& out, const Citizen& citizen)
{
	out << "name:" << citizen.getName() << endl << "id: " << citizen.getId() << endl << "birth year:" << citizen.getBornYear() << endl << "district: " << citizen.getDistrictNumber() << endl;
	return out;
}
