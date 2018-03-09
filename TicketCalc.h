//April Shin
//CSIS 137 Wed Night Class
//Final Project

#pragma once
#define TICKETCALC
#include "TicketInfo.h"
#include "ArrangedSeating.h"
#include "Deduction.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TicketCalc
{
	friend ostream& operator<<(ostream&, const TicketCalc&);

private:
	TicketInfo info;
	ArrangedSeating arrangedObject;
	Deduction deductObject;
	vector<int> seatNumbers;
	vector<double> unitSale;
	vector<double> unitDifference; // difference refers to unit profit or loss
	double unitCost;
	double totalCost;
	double totalSale;
	double totalDifference;
	double totalDeduction;
	double serviceFee;
	double totalPayout;
	double profitPercent;
	bool recommend;

public:
	TicketCalc();
	TicketCalc(TicketInfo, ArrangedSeating, Deduction, double, vector<double> &);

	// set and get functions
	void setUnitCost();
	void setTotalCost(double);
	void setTotalSale();
	void setTotalDifference();
	void setTotalDeduction();
	void setServiceFee();
	void setTotalPayout();
	void setProfitPercent();
	void setRecommend();
	double getUnitCost() const;
	double getTotalCost() const;
	double getTotalSale() const;
	double getTotalDifference() const;
	double getTotalDeduction() const;
	double getServiceFee() const;
	double getTotalPayout() const;
	double getProfitPercent() const;
	bool getRecommend() const;


	void setUnitSaleVector(vector<double> &);
	void assignUnitDifferenceVector();
	void assignSeatVector();



};
