#if !defined(ANAGRAM_H)
#define ANAGRAM_H
#include <string>
#include <vector>

class anagram
{
private:
    std::string sourceStr;
public:
    anagram() = delete;
    anagram(std::string input);
    std::vector<std::string> matches(std::vector<std::string> inputList);
};

#endif // ANAGRAM_H
