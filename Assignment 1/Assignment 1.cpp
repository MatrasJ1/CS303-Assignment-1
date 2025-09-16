// Assignment 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <string>
#include "Functions.h"

int main()
{
    int index = 0;
    int arr[150];
    std::ifstream inStream;
    //Open txt file
    inStream.open("A1input.txt");
    //Check if file is opened
    if (!inStream.good()) {
        std::cout << "Could not open file.";
        return -1;
    }
    //declare variables to load array
    int element;
    std::string inLine;
    //Loop through text file line by line
    while (getline(inStream, inLine)) {
        //Convert line to stringstream
        std::istringstream inSS(inLine);
        //Loop through stringstring and load array element by element
        while (inSS >> element) {
            arr[index] = element;
            index++; //After loop index should = size of array
        }
    }
    inStream.close();
    menu(arr, index);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
