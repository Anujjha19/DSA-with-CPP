bool arraySortedOrNot(int arr[], int n) {
        // code here
        bool a= true;
        
        for( int i=1; i<n ; i++){
            if( arr [i] < arr[i-1]){
                a=false;
                
            }
        }
        if( a == true ) return 1;
        else return 0;
        
    }

/* 

bool isSorted(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[i])
        return false;
    }
  }

  return true;
} */