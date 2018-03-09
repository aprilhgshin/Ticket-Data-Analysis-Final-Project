//April Shin
//CSIS 137 Wed Night Class
//Final Project

#include "Deduction.h"
#include <iostream>
using namespace std;

Deduction::Deduction()
{

}
Deduction::Deduction(int domainChoice, int format)
{
	setDomain(domainChoice);
	setTicketFormat(format);
	setShippingFee();
	setServiceFeePercent();
}
void Deduction::setDomain(int choice)
{
	if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
	{
		domain = choice;
	}
	else
	{
		while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
		{
			cout << "Invalid Input." << endl;
			cout << "Please select the domain in which you sold the ticket(s): " << endl
				<< "1) Social Media" << endl
				<< "2) Stubhub " << endl
				<< "3) Vividseats" << endl
				<< "4) Ticketmaster" << endl;
			cin >> choice;
		}
		domain = choice;
	}
}
void Deduction::setTicketFormat(int format)
{
	// 1 = PDF ticket
	// 2 = hardstock ticket

	if (format == 1 || format == 2)
	{
		ticketFormat = format;
	}
	else
	{
		while (format != 1 && format != 2)
		{
			cout << "Invalid Input." << endl;
			cout << "Please select the ticket format: " << endl
				<< "1) PDF " << endl
				<< "2) Hardstock" << endl;
			cin >> format;
		}
		ticketFormat = format;
	}
}
void Deduction::setShippingFee()
{
	// when domain != 1, the domain can be Stubhub, VividSeats, or Ticketmaster. And shipping is free.
	// when domain = 1, the domain is social media. And shipping is $2.77

	if (getTicketFormat() == 1)
	{
		shippingFee = 0;
	}
	else if (getTicketFormat() == 2)
	{
		if (getDomain() == 1)
		{
			shippingFee = 2.77;
		}
		else if (getDomain() != 1)
		{
			shippingFee = 0;
		}
	}
}
void Deduction::setServiceFeePercent()
{
	if (getDomain() == 1)
	{
		serviceFeePercent = 0;
	}
	else if (getDomain() == 2)
	{
		serviceFeePercent = 0.09;
	}
	else if (getDomain() == 3)
	{
		serviceFeePercent = 0.1;
	}
	else if (getDomain() == 4)
	{
		serviceFeePercent = 0.11;
	}
}
int Deduction::getDomain() const
{
	return domain;
}
int Deduction::getTicketFormat() const
{
	return ticketFormat;
}
double Deduction::getShippingFee() const
{
	return shippingFee;
}
double Deduction::getServiceFeePercent() const
{
	return serviceFeePercent;
}

