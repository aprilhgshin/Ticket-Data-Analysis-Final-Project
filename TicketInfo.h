//April Shin
//CSIS 137 Wed Night Class
//Final Project

#pragma once
#define TICKETINFO
#include <string>
#include "GeneralAdmission.h"
#include "Deduction.h"
#include "ArrangedSeating.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class TicketInfo
{

	friend ostream& operator<<(ostream&, const TicketInfo&);

private:
	GeneralAdmission generalObject;
	ArrangedSeating arrangedObject;
	Deduction deductObject;
	string username;
	string eventName;
	string eventVenue;
	string eventDate;
	string eventTime;
	int numTickets;
	int eventType;


public:
	TicketInfo();
	TicketInfo(GeneralAdmission, ArrangedSeating, Deduction, const string&, const string&, const string&, const string&, const string&, int,int);

	// set and get functions
	void setUsername(const string&);
	void setEventName(const string&);
	void setEventVenue(const string&);
	void setEventDate(const string&);
	void setEventTime(const string&);
	void setNumTickets(int);
	void setEventType(int);
	string getUsername() const;
	string getEventName() const;
	string getEventVenue() const;
	string getEventDate() const;
	string getEventTime() const;
	int getNumTickets() const;
	int getEventType() const;

};