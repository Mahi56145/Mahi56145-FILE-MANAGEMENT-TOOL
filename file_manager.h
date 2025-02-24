// filepath: file-management-tool/src/file_manager.h
#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>

class FileManager {
public:
    static std::string readFile(const std::string& filePath);
    static void writeFile(const std::string& filePath, const std::string& content);
    static void appendToFile(const std::string& filePath, const std::string& content);
};

#endif // FILE_MANAGER_H