#include "isogram.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <locale>
namespace isogram {

bool is_isogram(const std::string& str)
{
    std::list<char>parsed  = {};
    for (const char letter : str)
    {
        if (' ' == letter  || '-' == letter)
            continue;
        const char normalized = std::tolower(letter, std::locale());
        if(std::find(parsed.begin(),parsed.end(),normalized) != parsed.end())
        {
            std::cout <<  str << " is Not Isogram "  << std::endl;
            return false;
        }
        parsed.push_back(normalized);
    }
    std::cout <<  str << " is Isogram" << std::endl;
	return true;
}
}  // namespace isogram
