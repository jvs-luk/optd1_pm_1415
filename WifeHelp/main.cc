//bhjvgcxxtcxrcx
#include <iostream>

using namespace std;

const int currentYear = 2014;
const int currentMonth = 9;
const int currentDay = 19;

int main()
{
	int birthYear;
	int birthMonth;
	int birthDay;
	int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	cout << "Welkom in de toelatingsprogramma van Universiteit Leiden. Wij willen graag uw leeftijd weten." << endl;
	cout << "Type in uw geboortejaar en druk Enter." << endl;
	cin >> birthYear;

	int ageInYears = currentYear - birthYear;

	if(ageInYears < 10 || ageInYears > 101)
	{
		if(ageInYears >= 0 && ageInYears < 10)
		{
			cout << "U bent te jong om toegelaten te worden aan Universiteit Leiden. Dit is het einde van het programma." << endl;
		}
		if(ageInYears > 101)
		{
			cout << "U bent te oud om toegelaten te worden aan Universiteit Leiden. Dit is het einde van het programma." << endl;
		}
		if(ageInYears < 0)
		{
			cout << "Stap alstublieft terug in de tijdmachine. Dit is het einde van het programma." << endl;
		}
		return 1;
	}
	if((birthYear >= 1901 && birthYear <= 2099) && birthYear%4 == 0)
	{
		daysInMonth[1] = 29;
	}

	cout << "Type nu uw geboortemaand in cijfers en druk Enter." << endl;
	cout << "Bv. januari= 1, februari= 2, maart= 3, etc." << endl;
	cin >> birthMonth;

	if(birthMonth <= 0 || birthMonth > 12)
	{
		cout << "Uw ingevoerde maand bestaat niet. Dit is het einde van dit programma" << endl;
		return 1;
	}

	int ageInMonths= (ageInYears * 12) + (currentMonth - birthMonth);

	if(ageInMonths < 120 || ageInMonths > 1212)
	{
		if(ageInMonths < 120)
		{
			cout << "U bent te jong om toegelaten te worden tot Universiteit Leiden. Dit is het einde van het programma." << endl;
		}
		if(ageInMonths > 1212)
		{
			cout << "U bent te oud om toegelaten te worden tot Universiteit Leiden. Dit is het einde van het programma." << endl;
		}
		return 1;
	}

	cout << "Type nu uw geboortedag in cijfers en druk Enter." << endl;
	cin >> birthDay;
	if((birthDay > daysInMonth[birthMonth - 1]) || birthDay < 1)
	{
		cout << "Deze dag in de maand bestaat niet. Dit is het einde van het programma." << endl;
		return 1;
	}

	int ageInMonthsBasedOnDay= currentDay - birthDay;

	if(ageInMonthsBasedOnDay < 0)
	{
		ageInMonths --;
	}
	else
	{
		ageInMonthsBasedOnDay = ageInMonths;
	}

	if(ageInMonths < 120 || ageInMonths >= 1212)
	{
		if(ageInMonths < 120)
		{
			cout << "U bent te jong om toegelaten te worden tot Universiteit Leiden. Dit is het einde van het programma." << endl;
		}
		if(ageInMonths >= 1212)
		{
			cout << "U bent te oud om toegelaten te worden tot Universiteit Leiden. Dit is het einde van het programma." << endl;
		}
		return 1;
	}

	return 0;
}
