#ifndef token_string
#define token_string
enum token_type_id{
	brackets=100,
	left_parenthes=101,right_parenthes=102,
	left_bracket=103,right_bracket=104,
	left_brace=105,right_brace=106,
	operators=200,
	addition=201,subtraction=202,
	multiplication=203,division=204,
	modulation=204,power=205,
	bit_and=206,bit_or=207,
	bit_nand=208,bit_nor=209,
	bit_xor=210,bit_xnor=211,
	functions=300,
	numbers=400,
	variables=500,
};
namespace calc_token
{
	template <class NumType, class StringType>
	class TokenWord
	{
	private:
		//static StringType names[];
	public:
		unsigned_short type_id, id_detail;
		NumType *number;
		TokenWord();
		TokenWord(const StringType text)constexpr;
		TokenWord(TokenWord &another);
		bool readin(StringType text);
		StringType to_string();
		bool isnum();
		bool isvar();
	}
}

#endif
