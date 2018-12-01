//
// Created by Victor Debray on 2018-12-01.
//

#include "MyException.hpp"

MyException::MyException(std::string const &e) noexcept : _e(e.c_str()) {}

const char *MyException::what() const noexcept {
  return _e.what();
}
