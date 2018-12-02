#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <sys/stat.h>
# include <map>
# include "LanguageModel.hpp"

bool fileExists(std::string const &path);

using LMMap = std::map<std::string, LanguageModel>;

#endif