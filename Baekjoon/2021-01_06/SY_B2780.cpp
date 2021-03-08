//
#include <stdio.h>

int dp[1001][10];

int main()
{
	int T;
	for(int i = 0; i< 10; i++)
	{
		dp [1][i] = 1;
	}
	while(T--){
		int input;
		cin >> input;

		if( input == 1)
		{
			int res;
			for(int i = 0; i < 10; i++)
			{
				res += dp[input][i];
			}
			cout << res << '\n';
			break;
		}
		for(int i = 2; i <= input )
		{
			for(int k = 0; k < 10; k++)
			{
				if(dp[i][k]==0)
				{
					switch(k)
					{
						case 0 : 
							dp[i][k] = dp[i-1][7];
							break;
						case 1 : 
							dp[i][k] = dp[i-1][2] + dp[i-1][4];
							break;
						case 2 : 
							dp[i][k] = dp[i-1][1] + dp[i-1][3] + dp[i-1][5];
							break;
						case 3 : 
							dp[i][k] = dp[i-1][2] + dp[i-1][6];
							break;
						case 4 : 
							dp[i][k] = dp[i-1][1] + dp[i-1][5] + dp[i-1][7];
							break;
						case 5 : 
							dp[i][k] = dp[i-1][2] + dp[i-1][4] + dp[i-1][6] + dp[i-1][6];
							break;
						case 6 : 
							dp[i][k] = dp[i-1][3] + dp[i-1][5] + dp[i-1][9];
							break;
						case 7 : 
							dp[i][k] = dp[i-1][0] + dp[i-1][4] + dp[i-1][8];
							break;
						case 8 : 
							dp[i][k] = dp[i-1][5] + dp[i-1][7] + dp[i-1][9];
							break;
						case 9 : 
							dp[i][k] = dp[i-1][6] + dp[i-1][8];
							break;
					}
				}
			}
		}
		for(int i = 0; i < 10; i++)
		{
			res += dp[input][i];
		}
		cout << res << '\n';
	}
	return 0;
}
