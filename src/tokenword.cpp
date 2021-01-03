#include "tokenword.h"
/*TEMPLATE ZONE*/
template <class NumType>
calc_token::TokenWord<NumType>::s_brackets[7] = {"", "(", ")", "[", "]", "{", "}"}

template <class NumType>
calc_token::TokenWord<NumType>::s_operators[7] = {"", "+", "-", "*", "/", "%", "^"}

template <class NumType>
calc_token::TokenWord<NumType>::s_f_normal[] = {"", "abs", "sqr", "cube", "sign", "fade", "pow", "mode", "sqrt", "cbrt", "xroot", "oppo", "remainder"}

template <class NumType>
calc_token::TokenWord<NumType>::TokenWord()
{
	type_id = not_yet;
	id_detail = 0;
	number = NumType(0);
}
template <class NumType>
bool calc_token::TokenWord<NumType>::token_is_bracket(string text)
{
	for (unsigned short po = 1; po <= 6; po++)
	{
		if (s_brackets[po] == text)
		{
			type_id = 100 * brackets + po;
			return true;
		}
	}
	return false;
}
template <class NumType>
bool calc_token::TokenWord<NumType>::token_is_operator(string text)
{
	for (unsigned short po = 1; po <= 6; po++)
	{
		if (s_operators[po] == text)
		{
			type_id = 100 * operators + po;
			return true;
		}
	}
	return false;
}

/*LONG DOUBLE ZONE*/
void calc_token::TokenWord<long double>::readin_number(string text, unsigned short base)
{
	if (base < 2)throw TooSmallBase;
	if (base > 16)throw TooBigBase;
	unsigned short po = 0, len = text.length();
	if (len == 0)
		throw VoidToken;
	type_id = n_normal;
	number = 0;
	long double ibase = base;
	bool flag = false;
	if (text[po] == '-')
	{
		flag = true;
		po++;
	}
	while (po != len)
	{
		if (text[po] < '0' || text[po] > base - 1 + '0')break;
		number = number * base + (text[po] - '0');
		po++;
	}
	if (po != len)
	{
		if (text[po] == '.')po++;
		if (po == len)throw NumberGrammarError;
		while (po != len)
		{
			number = number + (text[po] - '0') / ibase;
			ibase *= base;
			po++;
		}
	}
	if (flag)number = -number;
}
/*INTEGAR ZONE*/
void calc_token::TokenWord<long long>::readin_number(string text, unsigned short base)
{
	if (base < 2)throw TooSmallBase;
	if (base > 16)throw TooBigBase;
	unsigned short po = 0, len = text.length();
	if (len == 0)throw VoidToken;
	type_id = n_normal;
	number = 0;
	long long ibase = base;
	bool flag = false;
	if (text[po] == '-')
	{
		flag = true;
		po++;
	}
	while (po != len)
	{
		if (text[po] < '0' || text[po] > base - 1 + '0')break;
		number = number * base + (text[po] - '0');
		po++;
	}
	if (flag)number = -number;
}