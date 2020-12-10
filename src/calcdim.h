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
		realn real,imag;
		bool isonlyr;//not imag!=0or something,only shows whether it is "polluted"...
		short si[DIMENSION_NUM];
		bool simple_unit_output();
	public:
		bool ispure;//makes it quicker to calc
		cvector();
		cvector(realn re);
		cvector(realn re,short type);
		cvector(realn re,realn im,short type);
		cvector(realn re,short di[]);
		cvector(realn re,realn im,short di[]);
		void output();
		void output(unsigned short base);
		void output_info();
		void plus(cvector right);
		void minus(cvector right);
		void multipy(cvector right);
		void divide(cvector right);
		void mod(cvector right);
		void power(cvector right);
		realn data();
		string to_string();
		bool isinf();
		bool isnan();
};
extern string cmessages[];
#define UNIT_NUM 45
extern string unit_name[UNIT_NUM];
extern string unit_insert[UNIT_NUM];
#endif
