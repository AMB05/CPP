
#include<stdio.h>   
#include<stdlib.h>  
#include<cmath>     
#include<cstdlib>   
#include<ctime>
#include<array>
#include<iomanip>

#include<iostream>    //deklarasi library 
#include<conio.h>
#include <windows.h>
#define MAX 100
using namespace std;

int nomer[MAX];
int head=-1;
int tail=-1;

bool IsEmpty() 
{ 
   if(tail == -1)
   {
       return true;
   }
   else
   {
       return false;
   }
}
bool IsFull() 
{ 
   if(tail == MAX-1)
   {
       return true;
   }
   else
   {
       return false;
   }
}

void AntrianMasuk(int no)
{
    if (IsEmpty())
    {
        head=tail=0;
    }
    else 
    {
        tail++;
    }
    nomer[tail]=no;
}

void AntrianKeluar()
{
    if(IsEmpty())
    {
        cout<<"Antrian sudah kosong ! ";
        getch();
    }
    else 
    {
        for(int a=head;a<tail;a++)
        {
            nomer[a]=nomer[a+1];
        }
        tail--;
        if(tail == -1)
        {
            head = -1;
        }
    }
}

void Clear()
{
     head=tail=-1;
}

void View()
{
     if(IsEmpty())
     {
         cout<<"Antrian kosong ! ";

     }
     else 
     {
         system("cls");
         for(int a=head;a<=tail;a++)
         {
              cout << "==============================="
                   << "\n >> No. Antrian : [" << nomer[a] << "]"
                   << "\n==============================="<< endl;
         }
     }
}

int main()
{    
    int choose, p=1, urut;
    do
    {
        system("cls");
        cout << "\n\n=PROGRAM ANTRIAN PEMBAYARAN BPJS ="
             << "\n===================================="
             << "\n|1. Ambil Nomor Antrian            |"
             << "\n|2. Memanggil Nomor Antrian        |"
             << "\n|3. Menampilkan Daftar Antrian     |"
             << "\n|4. Hapus Seluruh Antrian          |"
             << "\n|5. Exit                           |"
             << "\n===================================";
        cout << "\nChoose ! "; 
        cin  >> choose;
        cout << "\n\n";
        if(choose == 1)
        {
            if(IsFull()) 
            {
                cout<<"Nomor Antrian Sudah Penuh, Silahkan Menunggu Beberapa Saat Lagi ";
            }
            else
            {
                urut=p;
                AntrianMasuk(urut);
                cout << "---------------------------------" << endl;
                cout << "|          NO. ANTRIAN          |" << endl;
                cout << "|               " << p << "               |" << endl;
                cout << "---------------------------------" << endl;
                cout << "|       Silahkan Mengantri      |" << endl;
                cout << "|       Menunggu " << tail << " Antrian      |" << endl;
                cout << "---------------------------------" << endl;
                p++;
            }
        }
        else if(choose == 2)
        {
            cout << "=================================" << endl;
            cout << "No. Antrian : [" << nomer[head] << "]";
            cout << "\n=================================" << endl;
            AntrianKeluar();
            cout << "Silahkan Dipanggil !" << endl;
        }
        else if(choose == 3)
        {
            View();
        }
        else if(choose == 4)
        {
            Clear();
            cout<<"Antrian dikosongkan ! ";
        }
        else if(choose == 5)
        {
            
        }
        else
        {
            cout << "Masukan anda salah ! \n"<< endl;
        }
        getch();
    }while(choose!=5);
}

