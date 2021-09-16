#include"elections.h"
#include<iostream>

using namespace std;
#define MAX_LENGTH 50

enum class Menu_Option
{
	ADD_DISTRICT = 1,
	ADD_CIVIL,
	ADD_PARTY,
	ADD_CITIZEN_AS_PARTY_REPRESENTOR,
	DISPLAY_DISTRICTS,
	DISPLAY_CITIZENS,
	DISPLAY_PARTYS,
	VOTING,
	ELECTIONS_RESULTS,
	EXIT
};

void mainMenu( Elections& my_elections)
{
	int userChoice;
	while (true)
	{
		cout << "Choose an option:" << endl;
		cout << "1. Add district" << endl;
		cout << "2. Add citizen" << endl;
		cout << "3. Add party" << endl;
		cout << "4. Add citizen as party representor" << endl;
		cout << "5. Display districts" << endl;
		cout << "6. Display citizens" << endl;
		cout << "7. Display partys" << endl;
		cout << "8. Voting" << endl;
		cout << "9. election results" << endl;
		cout << "10. Exit" << endl;

		cin >> userChoice;
		const Menu_Option menuOption = static_cast<Menu_Option>(userChoice);
		char name[MAX_LENGTH];
		District* temp;
		Citizen* new_rep;
		Citizen* new_candidate;
		Citizen* voter;

		if (menuOption == Menu_Option::EXIT)
			break;
		switch (menuOption)
		{
		case Menu_Option::ADD_DISTRICT:
			int num_rep;
			cout << "Enter the name of the district: ";
			cin >> name;
			cout << "Enter the number of representors : ";
			cin >> num_rep;

			if (my_elections.add_district(District(name, num_rep)))
				cout << "District added successfully" << endl << endl << endl;
			else
				cout << "Invalid input" << endl << endl << endl;
			break;
		case Menu_Option::ADD_CIVIL:
			int id,birthDay,district_num;
			cout << "Enter the name of the citizen: ";
			cin >> name;
			cout << "Enter the id of the citizen: ";
			cin >> id;
			cout << "Enter birth day: ";
			cin >> birthDay;
			cout << "Enter district number: ";
			cin >> district_num;

			if (my_elections.add_citizen(Citizen(name, id, birthDay, district_num)))
				cout << "Citizen added successfully" << endl << endl << endl;
			else
				cout << "Citizen already exist/district doesnt exist" << endl << endl<<endl;
			break;
		case Menu_Option::ADD_PARTY:
			int id_candidate;
			cout << "Enter the name of the party: ";
			cin >> name;
			cout << "Enter the id of the candidate: ";
			cin >> id_candidate;

			if(!my_elections.add_party(Party(name), id_candidate))
				cout << "Candidate not found by id" << endl << endl << endl;
			else
				cout << "Party added successfully" << endl << endl << endl;
			 
			break;
		case Menu_Option::ADD_CITIZEN_AS_PARTY_REPRESENTOR:
			int rep_id,party_num,dis_num;
			cout << "Enter the id of the Representor: ";
			cin >> rep_id;
			cout << "Enter the number of the party: ";
			cin >> party_num;
			cout << "Enter the number of the district: ";
			cin >> dis_num;

			if(!my_elections.add_rep_to_party(rep_id,party_num, dis_num))
				cout << "Representor/District/Party not found"<<endl<<endl<<endl;
			else
			{
				cout << "Representor added successfully" << endl << endl << endl;
			}
			
			break;

		case Menu_Option::DISPLAY_DISTRICTS:
			my_elections.print_districts();
			break;
		case Menu_Option::DISPLAY_CITIZENS:
			my_elections.print_vNotebook();
			break;
		case Menu_Option::DISPLAY_PARTYS:
			my_elections.print_partys();
			break;
		case Menu_Option::VOTING:
			int id_voter, num_of_party;
			cout << "Please enter the id of the voter:";
			cin >> id_voter;
			cout << "Please enter the number of the party:";
			cin >> num_of_party;
		
		//	my_elections.add_vote(id_voter, num_of_party);
			
			if(my_elections.add_vote(id_voter,num_of_party))
				cout << "Voting added successfully " << endl << endl << endl;
			else
			{
				cout << "voting failed !" << endl << endl << endl;
			}
			break;

		default:
			break;

		}
		
	}
}

int main()
{
	Elections my_election(2020, 4, 1);
	cout << "***********ELECTION 1/4/2020 ***********" << endl<<endl;
	mainMenu(my_election);
     
}