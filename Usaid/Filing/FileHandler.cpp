#include "FileHandler.h"
#include <sys/stat.h>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

bool FileHandler::fileExists(const string& filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}

bool FileHandler::createFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error creating file: " << filename << endl;
        return false;
    }
    file.close();
    return true;
}

vector<string> FileHandler::readAllLines(const string& filename) {
    vector<string> lines;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error opening file for reading: " << filename << endl;
        return lines;
    }
    
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }
    
    file.close();
    return lines;
}

bool FileHandler::writeLine(const string& filename, const string& line) {
    ofstream file(filename, ios::out | ios::trunc);
    if (!file.is_open()) {
        cerr << "Error opening file for writing: " << filename << endl;
        return false;
    }
    
    file << line << endl;
    file.close();
    return true;
}

bool FileHandler::appendLine(const string& filename, const string& line) {
    ofstream file(filename, ios::out | ios::app);
    if (!file.is_open()) {
        cerr << "Error opening file for appending: " << filename << endl;
        return false;
    }
    
    file << line << endl;
    file.close();
    return true;
}

bool FileHandler::removeLine(const string& filename, const string& lineToRemove) {
    vector<string> lines = readAllLines(filename);
    bool found = false;
    
    for (auto it = lines.begin(); it != lines.end(); ) {
        if (*it == lineToRemove) {
            it = lines.erase(it);
            found = true;
        } else {
            ++it;
        }
    }
    
    if (!found) {
        return false;
    }
    
    ofstream file(filename, ios::out | ios::trunc);
    if (!file.is_open()) {
        cerr << "Error opening file for updating: " << filename << endl;
        return false;
    }
    
    for (const string& line : lines) {
        file << line << endl;
    }
    
    file.close();
    return true;
}

bool FileHandler::createBackup(const string& sourceFile, const string& backupDir) {
    if (!fileExists(sourceFile)) {
        cerr << "Source file doesn't exist for backup: " << sourceFile << endl;
        return false;
    }
    
    // Create backup directory if it doesn't exist
    if (!fileExists(backupDir)) {
#ifdef _WIN32
        mkdir(backupDir.c_str());
#else
        mkdir(backupDir.c_str(), 0777);
#endif
    }
    
    // Generate timestamp for backup filename
    time_t now = time(0);
    tm* ltm = localtime(&now);
    stringstream ss;
    ss << backupDir << "backup_"
       << 1900 + ltm->tm_year << "_"
       << setw(2) << setfill('0') << 1 + ltm->tm_mon << "_"
       << setw(2) << setfill('0') << ltm->tm_mday << "_"
       << setw(2) << setfill('0') << ltm->tm_hour << "_"
       << setw(2) << setfill('0') << ltm->tm_min << "_"
       << setw(2) << setfill('0') << ltm->tm_sec << "_"
       << sourceFile.substr(sourceFile.find_last_of("/\\") + 1);
    
    string backupFile = ss.str();
    
    ifstream src(sourceFile, ios::binary);
    ofstream dst(backupFile, ios::binary);
    
    if (!src.is_open() || !dst.is_open()) {
        cerr << "Error creating backup from " << sourceFile << " to " << backupFile << endl;
        return false;
    }
    
    dst << src.rdbuf();
    
    src.close();
    dst.close();
    
    return true;
}
