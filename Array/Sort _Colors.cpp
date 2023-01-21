#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& v) {
        int l = 0, m = 0, h = v.size()-1;
        while(l<=m and m<=h) {
            if(v[m]==0) {
                swap(v[l],v[m]);
                m++;
                l++;
            }
            else if(v[m]==1) {
                m++;
            }
            else if(v[m]==2) {
                swap(v[m],v[h]);
                h--;
            }
        }
    }
};

int main(){
    
    return 0;
}
