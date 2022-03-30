//손풀기

#include <iostream>
using namespace std;

int main()
{
	int A;
	int B;

	cin >> A >> B;

	if ( A > B )
	{
		cout << ">";
		return 0;
	}
	if ( A < B )
	{
		cout << "<";
		return 0;
	}
	cout << "==";
	
	return 0;
}
