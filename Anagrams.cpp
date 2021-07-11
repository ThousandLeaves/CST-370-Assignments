/*
* Title: hw1_2
* Abstract: Determines if 2 strings are an anagram
* ID: 6081
* Name: Christopher Boyd
* Date: 11-02-2020
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main() {
    
    bool isSame = true;
    string string1, string2;
    map<char, int> stringsFound;
    
    cin >> string1;
    cin >> string2;
    
    // If string length not same, avoid next section
    if(string1.length() != string2.length()) {
        isSame = false;
    } else {
        // String length same, analyze strings to determine if anagram
        sort(string1.begin(), string1.end());
        sort(string2.begin(), string2.end());
        
        for (int i = 0; i < string1.length(); i++) {
            if(string1[i] != string2[i]) {
                isSame = false;
                break;
            }
            else {
                if(!stringsFound.count(string1[i])) {
                    stringsFound[string1[i]] = 1;
                } else {
                    stringsFound[string1[i]]++;
                }
            }
        }   
    }
    
    if (isSame) {
        cout << "ANAGRAM" << endl;
        for(auto const& vals : stringsFound) {
            cout << vals.first << ":" << vals.second << endl;
        }
        // Some map output functions here...
    } else {
        cout << "NO ANAGRAM" << endl;
    }
    
    return 0;
}
