#include <iostream>
using namespace std;
int main()
{
    int N;
    cout <<"Enter no. of rows: ";
    cin >> N;
    int i=1;
    int j;
    int k;
    while(i <= N)
    {
        int j=1;
        while(j <=N-i)
        {
            cout << " ";
            j++;
        }
        k=1;
        while(k < i)
        {
            cout << k;
            k++;
        }
        while(k > 0)
        {
            cout << k;
            k--;
        }
        i++;
        cout << endl;
        
    }
    i=N-1;
    while(i>0)
    {
        j=1;
        while(j <=N-i)
        {
            cout << " ";
            j++;
        }
        k=1;
        while(k < i)
        {
            cout << k;
            k++;
        }
        while(k>0)
        {
            cout << k;
            k--;
        }
        i--;
        cout << endl;
    }
    return 0;
}