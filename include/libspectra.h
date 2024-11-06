#ifndef LIBSPECTRA_H
#define LIBSPECTRA_H

#include <functional>
#include <string>
#include <unordered_map>
#include <stdexcept>

class Spectra {
public:
    using FuncType = std::function<void()>;

    static void registerFunction(const std::string& name, FuncType func);

    static void invoke(const std::string& name);

private:
    static std::unordered_map<std::string, FuncType>& getFunctionMap();
};

#endif // LIBSPECTRA_H