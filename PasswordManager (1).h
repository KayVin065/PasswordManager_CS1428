// File Name: PasswordManager.h
//
// Author: Kayla Vincent
// Collaborators: none
// Date: 3/16/2023
// Assignment Number: 4
// CS 2308 Spring 2023
//
// Class declaration for the PasswordManager class. Creates 
// prototypes for the member functions. 

#include <iostream>
#include <string>
using namespace std;

class PasswordManager
{
  private:
    string username;
    string password;
    string encrypt(string);
    bool meetsCriteria(string);

  public:
    void setUsername(string);
    string getUsername();
    void setEncryptedPassword(string);
    string getEncryptedPassword();
    bool setNewPassword(string);
    bool authenticate(string);
};
