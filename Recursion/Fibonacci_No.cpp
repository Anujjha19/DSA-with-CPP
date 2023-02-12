#include<bits/stdc++.h>
using namespace std;

int fibonacci( int n){
    if( n <= 1) return n;

    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
cout << "Enter N : " ;
int n;
cin>>n;

cout << "Fibonacci of a  N : " << fibonacci(n) << endl ;

    return 0;

}
//TC - O ( 2 * n)