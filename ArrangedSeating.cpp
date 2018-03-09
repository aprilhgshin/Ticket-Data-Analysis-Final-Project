//April Shin
//CSIS 137 Wed Night Class
//Final Project

#include "ArrangedSeating.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

ArrangedSeating::ArrangedSeating()
{
	setStartingSeatNum(1);
	setSeatOrder(1);
}
ArrangedSeating::ArrangedSeating(const string& section, const string& row, int startSeat, int order)
{
	setSectionNum(section);
	setRowNum(row);
	setStartingSeatNum(startSeat);
	setSeatOrder(order);
}
void ArrangedSeating::setSectionNum(const string& section)
{
	sectionNum = section;
}
void ArrangedSeating::setRowNum(const string& row)
{
	rowNum = row;
}
void ArrangedSeating::setStartingSeatNum(int startSeat)
{
	if (startSeat >= 0)
	{
		startingSeatNum = startSeat;
	}
	else if (startSeat < 0)
	{
		while (startSeat < 0)
		{
			cout << "Invalid Input. " << endl
				<< "Please enter the starting seat number: " << endl;
			cin >> startSeat;
		}
		startingSeatNum = startSeat;
	}
}
void ArrangedSeating::setSeatOrder(int order)
{
	// order = 1 for consecutive seating
	// order = 2 for even/odd seating

	if (order == 1 || order == 2)
	{
		seatOrder = order;
	}
	else
	{
		while (seatOrder != 1 && seatOrder != 2)
		{
			cout << "Invalid Input." << endl;
			cout << "Please select the one that describes the seating of your tickets: " << endl
				<< "1) consecutive" << endl
				<< "2) Even/Odd" << endl;
			cin >> order;
		}
		seatOrder = order;
	}
}
string ArrangedSeating::getSectionNum() const
{
	return sectionNum;
}
string ArrangedSeating::getRowNum() const
{
	return rowNum;
}
int ArrangedSeating::getStartingSeatNum() const
{
	return startingSeatNum;
}
int ArrangedSeating::getSeatOrder() const
{
	return seatOrder;
}
