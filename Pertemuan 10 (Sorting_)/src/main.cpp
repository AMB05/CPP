
#include<stdio.h>   
#include<stdlib.h>  
#include<cmath>     
#include<cstdlib>   
#include<ctime>
#include<conio.h>

#include<array>

#include<iostream>    //deklarasi library 
#include<iomanip>
using namespace std;
int main()
{
	int NumList[8] = {5,34,32,25,75,42,22,2};
	int Swap;
	cout<<"Data Sebelum disorting : " << endl;
	for (int h=0; h<8; h++){
		cout<<setw(3)<<NumList[h];
	}
	cout<<endl;
	cout<<endl;
	for (int i=0; i<7; i++){
	   for (int j=0; j<7; j++){
		if (NumList[j] > NumList[j+1]){
			Swap         = NumList[j];    //Proses Sorting
			NumList[j]   = NumList[j+1];  //Proses Sorting
			NumList[j+1] = Swap;          //Proses Sorting
			}
		}
	}
	cout<<"Data Setelag disorting : " << endl;
	for (int k=0; k<8; k++){
		cout<<setw(3)<<NumList[k];
	}
	cout<<endl;
}
