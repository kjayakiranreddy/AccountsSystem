/*
Project: Banking System Simulation using C++.
 Resources Name(s): Kotha Murali(3208),Konkala Jayakiran Reddy(3198), Pathakota Sindhura(3197).
Features :
			Creating an account
			Withdraw
			Deposit
			Show Account Details
			Average Of all Accounts
			Display All Acounts
			Balance Display
			Deletion of Account
			Sorting of Account numbers on the different basis.
			Exiting the Application
*/
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <iomanip>
using namespace std;

double minimum, maximum;		//Account number starting and end range
int accountCount = 0;		   //total number of accounts
const int SIZE = 100;		  //Maximum Possible number of accounts in the range

//Basic Info Of A Bank Account

struct details {
	int account_number;
	double balance;
	string last_name;
	string first_name;

};

// Function Declarations

void accountCreation(details Account[SIZE]);
void accountCreation(details Account[SIZE], string firstName, string lastName, int acntNumber, double balance);
void accountDeletion(details Account[SIZE]);
void withDrawl(details Account[SIZE], int option);
void avgAndSumBalances(details Account[SIZE], int option);
void displayAccountInfo(details Account[SIZE]);
void sortingInAlphabaticalOrder(details Account[SIZE]);
void sorter(details Account[SIZE], int option);
bool checkCondition(int conditionMode, details Account, details key);
double inputValidation(double min, double max);
bool isAccNumberExist(details Account[SIZE], int AccountNumber);

// main function 
int main()
{
	int selection;
	details account[SIZE];
	bool exitLoop = true;			//default value is true for while condition until program quits((Q,q)-keys aren't pressed)

	//demo data 
	accountCreation(account, "Murali", "Kotha", 10009, 50000);			//creating 3 accounts by default to check the code functionality
	accountCreation(account, "JayaKiran Reddy", "Konkala", 10010, 60000);
	accountCreation(account, "Sindhura", "Pathakota", 10011, 90000);

	do {
		cout << "--------------------------------------------" << endl;
		cout << "     WELCOME TO ONLINE BANKING SYSTEM       " << endl;
		cout << "--------------------------------------------" << endl;
		cout << "\n	Menu";
		cout << "\n 1. To Create An Account \n 2. To Withdraw Funds \n 3. To Deposit Funds \n 4. To Display Account Info \n 5. Average funds of all accounts  \n 6. Display info of all accounts  \n 7. Total funds in all accounts \n 8. Remove an account \n 9. To Display info in an order(Ascending/Descending) \n 10. Exit From The Application\n\nNote: All amounts are displayed in CAD $\n";
		cout << "Select an option: ";
		cin >> selection;
		switch (selection) {
		case 1: accountCreation(account);
			break;
		case 2: withDrawl(account, 1);		
			break;

		case 3: withDrawl(account, 2);		
			break;

		case 4: withDrawl(account, 3);		
			break;

		case 5: avgAndSumBalances(account, 2);
			break;

		case 6: displayAccountInfo(account);
			break;

		case 7: avgAndSumBalances(account, 1);
			break;

		case 8: accountDeletion(account);
			break;

		case 9: sortingInAlphabaticalOrder(account);
			break;

		case 10:
			exitLoop = false;
			break;
		}
	} while (exitLoop);
}

// Validation 
double inputValidation(double min_value, double max_value) {

	double first_deposit;
	cin >> first_deposit;
	while ((cin.fail() || cin.peek() != '\n') || (first_deposit<min_value || first_deposit>max_value)) {

		cin.clear();
		cin.ignore(512, '\n');
		cout << "Enter a valid Number between 10000 and 11000 :";
		cin >> first_deposit;

	}
	cin.ignore(512, '\n');
	return first_deposit;
}

//while entering a new account we can check if the new account is unique or not
bool isAccNumberExist(details Account[SIZE], int AccountNumber) {
	for (int i = 0; i < accountCount; i++) {
		if ((Account[i].account_number == AccountNumber))
		{
			cout << "Account number already present, choose another number" << endl;
			return true;
		}
	}
	return false;
}

