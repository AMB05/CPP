#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main () //fungsi utama
{
    int panjang; //int = tipe data, panjang = variabel
    int lebar, tinggi;
    float volume;
    string nama;
    char jenis_kelamin;

    cout << "Program Menghitung Luas" << endl;
    cout << endl;
    cout << "Input Panjang" << endl;
    cin >> panjang;
    cout << endl;
    cout << "Input Lebar" << endl;
    cin >> lebar;
    cout << endl;
    cout << "Input Tinggi" << endl;
    cin >> tinggi;
    cout << endl;

    volume = panjang * lebar * tinggi;

    cout << "Hasil = " << endl;
    cout << volume;

}