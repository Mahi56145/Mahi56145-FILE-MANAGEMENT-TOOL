// filepath: file-management-tool/src/file_manager.cpp
#include "file_manager.h"
#include <fstream>
#include <sstream>

std::string FileManager::readFile(const std::string& filePath) {
    std::ifstream file(filePath);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void FileManager::writeFile(const std::string& filePath, const std::string& content) {
    std::ofstream file(filePath);
    file << content;
}

void FileManager::appendToFile(const std::string& filePath, const std::string& content) {
    std::ofstream file(filePath, std::ios_base::app);
    file << content;
}