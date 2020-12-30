#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int reverse(int x) {
   string sinteger  = to_string(x);
   std::reverse(sinteger.begin(), sinteger.end());
   cout << "sinteger : " << sinteger << endl;
   try
   {
       /* code */
       int minteger = std::stoi(sinteger);
       cout << "minteger : " << minteger << endl;
       if(x < 0){
           minteger  = (-minteger);
       }
       cout << " S is:" << x << " reverse x is:" << minteger << endl;
       return 0;
   }
   catch(const std::out_of_range& e)
   {
       cout << "out of range "<< endl;
       return 0;
   }

}
int main(int argv, char** argc){
    reverse(1534236464);
    return 0;
}