// THis function is for account creation 
void accountCreation(details Account[SIZE], string firstName, string lastName, int acntNumber, double balance) {
	Account[accountCount].first_name = firstName;
	Account[accountCount].last_name = lastName;
	Account[accountCount].account_number = acntNumber;
	Account[accountCount].balance = balance;
	accountCount++;																//increment if an account is added
}

void accountCreation(details Account[SIZE]) {
	string firstName, lastName;
	int acntNumber;
	double balance;
	char ans;
	do {
		do {
			minimum = 9999;										//account cannot be less than 10000 and cannot be more than 10099
			maximum = 11000;
			cout << "\nEnter account number between 10000 and 10099: ";
			acntNumber = inputValidation(minimum, maximum);

		} while (isAccNumberExist(Account, acntNumber));
		cout << "Enter the first name : ";
		getline(cin, firstName);
		cout << "Enter the last name : ";
		getline(cin, lastName);								
		//Input Validation for balance
		minimum = 0;
		maximum = 10000000;
		cout << "Enter the initial balance of the account: ";
		balance = inputValidation(minimum, maximum);		//Account[accountCount].balance;
		accountCreation(Account, firstName, lastName, acntNumber, balance);			//calling function to create account
		cout << "Account Created." << endl << endl;
		cout << "Create new account? (Y/N) : ";
		cin >> ans;
		while (ans != 'Y' && ans != 'N' && ans != 'y' && ans != 'n') {					/*asking for entering more accounts*/
			cout << "Invalid input. Create new account? (Y/N) : ";
			cin >> ans;
		}
		cout << endl;
	} while (ans != 'N' && ans != 'n');
}


// withdraw function 

void withDrawl(details Account[SIZE], int option) {
	int actNum, i;
	details account[SIZE];
	double amount;
	minimum = 9999;
	maximum = 11000;
	bool check = false;
	cout << "Please enter your account number : ";
	actNum = inputValidation(minimum, maximum);
	//cin >> actNum;
	for (i = 0; i < accountCount; i++)							//if account find then assign check as true
	{
		if (actNum == Account[i].account_number)
		{
			check = true;
			break;
		}

	}


	if (check == true) {
		cout << "Hi " << Account[i].first_name << " " << Account[i].last_name << endl;

		switch (option) {
		case 1:     //withdrawing amount from an account
		{
			// if check is true then subtract the amount from the balance
			minimum = 1;
			maximum = 10000000;
		label:                    //goto label
			{
				cout << "Your available account balance :   " << Account[i].balance << endl;

				cout << "Enter the amount you would like to withdraw :";
				amount = inputValidation(minimum, maximum);
			}
			if (Account[i].balance == 1)
			{
				cout << "Insufficient funds !" << endl;
				goto labelIf;
			}
			else if (amount >= Account[i].balance)
			{
				cout << "Insufficient funds !" << endl;
				goto label;
			}

			Account[i].balance = Account[i].balance - amount;
			cout << "Your transaction is successfull. Thank you" << endl << endl;
			cout << "Remaining balance : " << Account[i].balance << endl << endl;
		labelIf:
			break;
		}
		case 2:           //depositing the details of an account
		{
			//if check is true then add amount in the balance
			minimum = 1;
			maximum = 10000000;
			cout << "Available account balance :   " << Account[i].balance << endl;

			cout << "Enter the amount you would like to deposite : ";

			amount = inputValidation(minimum, maximum);
			Account[i].balance = Account[i].balance + amount;
			cout << "Amount successfully deposited. Thank you " << endl << endl;
			cout << "The account balance after deposit is : " << Account[i].balance <<" $" << endl;
			break;		}
		case 3:           // diplaying the details of an account
		{
			// if check is true then display the details
			cout << "Account number: " << Account[i].account_number << endl;
			cout << "Account balance: " << Account[i].balance <<" $"<< endl;
			break;
		}
		}
	}
	else
	{
		cout << "Invalid account details" << endl;

	}
}

