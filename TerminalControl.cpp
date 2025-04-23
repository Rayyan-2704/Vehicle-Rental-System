#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <conio.h>

#include "TerminalControl.h"
using namespace std;

void printProjectTitle()
{
    cout << "\n"
         << "\t\t\t\t __      __  _     _      _        _____            _        _    _____           _                 \n"
         << "\t\t\t\t \\ \\    / / | |   (_)    | |      |  __ \\          | |      | |  / ____|         | |                \n"
         << "\t\t\t\t  \\ \\  / /__| |__  _  ___| | ___  | |__) |___ _ __ | |_ __ _| | | (___  _   _ ___| |_ ___ _ __ ___  \n"
         << "\t\t\t\t   \\ \\/ / _ \\ '_ \\| |/ __| |/ _ \\ |  _  // _ \\ '_ \\| __/ _` | |  \\___ \\| | | / __| __/ _ \\ '_ ` _ \\ \n"
         << "\t\t\t\t    \\  /  __/ | | | | (__| |  __/ | | \\ \\  __/ | | | || (_| | |  ____) | |_| \\__ \\ ||  __/ | | | | |\n"
         << "\t\t\t\t     \\/ \\___|_| |_|_|\\___|_|\\___| |_|  \\_\\___|_| |_|\\__\\__,_|_| |_____/ \\__, |___/\\__\\___|_| |_| |_|\n"
         << "\t\t\t\t                                                                         __/ |                      \n"
         << "\t\t\t\t                                                                        |___/                       \n"
         << "\n";
}

ostream &printFormattedText(const string &text, const string &color, bool isCenter)
{
    int paddingBefore = isCenter ? (getScreenWidth() - text.length()) / 2 : 0;
    int paddingAfter = getScreenWidth() - (text.length() + paddingBefore);

    string lineToBePrinted = string(COLOR_CYAN) + "|" + COLOR_RESET + string(paddingBefore, ' ') + color + text + COLOR_RESET + string(paddingAfter, ' ') + COLOR_CYAN + "|" + COLOR_RESET;

    cout << lineToBePrinted << endl;
    return cout;
}

ostream &printLineWithDashes(const string &color)
{
    cout << color << "+" << string(getScreenWidth(), '-') << "+" << COLOR_RESET << endl;
    return cout;
}

ostream &printLineWithSpaces(const string &color)
{
    cout << color << "+" << string(getScreenWidth(), ' ') << "+" << COLOR_RESET << endl;
    return cout;
}

int getScreenWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1; // Returns the width of the console terminal
}

void maskCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // Obtain the console's output handle
    CONSOLE_CURSOR_INFO cursorInfo;                         // Declare a structure to hold cursor info
    cursorInfo.dwSize = 100;                                // Set the cursor size to a maximum value (invisible cursor)
    cursorInfo.bVisible = FALSE;                            // Make the cursor invisible
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);       // Apply the changes to the console
}