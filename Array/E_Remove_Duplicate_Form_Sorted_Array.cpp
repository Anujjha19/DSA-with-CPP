int removeDuplicates(vector<int> &nums)
{
    set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        s.insert(nums[i]);
    }

    int k = s.size();
    int j = 0;

    for (auto it : s)
    {
        nums[j++] = it;
    }

    return k;
}
/* 
int i = 0;

for (int j = 0; j < nums.size(); j++)
{
    if (nums[i] != nums[j])
    {
        i++;
        nums[i] = nums[j];
    }
}
return i + 1;
} */
