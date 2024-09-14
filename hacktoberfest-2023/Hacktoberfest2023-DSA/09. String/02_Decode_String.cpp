#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string decodeString(string s) {
    string result = "";

    // Traversing the encoded string 
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ']') {
            result.push_back(s[i]);
        } else {
            // Extract str from result
            string str = "";
            while (!result.empty() && result.back() != '[') {
                str.push_back(result.back());
                result.pop_back();
            }
            // Reverse the temp
            reverse(str.begin(), str.end());

            // Remove last char from result which is '['
            result.pop_back();

            // Extract num from result
            string num = "";

            while (!result.empty() && (result.back() >= '0' && result.back() <= '9')) {
                num.push_back(result.back());
                result.pop_back();
            }

            // Reverse the num string 
            reverse(num.begin(), num.end());

            // Convert string to integer
            int int_num = stoi(num);

            // Insert str in result int_num times
            while (int_num--) {
                result += str;
            }
        }
    }
    return result;
}

int main() {

    // string str;
    // cout<<"Enter the encoded string : ";
    // cin>>str;

    // string str = "2[ba]";    // Output : baba    
    string str = "3[b2[ca]]";   // Output : bcacabcacabcaca

    cout << decodeString(str);

    return 0;
}
