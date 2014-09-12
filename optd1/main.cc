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
	int leapYears[49] = {1904, 1908, 1912, 1916, 1920, 1924, 1928, 1932, 1936,
			1940, 1944, 1948, 1952, 1956, 1960, 1964, 1968, 1972, 1976, 1980,
			1984, 1988, 1992, 1996, 2000, 2004, 2008, 2012, 2016, 2020, 2024,
			2028, 2032, 2036, 2040, 2044, 2048, 2052, 2056, 2060, 2064, 2068,
			2072, 2076, 2080, 2084, 2088, 2092, 2096};


	cout << "Welkom in de toelatingsprogramma van Universiteit Leiden. "
			"Wij willen graag uw leeftijd weten." << endl;
	cout << "Type in uw geboortejaar en druk Enter." << endl;
	cin >> birthYear;

	int ageInYears = currentYear - birthYear; //Berekening van leeftijd gebaseerd
	                                          //op gehele jaartallen

	if(ageInYears < 10 || ageInYears > 101) //Exclusiefactoren voor gebruikers met een
		                                    //leeftijd jonger dan 10 en ouder dan 101
	{
		if(ageInYears >= 0 && ageInYears < 10) //Vergelijking indien gebruiker een leeftijd
			                                   //tussen 0 en 10 heeft, beeindig programma
		{
			cout << "U bent te jong om toegelaten te worden aan Universiteit Leiden."
					" Dit is het einde van het programma." << endl;
		}
		if(ageInYears > 101) //Vergelijking indien gebruiker ouder dan 101
			                 // is, beeindig programma
		{
			cout << "U bent te oud om toegelaten te worden aan Universiteit Leiden. "
					"Dit is het einde van het programma." << endl;
		}
		if(ageInYears < 0) // Vergelijking indien iemand na 2014 'geboren' is
			               //en een negatieve leeftijd heeft, beeindig programma
		{
			cout << "Stap alstublieft terug in de tijdmachine. "
					"Dit is het einde van het programma." << endl;
		}
		return 1;
	}
	// Berekening om na te gaan of iemand in een schrikkeljaar is geboren
	if((birthYear >= 1901 && birthYear <= 2099) && birthYear%4 == 0)
	{
		daysInMonth[1] = 29; //Indien sprake is van schrikkeljaar,
		                     //geldt dat maand februari 29 dagen heeft
	}

	cout << "Type nu uw geboortemaand in cijfers en druk Enter." << endl;
	cout << "Bv. januari= 1, februari= 2, maart= 3, etc." << endl;
	cin >> birthMonth;

	//Indien men een niet-bestaand maand invoert, beeindig programma.
	if(birthMonth <= 0 || birthMonth > 12)
	{
		cout << "Uw ingevoerde maand bestaat niet. "
				"Dit is het einde van dit programma" << endl;
		return 1;
	}

	//Berekening van leeftijd in maanden, bepaald uit geboortejaar en geboortemaand
	int ageInMonths= (ageInYears * 12) + (currentMonth - birthMonth);

	if(ageInMonths < 120 || ageInMonths > 1212) //Exclusiefactoren voor gebruikers met
		                                        //een leeftijd jonger dan 10 en ouder dan 101
	{
		if(ageInMonths < 120) //Indien men jonger dan 10 jaar is, gebaseerd op maanden,
			                  //beeindig programma
		{
			cout << "U bent te jong om toegelaten te worden tot Universiteit Leiden. "
					"Dit is het einde van het programma." << endl;
		}
		if(ageInMonths > 1212) //Indien men ouder is dan 101 is, gebaseerd op maanden,
			                   //beeindig programma
		{
			cout << "U bent te oud om toegelaten te worden tot Universiteit Leiden. "
					"Dit is het einde van het programma." << endl;
		}
		return 1;
	}

	cout << "Type nu uw geboortedag in cijfers en druk Enter." << endl;
	cin >> birthDay;
	/* Ingetyped geboortedag wordt gecheckt met de dagen in de geboortemaand,
	 * deze waarde mag niet hoger zijn dan de waarde in de array-element
	 * en mag niet gelijk of lager zijn dan 0, anders beeindig programma
	 */
	if((birthDay > daysInMonth[birthMonth - 1]) || birthDay < 1)
	{
		cout << "Deze dag in de maand bestaat niet. "
				"Dit is het einde van het programma." << endl;
		return 1;
	}

	if(currentDay - birthDay < 0)
	{
		ageInMonths --; // Indien de geboortedag van de maand nog niet gepasseerd is,
		                //zal er een waarde van de leeftijd in maanden afgetrokken worden.
	}
	//Indien de geboortedag al gepasseerd is, is de variabele ageInMonths accuraat
	//en zal hiermee ongewijzigd verder berekend worden

	//Exclusiefactoren voor gebruikers jonger dan 10 jaar en gelijk of ouder dan 101 jaar
	if(ageInMonths < 120 || ageInMonths >= 1212)
	{
		if(ageInMonths < 120) //Indien gebruiker jonger dan 10 jaar is,
			                  //beeindig programma
		{
			cout << "U bent te jong om toegelaten te worden tot Universiteit Leiden. "
					"Dit is het einde van het programma." << endl;
		}
		if(ageInMonths >= 1212) //Indien gebruiker ouder dan of gelijk aan 101 jaar is,
			                    //beeindig programma
		{
			cout << "U bent te oud om toegelaten te worden tot Universiteit Leiden. "
					"Dit is het einde van het programma." << endl;
		}
		return 1;
	}

	int ageInDays = 0;

	for(int i = birthMonth-1; i < 12; i++) // Berekening van de dagen tussen geboortemaand
		                                   //en eind van geboortejaar
	{
		if(birthYear%4==0)
		{
			daysInMonth[1]=29;
		}
		else
		{
			daysInMonth[1]=28;
		}
		ageInDays += daysInMonth[i];
	}
	ageInDays -= birthDay; // Berekening van de dagen tussen geboortedag en eind van geboortejaar

	int yearsDiff = currentYear - (birthYear);

	for(int i = birthYear + 1; i <= currentYear ; i++)
	{
		for(int l = 0; l < 49; l++)
		{
			if(i == leapYears[l])
			  {
				ageInDays++;
			  }
		}

	}
	ageInDays += yearsDiff*365;

	for(int i = currentMonth-1; i < 12; i++)
	{
		if(birthYear%4==0)
		{
			daysInMonth[1]=29;
		}
		else
		{
			daysInMonth[1]=28;
		}
		ageInDays -= daysInMonth[i];
	}

	ageInDays += (daysInMonth[currentMonth]-currentDay);

	cout << ageInDays << endl;

	return 0;
}
