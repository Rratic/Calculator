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
    template <class NumType>
    class TokenString
    {
    public:
        unsigned short status;
        queue<TokenWord<class NumType>> tokens;
        TokenWord<class NumType> now;
        TokenString();
        bool readin(string text);
    };
} // namespace calc_token
#endif