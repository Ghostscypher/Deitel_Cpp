#include <iostream>
#include <string>

using namespace std;

 int check_character_entered(char entered)// Start of function
{
	//checks if correct character is entered
	if (entered == 'k' || entered == 'K' || entered == 'P' || entered == 'p')
	{
		return 0;//return 0 if a correct character is entered
	}
	else
	{
		return -1;//returns -1 if incorrecet character is entered
	}
}//end of function

int main()
{
	float weight, height, BMI;//declares weight in both pounds and kilograms. Height inches, meteres
	char dvar;//dvar is the decison variable that will change from time to time
	string wtype, htype;//weight units and height units to be used exactly
	
	//display BMI information according to Departement of Health and Human services
	cout << "---------BMI Values---------" << endl;
	cout << "Underweight : less than 18.5" << endl;
	cout << "Normal : between 18.5 and  24.9" << endl;
	cout << "Overweight : between 25 and 29.9" << endl;
	cout << "Obese : 30 or higher\n" << endl;
	
	//loop until user inputs the correct character
	
	while (check_character_entered(dvar) == -1)	
	{
	cout << "Enter p to use pounds or k to use kilograms: ";//labeled to be referenced back on
	cin >> dvar;//read the character
	
	if (check_character_entered(dvar) == -1)
		cout << "Incorrect character try again" << endl;
	}
	
	//checking whether the user will be using kilograms and metres or pounds and inches
	if (dvar == 'p' || dvar == 'P')
	{
		wtype = "pounds";
		htype = "inches";
	}
	else
	{
		wtype = "kilograms";
		htype = "metres";
	}
	
	cout << "Please enter your weight in " << wtype << ": " << endl;
	cin >> weight;
	cout << "Please enter your height in " << htype << ": " << endl;
	cin >> height;
	cout << endl;
	   
	//BMI calculation here depending on the units used	
	if (dvar == 'p' || dvar == 'P')
		BMI = (weight * 703) / (height * height);
	else
		BMI = weight / (height * height);
	
	//Evaluating the results of the BMI index
	if (BMI < 18.5)
	{
		cout << "BMI Value: " << BMI << endl;
		cout << "Underweight" << endl;
	}
	else if (BMI < 24.9)
	{
		cout << "BMI Value: " << BMI << endl;
		cout << "Normal" << endl;
	}
	else if (BMI < 29.9)
	{
		cout << "BMI Value: " << BMI << endl;
		cout << "Overweight" << endl;
	}
	else
	{
		cout << "BMI Value: " << BMI << endl;
		cout << "Obese" << endl;
	}
} // End main function