//
//  main.cpp
//  project1 Banking
//
//  Created by Vivek Kumar on 3/24/20.
//  Copyright © 2020 Vivek Kumar. All rights reserved.
//

#include <iostream>
#include "Bank.h"

int main(){
    string name;
    string address;
    string workingHours;
   
    cout << "Enter the name of the bank: ";
    getline(cin,name); //getline function is used here to get a line for name.
    cout << "Enter the address of the bank: ";
    getline(cin,address);//getline function is used here to get a line for address.
    cout << "Enter the working hours: ";
    getline(cin,workingHours);//getline function is used here to get a line for working hours.
    cout << endl;
    Bank object(name,address,workingHours); // a general constructor is used here to pass values.
    object.mainMenu(); // an object of Bank is declared and is used to call main menu.
    
   // object.printInfo();
}
