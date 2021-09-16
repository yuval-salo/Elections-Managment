#pragma once
#include"citizenList.h"
#include"district.h"

static int p_id = 1;
class Party {

private:
	char* _name;
	Citizen* candidate;
	int party_id;

	CitizenList* rep_list;
	int logsize = 0;
	int physize = INIT_SIZE;
public:
	Party() :rep_list(new CitizenList[INIT_SIZE]), candidate(nullptr), _name(nullptr), party_id(p_id++) {}
	~Party();
	Party(const char* name);

	int getParty_id()const;
	char* getParty_name()const;
	const Citizen& get_representive()const;

	bool setName(const char* name);
	bool add_rep_to_district(int dis_num,Citizen* new_rep);
	bool set_Representive(Citizen* citizen);
	
	void update_logsize();

	CitizenList* CLreallocate();



	const Party& operator=(const Party& other);
	friend ostream& operator<<(ostream& out, const Party& myparty);




};
