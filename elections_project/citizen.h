#pragma once
#include<iostream>
using namespace std;
#define INIT_SIZE 2

class Citizen {
private:
	char* _name;
	int _id;
	int _bornYear;
	int _district_number;

	bool voted = false;
public:
	friend class citizenList;
	Citizen() {}
	Citizen(const char* name, int id, int bornYear, int district_num);
	~Citizen();

	int getId()const;
	int getBornYear()const;
	int getDistrictNumber()const;
	const char* getName()const;
	bool had_Voted()const;


	bool setBornYear(int bornYear);
	bool setDistrictNumber(int distictNum);
	bool setName(const char* name);
	bool setId(int id);
	bool setVote();

	
	const Citizen& operator=(const Citizen& other);
	friend ostream& operator<<(ostream& out, const Citizen& citizen);

};
