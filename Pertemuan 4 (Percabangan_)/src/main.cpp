#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main ()  //fungsi
{
    int uts, uas, tugas;
    double nilaiakhir;
    string nilaihuruf;

    cout << "Input Nilai UTS : ";
    cin  >> uts;
    cout << "Input Nilai UAS : ";
    cin  >> uas;
    cout << "Input Nilai TUGAS : ";
    cin  >> tugas;
    cout << endl;

    nilaiakhir = (uts+uas+tugas)/3;

    if (nilaiakhir >= 85)
    {
        nilaihuruf="A";
    }
    else if (nilaiakhir >= 70)
    {
        nilaihuruf="B";
    }
    else if (nilaiakhir >= 55)
    {
        nilaihuruf="C";
    }
    else if (nilaiakhir >= 40)
    {
        nilaihuruf="D";
    }
    else
    {
        nilaihuruf="E";
    }  

    cout << "Nilai Akhir Angka : " << nilaiakhir << endl;
    cout << "Nilai Akhir Huruf : " << nilaihuruf << endl;
}