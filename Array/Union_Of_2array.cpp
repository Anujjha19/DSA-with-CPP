/*     vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements

        map<int,int>mp;
        vector<int> ans;

        for( int i=0 ; i<n ; i++){
            mp[arr1[i]]++;

        }
        for( int j=0 ; j<m ; j++){
            mp[arr2[j]]++;

        }

        for ( auto it : mp){
            ans.push_back(it.first );
        }

        return  ans;
    }

 */
/*  set<int>s;

        vector<int> ans;

        for( int i=0 ; i<n ; i++){
            s.insert(arr1[i]);

        }
        for( int j=0 ; j<m ; j++){
            s.insert(arr2[j]);

        }

        for ( auto it : s){
            ans.push_back(it );
        }

        return  ans;

    */

#include <iostream>
#include <vector>

using namespace std;

vector<int> sortedArray(vector<int> a, vector<int> b)
{
    int n = a.size();
    int m = b.size();

    int i = 0;
    int j = 0;
    vector<int> result;

    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            if (result.empty() || result.back() != a[i])
            {
                result.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (result.empty() || result.back() != b[j])
            {
                result.push_back(b[j]);
            }
            j++;
        }
    }

    while (i < n)
    {
        if (result.empty() || result.back() != a[i])
        {
            result.push_back(a[i]);
        }
        i++;
    }

    while (j < m)
    {
        if (result.empty() || result.back() != b[j])
        {
            result.push_back(b[j]);
        }
        j++;
    }

    return result;
}

int main()
{
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    vector<int> a(arr1, arr1 + n);
    vector<int> b(arr2, arr2 + m);
    vector<int> Union = sortedArray(a, b);
    cout << "Union of arr1 and arr2 is  " << endl;
    for (auto &val : Union)
        cout << val << " ";
    return 0;
}
