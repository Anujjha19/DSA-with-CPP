#include <bits/stdc++.h>
using namespace std;

vector<int> NSE(vector<int>& v, int n) {
    vector<int> ans(n);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && v[i] <= v[s.top()]) {
            s.pop();
        }
        ans[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    return ans;
}

vector<int> PSE(vector<int>& v, int n) {
    vector<int> ans(n);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && v[i] < v[s.top()]) {
            s.pop();
        }
        ans[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    return ans;
}

int getMaxArea(vector<int>& heights, int n) {
    vector<int> next = NSE(heights, n);
    vector<int> prev = PSE(heights, n);
    int area = INT_MIN;

    for (int i = 0; i < n; i++) {
        int l = heights[i];
        int bw = next[i] - prev[i] + 1;
        int newArea = l * bw;
        area = max(area, newArea);
    }

    return area;
}

int main() {
    vector<int> hist = {2, 1, 5, 6, 2, 3};
    int n = hist.size();
    int maxArea = getMaxArea(hist, n);

    cout << "Histogram: ";
    for (int i : hist) {
        cout << i << " ";
    }

    cout << "\nMaximum area: " << maxArea << endl;

    return 0;
}


/* class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n= heights.size();
        int leftS[n] , rightS[n];
        stack<int>s;
                
Left Right Smaller Array
        for( int i=0 ;i<n; i++){
            while( !s.empty() && heights[s.top()] >= heights[i] ){
                s.pop();
            }
            if( s.empty()) leftS[i] =0;
            else leftS[i] = s.top() +1;
            s.push(i);
        }

To re used 
        while( !s.empty()) s.pop();


Right Smaller Array
        for( int i=n-1 ;i>=0; i--){
            while( !s.empty() && heights[s.top()] >= heights[i] ){
                s.pop();
            }
            if( s.empty()) rightS[i] =n-1;
            else rightS[i] = s.top() -1;
            s.push(i);
        }

        int maxA=0;
        for( int i=0 ; i< n; i++){
            maxA= max( maxA , heights[i] * ( rightS[i] - leftS[i] + 1 ));
        }
        
        return maxA;
    }
}; */


/*
Brute Force Approach to find largest rectangle area in Histogram
Time Complexity: O(N*N ) 
Space Complexity: O(1)


int largestarea(int arr[], int n)
{
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int minHeight = INT_MAX;
        for (int j = i; j < n; j++)
        {
            minHeight = min(minHeight, arr[j]);
            maxArea = max(maxArea, minHeight * (j - i + 1));
        }
    }
    return maxArea;
} */