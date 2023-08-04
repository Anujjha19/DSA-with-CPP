#include <iostream>
using namespace std;
int countDistinctWays(int nStairs) {
    if (nStairs < 0)
        return 0;
    if (nStairs == 0)
        return 1;

    int ans = countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);

    return ans;
}

int main() {
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;

    int distinctWays = countDistinctWays(n);
    cout << "Number of distinct ways to climb " << n << " stairs: " << distinctWays << endl;

    return 0;
}
