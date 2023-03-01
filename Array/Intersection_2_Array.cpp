

#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> A{1, 2, 3, 3, 4, 5, 6, 7};
    vector<int> B{3, 3, 4, 4, 5, 8};

    vector<int> ans;

    int i = 0, j = 0; // to traverse the arrays

    while (i < A.size() && j < B.size())
    {
        if (A[i] < B[j])
        { // if current element in i is smaller
            i++;
        }
        else if (B[j] < A[i])
        {
            j++;
        }
        else
        {
            ans.push_back(A[i]); // both elements are equal
            i++;
            j++;
        }
    }
    cout << "The elements are: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
// Count
/*     int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
       unordered_set<int>s;
       for(int i=0;i<n;i++)
           s.insert(a[i]);

       int count=0;
       for(int i=0;i<m;i++){
           int key=b[i];
           if(s.find(key)!=s.end())
               count++;
               s.erase(b[i]);   // remove the already counted element , otherwise  it would be counted multiple times.
       }
   return count;
   }
 */

/* #include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> A{1, 2, 3, 3, 4, 5, 6, 7};
    vector<int> B{3, 3, 4, 4, 5, 8};

    vector<int> ans;
    vector<int> visited(B.size(), 0); // to maintain visited
    int i = 0, j = 0;
    for (i = 0; i < A.size(); i++)
    {
        for (j = 0; j < B.size(); j++)
        {

            if (A[i] == B[j] && visited[j] == 0)
            {
                // if element matches and has not been matched with any other before
                ans.push_back(B[j]);
                visited[j] = 1;

                break;
            }
            else if (B[j] > A[i])
                break;
            // because array is sorted , element will not be beyond this
        }
    }
    cout << "The elements are: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
 */