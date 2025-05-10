#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>

#include "TerminalControl.h"
using namespace std;

void printProjectTitle()
{
    cout << COLOR_MAGENTA << "\n"
         << "\t\t\t\t __      __  _     _      _        _____            _        _    _____           _                 \n"
         << "\t\t\t\t \\ \\    / / | |   (_)    | |      |  __ \\          | |      | |  / ____|         | |                \n"
         << "\t\t\t\t  \\ \\  / /__| |__  _  ___| | ___  | |__) |___ _ __ | |_ __ _| | | (___  _   _ ___| |_ ___ _ __ ___  \n"
         << "\t\t\t\t   \\ \\/ / _ \\ '_ \\| |/ __| |/ _ \\ |  _  // _ \\ '_ \\| __/ _` | |  \\___ \\| | | / __| __/ _ \\ '_ ` _ \\ \n"
         << "\t\t\t\t    \\  /  __/ | | | | (__| |  __/ | | \\ \\  __/ | | | || (_| | |  ____) | |_| \\__ \\ ||  __/ | | | | |\n"
         << "\t\t\t\t     \\/ \\___|_| |_|_|\\___|_|\\___| |_|  \\_\\___|_| |_|\\__\\__,_|_| |_____/ \\__, |___/\\__\\___|_| |_| |_|\n"
         << "\t\t\t\t                                                                         __/ |                      \n"
         << "\t\t\t\t                                                                        |___/                       \n"
         << "\n" << COLOR_RESET;
}

void printFormattedText(const string &text, const string &color, bool isCenter)
{
    int paddingBefore = isCenter ? (getScreenWidth() - text.length()) / 2 : 0;
    int paddingAfter = getScreenWidth() - (text.length() + paddingBefore);

    string lineToBePrinted = string(COLOR_CYAN) + "|" + COLOR_RESET + string(paddingBefore, ' ') + color + text + COLOR_RESET + string(paddingAfter, ' ') + COLOR_CYAN + "|" + COLOR_RESET;

    cout << lineToBePrinted << endl;
}

void printLineWithDashes()
{
    cout << COLOR_CYAN << "+" << string(getScreenWidth(), '-') << "+" << COLOR_RESET << endl;
}

void printLineWithSpaces()
{
    cout << COLOR_CYAN << "|" << string(getScreenWidth(), ' ') << "|" << COLOR_RESET << endl;
}

void printInputPrompt() 
{
    cout << COLOR_CYAN << "| >> " << COLOR_RESET;
}

int getScreenWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left - 2; // Returns the width of the console terminal
}

void maskCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // Obtain the console's output handle
    CONSOLE_CURSOR_INFO cursorInfo;                         // Declare a structure to hold cursor info
    cursorInfo.dwSize = 100;                                // Set the cursor size to a maximum value (invisible cursor)
    cursorInfo.bVisible = FALSE;                            // Make the cursor invisible
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);       // Apply the changes to the console
}

bool isEmailValid(const string &email)
{
    // Ensure that the email does not contain any spaces
    if (email.find(' ') != string::npos)
    {
        return false;
    }

    size_t atPos = email.find('@');
    size_t dotPos = email.find('.', atPos);

    // Ensure that both '@' and '.' are present
    if (atPos == string::npos || dotPos == string::npos)
    {
        return false;
    }

    // Ensure that '@' is not at the start, there is atleast one character between '@' and the following '.' and atleast 2 characters are present after the last occuring '.'
    if (atPos == 0 || dotPos - atPos <= 1 || dotPos + 2 >= email.length())
    {
        return false;
    }

    // Ensure that '@' does not appear more than once
    if (email.find('@', atPos + 1) != string::npos)
    {
        return false;
    }

    return true;
}

string maskedPassword()
{
    string NewPassword = "";
    char ch;

    while ((ch = _getch()) != '\r')
    {
        if (ch == '\b')
        {
            if (!NewPassword.empty())
            {
                cout << "\b \b";
                NewPassword.pop_back();
            }
        }
        else
        {
            cout << '*';
            NewPassword += ch;
        }
    }
    return NewPassword;
}

string lowercaseString(const string& input) 
{
    string result;
    for (char ch : input) 
    {
        if (isalpha(ch)) 
        {
            result += tolower(ch);
        } 
        else 
        {
            result += ch;
        }
    }
    return result;
}

string toTwoDecimalString(double value) 
{
    stringstream ss;
    ss << fixed << setprecision(2) << value;
    return ss.str();
}