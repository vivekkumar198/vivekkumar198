//
//  CheckingSubAccount.h
//  project1 Banking
//
//  Created by Vivek Kumar on 4/6/20.
//  Copyright © 2020 Vivek Kumar. All rights reserved.
//

#ifndef CheckingSubAccount_h
#define CheckingSubAccount_h
class Checkingsubaccount{
private:
    int maximumCapacity;
    int checkingBalance = 0;
    bool lock = false;
    string checkingAccountnum;
    char input;
protected:
    static unsigned int checkingNum;
    static string variable2;
    

public:
    Checkingsubaccount(){//default constructor.
        
    }
    Checkingsubaccount(int checkingBalance,int maximumCapacity,char input){ // general constructor is used here for assigning.
        this->checkingBalance = checkingBalance;
        this->maximumCapacity = maximumCapacity;
        this->input = input;
      //  this->lock = lock;
        checkingNum++;
        checkingAccountnum = variable2 + to_string(checkingNum);
        cout <<" | A new Checking Sub-Account "<< checkingAccountnum <<" was successfully created." << endl;
        cout << endl;
    }
    void setcheckingBalance(int checkingBalance){
        this->checkingBalance = checkingBalance;
    }
    int getcheckingBalance(){
        return this->checkingBalance;
    }
    void setmaximumCapacity(int maximumCapacity){
        this->maximumCapacity = maximumCapacity;
    }
    int getmaximumCapacity(){
        return maximumCapacity;
    }
    bool Locked(char input){
        if((input == 'L') || (input == 'l')){
            return true;
        }
        else{
            return false;
        }
    }
    void checkingprintInfo(){
        cout << " | sub-account number: " << variable2 + to_string(checkingNum) << endl;
        cout << " | Balance: " << getcheckingBalance() << endl;
        cout << endl;
        cout << " | The maximum capacity is: " << maximumCapacity << endl;
        if(Locked(input) == true){
            cout << " | The sub-account is locked. " << endl;
        }
        else{
            cout << " | The sub-account is not locked. " << endl;
        }
        cout << endl;
    
    }
    
    void checkingDeposit(int deposit,int &checkingBalance){
        checkingBalance = checkingBalance + deposit;
    }
    

    void checkingWithdraw(int withdraw,int &checkingBalance){
        checkingBalance = checkingBalance - withdraw;
       
    }
    
    void checkingMenu(){
        char character;
     do{
           cout << "Eligible services for sub-account " << variable2 + to_string(checkingNum) << endl;
           cout <<"          D -- Deposit" << endl;
           cout <<"          W -- Withdraw" << endl;
           cout <<"          C -- Max Capacity" << endl;
           cout <<"          L -- Lock sub-Account" << endl;
           cout <<"          U -- Unlock sub-Account" << endl;
           cout <<"          X -- Exit" << endl;
                           cin >> character;
                        if((character == 'D') || (character == 'd')){
                               int deposit;
                               cout << " | Enter the amount to deposit: ";
                               cin >> deposit;
                               cout << endl;
                            
                              
                               if(Locked(input) == true){ // if locked true then deposit wont be possible.
                                   cout << " | The account is currently locked! " << endl;
                                   cout << " | The deposit was unsuccessful. " << endl;
                               }
                               
                               else{
                                   checkingDeposit(deposit,checkingBalance); // else deposit if not locked and display current balance.
                                   cout << " | Deposit was successful. "<< endl;
                                   cout << " | The current balance is: " << getcheckingBalance() << endl;
                                   cout << endl;
                                   }
                           
                           }
                        else if((character == 'W') || (character == 'w')){
                               int withdraw;
                               cout << " | Enter the amount to withdraw: ";
                               cin >> withdraw;
                               cout << endl;
                               if(Locked(input) == true){// if locked true then withdraw wont be possible.
                                   cout << " | The account is currently locked! " << endl;
                                   cout << " | The deposit was unsuccessful. " << endl;
                               }
                               else{ // else withdraws if not locked and displays current balance.
                                  checkingWithdraw(withdraw,checkingBalance);
                                   cout << " | Withdraw was successful. " << endl;
                                   cout << " | The current balance is: " << getcheckingBalance() << endl;
                                   
                               }
                           }
                        else if((character == 'C') || (character == 'c')){
                                if(getcheckingBalance() > getmaximumCapacity()){
                                cout << " | Deposit was denied!" << endl;
                              }
                           }
                        else if((character == 'L') || (character == 'l')){
                                input = character;
                              if(Locked(input) == true){
                                  cout << " | The sub-account "<< variable2 + to_string(checkingNum) <<" has been locked now! " << endl;
                              }
                           }
                       
                        else if((character == 'U') || (character == 'u')){
                               input = character;
                               if(Locked(input) == false){
                                    cout << " | The sub-account "<< variable2 + to_string(checkingNum) <<" has been unlocked now! " << endl;
                               }
                              }
                           
                           
                        else {
                               cout <<" | End of service for sub-account " << variable2 + to_string(checkingNum) << endl;
                           }
                       }
                       while(character != 'X');
    
    }
};
unsigned int Checkingsubaccount::checkingNum = 5999;
string Checkingsubaccount::variable2 = "CHK";
#endif /* CheckingSubAccount_h */
