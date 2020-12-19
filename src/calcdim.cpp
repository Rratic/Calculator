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
	for(int i=1;i<DIMENSION_NUM;++i)si[i]=0;
}
cvector::cvector(realn re){
	real=re;
	for(int i=1;i<DIMENSION_NUM;++i)si[i]=0;
}
cvector::cvector(realn re,short type){
	real=re;
	for(int i=1;i<DIMENSION_NUM;++i)si[i]=0;
}
cvector::cvector(realn re,short di[]){
	real=re;
	for(int i=1;i<DIMENSION_NUM;++i)si[i]=di[i];
}
void cvector::output(){
	cout<<real;
	bool flag=false;
	for(int i=1;i<DIMENSION_NUM;++i){
		if(si[i]==0)continue;
		if(flag)cout<<"*";
		flag=true;
		cout<<unit[i];
		if(si[i]!=1)cout<<"^"<<si[i];
	}
}
void cvector::output(unsigned short base){
	cout<<PutReal(real,base);
	bool flag=false;
	for(int i=1;i<DIMENSION_NUM;++i){
		if(si[i]==0)continue;
		if(flag)cout<<"*";
		flag=true;
		cout<<unit[i];
		if(si[i]!=1)cout<<"^"<<si[i];
	}
}
void cvector::output_info(){
	cout<<"\nReal Number "<<real<<"\nDimension According To SI:\n";
	for(int i=1;i<DIMENSION_NUM;++i)cout<<"Dimension ID "<<i<<":="<<si[i]<<endl;
}
realn cvector::data(){
	return real;
}
bool cvector::isinf(){
	if(std::isinf(real))return true;
	return false;
}
bool cvector::isnan(){
	if(std::isnan(real))return true;
	return false;
}
bool cvector::ispure(){
	for(int i=1;i<DIMENSION_NUM;++i)if(si[i]!=0)return false;
	return true;
}
cvector operator+(cvector left,cvector right){
	cvector ans(left.real+right.real);
	try{
		for(int i=1;i<DIMENSION_NUM;++i){
			if(left.si[i]!=right.si[i])throw DimErr;
			ans.si[i]=left.si[i];
		}
	}
	catch(ErrType i){
		throw i;
	}
	return ans;
}
cvector operator-(cvector left,cvector right){
	cvector ans(left.real-right.real);
	try{
		for(int i=1;i<DIMENSION_NUM;++i){
			if(left.si[i]!=right.si[i])throw DimErr;
			ans.si[i]=left.si[i];
		}
	}
	catch(ErrType i){
		throw i;
	}
	return ans;
}
cvector operator*(cvector left,cvector right){
	cvector ans(left.real*right.real);
	for(int i=1;i<DIMENSION_NUM;++i)ans.si[i]=left.si[i]+right.si[i];
	return ans; 
}
cvector operator/(cvector left,cvector right){
	cvector ans(left.real/right.real);
	for(int i=1;i<DIMENSION_NUM;++i)ans.si[i]=left.si[i]-right.si[i];
	return ans;
}
cvector operator%(cvector left,cvector right){
	cvector ans(fmod(left.real,right.real));
	try{
		for(int i=1;i<DIMENSION_NUM;++i){
			if(left.si[i]!=right.si[i])throw DimErr;
			ans.si[i]=left.si[i];
		}
	}
	catch(ErrType i){
		throw i;
	}
	return ans;
}
cvector operator^(cvector left,cvector right){
	cvector ans(pow(left.real,right.real));
	try{
		for(int i=1;i<DIMENSION_NUM;++i){
			if(right.si[i]!=0)throw DimErr;
			ans.si[i]=left.si[i]*right.real;
		}
	}
	catch(ErrType i){
		throw i;
	}
	return ans;
}
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
