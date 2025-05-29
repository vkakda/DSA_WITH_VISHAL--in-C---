//DSA with Vishal - Permutation in string

// LeetCode - 567 - link- https://leetcode.com/problems/permutation-in-string/

//code 👇

#include<iostream>
#include<string>
using namespace std; 

bool isFreqSame(int freq1[], int freq2[]) {
    for(int i = 0; i<26; i++){
        if (freq1[i] != freq2[i]){
            return false;
        }
    }
    return true;
}

bool checkInclusion( string s1 , string s2) {
    int freq[26] = {0};

    for(int i = 0; i<s1.length(); i++){
        freq[s1[i] - 'a']++;
    }

    int windSize = s1.length();

    for(int i=0; i<s2.length(); i++){
        int windIdx = 0, idx =i;
        int windFreq[26] = {0} ;

        while(windIdx < windSize && idx < s2.length()) {
            windFreq[s2[idx] - 'a']++;
            windIdx++; idx++;
        }

        if(isFreqSame(freq, windFreq)){
            return true;
        }
    }
    return false;
    
}


int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";

    if (checkInclusion(s1, s2)) {
        cout << "Permutation exists in s2." << endl;
    } else {
        cout << "Permutation does not exist in s2." << endl;
    }

    return 0;
}
