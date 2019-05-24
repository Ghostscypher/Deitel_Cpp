#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int b = 205;
	int c = 30;
	int d = 200;
	int e = 50;
	int f = 6;
	int g = 7;
	int h = 20;
	int i = 15;
	int j = 20;
	
	int MaximumValue;
	int temporarymax;
	
		MaximumValue = a;
				
			if(b > MaximumValue)
				MaximumValue = b;
			
			if(c > MaximumValue)
				MaximumValue = c;
			
			if(d > MaximumValue)
				MaximumValue = d;
			
			if(e > MaximumValue)
				MaximumValue = e;
			
			if(f > MaximumValue)
				MaximumValue = f;
			
			if(g > MaximumValue)
				MaximumValue = g;
			
			if(h > MaximumValue)
				MaximumValue = h;
			
			if(i > MaximumValue)
				MaximumValue = i;
			
			if(j > MaximumValue)
				MaximumValue = j;
			
			cout << "The maximum value is: " << MaximumValue << endl;
			
			temporarymax = MaximumValue;
			
			MaximumValue = a;
			
			if(b < temporarymax && b >= MaximumValue)
				MaximumValue = b;
			
			if(c < temporarymax && c >= MaximumValue)
				MaximumValue = c;
			
			if(d < temporarymax && d >= MaximumValue)
				MaximumValue =d;
			
			if(e < temporarymax && e >= MaximumValue)
				MaximumValue = e;
			
			if(f < temporarymax && f >= MaximumValue)
				MaximumValue = f;
			
			if(g < temporarymax && g >= MaximumValue)
				MaximumValue = g;
			
			if(h < temporarymax && h >= MaximumValue)
				MaximumValue = h;
			
			if(i < temporarymax && i >= MaximumValue)
				MaximumValue = i;
			
			if(j < temporarymax && j >= MaximumValue)
				MaximumValue = j;
			
			cout << "The second maximum number is: " << MaximumValue << endl;
}