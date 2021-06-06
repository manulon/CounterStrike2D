#include "Exception.h"
#include <cstdarg>

Exception::Exception(const char *format, ...) noexcept {
    va_list args;
    va_list argsCopy;
    va_start(args, format);
    va_start(argsCopy, format);

    int bufferSize = (std::vsnprintf(nullptr, 0, format, args) + 1);
    msgError.reserve(bufferSize);
    std::vsnprintf(&msgError.front(), bufferSize, format, argsCopy);
    va_end(argsCopy);
    va_end(args);
}

Exception::~Exception() { }

const char* Exception::what() const noexcept {
    return msgError.c_str();
}
