#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class FileHandler {
public:
    // Generic file operations
    static bool fileExists(const string& filename);
    static bool createFile(const string& filename);
    
    // Data operations
    static vector<string> readAllLines(const string& filename);
    static bool writeLine(const string& filename, const string& line);
    static bool appendLine(const string& filename, const string& line);
    static bool removeLine(const string& filename, const string& line);
    
    // Backup operations
    static bool createBackup(const string& sourceFile, const string& backupDir = "backups/");
};

#endif
