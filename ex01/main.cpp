/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tszymans <tszymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:28:13 by tszymans          #+#    #+#             */
/*   Updated: 2026/03/10 20:24:51 by tszymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

// Test function 1: Displays Elements
template <typename T>
void displayElement(T &element)
{
	std::cout << element << " ";
}

// Test function 2: Changes the element to 42 [cite: 82-86]
template <typename T>
void makeFortyTwo(T &element)
{
	element = 42;
}

// Test function 3: Displays Ints
template <typename T>
void displayInt(int i)
{
	std::cout << i << " ";
}

// Test function 4: Displays Chars
template <typename T>
void displayChar(char c)
{
	std::cout << c << " ";
}

// Test function 5 Template function - takes argument by const reference
template <typename T>
void printElement(const T& element)
{
    std::cout << element << " ";
}

// Test function 6 Template function - takes argument by non-const reference and modifies it
template <typename T>
void incrementElement(T& element)
{
    element++;
}

// Test function 7 Function that takes const reference (read-only)
void printConstString(const std::string& str)
{
    std::cout << str << " ";
}

// Test function 8 Function that takes non-const reference (can modify)
void toUpperFirstChar(std::string& str)
{
    if (!str.empty() && str[0] >= 'a' && str[0] <= 'z')
        str[0] = str[0] - 32;
}

int main()
{
	int intArray[] = {0, 1, 2, 3, 4};
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	std::size_t len = 5;

	std::cout << "\n=== Test 1 Display Elements ===" << std::endl;
	std::cout << "--- Initial Array ---" << std::endl;
	iter(intArray, len, displayElement<int>);

	std::cout << "\n=== Test 2 Apply Function ===" << std::endl;
	int fortyTwoArray[] = {10, 20, 30, 40, 50};
	std::cout << "--- Applying 'makeFortyTwo' ---" << std::endl;
	iter(fortyTwoArray, len, makeFortyTwo<int>);

	std::cout << "--- Final Array ---" << std::endl;
	iter(fortyTwoArray, len, displayElement<int>);

	std::cout << "\n=== Test 3 Display Ints ===" << std::endl;
	iter(intArray, len, displayInt<int>);

	std::cout << "\n=== Test 4 Display Chars ---" << std::endl;
	iter(charArray, len, displayChar<char>);

	std::cout << "\n=== Test 5: Template function with const reference ===" << std::endl;
	std::cout << "Integer array with template: ";
	iter(intArray, 5, printElement<int>);
	std::cout << std::endl;

	std::cout << "Character array with template: ";
	iter(charArray, 5, printElement<char>);
	std::cout << std::endl;

	double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
	std::cout << "Double array with template: ";
	iter(doubleArray, 4, printElement<double>);
	std::cout << std::endl;

	std::cout << "\n=== Test 6: Template function with non-const reference (modify) ===" << std::endl;
	int modArray[] = {10, 20, 30, 40, 50};
	std::cout << "Before increment: ";
	iter(modArray, 5, printElement<int>);
	std::cout << std::endl;

	iter(modArray, 5, incrementElement<int>);
	std::cout << "After increment:  ";
	iter(modArray, 5, printElement<int>);
	std::cout << std::endl;

	std::cout << "\n=== Test 7: String array with const and non-const ===" << std::endl;
	std::string stringArray[] = {"hello", "world", "from", "iter"};

	std::cout << "Original strings: ";
	iter(stringArray, 4, printConstString);
	std::cout << std::endl;

	iter(stringArray, 4, toUpperFirstChar);
	std::cout << "After uppercase:  ";
	iter(stringArray, 4, printConstString);
	std::cout << std::endl;

	return 0;
}
