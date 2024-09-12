// File Name: PasswordDriver.cpp
//
// Author: Kayla Vincent
// Collaborators: none
// Date: 3/16/2023
// Assignment Number: 4
// CS 2308 Spring 2023
//
// Takes in input for a file, a netID, old password, and new
// password. Stores the info from the file into an array of 
// PasswordManager objects. Outputs different responses depending
// on the accuracy of user input. If all input is accurate and 
// usable, the program outputs the changed password for the 
// netID and the entire array of PasswordManager objects. 

#include <iostream>
#include <fstream>
using namespace std;
#include "PasswordManager.h"

int main() {
  const int SIZE = 4;
  PasswordManager passwords[SIZE];
  string fileName,
         netID,
         oldPass,
         newPass,
         ID,
         p;
  bool validID = false;
  int index;

  // gets user input for file, netID, old, and new password
  cout << "Please enter the name of the input file:" << endl;
  cin >> fileName;
  ifstream in(fileName);
  cout << "Please enter your netID:" << endl;
  cin >> netID;
  cout << "Please enter your old password:" << endl;
  cin >> oldPass;
  cout << "Please enter your new password:" << endl;
  cin >> newPass;
  cout << endl;

  // updates PasswordManager array data to match file
  for(int i = 0; i < SIZE; i++) {
    in >> ID;
    passwords[i].setUsername(ID);
    in >> p;
    passwords[i].setEncryptedPassword(p);
  }

  // searches for user input netID in PasswordManager array 
  for(int i = 0; i < SIZE; i++) {
    if(passwords[i].getUsername() == netID) {
      validID = true;
      index = i;
    }
  }

  // output for invalid ID
  if(!validID) {
    cout << "NetID is invalid, password not changed." << endl << endl;
  }
  // output for incorrect password
  else if(!passwords[index].authenticate(oldPass)) {
    cout << "Old password is incorrect." << endl << endl;
  }
  // output for invalid new password
  else if(!passwords[index].setNewPassword(newPass)) {
    cout << "New Password does not meet criteria." << endl << endl;
  }
  // output for all correct/usable input data
  else {
    cout << "Password has been changed for netID: " << netID << endl << endl;
    passwords[index].setNewPassword(newPass);
  }

  // output PasswordManager array data
  for(int i = 0; i < SIZE; i++) {
    cout << passwords[i].getUsername() << "  ";
    cout << passwords[i].getEncryptedPassword();
    cout << endl;
  }
  
  return 0;
}