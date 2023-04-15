#include <iostream>
#include <list>
#include <algorithm>
using namespace std;


class HashTable{

        const int TS = 10;
        list<int> *table;
public:
        HashTable()
        {
                //this->TS = size;
                table = new list<int>[TS];
        }
        void insertitem(int x);

        void removeitem(int x);

        int findvalue(int x);

        int Hashfunction(int x)
        {
                return(x%TS);
        }

        void displayhash();
};


void HashTable::insertitem(int key)
{
        int index = Hashfunction(key);
        table[index].push_back(key);
}

void HashTable::removeitem(int key)
{
        int index = Hashfunction(key);
        list <int> :: iterator i;
        for(i= table[index].begin(); i != table[index].end();i++)
        {
                if(*i == key)
                break;
        }
        if(i != table[index].end())
        table[index].erase(i);
}

int HashTable :: findvalue(int x)
{
     int index = Hashfunction(x);
     auto it = find(table[index].begin(), table[index].end(),x);
     return (it != table[index].end());

}


void HashTable::displayhash()
{
        for(int i=0;i<TS;i++)
        {
                cout << i ;
                for (auto x : table[i])
                        cout << " --> " << x;
                cout << endl;
        }
}
int main()
{
        int x;
        
        cout << "Enter the number of values you want to enter into the table: ";
        cin >> x;
        int a[x];
        int t;
        for(int i=0;i<x;i++)
        {
                cout << "Enter "<< i << " value into table:";
                cin >> a[i];

        }
        int n= sizeof(a)/sizeof(a[0]);

        HashTable h;

        for(int i=0; i<n; i++)
        {
                h.insertitem(a[i]);
        }
        cout << "Enter a value to find : ";
        cin >> t;

        h.removeitem(12);

        if(h.findvalue(t))
        {
                cout << "Value found\n";
        }

        h.displayhash();

}