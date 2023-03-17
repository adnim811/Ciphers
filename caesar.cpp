/*
 * caesar.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Aditya Nimbalkar
 * Adnim
 *
 * EECS 183: Project 3
 * Winter 2023
 *
 * Caesar cipher functions implementations
 */

#include "caesar.h"
#include <iostream>
#include <cmath>



// shifts character and does not matter if shifter less or more than 26
char shiftAlphaCharacter(char c, int n){
    if (!isalpha(c)) {
           return c;
       }

       int base;
       if (isupper(c)) {
           base = 'A';
       }
       else {
           base = 'a';
       }

       int shifted = (c - base + n) % 26;
       if (shifted < 0) {
           shifted += 26;
       }

       char result = char(shifted + base);
       return result;
}


// uses shift alpha character to allow for strings
string caesarCipher(string original, int key, bool encrypt){
    string encrypted;
    string decrypted;
  
    
    if (encrypt == true){
        for (int i = 0; i < original.length(); i++){
            char isolatedChar = original[i];
            char newChar = shiftAlphaCharacter(isolatedChar, key);
            encrypted += newChar;
        }
        return encrypted;
    }
    else{
        for (int i = 0; i < original.length(); i++){
            char isolatedChar = original[i];
            char newChar = shiftAlphaCharacter(isolatedChar, -(key));
            decrypted += newChar;
        }
        return decrypted;
    }
}
