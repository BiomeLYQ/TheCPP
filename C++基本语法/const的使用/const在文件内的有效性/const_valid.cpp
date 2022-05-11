#include<iostream>
using namespace std;

int main(){
    const int only_valid = 42;      //valid in current file only
    extern const int all_valid;     //declare and use
    
    //notice that the "all_vaild" was defined at const_valid.h
}
