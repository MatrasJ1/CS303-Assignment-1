#include "Functions.h"

bool isDigits(std::string str1) {
	//returns true if every character is a digit, false otherwise
	return str1.find_first_not_of("0123456789") == std::string::npos;
}

int find(int arr[], int size) {
	int val; // value to find
	std::string inVal; //string value to find for user input
	std::cout << "Enter an integer to find in the array: ";
	std::getline(std::cin, inVal); //load user input into string
	if (!isDigits(inVal)) { //check if input is numerical
		throw std::invalid_argument("Invalid value");
	}
	val = std::stoi(inVal); //convert string user input to int
	for (int i = 0; i < size; i++) { //loop through array to find if value exists
		if (arr[i] == val) {
			std::cout << "Found " << val << " at index " << i << std::endl;
			return i; //return index of found value
		}
	}
	std::cout << "Could not find index for " << val << std::endl;
	return -1; //return -1 if value not found
}

void replace(int arr[], int size) {
	int index, oldValue, newValue;
	std::string inputIndex, inputValue;
	std::cout << "Enter an index to replace: ";
	try {
		std::getline(std::cin, inputIndex); // load index string with input
		if (!isDigits(inputIndex)) { //check if index is numerical
			throw std::invalid_argument("Invalid index.");
		}
		index = std::stoi(inputIndex); //convert index to int
		if (index < 0 || index >= size) { //check if index is in range
			throw std::out_of_range("Index out of range.");
		}
		std::cout << "Enter the new value: ";
		std::getline(std::cin, inputValue); //load value string
		if (!isDigits(inputValue)) { //check if value is numerical
			throw std::invalid_argument("Invalid value.");
		}
		newValue = std::stoi(inputValue); //convert value to int
		oldValue = arr[index]; // store old value at index
		arr[index] = newValue; // change value at index to new value
		std::cout << "Old Value at index " << index << ": " << oldValue
			<< "\nNew value: " << newValue << std::endl;
	}
	catch (std::invalid_argument e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::out_of_range e) {
		std::cout << e.what() << std::endl;
	}
}

void push_back(int arr[], int& size) {
	int val;
	std::string inVal;
	std::cout << "Enter an integer to be added to the array: ";
	try {
		std::getline(std::cin, inVal); //load user input into string
		if (!isDigits(inVal)) { //check if input is numerical
			throw std::invalid_argument("Invalid value.");
		}
		val = std::stoi(inVal); //convert input to int
		if (size >= 150) { // check if array is full
			throw std::out_of_range("Array full. Could not add value.");
		}
		arr[size] = val; // assign last index of array with user input
		size++; // increase "size" or number of items in array
	}
	catch (std::invalid_argument e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::out_of_range e) {
		std::cout << e.what() << std::endl;
	}
	

}

void remove(int arr[], int& size) {
	int index, removeVal;
	std::string inputIndex; //string for user input
	std::cout << "Enter an index to remove: ";
	std::getline(std::cin, inputIndex); //load string with user input
	if (!isDigits(inputIndex)) { //check if input is numerical
		throw std::invalid_argument("Invalid index.");
	}
	index = std::stoi(inputIndex); // convert string input to int
	if (index < 0 || index >= size) { //check if index is in range
		throw std::out_of_range("Index is out of range.");
	}
	removeVal = arr[index];
	for (int i = index + 1; i < size; i++) { // shift every element above the index one down
		arr[i - 1] = arr[i];
	}
	std::cout << "Removed value " << removeVal << " at index " << index << std::endl;
	size--; // change "size" or number of items currently stored in the array
}

void menu(int arr[], int& size) {
	bool running = true;
	std::string choice;
	while (running) {
		std::cout << "a. Check index of integer"
			"\nb.Modify the value at given index"
			"\nc.Add new integer to the end of array"
			"\nd.Remove integer at given index"
			"\ne.Quit" << std::endl;
		std::cout << "Enter your choice: ";
		try {
			getline(std::cin, choice); // User input for choice
			if (choice.size() != 1 || (tolower(choice[0]) != 'a'
				&& tolower(choice[0]) != 'b'
				&& tolower(choice[0]) != 'c'
				&& tolower(choice[0]) != 'd'
				&& tolower(choice[0]) != 'e')) {
				throw std::invalid_argument("Invalid input.");
			}
		}
		catch (std::invalid_argument e) {
			bool valid = false;
			std::cout << e.what() << " Please enter a valid input." << std::endl;
			while (!valid) {
				std::cout << "Enter your choice: ";
				getline(std::cin, choice); // User input for choice
				if (choice.size() != 1 || (tolower(choice[0]) != 'a'
					&& tolower(choice[0]) != 'b'
					&& tolower(choice[0]) != 'c'
					&& tolower(choice[0]) != 'd'
					&& tolower(choice[0]) != 'e')) {
					std::cout << "Invalid input." << std::endl;
					continue;
				}
				else {
					valid = true;
					break;
				}
			}
		}
		if (tolower(choice[0]) == 'a') {
			int index = find(arr, size);
		}
		else if (tolower(choice[0]) == 'b') {
			replace(arr, size);
		}
		else if (tolower(choice[0]) == 'c') {
			push_back(arr, size);
		}
		else if (tolower(choice[0]) == 'd') {
			remove(arr, size);
		}
		else {
			break;
		}

	}
}