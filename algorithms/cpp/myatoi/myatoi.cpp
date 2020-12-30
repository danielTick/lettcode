#include<string>
#include<iostream>
using namespace std;
int myatoi(string s){
    unsigned long long sum;
    string non_empty;
    bool negative = false;
    if(s.empty()){
        cout << "s is empty()" << endl;
        return 0;
    }
    int index = s.find_first_not_of(" ");
    cout << "index :" << index << endl;
    for(int i = index; i < s.size() ; i++){
        if((i != index)&& (s[i] == '-')){
            cout << "-" << s[i] << endl;
            break;
        }else if((i == index) && (s[i] == '-')){
            cout << i << " : " << s[i] << endl;
            negative = true;
            continue;
        }else if((i == index) && (s[i] == '+')){
            negative = false;
            continue;
        }
        if( (s[i] >= 48) && (s[i] <= 57)){
            //cout << s[i] << endl;
            if((negative == true) && ((sum * 10 + (s[i] - 48)) > 0x7FFFFFFF)){
                cout <<"```````````" << (sum * 10 + s[i] -48 > 0x7FFFFFFF) << endl ;
                return INT32_MIN;
            }
            if((negative == false) && ((sum * 10 + (s[i] -48)) >= INT32_MAX)){
                //cout << "sum " << sum * 10 + s[i] -48 << endl;
                return INT32_MAX;
            }
            sum = sum * 10 + (s[i] - 48);
        }else{
            break;
        }
    }

    if(negative == true){
        sum = (-sum);
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    cout << myatoi("-2147483647") << endl;
    /* code */
    return 0;
}
