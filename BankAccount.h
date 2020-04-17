//
//  BankAccount.h
//  project1 Banking
//
//  Created by Vivek Kumar on 3/25/20.
//  Copyright © 2020 Vivek Kumar. All rights reserved.
//

#ifndef BankAccount_h
#define BankAccount_h
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
//#include <utility>
#include "SavingSubAccount.h"
#include "CheckingSubAccount.h"
#include<vector>

class Bankaccount:protected Savingsubaccount, protected Checkingsubaccount
{
private:
    string firstName;
    string lastName;
    string SSN;
    static unsigned int accountNum;
    static string variable;
    string bankAccountnum;
    char input;
    vector <Savingsubaccount> savingAccounts; // A vector is being used to store number of saving accounts.
    vector <Checkingsubaccount> checkingAccounts;// A vector or list is being used to store number of checking accounts.
    static unsigned int savingAccountcount; // static variables used here are for keeping the count of saving accounts.Static so that can be accessed anywhere.
    static unsigned int checkingAccountcount;
    
    Checkingsubaccount checkingObject;
    vector<Savingsubaccount> savObjects;
    Savingsubaccount savingObject;
    vector<Checkingsubaccount> checkObjects;
   
    
    
public:
    static unsigned int getsavingAccountcount(){
        return savingAccountcount;
    }
    static unsigned int getcheckingAccountcount(){
        return checkingAccountcount;
    }

    
    Bankaccount(){ // default constructor
        
    }
    Bankaccount(string firstName,string lastName,string SSN){ // general constructor
        this->firstName = firstName;
        this->lastName = lastName;
        this->SSN = SSN;
        accountNum++; // accountNum++ increments whenever a new account is opened.
        bankAccountnum = variable + to_string(accountNum); // to_string function is being used to convert an integer into a string so that it can be assigned to bankAccountnum.
        cout <<" | A new Bank Account "<< bankAccountnum <<" was successfully created." << endl;
        cout << endl;
    }

    void setfirstName(string firstName){ //setters.
        this->firstName =  firstName;
    }
    void setlastName(string lastName){//setters.
        this->lastName = lastName;
    }
    void setSSN(string SSN){//setters.
        this->SSN = SSN;
    }
    string getfirstName(){//getters.
        return this->firstName;
    }
    string getlastName(){ //getters.
        return this->lastName;
    }
    string getSSN(){//getters.
        return this->SSN;
    }
    
   
    bool compareBalance(Savingsubaccount& savingAccounts,Checkingsubaccount& checkingAccounts){
        return savingAccounts.getsavingBalance() > checkingAccounts.getcheckingBalance();
    }
    
    void fillSavingVector(){ //function is used to add saving sub accounts.
        int balance;
        cout <<" | Enter the intial balance: ";
        cin >> balance;
        Savingsubaccount savingAccount(balance); //a constructor is being used here.
        savingAccounts.push_back(savingAccount); // push_back to add saving subaccounts.
        savObjects.push_back(savingObject);
        savingObject.setsavingBalance(balance);
        savingAccountcount++;
        
    }
    void fillCheckingVector(){ //function is used to add checking sub accounts.
        int maxCapacity = 0;
        int balance2;
        cout << " | Enter the intial balance: ";
        cin >> balance2;
        cout << " | Enter the desired maximum capacity: ";
        cin >> maxCapacity;
        cout << " | Define the intial state: (L - locked,otherwise - unlocked) ";
        cin >> input;
        cout << endl;
        Checkingsubaccount checkingAccount(balance2,maxCapacity,input);//a constructor is being used here.
        checkingAccounts.push_back(checkingAccount);
        
        checkObjects.push_back(checkingObject);
        checkingObject.setcheckingBalance(balance2);
        checkingObject.setmaximumCapacity(maxCapacity);
        checkingAccountcount++;
    }
    
   
    
