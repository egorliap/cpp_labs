#include "wrapper.h"
#include <vector>
#include <functional>
#include <string>
#include <iostream>
#include <algorithm>

std::string Wrapper::execute(const ArgsMap& args_map) {
    if (args_map.size() != argsTitles.size()) {
        std::cerr << "Wrong number of arguments. Expected: " << argsTitles.size() 
                  << ", but got: " << args_map.size() << std::endl;
        return "";
    }

    std::vector<std::string> argsFunc;
    for (const auto& title : argsTitles) {
        auto it = std::find_if(args_map.begin(), args_map.end(), [&title](const auto& pair) {
            return pair.first == title;
        });
        if (it == args_map.end()) {
            std::cerr << "Missing argument: " << title << std::endl;
            return "";
        }
        argsFunc.emplace_back(it->second);
    }

    try {
        return function(argsFunc);
    } catch (const std::exception& ex) {
        std::cerr << "Exception during function execution: " << ex.what() << std::endl;
        return "";
    } catch (...) {
        std::cerr << "Unknown error during function execution." << std::endl;
        return "";
    }
}