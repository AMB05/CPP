
#include<stdio.h>   
#include<stdlib.h>  
#include<cmath>     
#include<cstdlib>   
#include<ctime>
#include<conio.h>
#include<iomanip>
#include<array>

#include<iostream>    //deklarasi library 

using namespace std;

void Tulis10Kali() //fungsi tanpa nilai balik
{
	for (int i = 0; i < 10; i++)
	{
		cout<<"Fungsi Tanpa Nilai Balik"<<endl;
	}
	
}

double FungsiBilangan() //fungsi dengan nilai balik
{
	return(3.14 * 2); //return = nilai balik
}

int main() //fungsi utama
{
	Tulis10Kali(); //memanggil fungsi
	cout<<endl;
	cout<<"Hasil Perhitungan 3.14 * 2 = " << 
			FungsiBilangan() <<endl; //memanggil fungsi
	cout<<endl;
}

