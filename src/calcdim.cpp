#include"calcdim.h"
string PutReal(realn num,unsigned short base){
	if(isnan(num))throw Inf;
	if(isinf(num))throw Nan;
    static char sign[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    string n,temp;
    if(num<0){
        n="-";
        num=-num;
    }
    if(num==0)n="0";
    realn inp=floor(num);
    realn dep=num-inp;
    while(inp>0){
        temp+=sign[int(fmod(inp,base))];
        inp/=base;
        inp=floor(inp);
    }
    int len=temp.length()-1;
    for(int i=len;i>=0;--i)n+=temp[i];
    if(dep==0)return n;
    n+='.';
    for(int i=0;i<16;++i){
        if(dep==0)break;
        dep*=base;
        n+=sign[int(dep)];
        dep-=floor(dep);
    }
    return n;
}
cvector::cvector(){
	real=0;
	imag=0;
	isonlyr=true;
	ispure=true;
	for(int i=1;i<DIMENSION_NUM;++i)si[i]=0;
}
cvector::cvector(realn re){
	real=re;
	imag=0;
	isonlyr=true;
	ispure=true;
	for(int i=1;i<DIMENSION_NUM;++i)si[i]=0;
}
cvector::cvector(realn re,short type){
	real=re;
	imag=0;
	isonlyr=true;
	for(int i=1;i<DIMENSION_NUM;++i)si[i]=0;
	if(type==0)ispure=true;
	else{
		si[type]=1;
		ispure=false;
	}
}
cvector::cvector(realn re,realn im,short type){
	real=re;
	imag=im;
	isonlyr=false;
	for(int i=1;i<DIMENSION_NUM;++i)si[i]=0;
	if(type==0)ispure=true;
	else{
		si[type]=1;
		ispure=false;	
	}
}
cvector::cvector(realn re,short di[]){
	real=re;
	imag=0; 
	isonlyr=true;
	for(int i=1;i<DIMENSION_NUM;++i)si[i]=di[i];
	ispure=false;
}
cvector::cvector(realn re,realn im,short di[]){
	real=re;
	imag=im;
	isonlyr=false;
	for(int i=1;i<DIMENSION_NUM;++i)si[i]=di[i];
	ispure=false;
}
void cvector::output(){
	if(isonlyr)cout<<real;
	else cout<<"("<<real<<","<<imag<<")";
	if(!ispure){
		bool flag=false;
		for(int i=1;i<DIMENSION_NUM;++i){
			if(si[i]==0)continue;
			if(flag)cout<<"*";
			flag=true;
			cout<<unit[i];
			if(si[i]!=1)cout<<"^"<<si[i];
		}
	}
}
void cvector::output(unsigned short base){
	if(isonlyr)cout<<PutReal(real,base);
	else cout<<"("<<PutReal(real,base)<<","<<PutReal(imag,base)<<")";
	if(!ispure){
		bool flag=false;
		for(int i=1;i<DIMENSION_NUM;++i){
			if(si[i]==0)continue;
			if(flag)cout<<"*";
			flag=true;
			cout<<unit[i];
			if(si[i]!=1)cout<<"^"<<si[i];
		}
	}
}
void cvector::output_info(){
	cout<<"\nPart 1:"<<real<<endl;
	if(isonlyr)cout<<"No Part 2"<<endl;
	else cout<<"Part 2:"<<imag;
	if(ispure)cout<<endl<<"Pure Number"<<endl;
	else{
		cout<<"Dimension According To SI:"<<endl;
		for(int i=1;i<DIMENSION_NUM;++i){
			cout<<"Dimension"<<i<<":="<<si[i]<<endl;
		}
	}
}
void cvector::plus(cvector right){
	try{
		if(ispure!=right.ispure)throw DimErr;
		for(int i=1;i<DIMENSION_NUM;++i)if(si[i]!=right.si[i])throw DimErr;
	}
	catch(ErrType i){
		throw i;
	}
	real+=right.real;
	imag+=right.imag;
	ispure&=right.ispure;
	isonlyr&=right.isonlyr;
}
void cvector::minus(cvector right){
	try{
		if(ispure!=right.ispure)throw DimErr;
		for(int i=1;i<DIMENSION_NUM;++i)if(si[i]!=right.si[i])throw DimErr;
	}
	catch(ErrType i){
		throw i;
	}
	real-=right.real;
	imag-=right.imag;
	ispure&=right.ispure;
	isonlyr&=right.isonlyr;
}
void cvector::multipy(cvector right){
	if(!ispure||!right.ispure)for(int i=1;i<DIMENSION_NUM;++i)si[i]+=right.si[i];
	real=real*right.real-imag*right.imag;
	imag=imag*right.real+real*right.imag;
	ispure&=right.ispure;
	isonlyr&=right.isonlyr;
}
void cvector::divide(cvector right){
	try{
		if(right.real==0)throw Nan;
	}
	catch(ErrType i){
		throw i;
	}
	if(!ispure||!right.ispure)for(int i=1;i<DIMENSION_NUM;++i)si[i]-=right.si[i];
	real/=right.real;
	//imag+=right.imag;
	ispure&=right.ispure;
	isonlyr&=right.isonlyr;
}
void cvector::mod(cvector right){
	try{
		if(ispure!=right.ispure)throw DimErr;
		for(int i=1;i<DIMENSION_NUM;++i)if(si[i]!=right.si[i])throw DimErr;
	}
	catch(ErrType i){
		throw i;
	}
	real=fmod(real,right.real);
	isonlyr&=right.isonlyr;
}
void cvector::power(cvector right){
	try{
		if(!right.ispure)throw DimErr;
	}
	catch(ErrType i){
		throw i;
	}
	for(int i=1;i<DIMENSION_NUM;++i)si[i]*=right.real;
	real=pow(real,right.real);
	//imag
	isonlyr&=right.isonlyr;
}
realn cvector::data(){
	return real; 
}
string cvector::to_string(){
	return "createv("+std::to_string(real)+")";
}
bool cvector::isinf(){
	if(std::isinf(real)||std::isinf(imag))return true;
	return false;
}
bool cvector::isnan(){
	if(std::isnan(real)||std::isnan(imag))return true;
	return false;
}
//
string cmessages[]={
	"NULL","Unknown Type",
	"Unknown Word","Grammer Error",
	"Math Error(Reason Unknown)","Infinate Result",
	"Not Any Number Result","Out Of Function Range",
	"Code Bug","No Real Root",
	"No Root","Unknown Unit Error",
	"Dim Operation Error","Unknown Command",
	"Command Error","No Jokes",
};
string unit_name[UNIT_NUM]={"km","m","dm","cm","mm","t","kg","g","mg",
"h","min","s","A","mA","K","mol","cd",
"N","J","kJ","W","kW","kWh","mL","L","Pa","mmHg","cmHg",
"inch","nmi","eV","V","Omega","C","Hz","day","lightsecond","T",
"week","mile","F","rad","degree","Wb","percent",
"atm","kPa"};
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
	"createdev(101325,-1,1,-2,0,0,0,0)","createdev(1000,-1,1,-2,0,0,0,0)",
};
