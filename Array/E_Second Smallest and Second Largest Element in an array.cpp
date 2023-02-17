int secondSmallest(int arr[], int n)
{
    if (n < 2)
        return -1;
    int small = INT_MAX;
    int second_small = INT_MAX;
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] < small)
        {
            second_small = small;
            small = arr[i];
        }
        else if (arr[i] < second_small && arr[i] != small)
        {
            second_small = arr[i];
        }
    }
    return second_small;
}
int secondLargest(int arr[], int n)
{
    if (n < 2)
        return -1;
    int large = INT_MIN, second_large = INT_MIN;
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > large)
        {
            second_large = large;
            large = arr[i];
        }

        else if (arr[i] > second_large && arr[i] != large)
        {
            second_large = arr[i];
        }
    }
    return second_large;
}

/* int print2largest(int arr[], int n)
{
    // code here
    int large = INT_MIN;
    int secLarge = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > large)
            large = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > secLarge && arr[i] != large)
        {
            secLarge = arr[i];
        }
    }

    return secLarge;
}
 */
/*

void getElements(int arr[],int n)
{
    if(n==0 || n==1)
        cout<<-1<<" "<<-1<<endl;  // edge case when only one element is present in array
    sort(arr,arr+n);
    int small=arr[1];
    int large=arr[n-2];
    cout<<"Second smallest is "<<small<<endl;
    cout<<"Second largest is "<<large<<endl;
}
 */