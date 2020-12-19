#ifndef calcdim_h
	#define calcdim_h
#include<cmath>
#include<iostream>
using namespace std;
typedef long double realn;
#define DIMENSION_NUM 8
string PutReal(realn num,unsigned short base);
const string unit[DIMENSION_NUM]={
"BUG","m","kg","s",
"A","K","mol","cd",
};
/*DimType*/
enum DimType{
	p_pure,
	p_length,p_weight,p_time,p_current,p_temperature,p_mol,p_light,
};
/*ErrType*/
enum ErrType{
	Nothing,UnknownType,
	UnknownWord,GrammerErr,
	MathErr,Inf,
	Nan,OutOfRange,
	ProBug,NoRealRoot,
	NoRoot,UnknownDim,
	DimErr,UnknownOrder,
	OrderErr,JokeErr,
};
/*Basic Vector*/
class cvector{
	private:
		bool simple_unit_output();
	public:
		realn real;
		short si[DIMENSION_NUM];
		cvector();
		cvector(realn re);
		cvector(realn re,short type);
		cvector(realn re,short di[]);
		void output();
		void output(unsigned short base);
		void output_info();
		realn data();
		bool isinf();
		bool isnan();
		bool ispure();
		friend cvector operator+(cvector left,cvector right);
		friend cvector operator-(cvector left,cvector right);
		friend cvector operator*(cvector left,cvector right);
		friend cvector operator/(cvector left,cvector right);
		friend cvector operator%(cvector left,cvector right);
		friend cvector operator^(cvector left,cvector right);
};
extern string cmessages[];
#define UNIT_NUM 47
extern string unit_name[UNIT_NUM];
extern string unit_insert[UNIT_NUM];
#endif
