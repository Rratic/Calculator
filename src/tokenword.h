#ifndef token_word
#define token_word

namespace calc_token
{
	enum token_type_id
	{
		brackets = 1,
		left_parenthes = 101,
		right_parenthes,
		left_bracket,
		right_bracket,
		left_brace,
		right_brace,
		operators = 2,
		addition = 201,
		subtraction,
		multiplication,
		division,
		modulation,
		power,
		bit_and,
		bit_or,
		bit_nand,
		bit_nor,
		bit_xor,
		bit_xnor,
		functions = 3,
		f_normal = 301,
		f_user,
		f_convert,
		f_decide,
		f_bool,
		f_simple,
		f_exp,
		f_log,
		f_tri,
		f_hyp,
		f_atri,
		f_ahyp,
		numbers = 4,
		n_inf = 401,
		n_nan, //may be used
		variables = 5,
		v_user = 501,
		v_pi,
	};
	template <class NumType, class StringType>
	class TokenWord
	{
	private:
		//static StringType names[];
	public:
		unsigned short type_id, id_detail;
		NumType number;
		TokenWord();
		constexpr TokenWord(const StringType text);
		//TokenWord(TokenWord &another);
		//~TokenWord();//3-5-0 principle
		bool readin(StringType text);
		StringType to_string();
		bool isnum();
		bool isvar();
	};
} // namespace calc_token

#endif
