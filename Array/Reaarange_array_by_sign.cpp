#include <bits/stdc++.h>
using namespace std;

vector<int> RearrangebySign(vector<int> A, int n)
{
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > 0)
            pos.push_back(A[i]);
        else
            neg.push_back(A[i]);
    }
    // Positives on even indices, negatives on odd.
    for (int i = 0; i < n / 2; i++)
    {

        A[2 * i] = pos[i];
        A[2 * i + 1] = neg[i];
    }

    return A;
}

vector<int> RearrangebySign(vector<int> A)
{

    int n = A.size();
    vector<int> ans(n, 0);

    // positive elements start from 0 and negative from 1.
    int posIndex = 0, negIndex = 1;
    for (int i = 0; i < n; i++)
    {

        // Fill negative elements in odd indices and inc by 2.
        if (A[i] < 0)
        {
            ans[negIndex] = A[i];
            negIndex += 2;
        }

        // Fill positive elements in even indices and inc by 2.
        else
        {
            ans[posIndex] = A[i];
            posIndex += 2;
        }
    }
    return ans;
}

vector<int> RearrangebySign(vector<int> A, int n)
{

    // Define 2 vectors, one for storing positive
    // and other for negative elements of the array.
    vector<int> pos;
    vector<int> neg;

    // Segregate the array into positives and negatives.
    for (int i = 0; i < n; i++)
    {

        if (A[i] > 0)
            pos.push_back(A[i]);
        else
            neg.push_back(A[i]);
    }

    // If positives are lesser than the negatives.
    if (pos.size() < neg.size())
    {

        // First, fill array alternatively till the point
        // where positives and negatives ar equal in number.
        for (int i = 0; i < pos.size(); i++)
        {

            A[2 * i] = pos[i];
            A[2 * i + 1] = neg[i];
        }

        // Fill the remaining negatives at the end of the array.
        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {

            A[index] = neg[i];
            index++;
        }
    }

    // If negatives are lesser than the positives.
    else
    {
        for (int i = 0; i < neg.size(); i++)
        {

            A[2 * i] = pos[i];
            A[2 * i + 1] = neg[i];
        }

        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {

            A[index] = pos[i];
            index++;
        }
    }
    return A;
}

int main()
{
    int n = 4;
    vector<int> A{1, 2, -4, -5};

    vector<int> ans = RearrangebySign(A, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
