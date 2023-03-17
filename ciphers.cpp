/*
 * ciphers.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Aditya Nimbalkar
 * Adnim
 *
 * EECS 183: Project 3
 * Winter 2023
 *
 * This is the main file of the ciphers project that puts the functions
 // together to allow the user to interact
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"

#include <iostream>
#include <string>

using namespace std;

void caesar();


// allows user to pick which cipher type.
void ciphers(){
    char grid[SIZE][SIZE];
    string cipherType;
    string message = "";
    int countM = 0;
    string encryptOrDecrypt;
    int intKey;
    string key;
    string output;
    int count = 0;
    
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): ";
    cin >> cipherType;
    cout << endl;
    cipherType = toUpperCase(cipherType);
    
    
    // allows user to enter cipher type without case sensitivity
    
    if (cipherType == "CAESAR" || cipherType == "C"){
        cout << "Encrypt or decrypt: ";
        cin >> encryptOrDecrypt;
        cout << endl;
        encryptOrDecrypt = toUpperCase(encryptOrDecrypt);
        if (encryptOrDecrypt == "ENCRYPT" || encryptOrDecrypt == "E"){
            cout << "Enter a message: ";
            cin.ignore();
            getline(cin, message);
            cout << endl;
            
            cout << "What is your key: ";
            cin >> intKey;
            cout << endl;
            cout << "The encrypted message is: "
            << caesarCipher(message, intKey, true) << endl;
        
        }
        else if (encryptOrDecrypt == "DECRYPT" || encryptOrDecrypt == "D"){
            cout << "Enter a message: ";
            cin.ignore();
            getline(cin, message);
            cout << endl;
            
            cout << "What is your key: ";
            cin >> intKey;
            cout << endl;
            cout << "The decrypted message is: "
            << caesarCipher(message, intKey, false) << endl;
        
        }
        else{
            cout << "Invalid mode!" << endl;
            return;
        }
   
        
        
    }
    // vigenere cipher
    else if (cipherType == "VIGENERE" || cipherType == "V"){
        cout << "Encrypt or decrypt: ";
        cin >> encryptOrDecrypt;
        cout << endl;
        encryptOrDecrypt = toUpperCase(encryptOrDecrypt);
        if (encryptOrDecrypt == "ENCRYPT" || encryptOrDecrypt == "E"){
            cout << "Enter a message: ";
            cin.ignore();
            getline(cin, message);
            cout << endl;
            
            cout << "What is your key: ";
            
            getline(cin, key);
            
            for (int i = 0; i < key.length(); i++){
                if (isalpha(key[i]))
                    count++;
            }
            if (count < 1){
                cout << "Invalid key!" << endl;
            }
            else{
                cout << endl;
                cout << "The encrypted message is: "
                << vigenereCipher(message, key, true) << endl;
            }
           
            
        }
        else if (encryptOrDecrypt == "DECRYPT" || encryptOrDecrypt == "D"){
            cout  << "Enter a message: ";
            cin.ignore();
            getline(cin, message);
            cout << endl;
            
            cout << "What is your key: ";
            
            getline(cin, key);
            for (int i = 0; i < key.length(); i++){
                if (isalpha(key[i]))
                    count++;
            }
            if (count < 1){
                cout << "Invalid key!" << endl;
            }
            else{
                cout << endl;
                cout << "The decrypted message is: "
                << vigenereCipher(message, key, false) << endl;
            }
           
            
        }
        else{
            cout << "Invalid mode!" << endl;
            return;
            
            
            
        }
        
    
    }
    
    //polybius square cipher
    
    else if (cipherType == "POLYBIUS" || cipherType == "P"){
        cout << "Encrypt or decrypt: ";
        cin >> encryptOrDecrypt;
        
        encryptOrDecrypt = toUpperCase(encryptOrDecrypt);
        if (encryptOrDecrypt == "ENCRYPT" || encryptOrDecrypt == "E"){
            cout << endl << "Enter a message: ";
            cin.ignore();
            getline(cin, message);
            message = toUpperCase(message);
            
            for (int i = 0; i < message.length(); i++){
                if (!isalnum(message[i]) && !isspace(message[i])){
                    countM++;
                }
                
            }
            
            //checks if any special characters, if so then go to invalid
            if (countM > 0){
                cout << endl << "Invalid message!" << endl;
                return;
            }
            
            
            else{
                cout << endl << "What is your key: ";
                    
                getline(cin, key);
                cout << endl << "The encrypted message is: "
                << polybiusSquare(grid, key, message, true) << endl;
            }
            }
       else if (encryptOrDecrypt == "DECRYPT" || encryptOrDecrypt == "D"){
            cout << endl << "Enter a message: ";
            cin.ignore();
            getline(cin, message);
           
           for (int i = 0; i < message.length(); i++){
               if (!isalnum(message[i]) && !isspace(message[i])){
                   countM++;
               }
               
           }
           if (countM > 0){
               cout << endl << "Invalid message!" << endl;
               return;
           }
           else {
               cout << endl << "What is your key: ";
               
               getline(cin, key);
               cout << endl << "The decrypted message is: "
               << polybiusSquare(grid, key, message, false) << endl;
           }
            
            
        }
        else{
            cout << "Invalid mode!" << endl;
            return;
        }
        
    }
    
    else{
        cout << "Invalid cipher!" << endl;
        return;
        }
    
    
    
    return;
}



