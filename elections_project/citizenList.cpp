#include "citizenList.h"
#include<iostream>

using namespace std;

CitizenList::CitizenList()
{
	MakeEmptyList();
}
CitizenList::~CitizenList()
{
	ClearList();
}

void CitizenList::MakeEmptyList()
{
	head = tail = nullptr;
	count = 0;
}
void CitizenList::ClearList()
{
	cNode* temp = head;
	if (temp == nullptr)//Empty list
		return;
	while (temp != nullptr)
	{
		head = head->next;
		delete temp;
		temp = head;

	}
}

void CitizenList::addCitizen(Citizen* citizen)
{
	cNode* new_node = new cNode;
	new_node->data = citizen;

	if (head == nullptr)
	{
		head = tail = new_node;
	}
	else
	{
		tail->next = new_node;
		tail = new_node;

	}
	count++;
}
void CitizenList::addCitizen(const Citizen& citizen)
{
	cNode* new_node = new cNode;
	new_node->data = new Citizen();
	*new_node->data = citizen;

	if (head == nullptr)
	{
		head = tail = new_node;
	}
	else
	{
		tail->next = new_node;
		tail = new_node;

	}
	count++;
}
void CitizenList::addCitizen(const char* name, int id, int birthYear, int district)
{
	cNode* new_node = new cNode;
	new_node->next = nullptr;
	new_node->data = new Citizen(name, id, birthYear, district);

	if (head == nullptr)
	{

		head = tail = new_node;
	}
	else
	{
		tail->next = new_node;
		tail = new_node;

	}
	count++;
}

const int CitizenList::getCount()const
{
	return count;

}
Citizen* CitizenList::get_citizen_byId(int id) const
{
	cNode* temp = head;
	while (temp != nullptr)
	{
		if (temp->data->getId() == id)
			return temp->data;
		temp = temp->next;
	}
	return nullptr;
}
const Citizen& CitizenList::get_citizen_byId_ref(int id) const
{
	cNode* temp = head;
	while (temp != nullptr)
	{
		if (temp->data->getId() == id)
			return *temp->data;
		temp = temp->next;
	}
	
}

CitizenList::cNode* CitizenList::getHead()const { return head; }


bool CitizenList::isExist(int id)
{
	cNode* temp = head;
	for (int i = 0; i < count; i++)
	{
		if (temp->data->getId() == id)
			return true;
		temp = temp->next;
	}
	return false;
}
void CitizenList::operator=(const CitizenList& other)
{
	if (this != &other)
	{
		ClearList();
		cNode* temp = other.head;
		while (temp != nullptr)
		{
			this->addCitizen(temp->data);
			temp = temp->next;
		}
		count = other.count;
	}
}

ostream& operator<<(ostream& out, const CitizenList& myList)
{
	CitizenList::cNode* temp = myList.getHead();
	while (temp != nullptr)
	{
		out << *temp->data << endl;
		temp = temp->next;
	}
	return out;
}
