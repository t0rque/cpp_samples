#include "reverse_string.h"
#include <string>
#include <iostream>
#include <algorithm>
namespace reverse_string {
std::string reverse_string(const std::string& input)
{
    std::string retVal;
    for_each(input.rbegin(), input.rend(),
        [&](const char &c)
             {
                retVal.push_back(c);
            });
    std::cout << retVal<< std::endl;

    return retVal;
}
}  // namespace reverse_string
