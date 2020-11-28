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
string cmessages[]={
	"NULL","Unknown Type",
	"Unknown Word","Grammer Err",
	"Math Err(Reason Unknown)","Infinate",
	"Not Any Number","Out Of Function Range",
	"Code Bug","No Real Root",
	"No Root","Unknown Unit Err",
	"Dim Operation Err","Unknown Command",
	"Command Err","No Jokes",
};
#define UNIT_NUM 45
string unit_name[UNIT_NUM]={"km","m","dm","cm","mm","t","kg","g","mg","h","min","s","A","mA","K","mol","cd","N","J","kJ","W","kW","kWh","mL","L","Pa","mmHg","cmHg","inch","nmi","eV","V","Omega","C","Hz","day","lightsecond","T","week","mile","F","rad","degree","Wb","percent"};
string unit_insert[UNIT_NUM]={
	"createdev(1000,1,0,0,0,0,0,0)","createdev(1,1,0,0,0,0,0,0)","createdev(0.1,1,0,0,0,0,0,0)","createdev(0.01,1,0,0,0,0,0,0)","createdev(0.001,1,0,0,0,0,0,0)",
	"createdev(1000,0,1,0,0,0,0,0)","createdev(1,0,1,0,0,0,0,0)","createdev(0.001,0,1,0,0,0,0,0)","createdev(0.000001,0,1,0,0,0,0,0)",
	"createdev(3600,0,0,1,0,0,0,0)","createdev(60,0,0,1,0,0,0,0)","createdev(1,0,0,1,0,0,0,0)",
	"createdev(1,0,0,0,1,0,0,0)","createdev(0.001,0,0,0,1,0,0,0)",
	"createdev(1,0,0,0,0,1,0,0)",
	"createdev(1,0,0,0,0,0,1,0)",
	"createdev(1,0,0,0,0,0,0,1)",
	"createdev(1,1,1,-2,0,0,0,0)",//N
	"createdev(1,2,1,-2,0,0,0,0)","createdev(1000,2,1,-2,0,0,0,0)",//J
	"createdev(1,2,1,-3,0,0,0,0)","createdev(1000,2,1,-3,0,0,0,0)",//W
	"createdev(3600000,2,1,-2,0,0,0,0)",//KWH
	"createdev(0.001,3,0,0,0,0,0,0)","createdev(1,3,0,0,0,0,0,0)",//L
	"createdev(1,-1,1,-2,0,0,0,0)",//Pa
	"createdev(133.322368,-1,1,-2,0,0,0,0)","createdev(1333.22368,-1,1,-2,0,0,0,0)",//Hg
	"createdev(0.0254,1,0,0,0,0,0,0)","createdev(1852,1,0,0,0,0,0,0)","createdev(0.0000000000000000001602177,2,1,-2,0,0,0,0)",//eV
	"createdev(1,2,1,-3,-1,0,0,0)","createdev(1,2,1,-3,-2,0,0,0)","createdev(1,0,0,1,1,0,0,0)",//V,OMEGA,C
	"createdev(1,0,0,-1,0,0,0,0)",//Hz
	"createdev(86400,0,0,1,0,0,0,0)",//day
	"createdev(299792458,1,0,0,0,0,0,0)",//lightsecond
	"createdev(1,0,1,-1,-1,0,0,0)",//tesla
	"createdev(604800,0,0,1,0,0,0,0)",//week
	"createdev(1609.334,1,0,0,0,0,0,0)",//mile
	"createdev(1,-1,-1,4,2,0,0,0)",//farad
	"57.295779513082",//rad in deg mode
	"0.01745329251994",//degree in rad mode
	"createdev(1,2,1,-1,-1,0,0,0)",//Wb
	"0.01",
};
#endif
