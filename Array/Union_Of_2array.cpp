    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        
        map<int,int>mp;
        vector<int> ans;
        
        for( int i=0 ; i<n ; i++){
            mp[arr1[i]]++;
            
        }
        for( int j=0 ; j<m ; j++){
            mp[arr2[j]]++;
            
        }
        
        for ( auto it : mp){
            ans.push_back(it.first );
        }
        
        return  ans;
    }


 set<int>s;
        
        vector<int> ans;
        
        for( int i=0 ; i<n ; i++){
            s.insert(arr1[i]);
            
        }
        for( int j=0 ; j<m ; j++){
            s.insert(arr2[j]);
            
        }
        
        for ( auto it : s){
            ans.push_back(it );
        }
        
        return  ans;