#include "party.h"

Party::Party(const char* name) :party_id(p_id++), rep_list(new CitizenList[INIT_SIZE]), candidate(nullptr) {
	_name = nullptr;
	setName(name);

}
Party::~Party() {
	delete[] _name;
	delete[] rep_list;
}

int Party::getParty_id()const
{
	return party_id;
}
char* Party::getParty_name()const { return _name; }



bool Party::setName(const char* name)
{
	if (_name)
		delete[] _name;
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
bool Party::add_rep_to_district(int dis_num,Citizen* new_rep)
{
	if (dis_num <= physize)
	{
		if (rep_list[dis_num - 1].getHead() == nullptr)
			logsize++;
		rep_list[dis_num - 1].addCitizen(new_rep);
	}
	if (dis_num > physize)
	{
		if (physize * 2 < dis_num)
			physize += dis_num;
		else
			physize *= 2;
		rep_list = CLreallocate();
		rep_list[dis_num - 1].addCitizen(new_rep);
		logsize = dis_num;

	}
	return true;
}

bool Party::set_Representive(Citizen* citizen)
{
	candidate = citizen;
	return true;
}
const Citizen& Party::get_representive()const
{
	return *candidate;
}

void Party::update_logsize()
{
	logsize++;
}

CitizenList* Party::CLreallocate()
{
	CitizenList* new_array = new CitizenList[physize];
	for (int i = 0; i < logsize; i++)
	{
		new_array[i] = rep_list[i];
	}
	delete[] rep_list;

	return new_array;
}

const Party& Party:: operator=(const Party& other)
{
	if (this != &other)
	{
		
		_name = _strdup(other._name);
		candidate = other.candidate;
		party_id = other.party_id;
		rep_list = new CitizenList[other.physize];
		for (int i = 0; i < logsize; i++)
		{
			rep_list[i] = other.rep_list[i];
		}
		logsize = other.logsize;
		physize = other.physize;
	}
	return *this;
}

// print operator
ostream& operator<<(ostream& out, const Party& myparty)
{
	out << "Party number: " << myparty.getParty_id() << endl << "Party name:" << myparty.getParty_name() << endl << "Candidate for Head of State: " <<endl<<endl<<myparty.get_representive() << endl;
	for (int i = 0; i < myparty.logsize; i++)
		out <<"Representors to district "<<i+1<<":" <<endl<< myparty.rep_list[i] << endl;
	
	return out;

}