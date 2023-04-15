#include<iostream>
using namespace std;
int main()
{
	int line;
	cout << "Please enter the line number:" << endl;
	cin >> line;
	{
		for (int i = 1; i <= line; i++)
		{
			for (int j = line; j >= i + 1; j--)
			{
				cout << " ";
			}
			for (int k = 1; k <= 2 * i - 1; k++)
			{
				if (k <= i)
				{
					cout << k;
				}
			}
			for (int l = i - 1; l >= 1; l--)
			{
				cout << l;
			}
			cout << endl;
		}
	}
	{
		for (int n = line - 1; n >= 1; n--)
		{
			for (int l = 1; l <= line - n; l++ )
			{
				cout << " ";
			}
			for (int m = 1; m <= 2 * n - 1; m++)
			{
				if (m <= n)
					cout << m;
			}
			for (int o = n-1; o >= 1; o--)
			{
				cout << o;
			}
			cout << endl;
		}
	}

}