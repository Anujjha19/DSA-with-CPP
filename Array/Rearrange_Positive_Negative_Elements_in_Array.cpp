#include<vector>
#include<iostream>
using namespace std;


void rearrange(int arr[], int n)
{
    vector<int> positive, negative;
    // Run Loop To All Elements, In Original array
    for (int i = 0; i < n; i++)
    {
        // if Elements < 0 Store In Negative Vector
        if (arr[i] < 0)
        {
            negative.push_back(arr[i]);
        }
        else // Else In Positive Vector
        {
            positive.push_back(arr[i]);
        }
    }
    // Now Start Updating Values of Original Array
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < positive.size() && j < negative.size())
    { // As First Elements Should be Positive Thats Why
        arr[k++] = positive[i++];
        arr[k++] = negative[j++];
    }
    // Now if Elements Left In Positive Vector
    while (i < positive.size())
    {
        arr[k++] = positive[i++];
    }
    // If Elements Left In Negative Vector
    while (j < negative.size())
    {
        arr[k++] = negative[j++];
    }
}



/* 
vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> pos;
        vector<int> neg;

        for (auto i : nums)
        {
            if (i >= 0)
                pos.push_back(i);

            else
                neg.push_back(i);
        }

        int i = 0, j = 0, k = 0;
        bool flag = true;

        while (i < pos.size() || j < neg.size())
        {
            if (flag)
            {
                nums[k++] = pos[i++];
            }
            else
            {
                nums[k++] = neg[j++];
            }
            flag = !flag;
        }

        return nums;
    } */