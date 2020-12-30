#include<string>
#include<iostream>
using namespace std;
string find_palindrome_v1(string str, int left, int right){
    
    while((left >= 0 )&& (right <= (str.size()-1))&& (str[left] == str[right])){
        left--;
        right++;
    }
    cout << "substr : " << str.substr(left+1, right - left - 1);
    cout << "    left+1 : " << left + 1 << "  right: " << right << endl;   
    return str.substr(left + 1,right - left -1);
}

string find_palindrome_substring_v1(string str){
    string substring;
    string tempstring;
    int longest = 0;
    for(int i = 0; i < str.size() ; i++){
        tempstring = find_palindrome(str, i, i);
        //cout << "odd tempstring: " << tempstring << endl;
        if(substring.size() <= tempstring.size()){
            substring = tempstring;
            longest = tempstring.size();

        }
        tempstring = find_palindrome(str, i ,i+1);
        //cout << "pushu tempstring: " << tempstring << endl;
        if(substring.size() <= tempstring.size()){
            substring = tempstring;
            longest = tempstring.size();
        }
    }
    return substring;    
}

int main(int argv, char**argc){
    string teststring = "abbaaccccaabb";
    cout << find_palindrome_substring_v1(teststring) << endl;
    return 0;
}