    void printsavingVector(){// printsaving vector function prints the saving sub account info.
        for(int i = 0;i<savingAccounts.size();i++){
            savingAccounts.at(i).savingprintInfo();
            savingObject.savingprintInfo();
          
    }
    }
    void printcheckingVector(){//printchecking vector function prints the checking sub account info.
        for (int i =0;i<checkingAccounts.size();i++) {
            checkingAccounts.at(i).checkingprintInfo();
            checkingObject.checkingprintInfo();
        }
    }
    void printAggregatedBalance(){ //prints aggregated balance of subaccounts.
        if((savingAccounts.size() >= 1) && (checkingAccounts.size() == 0)){
            cout <<" | Aggregated balance of the bank account: "<< variable + to_string(accountNum) << " with " << savingAccounts.size()+checkingAccounts.size() << " Sub accounts is " << savingObject.getsavingBalance() << endl;
        }
         else if((savingAccounts.size() == 0) && (checkingAccounts.size() >= 1)){
            cout <<" | Aggregated balance of the bank account: "<< variable + to_string(accountNum) << " with " << savingAccounts.size()+checkingAccounts.size() << " Sub accounts is " << checkingObject.getcheckingBalance() << endl;
        }
        else{
            cout <<" | Aggregated balance of the bank account: "<< variable + to_string(accountNum) << " with " << savingAccounts.size()+checkingAccounts.size() << " Sub accounts is " << (savingObject.getsavingBalance() + checkingObject.getcheckingBalance()) << endl;
        }
        
    }
    void printInfo(){//prints customers info such as name , ssn, bankaccount number, balance and how many sub accounts it consists of.
        cout << " | Account Holder Full Name: " << firstName <<" "<< lastName << endl;
        cout << " | Account Holder SSN: " << SSN << endl;
        cout << " | Bank account number: " << bankAccountnum << endl;
        cout << " | Aggregated balance: " << savingObject.getsavingBalance() + checkingObject.getcheckingBalance() << endl;
        
        cout << " | Consists of "<< getsavingAccountcount() + getcheckingAccountcount() <<" Sub-Accounts" << endl;
        
    }
   
    void menu(){ // This menu consist of other services regarding the Bank account.

        char choice1;
      
        do{
            cout << "Eligible services for Bank account " << variable + to_string(accountNum) << endl;
            cout <<"      S -- Open Saving Sub-Account" << endl;
            cout <<"      C -- Open Checking Sub-Account" << endl;
            cout <<"      M -- Modify a Sub-Account" << endl;
            cout <<"      E -- Close a Sub-Account" << endl;
            cout <<"      D -- Detailed Bank Account Info Sorted Based on Balances of Sub-Accounts" << endl;
            cout <<"      B -- Brief Bank Account Info" << endl;
            cout <<"      X -- Exit" << endl;
            cout << "Please enter your selection: " << endl;
                cin >> choice1;
            
            if((choice1 == 'S') || (choice1 == 's')){
                fillSavingVector();
                
            }
            
            else if((choice1 == 'C') || (choice1 == 'c')){
                fillCheckingVector();
               
            }
            else if((choice1 == 'M') || (choice1 == 'm')){
    
                string subAccount;
                cout << "Enter the sub-account number to modify: ";
                cin >> subAccount;
                cout << endl;
                if (subAccount == Savingsubaccount::variable1 + to_string(savingNum)){//if statement for saving
                    savingObject.savingMenu();
                }
                else if(subAccount == variable2 + to_string(checkingNum)){
                    checkingObject.checkingMenu();
                    
                    
               }
                
            }
            else if((choice1 == 'E') || (choice1 == 'e')){
                string accountClosed;
                cout << "Enter the sub-account number to be closed: ";
                cin >> accountClosed;
                cout << endl;
                if(accountClosed == variable1 + to_string(savingNum)){
                    savingAccounts.pop_back();
                    cout << " | sub-account " << accountClosed <<" was successfully closed" << endl;
                }
                else if(accountClosed == variable2 + to_string(checkingNum)) {
                    checkingAccounts.pop_back();
                    cout << " | sub-account " << accountClosed <<" was successfully closed" << endl;
                }
            }
            else if((choice1 == 'D') || (choice1 == 'd')){
               printsavingVector();
                cout << endl << endl;
               printcheckingVector();
               
              
                
            }
            else if((choice1 == 'B') || (choice1 == 'b')){
                printAggregatedBalance();
                
            }
            else {
                cout <<" | End of service for bank-account " << variable + to_string(accountNum) << endl;
            }
            }
      while (choice1 != 'X');
       
    }
    
 

};
     unsigned int Bankaccount::accountNum = 9999;
     string Bankaccount::variable = "BNK";
    unsigned int Bankaccount::checkingAccountcount = 0;
    unsigned int Bankaccount::savingAccountcount = 0;
    
#endif /* BankAccount_h */