// Average and Sum of all the balances
void avgAndSumBalances(details Account[SIZE], int option) {
	double sum = 0.0, average;
	for (int i = 0; i < accountCount; i++)
	{
		sum = sum + Account[i].balance;
	}
	if (option == 1)
	{
		cout << "The total balance of all account is : " << sum << endl;
	}
	else if (option == 2)
	{
		average = sum / accountCount;
		cout << "The average of all account :" << average << endl;
	}

	system("pause");
}

//displaying every account details
void displayAccountInfo(details Account[SIZE])
{
	int width = 18;
	cout << "Account details: " << endl;
	cout << left << setw(width) << "First Name"
		<< setw(width) << "Last Name"
		<< setw(width) << "Account Number"
		<< setw(width) << "Balance" << endl;
	for (int i = 0; i < accountCount; i++) {
		cout << left << setw(width) << Account[i].first_name
			<< setw(width) << Account[i].last_name
			<< setw(width) << Account[i].account_number
			<< setw(width) << Account[i].balance << endl;
	}
	cout << endl;
	system("pause");
}

//deleting an account 
void accountDeletion(details Account[SIZE])
{
	int accountnum;
	int n = accountCount;
	bool msg = false;
	minimum = 9999;
	maximum = 11000;
	cout << "Enter account number to delete: ";
	accountnum = inputValidation(minimum, maximum);
	for (int i = 0; i < n; i++) {
		if (Account[i].account_number == accountnum) {
			for (int j = i; j < n - 1; j++)			//if account number found then move each account details to one position up.
			{
				Account[j].account_number = Account[j + 1].account_number;
				Account[j].balance = Account[j + 1].balance;
				Account[j].first_name = Account[j + 1].first_name;
				Account[j].last_name = Account[j + 1].last_name;
			}
			msg = true;
		}
	}
	if (msg)		//if "msg" is true
	{
		cout << "Account successfully deleted." << endl;
		accountCount--;
	}
	else
		cout << "No Account Found." << endl;
	system("pause");
}

// sorting the data
void sorter(details Account[SIZE], int option)		//swapping done if the next element is greater than the previous one
{
	int i, j, numLength = accountCount;
	details key;
	for (j = 1; j < numLength; j++)    // Start with 1 (not 0)
	{
		key.account_number = Account[j].account_number;	//Index position 1 is copied to variable "key"
		key.balance = Account[j].balance;
		key.first_name = Account[j].first_name;
		key.last_name = Account[j].last_name;
		for (i = j - 1; (i >= 0) && checkCondition(option, Account[i], key); i--)   // Smaller values move up
		{
			Account[i + 1].account_number = Account[i].account_number;
			Account[i + 1].balance = Account[i].balance;
			Account[i + 1].first_name = Account[i].first_name;
			Account[i + 1].last_name = Account[i].last_name;
		}
		Account[i + 1].account_number = key.account_number; 	//Put key into its proper location
		Account[i + 1].balance = key.balance;
		Account[i + 1].first_name = key.first_name;
		Account[i + 1].last_name = key.last_name;
	}
	displayAccountInfo(Account);
	return;
}

bool checkCondition(int conditionMode, details Account, details key)	//checking the condition of the according to the option in sort function
{
	switch (conditionMode) {
	case 0:
		return (Account.balance > key.balance);
		break;
	case 1:
		return Account.first_name.compare(key.first_name) > 0;
		break;
	case 2:
		return Account.last_name.compare(key.last_name) > 0;
		break;
	default:
		break;
	}
	return true;
}

void sortingInAlphabaticalOrder(details Account[SIZE])			// sorting menu calling sorter function
{
	int sortOption;
	bool exitLoop = true;
	cout << "Please choose from the below options to sort based on " << endl;
	do {
		cout << "1. Balance \n2. First Name \n3. Last Name \n4. To go back to previous menu \n";
		cin >> sortOption;
		switch (sortOption) {
		case 1:
			sorter(Account, 0);
			break;
		case 2:
			sorter(Account, 1);
			break;
		case 3:
			sorter(Account, 2);
			break;
		case 4:
		{
			exitLoop = false;
			break;
		}
		default:
		{
			cout << "Please enter valid option." << endl;
			system("pause");
			system("CLS");
			break;
		}
		}
	} while (exitLoop);
}
