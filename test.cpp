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
 * <#description#>
 */

#include <iostream>
#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"

void testShiftAlphaCharacter();
void testToUpperCase();
void testRemoveNonAlphas();
void testRemoveDuplicate();
void testCharToInt();
void testCaesarCipher();
void testVigenereCipher();
void testFillGrid();
void testMixKey();
void testFindInGrid();
void testPolybiusSquare();
void startTests();
void ciphers();


void startTests(){
    testShiftAlphaCharacter();
    testToUpperCase();
    testRemoveNonAlphas();
    testRemoveDuplicate();
    testCharToInt();
    testCaesarCipher();
    testVigenereCipher();
    testMixKey();
    testFillGrid();
    testFindInGrid();
    testPolybiusSquare();

    
}


void testShiftAlphaCharacter() {
    cout << shiftAlphaCharacter('a', 0) << endl;
    cout << shiftAlphaCharacter('b', 2) << endl;
    cout << shiftAlphaCharacter('X', -5) << endl;
    cout << shiftAlphaCharacter('X', 5) << endl;
    cout << shiftAlphaCharacter('X', 100) << endl;
    cout << shiftAlphaCharacter('X', -100) << endl;
    
    
}


void testToUpperCase(){
    cout << toUpperCase("hello world") << endl;
    cout << toUpperCase("hEllo worlD") << endl;
    
}


void testRemoveNonAlphas(){
    
    cout << removeNonAlphas("hello world! 123") << endl;
    
}



void testRemoveDuplicate(){
    cout << removeDuplicate("ABBCCA99") << endl;
    
    
}


void testCharToInt(){
    cout << charToInt('3') << endl;
    
    
}


void testCaesarCipher(){
    cout << endl << caesarCipher("Aditya", 1, true) << endl;
    cout << endl << caesarCipher("Bejuzb", 1, false) << endl;

    cout << caesarCipher("Meet me at the Diag at 11 p.m.", 42, true) << endl;

    cout << caesarCipher("Cuuj cu qj jxu Tyqw qj 11 f.c.", 42, false) << endl;

    cout << endl << caesarCipher("Hi My name is Aditya", 11 , true) << endl;
    cout << endl << caesarCipher("St Xj ylxp td Lotejl", 11 , false) << endl;
    
    
    
    
}


void testVigenereCipher(){
   
    cout << endl << vigenereCipher("Meet me at the Diag at 11 p.m.", "Squirrel!", true) << endl;
    cout << endl << vigenereCipher("Euyb dv ee lxy Lzrk ll 11 f.g.", "Squirrel!", false) << endl;
    cout << endl << vigenereCipher("U lgp'a os qaoxitk iaz ltvcfqq. Teoafoq ckwhtpd riady qh.", "Mischief managed.", false);
   
    
}

void testMixKey(){
    cout << endl << mixKey("POLYBIUS");

}

void testFillGrid(){
    char grid[SIZE][SIZE];
    fillGrid(grid, mixKey("ADIL"));
    printGrid(grid);
}


void testFindInGrid(){
    char grid[SIZE][SIZE];
    fillGrid(grid, mixKey("ADIL"));
    cout << endl << findInGrid('P', grid) << endl;
    
   
}


void testPolybiusSquare(){
    char grid[SIZE][SIZE];
    cout << endl << polybiusSquare(grid, "POLYBIUS", "EECS 183 IS THE BEST", true) << endl;
    
    cout << endl << polybiusSquare(grid, "POLYBIUS", "15151311 435445 0511 332215 04151133", false) << endl;
    
}





