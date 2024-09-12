// File Name: PasswordManager.cpp
//
// Author: Kayla Vincent
// Collaborators: none
// Date: 3/16/2023
// Assignment Number: 4
// CS 2308 Spring 2023
//
// Defines the public and private member functions of the
// PasswordManager class. The public functions are setUsername,
// getUsername, setEncryptedPassword, getEncryptedPassword, 
// setNewPassword, and authenticate. The private functions are 
// encrypt and meetsCriteria. 

#include "PasswordManager.h"
#include <iostream>
#include <string>
using namespace std;

//***********************************************************
// setUsername: takes a string and stores it in the username
//      member variable
// userInput: string, user input for the username, the 
//      username is also the netID
// returns: void
//***********************************************************
void PasswordManager :: setUsername(string userInput) {
  username = userInput;
}

//***********************************************************
// getUsername: accesses the username member variable 
// returns: string, the username of the PasswordManager object
//***********************************************************
string PasswordManager :: getUsername() {
  return username;
}

//***********************************************************
// setEncryptedPassword: takes a string and stores it in the 
//      password member variable
// encryptedPass: string, user input for the password
// returns: void
//***********************************************************
void PasswordManager :: setEncryptedPassword(string encryptedPass) {
  password = encryptedPass;
}

//***********************************************************
// setEncryptedPassword: accesses the password member variable 
// returns: string, the encrypted password of the 
//      PasswordManager object
//***********************************************************
string PasswordManager :: getEncryptedPassword() {
  return password;
}

//***********************************************************
// setNewPassword: checks if user input password meets criteria
//      to become a new password. If new password passes test,
//      the password is encrypted. The password member variable
//      is set to the new password
// userPass: string, user input for the new password
// returns: true - if user input meets the criteria,
//      false - if user input does not
//***********************************************************
bool PasswordManager :: setNewPassword(string userPass) {
  if(meetsCriteria(userPass)) {
    password = encrypt(userPass);
    return true;
  }
  else {
    return false;
  }
}

//***********************************************************
// authenticate: checks if the input user password is the same
//      as the current value of the password member variable
// userPass: string, input user for old password
// returns: true - if password member variable is the same as
//      encrypted user input password
//      false - if encrypted user input is different
//***********************************************************
bool PasswordManager :: authenticate(string userPass) {
  string newPass = encrypt(userPass);
  if(password == newPass) {
    return true;
  }
  else {
    return false; 
  }
}

//***********************************************************
// encrypt: changes the ASCII values of the password, increments 
//      using a Caesar Cipher
// pass: string, user input for a password
// returns: string, the encrypted password of the 
//      PasswordManager object
//***********************************************************
string PasswordManager :: encrypt(string pass) {
  string encrypted = "";
  int size = pass.length();
  char newChar;

  // changes ASCII value of each char in the string 
  for(int i = 0; i < size; i++) {
    newChar = ((int(pass.at(i)) - 33) + 41) % 94 + 33;
    encrypted.push_back(newChar);
  }

  return encrypted;
}

//***********************************************************
// meetsCriteria: checks user password to see if it meets the
//      criteria to become a new password, must have: at least
//      15 characters, uppercase letter, lowercase letter, and
//      a number or special character
// pass: string, the user input for a new password
// returns: true - if the new password meets all the criteria,
//      false - if the password does not meet all criteria
//***********************************************************
bool PasswordManager :: meetsCriteria(string pass) {
  bool upper = false;
  bool lower = false;
  bool number = false;
  bool symbol = false;
  char currChar;
  int passLength = pass.length();

  if(passLength < 15) { // checks for password length
    return false;
  }

  for(int i = 0; i < passLength; i++) {
    currChar = pass.at(i);
    
    if(isupper(currChar)) { // checks for uppercase letter
      upper = true;
    }    
    if(islower(currChar)) { // checks for lowercase letter
      lower = true;
    }
    if(isdigit(currChar)) { // checks for digit
      number = true;
    }
    if(ispunct(currChar)) { // checks for special character
      symbol = true;
    }
    
  }

  // checks for all criteria 
  if(upper && lower && (number || symbol)) {
    return true; 
  }
  else {
    return false;
  }
}