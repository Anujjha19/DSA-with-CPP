class Solution {
    private: 
    void swap(vector<int>& nums, int start,int end ) {
        int n= nums.size();

        
        while( start < end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;

        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() ==1) return ;
        int n= nums.size();

        if ( n<k){
            k = k%n;
        }

        swap( nums ,0,n-1);
        swap( nums,0 , k-1 );
        swap( nums,k ,n-1 );
        
        
    }
};

