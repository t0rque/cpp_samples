#include "hamming.h"

#include <stdexcept>
#include <iostream>
namespace hamming {

unsigned int compute(const std::string &s1, const std::string&s2)
{
    if (s1.length() != s2.length())
        throw std::domain_error("length mismatch");
    std::cout << s1 << s2 << std::endl;
    if(s1 != s2)
    {
        unsigned int j = 0;
        unsigned int count = 0;
        for_each(s1.begin(),s1.end(),[&](const char &c){
            if(s2[j] != c)
                count++;
            j++;
        }
        );
        return count;
    }
    else
        return 0;
}

}  // namespace hamming
    
