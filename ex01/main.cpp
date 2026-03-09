#include <iostream>
#include "iter.hpp"

// Test function 1: Displays the element
template <typename T>
void displayElement(T &element)
{
	std::cout << element << std::endl;
}

// Test function 2: Changes the element to 42 [cite: 82-86]
template <typename T>
void makeFortyTwo(T &element)
{
	element = 42;
}

int main()
{
	int intArray[] = {0, 1, 2, 3, 4};
	std::size_t len = 5;

	std::cout << "--- Initial Array ---" << std::endl;
	iter(intArray, len, displayElement<int>);

	std::cout << "--- Applying 'makeFortyTwo' ---" << std::endl;
	iter(intArray, len, makeFortyTwo<int>);

	std::cout << "--- Final Array ---" << std::endl;
	iter(intArray, len, displayElement<int>);

	return 0;
}
