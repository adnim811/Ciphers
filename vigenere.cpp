/*
 * vigenere.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Aditya Nimbalkar
 * Adnim
 *
 * EECS 183: Project 3
 * Winter 2023
 *
 * Vigenere cipher functions implementations
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include <iostream>



// Use following functions
// toUpperCase(), removeNonAlphas(), shiftAlphaCharacter()


//encrypts a string using another string as the key.

string vigenereCipher(string original, string keyword, bool encrypt){
    string encrypted;
    string decrypted;
    
    string modKey = keyword;
    modKey = removeNonAlphas(keyword);
    modKey = toUpperCase(modKey);
    
    int j = 0;
    encrypted = "";
    
    if (encrypt == true){
        for (int i = 0; i < original.length(); i++){
            if (!isalpha(original[i])){
                encrypted += original[i];
            }
            else{
                encrypted += shiftAlphaCharacter(original[i],
                (int) modKey[j % (modKey.length())] - 65);
                j++;
            }
        }
       
        return encrypted;
    }
    else{
        for (int i = 0; i < original.length(); i++){
            if (!isalpha(original[i])){
                decrypted += original[i];
            }
            else{
                decrypted += shiftAlphaCharacter(original[i],
                - ((int) modKey[j % (modKey.length())] - 65));
                j++;
            }
        }
       
        return decrypted;
    }
}
   











