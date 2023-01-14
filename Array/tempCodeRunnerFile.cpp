while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        reverseArray(arr , start+1, end-1 );
    }