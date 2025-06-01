//DSA with Vishal- Armstrong number

//for Ex- 153 -- (1^3) + (5^3) + (3^3) =>  1 + 125 + 27  =>  153


#include<iostream>
using namespace std;



bool isArmstrong(int n){
    int copyN = n;
    int sumOfCubes = 0;

    while(n !=0){
        int dig = n % 10;
        sumOfCubes += (dig * dig * dig);

        n = n/10;
    }
    return sumOfCubes == copyN;
}



int main() {
    int n= 371;
   
    if(isArmstrong(n)){
        cout << n << " is an Armstrong Number\n";
    } else {
         cout << n << " is not an Armstrong Number\n";
    }
    

    return 0;
}

