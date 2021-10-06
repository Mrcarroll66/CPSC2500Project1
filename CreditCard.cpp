/**
 * @file CPSC2500Project1/CreditCard.cpp
 * Implementation file for CreditCard class
 * @author Michael Carroll
 * @date September 2021
*/

#include "CreditCard.h"

//default constructor
CreditCard::CreditCard() = default;

//performs the Luhn algorithm on the number
bool CreditCard::luhnAlgorithm() {

    int num1; //stores 1st digit
    int num2; //stores 2nd digit
    int total = 0; //stores total

    //work from right to left
    for (int i = SIZE-1; i >= 0; i--) {
        if (i % 2 == 0) {
            //multiply by 2
            numArray[i] = numArray[i] * 2;
            //split 2 digit numbers
            num1 = numArray[i] / 10;
            num2 = numArray[i] % 10;
            //add to total
            total += num1;
            total += num2;
            //divide by 2 to preserve original number
            numArray[i] = numArray[i] / 2;
        }
        else {
            //add to total
            total += numArray[i];
        }
    }

    //if multiple of 10 return true
    if (total % 10 == 0) {
        return true;
    }
    else {
        return false;
    }
}

//Setter for array
void CreditCard::setArray(const int newNumber[]) {
    for (int i = 0; i < SIZE; i++) {
        numArray[i] = newNumber[i];
    }
}

//toString method returns the correctly formatted string
string CreditCard::toString() {
    string newString;
    //place a - every 4th number in the string and return
    for (int i = 0; i < SIZE; i++) {
        if (i == 4 || i == 8 || i == 12) {
            newString += "-" + to_string(numArray[i]);
        }
        else {
            newString += to_string(numArray[i]);
        }
    }
    return newString;
}
