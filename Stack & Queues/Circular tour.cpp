#include <iostream>
using namespace std;

struct PetrolPump
{
    int petrol;
    int distance;
};

int getTourIndex(PetrolPump arr[], int n)
{
    int defecit = 0;
    int balance = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        balance += arr[i].petrol - arr[i].distance;

        if (balance < 0)
        {
            defecit += balance;
            start = i + 1;
            balance = 0;
        }
    }

    return (defecit + balance >= 0) ? start : -1;
}

int main()
{
    PetrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}};
    int n = sizeof(arr) / sizeof(arr[0]);

    int tourIndex = getTourIndex(arr, n);

    if (tourIndex != -1)
    {
        cout << "The first petrol pump from where a truck can complete the circle is at index: " << tourIndex << endl;
    }
    else
    {
        cout << "There is no petrol pump from where a truck can complete the circle." << endl;
    }

    return 0;
}
