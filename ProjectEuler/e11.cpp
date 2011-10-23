// Project Euler #11

#include <iostream>
#include <fstream>
#include <list>

using namespace std;

void getSums( int , int );


// Array to store the numbers
int nums[20][20];
// List to store the possible sums
list<int> sums;

int main(){

    // open the file
    ifstream fin("e11nums.txt");

    int digit;

    // Read in the numbers
    for( int i = 0; i < 20; i++ ){
        for( int j = 0; j < 20; j++ ){
            fin >> digit;
            nums[i][j] = digit;
        }
    }    
 
    // find sums
    for( int i = 0; i < 20; i++ ){
        for( int j = 0; j < 20; j++ ){
            getSums( i , j );
        }
    }


    sums.sort();
    cout << sums.back() << endl;

    return 0;
}

void getSums( int i, int j){
    // This function adds the possible sums from an index to a list
   
    int sum = 0;

    // Add right sum
    if( j + 4 < 20 ){
        sum = nums[i][j] * nums[i][j + 1] * nums[i][j + 2] * nums[i][j + 3];
        sums.push_back( sum );

        // Add Diag 1 sum
        if( i + 4 < 20 ){
            sum = 1;
            for( int k = 0; k < 4; k++ ){
                sum *= nums[i + k][j + k];
            }
            sums.push_back( sum );
        }
        // diag 3 
        if( i - 4 >= 0 ){
            sum = 1;
            for( int k = 0; k < 4; k++ ){
                sum *= nums[i - k][j + k];
            }
            sums.push_back( sum );
        }
    }

    // Add left sum
    if( j - 4 >= 0 ){
        sum = nums[i][j] * nums[i][j - 1] * nums[i][j - 2] * nums[i][j - 3];
        sums.push_back( sum );
        
        // diag 2
        if( i + 4 < 20 ){
            sum = 1;
            for( int k = 0; k < 4; k++ ){
                sum *= nums[i + k][j - k];
            }
            sums.push_back( sum );
        }

        // diag 4
	if( i - 4 >= 0 ){
	    sum = 1;
	    for( int k = 0; k < 4; k++ ){
	        sum *= nums[i - k][j - k];
	    }
	    sums.push_back( sum );
        }
    }

    // Add up sum
    if( i - 4 >= 0 ){
       sum = nums[i][j] * nums[i -1][j] * nums[i - 2][j] * nums[i - 3][j];
       sums.push_back( sum );
    }
    // Add down sum
    if( i + 4 < 20 ){
        sum = nums[i][j] * nums[i + 1][j] * nums[i + 2][j] * nums[i + 3][j];
        sums.push_back( sum );
    }
  
    return;
}         
