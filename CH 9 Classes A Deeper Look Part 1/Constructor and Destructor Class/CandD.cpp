#include <iostream>
#include "CandD.h"
using namespace std;
//constructor
ConstructAndDestroy::ConstructAndDestroy(int ID, string messageString)
{
	objectID = ID;//set objects descriptive number
	message = messageString;//set object's descriptive message
	
	cout << "Object " << objectID << " constructor runs  "
	<< message << endl;
}

//destructor
ConstructAndDestroy::~ConstructAndDestroy()
{
	cout << ((objectID == 1 || objectID == 6)? "\n": "");
	
	cout << "Object " << objectID << "  Destructor runs  " << message <<endl;
}