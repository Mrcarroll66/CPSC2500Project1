/**
 * @file CPSC2500Project1/CreditCard.h
 * header file for CreditCard class
 * @author Michael Carroll
 * @date September 2021
*/

#ifndef PROJECT1_V0_1_CREDITCARD_H
#define PROJECT1_V0_1_CREDITCARD_H
#include <iostream>
using namespace std;

class CreditCard {
private:
    static const int SIZE = 16; //size of array
    int numArray[SIZE]; // int array to store the credit card numbers

public:
    /**
     * default constructor
     */
    CreditCard();

    /**
    * Performs the luhn algorithm on the number
    * @param none
    * @return true or false if it is a valid number
    */
    bool luhnAlgorithm();

    /**
     * Setter for the array
     * @param newNumber for the array
     */
    void setArray (const int newNumber[]);

    /**
    * print the working number
    * @param none
    * @return the entire contents of the array as a single string
    */
    string toString();
};


#endif //PROJECT1_V0_1_CREDITCARD_H