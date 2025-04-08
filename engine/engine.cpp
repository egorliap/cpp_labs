#include "wrapper.h"
#include "engine.h"
#include <iostream>
#include <map>
bool Engine::register_command(Wrapper* wrapper, const std::string& command_name) {
    if (!wrapper) {
        std::cerr << "Invalid wrapper provided for command: " << command_name << std::endl;
        return false;
    }
    auto result = wrappers.emplace(command_name, wrapper);
    if (!result.second) {
        std::cerr << "Command is already registered: " << command_name << std::endl;
        return false;
    }
    return true;
}


std::string Engine::execute(const std::string& command_name, const ArgsMap& args_map) {
    auto it = wrappers.find(command_name);
    if (it != wrappers.end()) {
        return it->second->execute(args_map);
    } else {
        std::cerr << "Command was not registered: " << command_name << std::endl;
        return "";
    }
}