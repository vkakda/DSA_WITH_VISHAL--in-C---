//DSA with Vishal- Digits in a number

#include<iostream>
using namespace std;


// print all digits
void printDigits( int n) {   //TC- O(log10(n))
    while(n != 0){
        int digit = n% 10;
        cout << digit << endl;

        n = n /10;
    }
}

//count all digits
void countDigits( int n) {
    int count = 0;
    while(n != 0){
        int digit = n% 10;
        count++;

        n = n /10;
    }
    cout << count << endl;
}

//sum of Digits
void sumOfDigits( int n) {
    int sum = 0;
    while(n != 0){
        int digit = n% 10;
        sum += digit;

        n = n /10;
    }
    cout << sum << endl;
}




int main() {
    int n= 3568 ;
   
    printDigits(n);

    cout << "Counts of digits: ";
    countDigits(n);

    cout <<"Sum: ";
    sumOfDigits(n);

    return 0;
}

