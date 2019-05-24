#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rolldice();//rolls dice, calculates and displays sum. Function will be written below the main

int main()
{
	//enumeration with constants that represents gamestatus
	//all constants are in caps
	enum Status {CONTINUE, LOST, WON};//end enum
	
	int myPoint;//point if no win or loss on first roll
	Status gameStatus;//can contain {CONTINUE, LOST, WON}
	
	//seed the PSRNG
	srand(time(0));
	
	int sumOfDice = rolldice();//first roll of dice
	
	//determine game status after first roll
	switch(sumOfDice)
	{
	case 7:
	case 11:
		gameStatus = WON;
		break;
	
	case 2:
	case 3:
	case 12:
		gameStatus = LOST;
		break;
	
	default:
		gameStatus = CONTINUE;//the game is not over
		myPoint = sumOfDice;
		cout << "Point is: " << myPoint << endl;
		break;
	}//end switch
	
	//start loop till player loses or wins
	while(gameStatus == CONTINUE)
	{
		sumOfDice = rolldice();//roll dice again
		
		//determine game status
		if (sumOfDice == myPoint)//win by making point
			gameStatus = WON;
		else
			if (sumOfDice == 7)//lose by rolling 7 before point 
				gameStatus = LOST;
	}//end loop
	
	//print results
	if (gameStatus == WON)
		cout << "Player wins" << endl;
	else
		cout << "Player loses" << endl;
}//end main

int rolldice()
{
	int die1 = 1 + rand() % 6;//first die roll
	int die2 = 1 + rand() % 6;//second die roll
	int sum = die1 + die2;//add reult of die1 and die
	
	//display result of the roll
	cout << "Player rolled " << die1 << " + " << die2 << " = " << sum << endl;
	return sum;//return result to caller
}//end rolldice funtion