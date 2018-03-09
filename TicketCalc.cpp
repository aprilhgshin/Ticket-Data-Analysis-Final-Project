//April Shin
//CSIS 137 Wed Night Class
//Final Project

#include "TicketCalc.h"
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

TicketCalc::TicketCalc()
{
totalCost = 0.0;
unitCost = 0.0;
seatNumbers.assign(0, 0);
unitSale.assign(0, 0);
unitDifference.assign(0, 0);
setUnitCost();
setTotalSale();
setTotalDifference();
setServiceFee();
setTotalDeduction();
setTotalPayout();
setProfitPercent();
setRecommend();
}
TicketCalc::TicketCalc(TicketInfo i, ArrangedSeating a, Deduction d, double total, vector<double> &sale) : info(i), arrangedObject(a), deductObject(d)
{
	setTotalCost(total);
	assignSeatVector();
	setUnitCost();
	setUnitSaleVector(sale);
	assignUnitDifferenceVector();
	setTotalSale();
	setTotalDifference();
	setServiceFee();
	setTotalDeduction();
	setTotalPayout();
	setProfitPercent();
	setRecommend();
}
void TicketCalc::setTotalCost(double c)
{
	if (c >= 0)
	{
		totalCost = c;
	}
	else if (c < 0)
	{
		while (c < 0)
		{
			cout << "Invalid Input." << endl
				<< "Please enter the total face value of the ticket(s): " << endl;
			cin >> c;
		}
		totalCost = c;
	}
}
void TicketCalc::setUnitSaleVector(vector<double> &sale)
{
	unitSale.assign(info.getNumTickets(), 0);
	for (int i = 0; i < unitSale.size(); ++i)
	{
		unitSale[i] = sale[i];
	}
}
void TicketCalc::setUnitCost()
{
	unitCost = getTotalCost() / info.getNumTickets();
}
void TicketCalc::setTotalSale()
{
	double sumSale = 0;
	for (int i = 0; i < unitSale.size(); ++i)
	{
		sumSale += unitSale[i];
	}
	totalSale = sumSale;
}
void TicketCalc::setTotalDifference()
{
	totalDifference = getTotalSale() - getTotalCost();  // This number may be negative because it signifies profit AND loss
}
void TicketCalc::setTotalDeduction()
{
	totalDeduction = getServiceFee() + deductObject.getShippingFee();
}
void TicketCalc::setServiceFee()
{
	serviceFee = deductObject.getServiceFeePercent() * getTotalSale();
}
void TicketCalc::setTotalPayout()
{
	totalPayout = getTotalSale() - getTotalDeduction();
}
void TicketCalc::setProfitPercent()
{
	profitPercent = ((getTotalSale() - getTotalCost()) / getTotalCost())*100;
}
void TicketCalc::setRecommend()
{
	if (getProfitPercent() >= 20)
	{
		recommend = true;
	}
	else if (getProfitPercent() < 20)
	{
		recommend = false;
	}
}
double TicketCalc::getUnitCost() const
{
	return unitCost;
}
double TicketCalc::getTotalCost() const
{
	return totalCost;
}
double TicketCalc::getTotalSale() const
{
	return totalSale;
}
double TicketCalc::getTotalDifference() const
{
	return totalDifference;
}
double TicketCalc::getTotalDeduction() const
{
	return totalDeduction;
}
double TicketCalc::getServiceFee() const
{
	return serviceFee;
}
double TicketCalc::getTotalPayout() const
{
	return totalPayout;
}
double TicketCalc::getProfitPercent() const
{
	return profitPercent;
}
bool TicketCalc::getRecommend() const
{
	return recommend;
}
void TicketCalc::assignUnitDifferenceVector()
{
	unitDifference.assign(unitSale.size(), 0);
	for (int i = 0; i < unitDifference.size(); ++i)
	{
		unitDifference[i] = unitSale[i] - getUnitCost();
	}
}
void TicketCalc::assignSeatVector()
{
	int number = 0;
	seatNumbers.assign(info.getNumTickets(), 0);

	if (info.getEventType() == 1)
	{
		for (int i = 0; i < info.getNumTickets(); ++i)
		{
			seatNumbers[i] = i + 1;
		}
	}
	else if (info.getEventType() == 2)
	{
		if (arrangedObject.getSeatOrder() == 1)
		{
			for (int i = 0; i < info.getNumTickets(); ++i)
			{
				seatNumbers[i] = arrangedObject.getStartingSeatNum() + i;
			}
		}
		else if (arrangedObject.getSeatOrder() == 2)
		{
			for (int i = 0; i < info.getNumTickets(); ++i)
			{
				seatNumbers[i] = arrangedObject.getStartingSeatNum() + (number);
				number += 2;
			}
		}
	}
}

ostream& operator<<(ostream &output, const TicketCalc &calc)
{
	output << "Seat # |" << setw(14) << "Unit Cost   "<< setw(14) << "Unit Sale   " << "  Unit Profit/Loss" << endl;
	for ( int i = 0; i < calc.seatNumbers.size(); ++i)
	{
		output << setw(6) <<calc.seatNumbers[i] << " |"<< setw(6) << fixed << setprecision(2) << "$"<< calc.getUnitCost() << "   " << right << setw(6) << "$"<< calc.unitSale[i] << "  "<< setw(6) << "$" <<calc.unitDifference[i] << endl;
	}
	output << "\nDEDUCTIONS =   " << "Shipping Fee:  $" << calc.deductObject.getShippingFee() << "     Service Fee:  $" << calc.getServiceFee() << endl;
	output << "\nTotal Cost:           $" << fixed << setprecision(2) << setw(7) << calc.getTotalCost() << endl
		     << "Total Sale:           $" << fixed << setprecision(2) << setw(7) << calc.getTotalSale() << endl
		     << "Total Deduction:      $" << fixed << setprecision(2) << setw(7) << calc.getTotalDeduction() << endl
		     << "Total Profit or Loss: $" << fixed << setprecision(2) << setw(7) << calc.getTotalDifference() << endl
		     << "Total Payout:         $" << fixed << setprecision(2) << setw(7) << calc.getTotalPayout() << endl;
	output << "\nProfit Percent: " << fixed << setprecision(1) << calc.getProfitPercent() << "%" << endl;
		
	if (calc.getRecommend() == true)
	{
		output << "\nBased on the data, it is recommended that you continue to sell tickets for this event.\n" << endl;
	}
	else if (calc.getRecommend() == false)
	{
		output << "\nBased on the data, it is NOT recommended that you continue to sell tickets for this event.\n" << endl;
	}
	return output;
} 
