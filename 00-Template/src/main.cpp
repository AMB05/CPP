#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main ()  //fungsi
{
    double tc,tf,tr;

    cout<<"Input Suhu Celcius : " << endl;
    cin >> tc;

    tf = ((9/5)*tc)+32;
    tr = ((4/5)*tc);

    cout<< endl;
    cout<<"Hasil Konversi " << endl;
    cout<<"Derajat Celcius      : " << tc << endl;
    cout<<"Derajat Fahrenhet    : " << tf << endl;
    cout<<"Derajat Reamur       : " << tr << endl;
}

    // int panjang; // int = tipe data, panjang = variabel
    // string a,b,c; // string = tipe data, a,b,c = variabel
    // char saya; // char = tipe data, saya = variabel

    // int lebar = 10; // int = tipe data, panjang = variabel, 10 = nilai dari variabel
    // string me = "arriva";
    // string you = "nama kamu";
    // int hasil = 2;
    // float angka = 0.5;

    // cout << "hello world" << endl;
    // cout << "nama saya adalah" << endl;

    // return 0;