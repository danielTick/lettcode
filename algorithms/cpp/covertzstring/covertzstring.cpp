#include<string>
#include<iostream>
#include<array>
#include<vector>
using namespace std;
string covert(string s, int mrows){
    string tempstring;
    vector<vector<char>> marray(mrows);
    bool forward = true;
    int slen = s.size();
    int tcolumn = 0, trow = 0;
    for(int i = 0; i <= s.size() -1 ; i++){
        if(mrows == 1){ 
            tcolumn = 0;
        }else{
            tcolumn = ( i - trow )/( mrows - 1);
        }
        //cout << i  <<",";
        //cout << trow <<","<<tcolumn << endl;
        marray[trow].push_back(s[i]);
        //cout << marray[trow][tcolumn] << endl;
        //marray[trow].push_back(s[i]);
        //marray[trow][tcolumn] = s[i];
        if(forward == true){
            if(trow < ( mrows -1))
                trow ++ ;
            if(trow == ( mrows - 1)){
                forward = false;
            }
        }else{
            if(trow > 0)
                trow --;
            if(trow == 0){
                forward = true;
            }
        }
    }
    for(int i = 0; i < mrows ; i++){
        for(int j = 0; j < marray[i].size(); j++)
            tempstring.push_back(marray[i][j]);
    }

    return tempstring;

}

int main(int argc, char const *argv[])
{
    /* code */
    cout << covert("AB", 1) << endl; 
    return 0;
}
