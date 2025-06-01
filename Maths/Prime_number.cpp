// DSA with Vishal- Prime number


#include<iostream>
using namespace std;

string isPrime( int n){
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0){
            return "Non Prime";
        }
    }
    return "Prime";
}

int main() {
    int n ;
    cout << "enter a number: ";
    cin >> n;

    cout << n << " is " << isPrime(n) << endl;


    return 0;
}



/*
//LeetCode- 204 - https://leetcode.com/problems/count-primes/

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n+1,true);
        int count = 0;

        for(int i =2; i<n; i++) {
            if(isPrime[i]) {
                count++;

                for(int j=i*2; j<n; j=j+i) {
                    isPrime[j] = false;
                }
            }
        }
        return count;
    }
};

*/