#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main ()  //fungsi
{
    int n = 5;
    for(int i = 1; i <= n; i++)
    {
		for(int j = n; j >= i; j--)
        {
			cout << "*" ;
		}
		cout << endl;
	}
}