//April Shin
//CSIS 137 Wed Night Class
//Final Project

#include "TicketInfo.h"
#include "Deduction.h"
#include "GeneralAdmission.h"
#include "ArrangedSeating.h"
#include "TicketCalc.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	TicketInfo info;
	GeneralAdmission generalObj;
	Deduction deductObj;
	ArrangedSeating arrangedObject;
	TicketCalc calcObj;
	char selection;
	string username, event, venue, date, time, section, row;
	int numTickets, domainChoice, format, seatingType, seatNumber, seatingOrder;
	double totalCost, unitSale;
	vector<double> sale;
	ofstream outputObject;
	outputObject.open("EventsAnalysis.txt");

	cout << "Welcome to Ticket Sale Analyzer." << endl;
	cout << "\nPlease enter your name: " << endl;
	getline(cin, username);
	info.setUsername(username);
	outputObject << "Welcome, " << info.getUsername() << ", to Ticket Sale Analyzer." << endl;

	do {
		cout << "\nPlease make a selection" << endl
			<< "1) Add Ticket Sale to Analyze on File" << endl
			<< "q) Quit Program" << endl;
		cin >> selection;
		cin.ignore();

		if (selection == '1')
		{
			// input for TicketInfo class

			cout << "\nEnter the name of the event of the tickets you sold: " << endl;
			getline(cin, event);

			cout << "Enter the event venue: " << endl;
			getline(cin, venue);

			cout << "Enter the date of the event: " << endl;
			getline(cin, date);

			cout << "Enter the starting time of the event: " << endl;
			getline(cin, time);

			cout << "Enter the number of tickets sold for the event: " << endl;
			cin >> numTickets;
			info.setNumTickets(numTickets);

			// input for Deduction class

			cout << "Please select the domain in which you sold the ticket(s): " << endl
				<< "1) Social Media" << endl
				<< "2) Stubhub " << endl
				<< "3) Vividseats" << endl
				<< "4) Ticketmaster" << endl;
			cin >> domainChoice;
			deductObj.setDomain(domainChoice);

			cout << "Please select the ticket format: " << endl
				<< "1) PDF " << endl
				<< "2) Hardstock" << endl;
			cin >> format;
			deductObj.setTicketFormat(format);

			Deduction deductObject(deductObj.getDomain(), deductObj.getTicketFormat());


			cout << "Please select the number that best describes the event seating: " << endl
				<< "1) General Admission" << endl
				<< "2) Arranged Seating" << endl;
			cin >> seatingType;
			info.setEventType(seatingType);
			cin.ignore();

				if (seatingType == 1)
				{
				}
				else if (seatingType == 2)
				{

					// input for ArrangedSeating Class

					cout << "Please enter the section(number or characters): " << endl;
					getline(cin, section);
					arrangedObject.setSectionNum(section);

					cout << "Please enter the row(number of characters): " << endl;
					getline(cin, row);
					arrangedObject.setRowNum(row);

					cout << "Please enter the starting seat number: " << endl;
					cin >> seatNumber;
					arrangedObject.setStartingSeatNum(seatNumber);

					cout << "Please select the one that describes the seating of your tickets: " << endl
						<< "1) consecutive" << endl
						<< "2) or even/odd?" << endl;
					cin >> seatingOrder;
					arrangedObject.setSeatOrder(seatingOrder);
				}
				else
				{
				}

			
			// input for TicketCalc class

			cout << "Please enter the total face value of the ticket(s) : " << endl;
			cin >> totalCost;
			calcObj.setTotalCost(totalCost);

				// Inputting individual sale prices
			cout << "Please enter the sale price of each ticket: " << endl;
			sale.assign(info.getNumTickets(), 0);
			for (int i = 0; i < sale.size(); ++i)
			{
				cout << "Ticket #" << i + 1 << ": ";
				cin >> unitSale;
				sale[i] = unitSale;
			}

			TicketInfo infoObject (generalObj, arrangedObject, deductObject, username, event, venue, date, time, info.getNumTickets(), info.getEventType());
			TicketCalc calcObject(infoObject, arrangedObject, deductObject, calcObj.getTotalCost(),sale);

			outputObject << infoObject;
			outputObject << calcObject;
		}

		else if (selection != '1' && selection != 'q' && selection != 'Q')
		{
			cout << "\nInvalid Selection." << endl;
		}
		else
		{

		}
	} while (selection != 'q' && selection != 'Q');

	cout << "\nPlease check 'EventsAnalysis.txt' for your ticket sale data. Thank you.\n" << endl;

	outputObject.close();

	system("PAUSE");
	return 0;
}
