#include "bob.h"
#include <map>

namespace bob {

enum class request:uint8_t {
    statement,
    question,
    yelling,
    yellingQuestion,
    silence,
};

std::map<request, std::string> responseMatch = {
    {request::statement, "Whatever."},
    {request::question, "Sure."},
    {request::yelling, "Whoa, chill out!"},
    {request::yellingQuestion, "Calm down, I know what I'm doing!"},
    {request::silence,"Fine. Be that way!"}
};


std::string hey(const std::string &conversation)
{
    request requestType = request::silence;
    
    //Find if there are yelling or not.
     find_if(conversation.begin(), conversation.end(),[&](const char &c)
             {
                if(isalnum(c))
                {
                    if(isupper(c))
                    {
                        requestType  = request::yelling;
                    }
                    if(requestType != request::yelling)
                    {
                        if(isnumber(c))
                            requestType = request::statement;
                    }
    
                    if (islower(c))
                    {
                        requestType = request::statement;
                        return true; //Not Yelling
                    }
                }
                return false;
    });
    
    //Find if there is a valid question
    auto found = conversation.find_last_of('?');
    if(found != std::string::npos)
    {
        auto questionStr = conversation.substr(found,conversation.size());
        auto it = find_if(questionStr.begin(),questionStr.end(),[](const char &c){
            if(isalnum(c))
               return true;
            return false;
        });
        if(it == questionStr.end())
        {
            if(requestType == request::yelling)
                requestType = request::yellingQuestion;
            else
                requestType = request::question;
        }
    }
    
    return responseMatch[requestType];
}

}  // namespace bob
