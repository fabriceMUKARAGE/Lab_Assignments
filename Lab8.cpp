
#include <iostream>
using namespace std;

// global varible and array which will be accessible in every every function
int C[5000];
int p;


//LiearIndx function which take 2-dimensional array 
int  LiearIndx(int n)
{
    int A[n][n];
    int B[n*(n+1)/2]; // 1-dimensional array to store the lower-trangular elements 
    
    
    // for loop to fill the elements in array A[][] randomly
    for(int i = 0; i < n; ++i)
    {
        for(int j =0; j <n; ++j)
        {
            A[i][j]= rand()%1000+1;  
            
        }
    }
    int a=-1;
    // nested for loop to check for only lower-trangular elements
    for(int i =0; i <n; ++i)
    {
        for(int j = 0; j <= i; ++j)
        { 
            a++; // variable a which will keep incrementing the size of array B
            cout<<" "<<A[i][j];  // Displaying out the lower-trangular elements in 1-dimensional array 
            B[a]=A[i][j]; //  

        }
        cout<<endl;
    }
    cout<<" lower-trangular elements in 1-dimensional array:"<<endl;
    for(int k = 0; k <n*(n+1)/2; ++k)
    {
        cout<<" "<<B[k];  // displying out the lower-trangular elements in 1-dimensional array
       
        
        //the global variable and array which access the information from the function LiearIndx()
        C[k]=B[k]; 
        p=k;
        
    }
    cout<<endl;

    
}


// InverseIdx() function to which reverse 1-dimensional array of corresponding elements in A[][]
int  InverseIdx(){
        for(int r=p;r>=0;r--){
            cout<<" "<<C[r];
        }
    
    
}

//main function to access LiearIndx() , and InverseIdx()
int main(){
    
    /* 
    calling the LiearIndx() , and InverseIdx() function.
    for example: A[8][8], A[32][32], or A[128][128] can be displayed as below
    
    */
    
    // for A[8][8]
    
    LiearIndx(8);
    cout<<endl;
    cout<<" The reverse will be: "<<endl;
    cout<<endl;
    InverseIdx();
    
    

 
}

