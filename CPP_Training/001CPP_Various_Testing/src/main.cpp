#include <iostream>

using namespace std;

int main(int argc,char* argv[])
{
	cout << "Test program !" << endl;
	cout << "Number of arguments given to program : " << argc << endl;
	
	for(int i=0; i < argc; i++)
	{
		cout << "Argument " << i << ": " << argv[i] << endl;
	}

	return 0;
}