

#include <bits/stdc++.h>
using namespace std;
// BF
double median(vector<int> &a, vector<int> &b)
{
    // size of two given arrays:
    int n1 = a.size(), n2 = b.size();

    vector<int> arr3;
    // apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
            arr3.push_back(a[i++]);
        else
            arr3.push_back(b[j++]);
    }

    // copy the left-out elements:
    while (i < n1)
        arr3.push_back(a[i++]);
    while (j < n2)
        arr3.push_back(b[j++]);

    // Find the median:
    int n = n1 + n2;
    if (n % 2 == 0)
    {
        double median = ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;
        return median;
    }
    return (double)arr3[n / 2];
}

// BS
double median(const std::vector<int> &a, const std::vector<int> &b)
{
    int cnt = 0;
    int elm1 = -1, elm2 = -1;

    int i = 0, j = 0;
    int n1 = a.size();
    int n2 = b.size();

    int n = n1 + n2;
    int ind1 = n / 2;
    int ind2 = ind1 - 1;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            if (cnt == ind1)
                elm1 = a[i];
            if (cnt == ind2)
                elm2 = a[i];
            cnt++;
            i++;
        }
        else
        {
            if (cnt == ind1)
                elm1 = b[j];
            if (cnt == ind2)
                elm2 = b[j];
            cnt++;
            j++;
        }
    }
    while (i < n1)
    {
        if (cnt == ind1)
            elm1 = a[i];
        if (cnt == ind2)
            elm2 = a[i];
        cnt++;
        i++;
    }
    while (j < n2)
    {
        if (cnt == ind1)
            elm1 = b[j];
        if (cnt == ind2)
            elm2 = b[j];
        cnt++;
        j++;
    }

    if (n % 2 == 1)
    {
        return (double)(elm1);
    }

    return (double)(elm1 + elm2) / 2.0;
}

// OS
double median(vector<int> &a, vector<int> &b)
{
    int n1 = a.size(), n2 = b.size();
    // if n1 is bigger swap the arrays:
    if (n1 > n2)
        return median(b, a);

    int n = n1 + n2;              // total length
    int left = (n1 + n2 + 1) / 2; // length of left half
    // apply binary search:
    int low = 0, high = n1;
    while (low <= high)
    {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        // calculate l1, l2, r1 and r2;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1)
            r1 = a[mid1];
        if (mid2 < n2)
            r2 = b[mid2];
        if (mid1 - 1 >= 0)
            l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
                return max(l1, l2);
            else
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }

        // eliminate the halves:
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0; // dummy statement
}

int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1)
         << median(a, b) << '\n';
}
