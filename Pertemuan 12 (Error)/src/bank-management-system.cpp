//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>

using namespace std;

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class account
{
	int acno;
	char name[50];
	int deposit;
	char type;

	public:
		void create_account();	//function to get data from user
		void show_account() const;	//function to show data on screen
		void modify();	//function to add new data
		void dep(int);	//function to accept amount and add to balance amount
		void draw(int);	//function to accept amount and subtract from balance amount
		void report() const;	//function to show data in tabular format
		int retacno() const;	//function to return account number
		int retdeposit() const;	//function to return balance amount
		char rettype() const;	//function to return type of account
};         //class ends here

void account::create_account()
{
	cout<<endl;
	cout<<"Enter The account No. : " << endl;
	cin >>acno;
	cout<<"Enter The Name of The account Holder : " << endl;
	cin.ignore();
	cin.getline(name,50);
	cout<<"Enter Type of The account (C/S) : " << endl;
	cin >>type;
	type=toupper(type);
	cout<<"Enter The Initial amount(>=500 for Saving and >=1000 for current ) : " <<endl;
	cin >>deposit;
	cout<<endl;
	cout<<"Account Created.." << endl;
}

void account::show_account() const
{
	cout<< endl;
	cout<<"Account No. : " << acno << endl;
	cout<<"Account Holder Name : " << name << endl;
	cout<<"Type of Account : " << type << endl;
	cout<<"Balance amount : " << deposit << endl;
}


void account::modify()
{
	cout<< endl;
	cout<<"Account No. : " << acno <<endl;
	cout<<"Modify Account Holder Name : " <<endl;
	cin.ignore();
	cin.getline(name,50);
	cout<<"Modify Type of Account : " << endl;
	cin >>type;
	type=toupper(type);
	cout<<"Modify Balance amount : " <<endl;
	cin >>deposit;
}

	
void account::dep(int x)
{
	deposit+=x;
}
	
void account::draw(int x)
{
	deposit-=x;
}
	
void account::report() const
{
	cout<< acno << setw(10) << " " << name << setw(10) << " " << type << setw(6) << deposit <<endl;
}
	
int account::retacno() const
{
	return acno;
}

int account::retdeposit() const
{
	return deposit;
}

char account::rettype() const
{
	return type;
}


//***************************************************************
//    	function declaration
//****************************************************************
void write_account();			 //function to write record in binary file
void display_sp(int);			 //function to display account details given by user
void modify_account(int);		 //function to modify record of file
void delete_account(int);		 //function to delete record of file
void display_all();				 //function to display all account details
void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account
void intro();					 //introductory screen function

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

int main()
{
	char ch;
	int num;
	intro();
	do
	{
		system("cls");
		cout<< endl;
		cout<<"MAIN MENU" << endl;
		cout<<"\t01. NEW ACCOUNT" << endl;
		cout<<"\t02. DEPOSIT AMOUNT" << endl;
		cout<<"\t03. WITHDRAW AMOUNT" << endl;
		cout<<"\t04. BALANCE ENQUIRY" << endl;
		cout<<"\t05. ALL ACCOUNT HOLDER LIST" << endl;
		cout<<"\t06. CLOSE AN ACCOUNT" << endl;
		cout<<"\t07. MODIFY AN ACCOUNT" << endl;
		cout<<"\t08. EXIT" << endl;
		cout<<"\tSelect Your Option (1-8) " << endl;
		cin >>ch;

		system("cls");
		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			cout<< endl;
			cout<<"\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			cout<< endl;
			cout<<"\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4': 
			cout<< endl;
			cout<<"\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			cout<< endl;
			display_all();
			break;
		case '6':
			cout<< endl;	
			cout<<"\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		case '7':
			cout<< endl;
			cout<<"\tEnter The account No. : "; cin>>num;
			modify_account(num);
			break;
		case '8':
		 	cout<< endl;
			cout<<"\tThanks for using bank managemnt system";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
    }
	while(ch!='8');
	return 0;
}


//***************************************************************
//    	function to write in file
//****************************************************************

void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}

//***************************************************************
//    	function to read specific record from file
//****************************************************************

void display_sp(int n)
{
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key..." << endl;
		return;
	}
	cout<< endl;
	cout<<"BALANCE DETAILS" << endl;
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=true;
		}
	}
    inFile.close();
	if(flag==false)
	{
		cout<< endl;
		cout<<"Account number does not exist" << endl;
	}
		
}


//***************************************************************
//    	function to modify record of file
//****************************************************************

void modify_account(int n)
{
	bool found=false;
	account ac;
	fstream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<< endl;
			cout<<"Enter The New Details of account" << endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
		    File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<< endl;
			cout<< endl;
		    cout<<"\t Record Updated" << endl;
		    found=true;
		  }
	}
	File.close();
	if(found==false)
	{
		cout<< endl;
		cout<<"Record Not Found " <<endl;
	}
		
}

//***************************************************************
//    	function to delete record of file
//****************************************************************


void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
    inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<< endl;
	cout<< endl;
	cout<<"\tRecord Deleted ..";
}

//***************************************************************
//    	function to display all accounts deposit list
//****************************************************************

void display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST" << endl;
	cout<<"====================================================" << endl;
	cout<<"A/c no.      NAME           Type  Balance " << endl;
	cout<<"====================================================" << endl;
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}

//***************************************************************
//    	function to deposit and withdraw amounts
//****************************************************************

void deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	account ac;
	fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<< endl;
				cout<<"\tTO DEPOSITE AMOUNT " << endl;
				cout<<"Enter The amount to be deposited" << endl;
				cin>>amt;
				ac.dep(amt);
			}
		    if(option==2)
			{
				cout<< endl;
				cout<<"\tTO WITHDRAW AMOUNT " << endl;
				cout<<"Enter The amount to be withdraw" << endl;
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
				{
					cout<<"Insufficience balance" << endl;
				}
				else
				{
					ac.draw(amt);
				}
			}
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<< endl;
			cout<< endl;
			cout<<"\t Record Updated";
			found=true;
	    }
    }
    File.close();
	if(found==false)
	{
		cout<< endl;
		cout<<"Record Not Found " << endl;
	}
		
}


//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{
	cout<<endl;
	cout<<"BANK MANAGEMENT SYSTEM" << endl;
	cout<<"----------------------" << endl;
	cin.get();
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************