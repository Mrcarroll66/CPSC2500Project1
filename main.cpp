/**
 * @file CPSC2500Project1/main.cpp
 * Driver file for CreditCard class; algorithm to check credit card numbers
 * @author Michael Carroll
 * @date September 2021
*/

#include <iostream>
#include "CreditCard.h"

/**
 * Return a value to determine whether the user input is of correct type
 * @param cardNum
 * @param cardArray
 * @return 0, 1, or 2
 */
int TestNumber(string cardNum, int cardArray[]);

int main() {
    string num = ""; // stores user input
    int testVal; // for error checking
    const int totalNum = 16; // size for array outside of class
    int cardArray[totalNum]; // array fto process user input outside class
    CreditCard newCard; // create newCard class
    while (true) {
        while (true) {
            /** repeat steps to continue receiving input
             * until the user only enters numbers and/or dashes/spaces
             * and is 16 digits
             */
            cout << "Enter a credit card number or exit: ";
            //collect input
            getline(cin, num);
            if (num == "exit") {
                exit(EXIT_SUCCESS);
            }
            //run function to check input
            testVal = TestNumber(num, cardArray);
            //print message if incorrect input
            if (testVal == 1) {
                cout << "Card numbers only contain numbers, dashes, and spaces.\n";
            } else if (testVal == 2) {
                cout << "This algorithm only evaluates 16 digit numbers.\n";
            } else {
                //breaks out of first while if number is entered correctly
                break;
            }
        }

        //set the array in the class to the user's input
        newCard.setArray(cardArray);
        //run algorithm
        if (newCard.luhnAlgorithm()) {
            cout << newCard.toString() << endl;
            cout << "This card number is valid.\n";
        } else {
            cout << newCard.toString() << endl;
            cout << "This card number is invalid.\n";
        }
    }
}

//definition of TestNumber funtion
int TestNumber(string cardNum, int cardArray[]){
    int size = cardNum.length(); //length of input
    int i = 0; // for use in loop control
    //used a while because I don't want i to increment every iteration of the loop
    while (i < size) {
        if (isdigit(cardNum[i])) {
            cardArray[i] = cardNum[i] -'0';
            i++;
        }
        else if(cardNum.compare(i, 1, "-") == 0 || cardNum.compare(i, 1, " ") == 0 ) {
            cardNum.erase(i, 1);
            size --;
        }
        else {
            //this will return if there are other characters in the input
            return 1;
        }
    }
    //check size
    if (size != 16) {
        return 2;
    }
    else {
        return 0;
    }
}


