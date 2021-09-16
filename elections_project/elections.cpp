#include "elections.h"

Elections::Elections(int year, int month, int day) :year(year), month(month), day(day),
partys_list(new Party[INIT_SIZE]), districts_list(new District[INIT_SIZE]) {}
Elections::~Elections() {
	if (partys_list)
		delete[] partys_list;

	if (districts_list)
		delete[] districts_list;

	CitizenList::cNode* temp = voters_notebook.head;

	for (int i = 0; i < voters_notebook.count; i++)
	{
		delete temp->data;
		temp = temp->next;
	}
		
}


int Elections::get_Plogsize()const { return plog_size; }

District* Elections::Get_districts_list()const { return districts_list; }
Party* Elections::Get_partys_list()const { return partys_list; }
const CitizenList& Elections::Get_voters_notebook()const { return voters_notebook; }


const District& Elections::get_district(int index)
{
	return (districts_list[index-1]);
}
const Party& Elections::get_party(int index)
{
	return (partys_list[index - 1]);
}


bool Elections::add_vote(int id, int num_party)
{
	Citizen* voter =voters_notebook.get_citizen_byId(id);
	if (num_party > get_Plogsize())
		return false;
	else if (!voter || voter->had_Voted())
		return false;
	
	int district = voter->getDistrictNumber();
    districts_list[district - 1].add_voting(num_party);
	voter->setVote();
	return true;
		

}
/*
bool Elections::add_vote(Citizen& voter, Party& num_party)
{
	if (voters_notebook.isExist(id))
	{
		Party p;
		Citizen voter = voters_notebook.get_citizen_byId_ref(id);
		if (is_party_exist(num_party))
		{
			 p = get_party(num_party);
		}
		District d = get_district(voter.getDistrictNumber());

		d.add_voting(p);
		return true;
	}
}*/

bool Elections::is_party_exist(int num_party)const
{
	if (num_party <= plog_size)
		return true;
	return false;
}


bool Elections::add_citizen(const Citizen& new_citizen)
{
	int dis = new_citizen.getDistrictNumber();
	if (voters_notebook.isExist(new_citizen.getId()))
		return false;

	if (districts_list[dis - 1].getDis_name() != nullptr)
	{
		voters_notebook.addCitizen(new_citizen);
		districts_list[dis - 1].addCitezen(voters_notebook.tail->data);
		return true;
	}
	return false;

}
bool Elections::add_district(const District& new_district)
{
	int location = new_district.getDis_id();

	if (location < dphy_size)
	{
		districts_list[location - 1] = new_district;
	}
	else
	{
		dphy_size *= 2;
		districts_list = Dreallocate();
		districts_list[location - 1] = new_district;

	}
	dlog_size++;
	return true;
}
bool Elections::add_party(const Party& new_party, int rep_id)
{
	//find the Party_representive by id.
	Citizen* Party_Chairman = voters_notebook.get_citizen_byId(rep_id);
	if (!Party_Chairman)
		return false;
	int location = new_party.getParty_id();
	if (location < pphy_size)
	{
		partys_list[location - 1] = new_party;
		partys_list[location - 1].set_Representive(Party_Chairman);
	}
	else
	{
		pphy_size *= 2;
		partys_list = Preallocate();
		partys_list[location - 1] = new_party;
		partys_list[location - 1].set_Representive(Party_Chairman);
	}
	//create cells in the voting arrays in the districts.
	for (int i = 0; i < dlog_size; i++)
		districts_list[i].update_voting_list(location);
	plog_size++;
	return true;
}
bool Elections::add_rep_to_party(int rep_id, int party_id, int dis_id)
{
	Citizen* new_rep = voters_notebook.get_citizen_byId(rep_id);
	if (!new_rep)             // the citizen doesnt exist.
		return false;
	if (party_id > plog_size) // the party doesnt exist.
		return false;
	if (dis_id > dlog_size)   // the district doesnt exist.
		return false;
	
	partys_list[party_id - 1].add_rep_to_district(dis_id, new_rep);
	return true;

}





void Elections::print_districts()const
{
	for (int i = 0; i < dlog_size; i++)
	{
		cout << districts_list[i] << endl;
	}
}
void Elections::print_vNotebook()const
{
	cout << voters_notebook << endl;
}
void Elections::print_partys()const
{
	for (int i = 0; i < plog_size; i++)
	{
		cout << partys_list[i] << endl;
	}
}

District* Elections::Dreallocate()
{
	District* new_array = new District[dphy_size];
	for (int i = 0; i < dlog_size; i++)
	{
		new_array[i] = districts_list[i];
	}
	delete[] districts_list;

	return new_array;
}
Party* Elections::Preallocate()
{
	Party* new_array = new Party[pphy_size];
	for (int i = 0; i < plog_size; i++)
	{
		new_array[i] = partys_list[i];
	}
	delete[] partys_list;

	return new_array;
}

