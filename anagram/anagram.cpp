#include "anagram.h"
#include <iostream>
#include <algorithm>

anagram::anagram(std::string input)
{
    sourceStr = input;
    std::transform(sourceStr.begin(), sourceStr.end(), sourceStr.begin(), ::tolower);
    
}
std::vector<std::string> anagram::matches(std::vector<std::string> inputList)
{
    std::vector<std::string> result;
    auto anagramCheck = [&](const std::string &str) {
        
        if(str.length() == sourceStr.length())
        {
            std::string tempOut = str;
            //Change the case before compare
            std::transform(tempOut.begin(), tempOut.end(), tempOut.begin(), ::tolower);
            //Same strings can't be anagram of each other
            if(tempOut != sourceStr)
            {
                if(std::is_permutation(tempOut.begin(), tempOut.end(), sourceStr.begin()))
                {
                    result.push_back(str);
                }
            }
        }
    };
    
    for_each(inputList.begin(), inputList.end(),anagramCheck);
    return result;
}  // namespace anagram
