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
