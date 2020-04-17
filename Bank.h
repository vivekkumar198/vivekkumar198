//
//  Bank.h
//  project1 Banking
//
//  Created by Vivek Kumar on 3/24/20.
//  Copyright © 2020 Vivek Kumar. All rights reserved.
//

#ifndef Bank_h
#define Bank_h
#include <iostream>
#include "BankAccount.h"

#include <string>
class Bank:public Bankaccount
{
private:
    string name;
    string address;
    string workingHours;
    vector<Bankaccount> accounts; // vector is being used instead of an array because size is not given.
    Bankaccount object1;
public:
  // Bankaccount object is declared here to call the menu in Bankaccount.
   void fillVector(){ // fill vector is used to make a vector of objects of accounts.
       string firstName;
       string lastName;
       string SSN;
       
       cout << "Enter the first name of the account holder: ";
       cin >> firstName;
       cout << "Enter the last name of the account holder: ";
       cin >> lastName;
       cout << "Enter the SSN of the account holder: ";
       cin >> SSN;
       cout << endl;
       Bankaccount account(firstName,lastName,SSN); //account is the object and general constructor as well.
       accounts.push_back(account); // push_back() pushes the first object of type class Bankaccount back and adds new object.
       
   }
    void printVector(){ // print vector is being used here to print the info such as first name,last name, SSN.
        for(unsigned int i = 0;i<accounts.size();i++){
            accounts.at(i).printInfo();
        }
    }

    Bank(){ // default constructor.
    }
    Bank(string name,string address,string workingHours){ // assigning of the variables using general constructor.
        this->name = name;
        this->address = address;
        this->workingHours = workingHours;
    }
    void printInfo(){ // prints the info.
        cout << " | Bank name: "<< name << endl;
        cout << " | Bank address: "<< address << endl;
        cout << " | Bank working hours: "<< workingHours << endl;
//        cout << " | Aggregated Balance: " << (Bankaccount::getsavingBalance() + Bankaccount::getcheckingBalance()) << endl;
        cout << " | Consists of " << accounts.size() <<" Bank-accounts" << endl;
        
    }
    void mainMenu(){ // main menu function displays the list of services.
     char choice;
        do{
                 cout << "Eligible services for " << name << endl;
                 cout <<"       A -- Number of Bank-Accounts" << endl;
                 cout <<"       S -- Number of Saving-Accounts" << endl;
                 cout <<"       H -- Number of Checking-Accounts" << endl;
                 cout <<"       O -- Open Bank-Account" << endl;
                 cout <<"       C -- Close Bank-Account" << endl;
                 cout <<"       M -- Modify Bank-Account" << endl;
                 cout <<"       D -- Detailed Bank-Accounts" << endl;
                 cout <<"       B -- Brief Bank-Accounts Info Sorted Based on Aggregated Balances" << endl;
                 cout <<"       E -- Exit" << endl;
            cout << "Please enter your selection: ";
            cin >> choice;
            cout << endl;
        if((choice == 'A') || (choice == 'a')){
            cout << "Number of Bank-Accounts: " << accounts.size() << endl; // accounts.size() is used to display number of accounts.
        }
        else if((choice == 'S') || (choice == 's')){
            cout << "Number of Saving-Accounts: " << Bankaccount::getsavingAccountcount() << endl; // getsavingAccountcount() displays the number of saving accounts.
            
        }
        else if((choice == 'H') || (choice == 'h')){
            cout << "Number of Checking-Accounts: " << Bankaccount::getcheckingAccountcount() << endl; //getcheckingAccountcount() displays the number of checking accounts.

        }
        else if((choice == 'O') || (choice == 'o')){
            fillVector();// fillvector function is called here to open a new bank account.
            object1.menu();// after opening a new bankaccount another menu of services automatically gets displayed.
        }
        else if((choice == 'C') || (choice == 'c')){
            accounts.pop_back(); // used to close an account permanently.
            
        }
        else if((choice == 'M')|| (choice == 'm')){
            object1.menu(); // The menu is again called for modifications if any.
            
        }
        else if((choice == 'D')|| (choice == 'd')){// called to print first name, last name , SSN, and Bankaccount number. displays detailed info regarding the bank.
            printInfo();
            cout << endl;
            printVector();
            cout << endl;
            object1.printsavingVector();
            cout << endl;
            object1.printcheckingVector();
          
            
        }
        else if((choice == 'B')|| (choice == 'b')){//displays brief info such as bank's name,address and working hours.// Also displays aggregated balance for number of subaccounts.
            printInfo();
            cout << endl;
            object1.printAggregatedBalance();

        }
        else{
            cout <<" | End of service for " << name << endl;
        
        }
        }
            while(choice != 'E');
    
    }
    
};

#endif /* Bank_h */

