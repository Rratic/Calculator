#include "tokenword.h"
using calc_token::token_type_id;
using calc_token::TokenWord;
template <class NumType, class StringType>
calc_token::TokenWord<NumType, StringType>::TokenWord()
{
    type_id = 0;
    id_detail = 0;
    number = NumType(0);
}