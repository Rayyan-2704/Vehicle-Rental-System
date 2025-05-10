#ifndef TERMINALCONTROL_H
#define TERMINALCONTROL_H

#include <iostream>
using namespace std;

#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_WHITE   "\033[37m"
#define COLOR_BOLD    "\033[1m"
#define BG_CYAN       "\033[46m"
#define BG_GREEN      "\033[42m"

void printProjectTitle();

/* Prints the formatted text */
ostream &printFormattedText(const string &text, const string &color, bool isCenter);

/* Prints line with dashes */
ostream &printLineWithDashes();

/* Prints line with spaces */
ostream &printLineWithSpaces();

/* Prints the input prompt */
void printInputPrompt();

/* Gets the width of the screen */
int getScreenWidth();

/* Hides the cursor on the terminal */
void maskCursor();

/* Verification of Email: Global function */
bool isEmailValid(const string &email);

/* Ensuring that when password is entered onto the console, it is masked by asterisks '*' */
string maskedPassword();

/* Converting the string to lowercase */
string lowercaseString(const string& input);

/* To convert non-string values to a 2-decimal places string */
string toTwoDecimalString(double value);

#endif