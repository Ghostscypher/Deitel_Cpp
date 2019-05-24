#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	string username;
	int answer_counter = 0;
	char answer;
	
	cout << "Welcome to Global Warming Test" << endl;
	cout << "To continue please enter your username: ";
	getline(cin, username);
	
	cout << setw(20)<< "Question 1" << endl;
	cout << "i. What is global warming." << endl;
	cout << "A.) The globe becoming warmer." << endl;
	cout << "B.) Rise in temeperature in the earth's earthmosphere because of carbon and green house gases." << endl;
	cout << "C.) Rise in temperature in the earth's atmosphere because of nitrogen." << endl;
	cout << "Any other character.) Pass\nAnswer: ";
	cin >> answer;
	
	if (answer == 'B' || answer == 'b')
			answer_counter++;
		
	cout << setw(20)<< "Question 2" << endl;
	cout << "i. Which of the following does not cause global warming." << endl;
	cout << "A.) Oxygen." << endl;
	cout << "B.) Methane." << endl;
	cout << "C.) Smog." << endl;
	cout << "Any other character.) Pass\nAnswer: ";
	cin >> answer;
	
	if (answer == 'A' || answer == 'a')
			answer_counter++;
		
	cout << setw(20)<< "Question 3" << endl;
	cout << "i. What should you do with garbage" << endl;
	cout << "A.) Burn them." << endl;
	cout << "B.) Throw them." << endl;
	cout << "C.) Recycle them." << endl;
	cout << "Any other character.) Pass\nAnswer: ";
	cin >> answer;
	
	if (answer == 'C' || answer == 'c')
			answer_counter++;
		
	cout << setw(20)<< "Question 4" << endl;
	cout << "i. Does the ozone have holes" << endl;
	cout << "A.) No." << endl;
	cout << "B.) Yes" << endl;
	cout << "C.) Maybe." << endl;
	cout << "Any other character.) Pass\nAnswer: ";
	cin >> answer;
	
	if (answer == 'b' || answer == 'B')
			answer_counter++;
		
	cout << setw(20)<< "Question 5" << endl;
	cout << "i. In which of the following ways can one help fight against global warming" << endl;
	cout << "A.) Planting more trees" << endl;
	cout << "B.) Cutting down trees" << endl;
	cout << "C.) Burning down trees and trashes" << endl;
	cout << "Any other character.) Pass\nAnswer: ";
	cin >> answer;
	
	if (answer == 'A' || answer == 'a')
			answer_counter++;
		
    cout << "\n" <<username << ": You scored " << answer_counter << "/5" << endl;
	if (answer_counter == 5)
		cout << "Excellent" << endl;
	else if (answer_counter == 4)
		cout << "Very good" << endl;
	else
		cout << "Why?" << endl;
}