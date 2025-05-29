// DSA with Vishal - String Compression

//Leetcode -  443 - https://leetcode.com/problems/string-compression/

//code 👇

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int compress(vector<char>& chars){
    int n =  chars.size();
    int idx = 0;
    for(int i = 0; i<n; i++){
        int ch = chars[i];
        int count = 0;
        while(i<n && chars[i] == ch){
            count++;
            i++;
        }
        if(count == 1){
          chars[idx++] = ch;
        } else {
            chars[idx++] = ch;
            string str = to_string(count);
            for(char dig: str){
                chars[idx++] = dig;
            }
        }
        i--;
        }   
    chars.resize(idx);
    return idx;

}



int main() {
    vector<char> chars = {'a','a','b','b','c','c','c'};
    
    int result = compress(chars);
    cout << "Compressed length: " << result << endl; 
    
    return 0;
}




