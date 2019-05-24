#include <iostream>

using namespace std;

int main()
{
	int i = 1;
	while(i <= 10)
	{
		if (i == 5)
		{
			break;
		} // End if
	cout << i << " ";
	i++;
	}
	cout << "\nThis loop stopped at: " << i << endl;
}