#pragma once
#include"citizen.h"

class CitizenList {
	 friend class Elections;
	 friend class Party;

private:
	struct cNode
	{
		Citizen* data;
		cNode* next = nullptr;
	};
public:
	cNode* head;
	cNode* tail;

	int count;
public:
	CitizenList();
	~CitizenList();

	void MakeEmptyList();
	void ClearList();

	void addCitizen(Citizen* citizen);
	void addCitizen(const Citizen& citizen);
	void addCitizen(const char* name, int id, int birthYear, int district);
	const int getCount()const;

	cNode* getHead()const;
	Citizen* get_citizen_byId(int id)const;
	const Citizen& get_citizen_byId_ref(int id)const;

	bool isExist(int id);

	void operator=(const CitizenList& other);

	friend ostream& operator<<(ostream& out, const CitizenList& myList); //print operator




};

