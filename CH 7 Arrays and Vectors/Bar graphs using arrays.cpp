#include <iostream>
#include <iomanip>
using namespace std;

//start of protoypes
	
//end of prototypes

int main()
{
	const int x = 11;
	int t_students = 0;
	
	cout << "Enter total number of students to evaluate: ";
	cin >> t_students;
	const int y = t_students;
	
	//dynamically alocate our array
	double grades[y];//initialize array to zero
	
	double average = 0;
	double total = 0;
	int counter[x] = {};//initilaize our counter to 0
	int i = 0;//to be used in loops
	int j = 0;//to be used in nested loops

	
	cout << "Enter grades for " << t_students << " students" << endl;
	for(i = 0; i < t_students; i++)
	{
L1:		cout << "\nStudent [" << i + 1 << "]: ";
		cin >> grades[i];
		//check that invalid marks are not entered
		if(grades[i] < 0 || grades[i] > 100)
		{
			cout << "Invalid marks. Please enter marks betweeen 0  and 100 (0 - 100)" << endl;
			goto L1;
		}
		
		//update counter
		/*check for number of students in each category
		i.e.
		0 - 9: counter[0]
		10 - 19: counter[1]
		20 - 39: counter[2]
		30 - 39: counter[3]
		40 - 49: counter[4]
		50 - 59: counter[5]
		60 - 69: counter[6]
		70 - 79: counter[7]
		80 - 89: counter[8]
		90 - 99: counter[9]
		100: counter[10]
		*/
		
		// To avoid using nested if I did it as shown below
		if(grades[i] < 10)
			counter[0]++;
		
		if(grades[i] >= 10 && grades[i] < 20)
			counter[1]++;
		
		if(grades[i] >= 20 && grades[i] < 30)
			counter[2]++;
		
		if(grades[i] >= 30 && grades[i] < 40)
			 counter[3]++;
		 
		 if(grades[i] >= 40 && grades[i] < 50)
		 	counter[4]++;
		 
		 if(grades[i] >= 50 && grades[i] < 60)
		 	counter[5]++;
		 
		 if(grades[i] >= 60 && grades[i] < 70)
		 	counter[6]++;
		 
		 if(grades[i] >= 70 && grades[i] < 80)
		 	counter[7]++;
		 
		 if(grades[i] >= 80 && grades[i] < 90)
		 	counter[8]++;
		 
		  if(grades[i] >= 90 && grades[i] < 100)
		 	counter[9]++;
		 
		 if(grades[i] == 100)
		 	counter[10]++;
	}
	
	//print spaces
	cout << endl << endl;
	
	//calculate the total, average and print grade. then draw bar graph
	//loop 10 times
	for(i = 0; i < t_students; i++)
	{
		//calculate total
		total += grades[i];
	}
	
	//calculate average
		average = total / static_cast <double> (t_students);
	
	//for the graph
	
	//finally draw the graph
	for (i = 0; i <= 10; i++)
	{
		if (i == 0)
			cout << " 0 -  9: ";
		else if (i == 10)
			cout << "    100: ";
		else
			cout << i * 10 << " - " << i * 10 + 9 << ": ";
		
		//print astericks to represent distributions
		for(j = 0; j < counter[i]; j++)
		{
			cout << "*";
		}
		cout << "\t Total number: " << counter[i] << endl;
	}
	//print spaces
	cout << endl;
	
	//print average and grade
	cout << "Total: " << setprecision(4) << fixed << total << endl;
	cout << "Average: " << setprecision(4) << fixed << average << endl;
}