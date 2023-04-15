#include <iostream>
using namespace std;

int main(){

int i,j,k;
int rows;
cout <<"Enter rows: ";
cin >> rows;

for( i=1;i<=rows;i++)
{
	for(j=1;j<=rows-i;j++)
	{
		cout << " ";
	}
	for(k=1;k<=2*i - 1;k++)
	{
		if ( k == 1 || k == 2*i - 1)
		{
			cout <<"*";
		}
		else
		{
			cout << " ";
		}
	}

	cout<<endl;
}
i-=2;
for( ;i>0;i--)
{
	for(j=1;j<=rows-i;j++)
	{
		cout << " ";
	}
	for(k=1;k<=2*i - 1;k++)
	{
		if ( k == 1 || k == 2*i - 1)
		{
			cout <<"*";
		}
		else
		{
			cout << " ";
		}
	}

	cout<<endl;
}

}