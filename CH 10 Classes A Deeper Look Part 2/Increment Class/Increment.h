#ifndef INCREMENT_H
#define INCREMENT_H
class 	Increment
{
public:
	Increment(int c = 0, int i = 1);//default constructor
	//function addIncrement definition
	void addIncrcement()
	{
		count += increment;
	}
	
	void print() const;//print count and increment
private:
	int count;
	const int increment;
};//end class increment
#endif