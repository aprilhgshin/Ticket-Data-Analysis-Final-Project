//April Shin
//CSIS 137 Wed Night Class
//Final Project

#pragma once
#define DEDUCTION

class Deduction
{
private:
	int domain;
	int ticketFormat;
	double shippingFee;
	double serviceFeePercent;

public:
	Deduction();
	Deduction(int, int);

	// set and get functions
	void setDomain(int);
	void setTicketFormat(int);
	void setShippingFee();
	void setServiceFeePercent();
	int getDomain() const;
	int getTicketFormat() const;
	double getShippingFee() const;
	double getServiceFeePercent() const;
	

};
