
#include<stdio.h>   
#include<stdlib.h>  
#include<cmath>     
#include<cstdlib>   
#include<ctime>

#include<iomanip>
#include<array>

#include<iostream>    //deklarasi library 
#include<conio.h>
using namespace std;

#define N_AKTIFITAS 5

struct aktifitas_t
{
	char aktif [50];
	char fitas [50];
}vitas[N_AKTIFITAS];

void printaktifitas(aktifitas_t vitas);

int main()
{
	char buffer [50];
	int n;
	for (int i = 0; i < N_AKTIFITAS; i++)
	{
		cout<<"Input Aktifitas anda : " << endl;
		cin.getline(vitas[n].aktif, 50);
		cout<<"Input Aktifitas anda : " << endl;
		cin.getline(buffer,50);
		vitas[n].fitas = atoi(buffer);
	}

	cout<<"\n Aktifitas Anda : \n";
	for (int j = 0; j < N_AKTIFITAS; j++)
	{
		printaktifitas(vitas[n]);
		return 0;
	}
	
}


// struct time
// {
// 	int jam;
// 	int min;
// };

// struct rencana
// {
// 	struct time awal;
// 	struct time akhir;
// 	int y;
// 	int z;
// };


// struct rencana kerja = {11,22,33,44,5,6};

// // funct(struct rencana oo);
// funct (struct rencana oo)
// {
// 	cout<<"Dalam fungsi (a)\n" <<
// 		   oo.awal.jam << " " <<
// 		   oo.awal.min << " " << 
// 		   oo.akhir.jam<< " " <<
// 		   oo.akhir.min<< " " <<
// 		   oo.y << " " << oo.z << endl;

// 	oo.awal.jam = 111;

// 	oo.y = 555;

// 	cout<<"Dalam fungsi (a)\n" <<
// 		oo.awal.jam << " " <<
// 		oo.awal.min << " " << 
// 		oo.akhir.jam<< " " <<
// 		oo.akhir.min<< " " <<
// 		oo.y << " " << oo.z << endl;	
// }


// int main() //fungsi utama
// {
// 	kerja.akhir.min=40;
// 	kerja.z=66;

// 	cout<<"Proses main sebelum ke fungsi \n" << 
// 		   kerja.awal.jam << " " << kerja.awal.min
// 		   << " " << kerja.akhir.jam << " " << kerja.akhir.min 
// 		   << " " << kerja.y << " " << kerja.z << endl;

// 	funct (kerja);

// 	cout<<"Proses main sesudah ke fungsi \n" << 
// 		   kerja.awal.jam << " " << kerja.awal.min
// 		   << " " << kerja.akhir.jam << " " << kerja.akhir.min 
// 		   << " " << kerja.y << " " << kerja.z << endl;	

// 	getch();
// }



