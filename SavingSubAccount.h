//
//  SavingSubAccount.h
//  project1 Banking
//
//  Created by Vivek Kumar on 3/26/20.
//  Copyright © 2020 Vivek Kumar. All rights reserved.
//

#ifndef SavingSubAccount_h
#define SavingSubAccount_h
#include <iostream>
#include <string>
using namespace std;
class Savingsubaccount{
private:
   
    int bonus = 100;
    string savingAccountnum;
     int savingBalance = 0;
protected:
    static unsigned int savingNum;
    static string variable1;
public:
    Savingsubaccount(){ //default constructor
        
    }
    Savingsubaccount(int balance) { // a general constructor is used to assign savingBalance.
        savingBalance = balance;
        savingNum++;
        savingAccountnum = variable1 + to_string(savingNum);
        cout <<" | A new Saving Sub-Account "<< savingAccountnum <<" was successfully created." << endl;
        cout << endl;
    }
       void setsavingBalance(int balance) {// a setter is used to assign balance to savingBalance.
             savingBalance = balance;
    }
        int getsavingBalance(){ //a getter is used here.
              return savingBalance;//returns savingBalance.
          }
    
   
    int getBonus(){
        if(variable1 + to_string(savingNum) == "SAV1000"){
            return bonus;
        }
        else{
            return 0;
        }
    }

        void savingDeposit(int balance){ //saving deposit function for deposit of saving sub account.
            int deposit;
            cout << " | Enter the amount to deposit: ";
            cin >> deposit;
            cout << endl;
            savingBalance = balance + deposit + getBonus();
            cout << " | Deposit was successful." << endl;
            cout << " | The current balance is: " << getsavingBalance() << endl;
            cout << endl;
            }
    
        void savingWithdraw(int balance){ //saving with function for withdraw of saving sub account.
            int withdraw;
            cout << " | Enter the amount to withdraw: ";
            cin >> withdraw;
            cout << endl;
            savingBalance = balance - withdraw;
            cout << " | Withdraw was successful. " << endl;
            cout << " | The current balance is: " << getsavingBalance() << endl;
            cout << endl;
            
        }
       
    
        void savingprintInfo() { //prints the saving sub-account number and balance.
           cout <<" | Sub-account number: " << variable1 + to_string(savingNum) << endl;
           cout <<" | Balance: "<<  getsavingBalance() << endl;
       }
        
         
    
    
    void savingMenu(){
    char character;
        do{
            cout << "Eligible services for sub-account " << variable1 + to_string(savingNum) << endl;
            cout <<"          D -- Deposit" << endl;
            cout <<"          W -- Withdraw" << endl;
            cout <<"          X -- Exit" << endl;
            cin >> character;
                      if((character == 'D') || (character == 'd')){
                          savingDeposit(savingBalance);
                      }
                      else if((character == 'W') || (character == 'w')){
                          savingWithdraw(savingBalance);

                      }
                      else{
                          
                          cout <<" |End of service for sub-account " << variable1 + to_string(savingNum) << endl;

                      }
                  
            }while(character != 'X');
    
    
    
    
    }
};
unsigned int Savingsubaccount::savingNum = 999;
string Savingsubaccount::variable1 = "SAV";
#endif /* SavingSubAccount_h */
