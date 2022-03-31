//최소, 최대를 구하는 문제
//N개의 입력값에서 구해야 한다.

#include <iostream>
using namespace std;

int main()
{
	int num;
	int in;
	int _min;
	int _max;

	cin >> num;
	for ( int i = 0; i < num; i++ )
	{
		cin >> in;
		if ( i == 0)
		{
			_min = in;
			_max = in;
		}
		else
		{
			if ( _min > in )
			{
				_min = in;
			}
			if ( _max < in )
			{
				_max = in;
			}
			
		}
	}
	cout << _min << " " << _max;
	return 0;
}
