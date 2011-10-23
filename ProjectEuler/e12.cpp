#include <iostream>
#include <math.h>
#include <list>

using namespace std;

void divisors( int );

list<int> divs;

int main(){
    bool notFound = true;
    int count = 1, tnum = 0;
    while(notFound){
        tnum += count;
        divisors(tnum);
        if( divs.size() >= 500 ){
            cout << tnum << endl;
            notFound = false;
        }
        count++;
    }

    return 0;
}

void divisors( int num ){
    // brute force divisors method.. so clever! 
    divs.clear();   
    for( int i = 1; i < sqrt( num ) + 1; i++ ){
        if( num % i == 0 ){
            divs.push_back( i );
            divs.push_back( num / i );
        }
    }
    divs.unique();
    return;
}
