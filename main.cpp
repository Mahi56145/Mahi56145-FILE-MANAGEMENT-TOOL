#include <iostream>
#include "file_manager.h"
#include "../include/httplib.h"

int main() {
    httplib::Server svr;

    // Middleware to add CORS headers to all responses
    svr.set_pre_routing_handler([](const httplib::Request &req, httplib::Response &res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
        res.set_header("Access-Control-Allow-Headers", "Content-Type");
        return httplib::Server::HandlerResponse::Unhandled;
    });

    // Serve static files
    svr.set_base_dir("../src/frontend");

    // Endpoint to read a file
    svr.Get("/read", [](const httplib::Request& req, httplib::Response& res) {
        auto filePath = req.get_param_value("file");
        auto content = FileManager::readFile(filePath);
        res.set_content(content, "text/plain; charset=utf-8");
    });

    // Endpoint to write to a file
    svr.Post("/write", [](const httplib::Request& req, httplib::Response& res) {
        auto filePath = req.get_param_value("file");
        auto content = req.body;
        FileManager::writeFile(filePath, content);
        res.set_content("File written successfully", "text/plain; charset=utf-8");
    });

    // Endpoint to append to a file
    svr.Post("/append", [](const httplib::Request& req, httplib::Response& res) {
        auto filePath = req.get_param_value("file");
        auto content = req.body;
        FileManager::appendToFile(filePath, content);
        res.set_content("File appended successfully", "text/plain; charset=utf-8");
    });

    std::cout << "Server started at http://localhost:8080" << std::endl;
    svr.listen("localhost", 8080);

    return 0;
}