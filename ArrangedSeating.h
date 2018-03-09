//April Shin
//CSIS 137 Wed Night Class
//Final Project

#pragma once
#define ARRANGEDSEATING
#include <vector>
#include <string>
using namespace std;

class ArrangedSeating
{
private:
	string sectionNum;
	string rowNum;
	int startingSeatNum;
	int seatOrder;

public:
	ArrangedSeating();
	ArrangedSeating(const string&, const string&, int, int);

	// set and get functions
	void setSectionNum(const string&);
	void setRowNum(const string&);
	void setStartingSeatNum(int);
	void setSeatOrder(int);
	string getSectionNum() const;
	string getRowNum() const;
	int getStartingSeatNum() const;
	int getSeatOrder() const;

};
