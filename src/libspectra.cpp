#include "../include/libspectra.h"

std::unordered_map<std::string, Spectra::FuncType>& Spectra::getFunctionMap() {
    static std::unordered_map<std::string, FuncType> functionMap;
    return functionMap;
}

void Spectra::registerFunction(const std::string& name, FuncType func) {
    getFunctionMap()[name] = func;
}

void Spectra::invoke(const std::string& name) {
    auto it = getFunctionMap().find(name);
    if (it != getFunctionMap().end()) {
        it->second();
    } else {
        throw std::runtime_error("Function not found: " + name);
    }
}