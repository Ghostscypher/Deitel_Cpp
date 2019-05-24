#include <string>
using namespace std;

#ifndef CANDD_H
#define CANDD_H
class ConstructAndDestroy
{
public:
	ConstructAndDestroy(int, string);//constructor function
	~ConstructAndDestroy();//destructor function
private:
	int objectID;//ID Nimber for object
	string message;//message for describing object
};
#endif