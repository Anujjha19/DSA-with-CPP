/* #include <iostream>
#include <map>
#include <vector>

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 1, 2, 2};
    std::map<int, int> frequency;

    for (auto x : v)
    {
        ++frequency[x];
    }

    int max_frequency = 0;
    int max_element;
    for (auto x : frequency)
    {
        if (x.second > max_frequency)
        {
            max_frequency = x.second;
            max_element = x.first;
        }
    }

    std::cout << "The element with the highest frequency is: " << max_element << std::endl;

    return 0;
}
 */
/*  //TC -O( N * N )

#include <bits/stdc++.h>
using namespace std;

void countFreq(int arr[], int n)
{
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        // Skip this element if already processed
        if (visited[i] == true)
            continue;
        // Count frequency
        int count = 0;
        for (int j = 0 ; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                visited[j] = true;
                count++;
            }
        }
        cout << arr[i] << " " << count << endl;
    }
}

int main()
{
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    countFreq(arr, n);
    return 0;
} */

#include <bits/stdc++.h>
using namespace std;
void Frequency(int arr[], int n)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
        map[arr[i]]++;
    // Traverse through map and print frequencies
    for (auto x : map)
        cout << x.first << " " << x.second << endl;
}

int main()
{
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Frequency(arr, n);
    return 0;
}
/* 
#include <iostream>
#include <map>

int findDiff(int arr[], int n)
{
    std::map<int, int> frequency;

    for (int i = 0; i < n; i++)
    {
        ++frequency[arr[i]];
    }

    int max_frequency = 0;
    int min_frequency = INT_MAX;
    for (auto x : frequency)
    {
        if (x.second > max_frequency)
        {
            max_frequency = x.second;
        }
        if (x.second < min_frequency)
        {
            min_frequency = x.second;
        }
    }

    return max_frequency - min_frequency;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int difference = findDiff(arr, n);

    std::cout << "The difference between the highest and lowest frequency is: " << difference << std::endl;

    return 0;
}
 */