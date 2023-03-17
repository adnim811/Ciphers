/*
 * polybius.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Aditya Nimbalkar
 * Adnim
 *
 * EECS 183: Project 3
 * Winter 2023
 *
 * Polybius square cipher functions.
 */


#include "polybius.h"
#include <string>
#include <iostream>
using namespace std;

// mixes key into ALNUM and removes duplicates and makes uppercase
string mixKey(string key){
    string alnumCopy = ALNUM;
    string keyCopy = removeDuplicate(key);
    keyCopy = toUpperCase(keyCopy);
    
    alnumCopy = keyCopy + alnumCopy;
    alnumCopy = removeDuplicate(alnumCopy);
    

    return alnumCopy;
}

// fills the grid with mixkey string
void fillGrid(char grid[SIZE][SIZE], string content){
        
    int j = 0;
    for (int i = 0; i < SIZE; i++){
        for (int k = 0; k < SIZE; k++){
            grid[i][k] = content[j];
            j++;
            
        }
    }
    
}

// finds specific character in grid and returns coordinates
string findInGrid(char c, char grid[SIZE][SIZE]){
    string coordinate = "";
    for (int i = 0; i < SIZE; i++ ){
        for (int k = 0; k < SIZE; k++){
            if (grid[i][k] == c){
                coordinate = to_string(i) + to_string(k);
            }
        }
    }
    
    return coordinate;
}

// allows findInGrid to work for strings and allows spaces
string polybiusSquare(char grid[SIZE][SIZE], string key,
                      string original, bool encrypt){
    
    string coordinates = "";
    string decrypted = "";
    string isolated = "";
    string keyCopy = mixKey(key);
    fillGrid(grid, keyCopy);
    
    if (encrypt == true) {
        for (int i = 0; i < original.length(); i++){
            if (isspace(original[i])){
                coordinates += " ";
            }
            else{
                isolated = findInGrid(original[i], grid);
                coordinates = coordinates + isolated;
            }
            
        }
        return coordinates;
    }
    
    else{
        
        for (int i = 0; i < original.length(); i += 2) {
                    if (isspace(original[i])){
                        decrypted += " ";
                        i--;
                    }
                    else {
                        int row = charToInt(original[i]) ;
                        int col = charToInt(original[i + 1]);
                        decrypted += grid[row][col];
                    }
                }
                return decrypted;
        
        
        
        
    }
    return " ";
}
