#include<conio.h>
#include<iostream>
#include<string>
using namespace std;

/*Mini Project - ATM
   -> Check Balance
   -> Cash Withdraw
   -> User Details
   -> U[date Mobile No.
*/


class atm{                                                                                                        // class atm
	private:                                                                                                     //  private member variables
		long int account_No;
		string name;
		int PIN;
		double balance;
		string mobile_No;
		
	public:
		//setData function is setting the data into the private member variables
        void setData(long int account_No_a,string name_a,int PIN_a,double balance_a,string mobile_No_a)
        {
        	account_No=account_No_a;     
        	PIN=PIN_a;
        	balance=balance_a;
        	mobile_No=mobile_No_a;
		}
		
		//getAcccountNo function is returning the user's account no
		long int getAccountNo()
		{
			return account_No;
		}
		
		//getName function is returning the user's Name
		string getName()
		{
			return name;
		}
		
		//getPIN function is returning the user's PIN
		int getPIN()
		{
			return PIN;
		}
		
		//getBalance is returning the user's Bank Balance
		double getBalance()
		{
			return balance;
		}
		
		//getMobileNo is returnning the user's Mobile NO.
		string getMobileNo()
		{
			return mobile_No;
		}
		
		//setMobile function is updating the user mobile no
		void setMobile(string mob_prev,string mob_new)
		{
			if(mob_prev == mobile_No)
			{                                                                                                      //checking mobile no is correct
				mobile_No = mob_new;                                           									   // if correct update mobile no
				cout << endl << "!!!!!!!!Succesfully Updated Mobile no.!!!!!!!!";
				_getch();
			}
			
			else{
				cout << endl << "!!!!!!!!Incorrect  !!! Old Mobile no!!!!!!!!";
				_getch();
			}
		}
		
		//cashWithdraw function is used to withdraw money from ATM
		void cashWithDraw(int amount_a)
		{
			if(amount_a >0 && amount_a < balance)                                                                   //amount balance is checking 
			{
				balance -= amount_a;                                                                                //if correct update balance
				cout << endl << "Please Collect Your Cash.";
				cout << endl << "Available Balance:" << balance;
				cout << endl << "Thank You";
				cout << endl << "Visit Again";
				_getch();
			}
			
			else
			{
				cout << endl << "!!!!!!!!Invalid Input or Insuffucient Balance!!!!!!!!";
				_getch();
			}
		}      
};

///////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	int choice = 0 , enterPIN;
	long int enterAccountNo;
	
	system("cls");
	
	// created User ( object )
	atm user1;
	// Set User Details ( into object )
	user1.setData(1234567,"Tim",1111,45000.90,"8824553464");
	
	
	do
	{
		system("cls");
		
		cout << endl << "*****Welcome to ATM*****" << endl;
		cout << endl << "Enter Your Account No: ";
		cin  >> enterAccountNo;
		
		cout << endl << "Enter PIN:";
		cin  >> enterPIN;		
		
		
		cout << "******************************************************************************************************" << endl;
		cout << "******************************************************************************************************" << endl;
		
		// check whether enter values matches with user details 
		if( (enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN()) )
		{
			do
			{
				int amount = 0;
				string oldMobileNo , newMobileNo;
				
				system("cls");
				//user interface
				cout << endl << "************************Welcome to ATM*********************" << endl;
				cout << endl << "Select Options";
				cout << endl << "1: Check Balance";
				cout << endl << "2: Cash Withdraw";
				cout << endl << "3: Show User Details";
				cout << endl << "4: Update Mobile no.";
				cout << endl << "5: Exit" << endl;
				cout << endl;
				
				cout << "Enter Choice:";
				cin  >> choice;                                   //taking user choice
				
				switch(choice)
				{
					case 1:
						cout << endl << "Your Bank Balance is:" << user1.getBalance();
						
						_getch();
						break;
						
						
						
					case 2:
						cout << endl << "Enter the amount:";
						cin  >> amount;
						user1.cashWithDraw(amount);
						
						break;
						
						
					case 3:
						cout << endl << "************User Details are :-************** ";
						cout << endl << "-> Account no:" << user1.getAccountNo();
						cout << endl << "-> Name:      " << user1.getName();
						cout << endl << "-> Balance:   " << user1.getBalance();
						cout << endl << "-> MOBILE no.:" << user1.getMobileNo();
						
						_getch();
						break;
					
					
					case 4:
						cout << endl << "Enter Old Mobile No.: ";
						cin  >> oldMobileNo;
						
						cout << endl << "Enter New Mobile No.: ";
						cin  >> newMobileNo;
						
						user1.setMobile(oldMobileNo,newMobileNo);
						
						break;
						
					case 5:
						exit(0);
						
					
					default:
						cout << endl << "***********************Enter Valid Data!!!***********************";
				}
	     	}while(1);
	    }
	}while(1);
	
	return 0;
}
