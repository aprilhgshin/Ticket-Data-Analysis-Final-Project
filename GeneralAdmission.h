//April Shin
//CSIS 137 Wed Night Class
//Final Project

#pragma once
#define GENERALADMISSION
#include <vector>
#include <string>
using namespace std;

class GeneralAdmission
{
private:
	string givenSectionNum;
	string givenRowNum;

public:
	GeneralAdmission(const string& sectionNum = "GA", const string& rowNum = "GA");

	// set and get functions
	void setGivenSectionNum(const string&);
	void setGivenRowNum(const string&);
	string getGivenSectionNum() const;
	string getGivenRowNum() const;
};
