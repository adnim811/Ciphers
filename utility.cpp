/*
 * utility.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Aditya Nimbalkar
 * Adnim
 *
 * EECS 183: Project 3
 * Winter 2023
 *
 * Helper functions to use in files for ciphers.
 */

#include "utility.h"
#include <iostream>
#include <cstring>
#include <cctype>

// turns strings to uppercase
string toUpperCase(string original) {
    string copyOriginal = original;
    
    for (int i = 0; i < copyOriginal.length(); i++) {
        char c = copyOriginal[i];
        if (isalpha(c)){
            copyOriginal[i] = toupper(c);
        }
    }
    return copyOriginal;
}

//removes non alpha characters
string removeNonAlphas(string original) {
    string result;
        for (int i = 0; i < original.length(); i++) {
            char c = original[i];
            if (isalpha(c)) {
                result += c;
            }
        }
        return result;
}

//turns char to an int
int charToInt(char original) {
    int charInt;
    charInt = int(original);
    
    return charInt - '0';
}

// removes duplicate characters
string removeDuplicate(string original) {
    string result;
    
    for (int i = 0; i < original.length(); i++){
        char c = original[i];
        
        bool outcome = false;
        for (int k = 0; k < result.length(); k++){
            if (result[k] == c){
                outcome = true;
            }
        }
        if (outcome == false){
            result += c;
        }
    }
    return result;
}

////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
