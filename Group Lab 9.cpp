

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int C[101][101];// array initialized globally to be accessible in searchValidEntries function

/*
that takes a parameter N, indicating how random pairs of indices < j,i> times 
it should generate,to update the entries the array A[][]. Note that undefined entries are assigned to zero
*/ 
void populateArray(int n){ //variable n will take the number of indices to be generated
    int A[101][101];
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            A[i][j] = rand()%5;
            cout <<" "<<A[i][j];
            
        }
        cout<<endl;
    }
    cout<<endl;
    int p = 0;; // variable p to count 2000 indices which are generated randomly
    
    cout<<"Updating the entries the array A[i][j]"<<endl;
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            int r=rand()%5;
            if(A[i][j] == 0 && p<=n && r==0){// checking for defined values
                A[i][j] = 1;
            }
            else if(A[i][j] != 0 && p<=n && r!=0){ //checking for undefined values in A[i][j]
                A[i][j] ++;
                p++;
            }
            cout<<" "<< A[i][j];
            C[i][j]=A[i][j];
            
        }
        cout<<endl;
    
    }
    cout<<"The number of indices generated randomly are: "<<p-1;
}

//function to search valid and undefined Entries in A[][]
void searchValidEntries(int XL, int YL, int XH, int YH){
    int countdefined=0;
    int countundefined=0;
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            if(i>=XL && i<=XH && j>=YL && j<=YH){
               cout<<" "<<C[i][j];
               if(C[i][j]>0){
                    countdefined++; 
               }
                if(C[i][j]==0){
                    countundefined++; 
               }
               
               
            }
        }
        
        cout<<endl;
    }
    
    //nested loop which display the indices i and j with its corresponding values within the bounding boxes
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            if(i>=XL && i<=XH && j>=YL && j<=YH){
                cout<<" "<<"A["<<i<<"]["<<j<<"] ="<<C[i][j]<<",";
            }
        }
        cout<<endl;
    }
    
    //counts of the entries in A[][] that lie withing the bounding boxes
    cout<<"The number of defined entries with positive values are: "<<countdefined<<endl;
    cout<<"The number of undefined entries: "<<countundefined;
    
    
}

int main()
{
    populateArray(7); 
    cout<<endl<<"The bounding boxes are";
    searchValidEntries(2, 5, 10, 10);
    searchValidEntries(3, 3, 7, 7);
    searchValidEntries(7, 8, 9, 10);
    searchValidEntries(1, 3, 5, 8);
    searchValidEntries(2, 2, 7,9);
    
}