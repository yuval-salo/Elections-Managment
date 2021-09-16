#pragma once
#include"party.h"


class Elections {
	friend class Party;
public:
	int year, month, day;

	CitizenList voters_notebook;

	Party* partys_list;
	int plog_size = 0, pphy_size = INIT_SIZE;

	District* districts_list;
	int dlog_size = 0, dphy_size = INIT_SIZE;


public:
	Elections(int year, int month, int day);
	~Elections();


	int get_Plogsize()const;
	District* Get_districts_list()const;
	Party* Get_partys_list()const;
	const CitizenList& Get_voters_notebook()const;

	const District& get_district(int index);
	const Party& get_party(int index);

	bool add_vote(int id, int num_party);

	bool is_party_exist(int num_party)const;
	bool add_district(const District& new_district);
	bool add_citizen(const Citizen& new_citizen);
	bool add_party(const  Party& new_party, int rep_id);
	bool add_rep_to_party(int rep_id, int praty_id, int dis_id);

	void print_districts()const;
	void print_vNotebook()const;
	void print_partys()const;


	District* Dreallocate();//increas the size of Districts_list.
	Party* Preallocate();//increas the size of Partys_list.

};



