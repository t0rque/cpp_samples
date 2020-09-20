#include "leap.h"

namespace leap {
bool is_leap_year(unsigned int year)
{
    if(((year %4) != 0) || (((year %100) == 0) && ((year % 400) != 0)))
    {
        return false;
    }
    return true;
}
}  // namespace leap
