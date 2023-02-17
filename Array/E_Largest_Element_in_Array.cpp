int largest(vector<int> &arr, int n)
    {
        int ans = arr[0];
        for( int i =1;i<n; i++){
            if( arr[i] > ans ) ans = arr[i];
        }
        return ans;
    }


    /* 
    int sortArr(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    return arr[arr.size()-1];
}

     */