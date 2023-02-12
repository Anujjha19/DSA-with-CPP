#include <bits/stdc++.h>
using namespace std;

int counter = 0;

void print()
{   
    //Base Call
    if (counter == 3)
        return;

    cout << counter << endl;
    counter++;
    print();
}
int main()
{
    print();
    return 0;
}