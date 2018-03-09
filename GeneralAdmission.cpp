//April Shin
//CSIS 137 Wed Night Class
//Final Project

#include "GeneralAdmission.h"

GeneralAdmission::GeneralAdmission(const string& section, const string& row)
{
	setGivenSectionNum(section);
	setGivenRowNum(row);
}
void GeneralAdmission::setGivenSectionNum(const string& section)
{
	givenSectionNum = section;
}
void GeneralAdmission::setGivenRowNum(const string& row)
{
	givenRowNum = row;
}
string GeneralAdmission::getGivenSectionNum() const
{
	return givenSectionNum;
}
string GeneralAdmission::getGivenRowNum() const
{
	return givenRowNum;
}
