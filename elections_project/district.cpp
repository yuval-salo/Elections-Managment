#include "district.h"


District::~District() {
	delete[]_name;
	//cout << "dtor district" << endl;

}

bool District::setName(const char* name)
{
	int size = strlen(name) + 1;
	_name = new char[size];
	int i = 0;
	while (name[i] != '\0')
	{
		_name[i] = name[i];
		i++;
	}
	_name[i] = '\0';
	return true;
}
int District::getDis_id()const {
	return _dis_Id;
}
int District::get_votes_LogSize()const { return logsize; }
int* District::get_voting_arr()const { return voting_arr; }
const char* District::getDis_name()const {
	return _name;
}

int District::getDis_numOfRep() const {
	return _num_of_rep;
}

const CitizenList& District::Get_citizenList()const
{
	return citizen_lst;
}
void  District::set_voters_percentage()
{
	int num_of_citizens = citizen_lst.getCount();
	float res = (static_cast<float>(voters_count) / static_cast<float>(num_of_citizens)) * 100;
	votes_percentage = res;

}
float District::get_votes_percentage()const
{
	return votes_percentage;
}
int District::get_leading_party()const
{
	int max = voting_arr[0];
	int res = 0;
	for (int i = 1; i < logsize; i++)
	{
		if (voting_arr[i] > max)    // Preference for the minimal serial number
		{
			max = voting_arr[i];
			res = i;
		}
	}
	return res+1;
}
void District::set_winning_candidate(Citizen* winner_candidate_)
{
	winning_candidate = winner_candidate_;
}


//create cell when new party added.
void District::update_voting_list(int num_party)
{
	if (num_party <= physize)
	{
		voting_arr[num_party - 1] = 0;
	}
	else
	{
		voting_arr=reallocate();
		voting_arr[num_party - 1] = 0;
	}
	logsize++;
}

void District::add_voting(int party)
{
	voting_arr[party - 1]++;
	voters_count++;
	set_voters_percentage();
}
void District::add_voting(const Party& party)
{
	voting_arr[party.getParty_id() - 1]++;
	voters_count++;
	set_voters_percentage();
}


//add to the list of civilian a reference to citizen.
void  District::addCitezen(Citizen* citizen)
{
	citizen_lst.addCitizen(citizen);
}


int* District::reallocate()
{
	physize *= 2;
	int* new_array = new int[physize];
	for (int i = 0; i < logsize; i++)
		new_array[i] = voting_arr[i];
	delete[]voting_arr;
	return new_array;
}

//assignment operator
const District& District:: operator=(const District& other)
{
	if (this != &other)
	{
		_name = _strdup(other._name);
		_dis_Id = other._dis_Id;
		_num_of_rep = other._num_of_rep;
		citizen_lst = other.citizen_lst;
		logsize = logsize;
		physize = physize;
		voting_arr = new int[other.physize];
		for (int i = 0; i < logsize; i++)
			voting_arr[i] = other.voting_arr[i];
	}
	return *this;
}

// print operator
ostream& operator<<(ostream& out, const District& mydistrict)
{
	out << "District number: " << mydistrict._dis_Id << endl << "District name: " << mydistrict.getDis_name() << endl << "Number of representors: " << mydistrict.getDis_numOfRep() << endl;
	for (int i = 0; i < mydistrict.get_votes_LogSize(); i++)
	{
		out << "votes for party number" << i + 1 <<": "<< mydistrict.get_voting_arr()[i] << endl;
	}
	out <<"votes percentage: " <<mydistrict.get_votes_percentage()<<"%"<< endl;
	return out;
}