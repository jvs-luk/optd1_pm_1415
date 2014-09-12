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

	cout << "Welkom in de toelatingsprogramma van Universiteit Leiden. Wij willen graag uw leeftijd weten.";
	cout << "Type in uw geboortejaar en druk Enter." << endl;
	cin >> birthYear;

	int ageInYears = currentYear - birthYear;

	if(ageInYears < 10 || ageInYears >= 101)
	{
		if(ageInYears >= 0 && ageInYears < 10)
		{
			cout << "U bent te jong om toegelaten te worden aan Universiteit Leiden. Dit is het einde van het programma." << endl;
		}
		if(ageInYears >= 101)
		{
			cout << "U bent te oud om toegelaten te worden aan Universiteit Leiden. Dit is het einde van het programma." << endl;
		}
		if(ageInYears < 0)
		{
			cout << "Stap alstublieft terug in de tijdmachine. Dit is het einde van het programma." << endl;
		}
		return 1;
	}
	cout << "Type nu uw geboortemaand in cijfers en druk Enter.";
	cout << "Bv. januari= 1, februari= 2, maart= 3, etc." << endl;
	cin >> birthMonth;

	if(birthMonth <= 0 || birthMonth > 12)
	{
		cout << "Uw ingevoerde maand bestaat niet. Dit is het einde van dit programma" << endl;
		return 1;
	}

	cout << "Type nu uw geboortedag in cijfers en druk Enter." << endl;
	cin >> birthDay;

	if(birthDay <= 0 || birthDay > 31)
	{
		cout << "Deze dag van de maand bestaat niet. Dit is het einde van dit programma." << endl;
		return 1;
	}

	return 0;
}
