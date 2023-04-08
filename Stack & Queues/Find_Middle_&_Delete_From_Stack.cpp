

#include <bits/stdc++.h>
using namespace std;

/* void deleteMiddleIterative(int arr[], int &n)
{
    // Check if array has an odd number of elements
    if (n % 2 == 0)
    {
        // Remove middle element by shifting all elements after it one position to the left
        for (int i = n / 2; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        // Decrease the size of the array by 1
        n--;
    }
    else
    {
        // If array has an even number of elements, remove both middle elements
        int midIndex = n / 2;
        for (int i = midIndex; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        // Decrease the size of the array by 2
        n -= 1;
    }
}

int main()
{

    int n = 5;
    int arr[n] = {1, 2, 3, 4, 5};
    deleteMiddleIterative(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
 */
void DeleteMiddleRecursively(stack<int> &st, int n, int count)
{
    if (count == n / 2)
    {
        st.pop();
        return;
    }
    int num = st.top();
    st.pop();

    DeleteMiddleRecursively(st, n, count + 1);
    st.push(num);
}

int main()
{

    stack<int> st;
    // push elements into the stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    // st.push(7);
    int count = 0;

    DeleteMiddleRecursively(st, st.size(), count);

    while (!st.empty())
    {
        int p = st.top();
        st.pop();
        cout << p << " ";
    }
    return 0;
}
