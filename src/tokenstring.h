#ifndef token_string
#define token_string
#include "tokenword.h"
#include <queue>
namespace calc_token
{
    enum token_string_status
    {
        unprepared,
        prepared,
        reading,
        calculating,
        errfound,
    };
    template <class NumType, class StringType>
    class TokenString
    {
    public:
        unsigned short status;
        queue<TokenWord<class NumType, class StringType>> tokens;
        TokenWord<class NumType, class StringType> now;
        TokenString();
        bool readin(StringType text);
    };
} // namespace calc_token
#endif