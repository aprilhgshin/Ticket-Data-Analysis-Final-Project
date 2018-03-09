//April Shin
//CSIS 137 Wed Night Class
//Final Project

#include "TicketInfo.h"
#include <string>
#include <iostream>
using namespace std;
TicketInfo::TicketInfo()
{

}
TicketInfo::TicketInfo(GeneralAdmission generalObj, ArrangedSeating arrangedObj, Deduction deductObj, const string& user, const string& name, const string& venue, const string& date, const string& time, int number, int type): generalObject(generalObj), arrangedObject(arrangedObj), deductObject(deductObj)
{
	setUsername(user);
	setEventName(name);
	setEventVenue(venue);
	setEventDate(date);
	setEventTime(time);
	setNumTickets(number);
	setEventType(type);
}
void TicketInfo::setUsername(const string& user)
{
	username = user;
}
void TicketInfo::setEventName(const string& name)
{
	eventName = name;
}
void TicketInfo::setEventVenue(const string& venue)
{
	eventVenue = venue;
}
void TicketInfo::setEventDate(const string& date)
{
	eventDate = date;
}
void TicketInfo::setEventTime(const string& time)
{
	eventTime = time;
}
void TicketInfo::setNumTickets(int number)
{
	if (number >= 0)
	{
		numTickets = number;
	}
	else if (number < 0)
	{
		while (number < 0)
		{
			cout << "Invalid Input. Please enter a positive integer: " << endl;
			cin >> number;
		}
		numTickets = number;
	}
}
void TicketInfo::setEventType(int type)
{
	// 1 = General Admission
	// 2 = Arranged Seating

	if (type == 1 || type == 2)
	{
		eventType = type;
	}
	else
	{
		while (type != 1 && type != 2)
		{
			cout << "Invalid Input. " << endl
				<< "Please select the number that best describes the event seating: " << endl
				<< "1) General Admission" << endl
				<< "2) Arranged Seating" << endl;
			cin >> type;
		}
		eventType = type;
	}

}
string TicketInfo::getUsername() const
{
	return username;
}
string TicketInfo::getEventName() const
{
	return eventName;
}
string TicketInfo::getEventVenue() const
{
	return eventVenue;
}
string TicketInfo::getEventDate() const
{
	return eventDate;
}
string TicketInfo::getEventTime() const
{
	return eventTime;
}
int TicketInfo::getNumTickets() const
{
	return numTickets;
}
int TicketInfo::getEventType() const
{
	return eventType;
}

ostream& operator<<(ostream &output, const TicketInfo &info)
{

	output << "-------------------------------------------------------------------" << endl
		<< "-------------------------------------------------------------------" << endl
		<< "\nEVENT INFORMATION " << endl
		<< "Name:  " << info.getEventName() << endl
		<< "Venue: " << info.getEventVenue() << endl
		<< "Date:  " << info.getEventDate() << endl
		<< "Time:  " << info.getEventTime() << endl
		<< "Number of Tickets Sold: " << info.getNumTickets() << endl;
	
	if (info.eventType == 1)
	{
		output << "\nSection: " << info.generalObject.getGivenSectionNum() << endl
			     << "Row:     " << info.generalObject.getGivenRowNum() << endl;
	}
	else if (info.eventType == 2)
	{
		output << "\nSection: " << info.arrangedObject.getSectionNum() << endl
			     << "Row:     " << info.arrangedObject.getRowNum() << endl;
	}

	

	return output;
}
