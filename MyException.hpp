//
// Created by Victor Debray on 2018-12-01.
//

#ifndef COMP472_MINIPROJECT3_MYEXCEPTION_HPP
# define COMP472_MINIPROJECT3_MYEXCEPTION_HPP

# include <exception>
#include <string>

class MyException : std::exception {
 public:
  MyException(std::string const& e) noexcept;
  ~MyException() noexcept override = default;
  const char *what() const noexcept override;

 private:
  std::runtime_error _e;
};

#endif //COMP472_MINIPROJECT3_MYEXCEPTION_HPP
