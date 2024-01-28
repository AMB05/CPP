#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main ()
{
	void *P;

	int X;
	long Y;
	double Z;

	P=&X;
	X=10;

	cout<<"Nilai X  : " << X << endl;
	cout<<"Nilai P  : " << P << endl;
	cout<<"Nilai &X : " << &X << endl;	

	cout<<endl;

	P=&Y;
	Y=2000;

	cout<<"Nilai Y  : " << Y << endl;
	cout<<"Nilai P  : " << P << endl;
	cout<<"Nilai &Y : " << &Y << endl;	

	cout<<endl;

	P=&Z;
	Z=21.0378;

	cout<<"Nilai Z  : " << Z << endl;
	cout<<"Nilai P  : " << P << endl;
	cout<<"Nilai &Z : " << &Z << endl;	

	return 0;
}

//pointer nilai dan alamat
// int main ()  //fungsi
// {
// 	long *P;
// 	long X;

// 	P=&X;

// 	X=10;

// 	cout<<"Nilai X  : " << X << endl;
// 	cout<<"Nilai *P : " << *P << endl;
// 	cout<<"Nilai P  : " << P << endl;
// 	cout<<"Nilai &X : " << &P << endl;

// 	cout<<endl;
// 	*P = 200;

// 	cout<<"Nilai X  : " << X << endl;
// 	cout<<"Nilai *P : " << *P << endl;
// 	cout<<"Nilai P  : " << P << endl;
// 	cout<<"Nilai &X : " << &P << endl;

// 	return 0;
// }
