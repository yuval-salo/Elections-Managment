#pragma once
#include"citizenList.h"
#include"party.h"

static int d_id = 1;
class District {

private:
	char* _name;
	int _dis_Id;
	int _num_of_rep;
	CitizenList citizen_lst;
	Citizen* winning_candidate;

	int voters_count = 0;
	float votes_percentage = 0;

	int* voting_arr;
	int logsize=0, physize= INIT_SIZE;

public:
	District() :_name(nullptr) {};
	District(const char* name, int num_of_rep) :_num_of_rep(num_of_rep), 
		_dis_Id(d_id++),voting_arr(new int[INIT_SIZE]){
		setName(name);
	}
	~District();
	

	int getDis_id()const;
	int get_votes_LogSize()const;
	int* get_voting_arr()const;
	const char* getDis_name()const;
	int getDis_numOfRep() const;
	const CitizenList& Get_citizenList()const;
	bool setName(const char* name);
	void set_voters_percentage();
	float get_votes_percentage()const;

	int get_leading_party()const;
	void set_winning_candidate(Citizen* winner_in_the_district);

	void update_voting_list(int num_party);
	void add_voting(int party);
	void add_voting(const Party& party);

	void addCitezen(Citizen* citizen);


	int* reallocate();
	const District& operator=(const District& other);

	friend ostream& operator<<(ostream& out, const District& mydistrict);

};
