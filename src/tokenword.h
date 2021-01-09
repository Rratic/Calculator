#ifndef token_word
#define token_word
#include <string>
using std::string;

namespace calc_token {
	enum token_error {
		VoidToken,
		NumberGrammarError,	 //0.
		TooSmallBase,
		TooBigBase,	 //base>16
	};
	enum token_type_id {
		not_yet = 0,
		brackets = 1,
		left_parenthes = 101,
		right_parenthes,
		left_bracket,
		right_bracket,
		left_brace,
		right_brace,
		operators = 2,
		o_add = 201,
		o_sub,
		o_mul,
		o_div,
		o_mod,
		o_pow,
		//+-*/%^
		o_abs,
		//|
		functions = 3,
		f_normal = 301,
		f_user,
		f_convert,
		f_to_int,
		f_decide,
		f_bool,
		f_simple,
		f_exp,
		f_log,
		f_tri,
		f_hyp,
		f_atri,
		f_ahyp,
		f_number_theory,
		f_if_else,
		f_rand,
		numbers = 4,
		n_normal = 401,
		n_inf,
		n_nan,	//may be used
		variables = 5,
		v_normal = 501,
		v_user,
		v_pi,
		v_e,
	};
	template <class NumType>
	class TokenWord {
	  private:
		static string s_brackets[];
		static string s_operators[];
		static string s_f_normal[];
		static string s_f_tri[];
		//static data,provides in-class models
	  public:
		unsigned short type_id, id_detail;
		NumType number;
		TokenWord();
		//constexpr TokenWord(const string text);
		//TokenWord(TokenWord &another);
		//~TokenWord();//3-5-0 principle
		bool token_is_bracket(string text);
		bool token_is_operator(string text);
		bool token_is_function(string text);
		void readin_number(string text, unsigned short base);
		bool readtoken(string text, unsigned short base);
		string to_string();
	};
}  // namespace calc_token

#endif
