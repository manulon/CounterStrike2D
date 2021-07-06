#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <exception>
#include <string>

class Exception : public std::exception {
   private:
      std::string msgError;

   public:
      explicit Exception(const char *format, ...) noexcept;
      virtual const char* what() const noexcept;
      virtual ~Exception() noexcept;
};

#endif  // _EXCEPTION_H_
