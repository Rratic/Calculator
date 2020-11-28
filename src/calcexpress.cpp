#include"calcexpress.h" 
/*Static Data*/
string expression::ptrList[EXP_PTR_NUM]={"f(",",","+","-","*","/","(",")","#","%","^"};
int expression::ptrArgCnt[EXP_PTR_NUM]={0,1,2,2,2,2,0,0,0,2,2};
string expression::funList[EXP_FUN_NUM]={
	"sin(","cos(","tan(","csc(","sec(","cot(",
	"deleted(","deleted(","sqrt(","floor(","ln(","cbrt(",
	"abs(","exp(","lg(","ceil(","round(","lb(",
	"pow(","sqr(","cube(","arcsin(","arccos(","arctan(",
	"log(","mod(","rand(","sinh(","cosh(","tanh(",
	"arcsinh(","arccosh(","arctanh(","deleted(","deleted(","deleted(",
	"x10p(","x2p(","deleted(","isint(","oppo(","average(",
	"fact(","gcd(","lcm(","isprime(","npr(","ncr(",
	"fact2(","root1(","root2(","sign(","createv(","createdev(",
	"gamma(","trunc(","digamma(","versin(","vercosin(","coversin(",
	"covercosin(","haversin(","havercosin(","hacoversin(","hacovercosin(","exsec(",
	"excsc(","fade(","csch(","sech(","coth(","arccsch(",
	"arcsech(","arccoth(","fma(",
	//zeta
};
int expression::funArgCnt[EXP_FUN_NUM]={
    1,1,1,1,1,1,
    2,2,1,1,1,1,
    1,1,1,1,1,1,
    2,1,1,1,1,1,
    2,2,2,1,1,1,
    1,1,1,1,1,2,
    1,1,1,1,1,2,
    1,2,2,1,2,2,
    1,3,3,1,2,8,
    1,1,1,1,1,1,
    1,1,1,1,1,1,
    1,1,1,1,1,1,
    1,1,3,
};
int expression::preceMap[EXP_PTR_NUM][EXP_PTR_NUM]={
//   f(  , +  -  *  /  (   )  #  %  ^
    {-1,-1,-1,-1,-1,-1,-1, 1, 1,-1,-1},//f(
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//,
    {-1, 1, 1, 1,-1,-1,-1, 1, 1,-1,-1},//+
    {-1, 1, 1, 1,-1,-1,-1, 1, 1,-1,-1},//-
    {-1, 1, 1, 1, 1, 1,-1, 1, 1, 1,-1},//*
    {-1, 1, 1, 1, 1, 1,-1, 1, 1, 1,-1},///
    {-1, 1,-1,-1,-1,-1,-1, 0, 1,-1,-1},//(
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//)
    {-1, 1,-1,-1,-1,-1,-1,-1, 0,-1,-1},//#
    {-1, 1, 1, 1, 1, 1,-1, 1, 1, 1,-1},//%
    {-1, 1, 1, 1, 1, 1,-1, 1, 1, 1,-1},//^
};
expression::expression(string &exp)
{
    pression=exp+"#";
    token="";
    pos=0;
    length=1+exp.length(); 
}
int expression::getPtrIndex(const string &ptr)
{
    for(int i=0;i<EXP_PTR_NUM;++i){
        if(ptrList[i]==ptr)return i;
    }
    return -1;
}
int expression::getFunIndex(const string &fun)
{
    for(int i=0;i<EXP_FUN_NUM;++i){
        if(funList[i]==fun)return i;
    }
    return -1;
}
int expression::comaprePrece(string &ptr1,string &ptr2)
{
    int m=getPtrIndex(ptr1),n=getPtrIndex(ptr2);
    if(m==-1)m=0;
    if(n==-1)n=0;
    return preceMap[m][n];
}
cvector expression::calculate(string &ptr,vector<cvector>&arg)
{
	try{
    	switch(getPtrIndex(ptr)){
        	case 2:{
        		arg[0].plus(arg[1]);
				break;
			}
        	case 3:{
        		arg[0].minus(arg[1]);
				break;
			}
        	case 4:{
        		arg[0].multipy(arg[1]);
				break;
			}
        	case 5:{
        		arg[0].divide(arg[1]);
				break;
			}
			case 9:{
				arg[0].mod(arg[1]);
				break;
			}
			case 10:{
				arg[0].power(arg[1]);
				break;
			}
    	}
    	return arg[0];
	}
	catch(ErrType){
		throw;
	}
    return 0;
}
cvector expression::callFun(string &fun,vector<realn>&arg)
{
	int n=arg.size();
	int id=getFunIndex(fun);
	try{
		if(is_trigonometric(id)){
			if(tri_type==TriRAD)for(int i=0;i<n;i++)arg[i]=fmod(arg[i],6.283185307179);
			else if(tri_type==TriGRAD){
				for(int i=0;i<n;i++){
					arg[i]=fmod(arg[i],400);
					arg[i]=arg[i]*0.015707963268;//pi/200
				}
			}
			else for(int i=0;i<n;i++){
				arg[i]=fmod(arg[i],360);
				arg[i]=arg[i]*0.01745329251994;//pi/180 
			}
			
		}
		if(id>=42&&id<=48)for(int i=0;i<n;i++)if(!isint(arg[i])||arg[i]<0)throw OutOfRange;
    	switch(id){
        	case 0:return sin(arg[0]);
        	case 1:return cos(arg[0]);
       		case 2:{
       			realn temp=tan(arg[0]);
       			if(abs(temp)>2.5e12)throw Inf;
       			return temp;
			} 
       		case 3:{
        		realn temp=sin(arg[0]);
        		if(temp==0)throw OutOfRange;
        		return 1/temp;
			}
        	case 4:{
        		realn temp=cos(arg[0]);
        		if(temp==0)throw OutOfRange;
        		return 1/temp;
        	}
        	case 5:{
        		realn temp=tan(arg[0]);
        		if(temp==0)throw OutOfRange;
        		return 1/temp;
			}
        	case 6:{
        		realn temp=arg[0];
        		for(int i=1;i<n;i++)temp=max(temp,arg[i]);
        		return temp;
			}
        	case 7:{
        		realn temp=arg[0];
        		for(int i=1;i<n;i++)temp=min(temp,arg[i]);
        		return temp;
        	}
        	case 8:{
        		if(arg[0]<0)throw OutOfRange;
        		return sqrt(arg[0]);
			}
        	case 9:return floor(arg[0]);	
        	case 10:{
        		if(arg[0]<0)throw OutOfRange;
        		return log(arg[0]);
			}
        	case 11:return cbrt(arg[0]);
        	case 12:return fabs(arg[0]);
        	case 13:return exp(arg[0]);
        	case 14:{
        		if(arg[0]<0)throw OutOfRange;
        		return log10(arg[0]);
			}
        	case 15:return ceil(arg[0]);
        	case 16:return round(arg[0]);
        	case 17:{
        		if(arg[0]<0)throw OutOfRange;
        		log2(arg[0]);
			}
			case 18:return pow(arg[0],arg[1]);
        	case 19:return arg[0]*arg[0];
        	case 20:return arg[0]*arg[0]*arg[0];
			case 21:return asin(arg[0]);
			case 22:return acos(arg[0]);
			case 23:return atan(arg[0]);
			case 24:return log(arg[1])/log(arg[0]);
			case 25:return fmod(arg[0],arg[1]);
			case 26:{
				int left=ceil(arg[0]);
				int right=floor(arg[1]);
				return left+rrand()%(right-left+1);
				break;
			}
			case 27:return sinh(arg[0]);
			case 28:return cosh(arg[0]);
			case 29:return tanh(arg[0]);
			case 30:return asinh(arg[0]);
			case 31:return acosh(arg[0]);
			case 32:return atanh(arg[0]);
			case 33:return 1;
			case 34:return arg[0];
			case 35:{
				realn temp=arg[0];
        		for(int i=1;i<n;i++)temp+=arg[i];
        		return temp;
			}
			case 36:return pow(10,arg[0]);
			case 37:return exp2(arg[0]);
			case 38:return arg[0]*0.01745329251994;
			case 39:{
				if(arg[0]==floor(arg[0]))return 1;
				return 0;
			}
			case 40:return -arg[0];
			case 41:{
				realn temp=arg[0];
        		for(int i=1;i<n;i++)temp+=arg[i];
        		return temp/n;
			}
			case 42:{
				if(arg[0]==0)return 1;
				realn temp=1;
				for(int i=2;i<=arg[0];i++)temp*=i;
				return temp;
			}
			case 43:{
				realn temp=floor(arg[0]);
				if(temp==0)throw OutOfRange;
        		for(int i=1;i<n;i++){
        			if(arg[i]==0)throw OutOfRange;
        			temp=gcd(temp,floor(arg[i]));
				}
        		return temp;
			}
			case 44:{
				realn temp=floor(arg[0]);
				if(temp==0)throw OutOfRange;
        		for(int i=1;i<n;i++){
        			if(arg[i]==0)throw OutOfRange;
        			temp=lcm(temp,floor(arg[i]));
				}
        		return temp;
			}
			case 45:{
				if(arg[0]<2)return 0;
				for(int i=2;i<=sqrt(arg[0]);i++){
					if(int(arg[0])%i==0)return 0;
				}
				return 1;
			}
			case 46:{
				if(arg[1]==0||arg[0]>arg[1])throw OutOfRange;
				realn temp=1;
				for(realn i=arg[1];i>=arg[0];i--)temp*=i;
				return temp;
			}
			case 47:{
				if(arg[1]==0||arg[0]>arg[1])throw OutOfRange;
				realn temp=1;
				for(realn i=arg[1];i>=arg[0];i--)temp*=i;
				for(realn i=2;i<=arg[0];i++)temp/=i;
				return temp;
			}
			case 48:{
				if(arg[0]==0)return 1;
				realn temp=1;
				for(int i=arg[0];i>=1;i-=2)temp*=i;
				return temp;
				break;
			}
			case 49:{
				if(arg[0]==0){
					if(arg[1]!=0)return arg[2]/arg[1];
					if(arg[2]==0)throw Nan;
					throw NoRoot;
				}
				realn temp=arg[1]*arg[1]-4*arg[0]*arg[2];
				if(temp<0)throw NoRealRoot;
				if(arg[0]>0)return (-arg[1]-sqrt(temp))/2/arg[0];
				if(arg[0]<0)return (-arg[1]+sqrt(temp))/2/arg[0];
			}
			case 50:{
				if(arg[0]==0){
					if(arg[1]!=0)return arg[2]/arg[1];
					if(arg[2]==0)throw Nan;
					throw NoRoot;
				}
				realn temp=arg[1]*arg[1]-4*arg[0]*arg[2];
				if(temp<0)throw NoRealRoot;
				if(arg[0]>0)return (-arg[1]+sqrt(temp))/2/arg[0];
				if(arg[0]<0)return (-arg[1]-sqrt(temp))/2/arg[0];
			}
			case 51:{
				if(arg[0]<0)return -1;
				if(arg[0]>0)return 1;
				return 0;
			}
			case 52:return cvector(arg[0],arg[1]);
			case 53:{
				short temp[DIMENSION_NUM]={
					0,short(arg[1]),
					short(arg[2]),short(arg[3]),
					short(arg[4]),short(arg[5]),
					short(arg[6]),short(arg[7]),
				};
				return cvector(arg[0],temp);
			}
			case 54:return tgamma(arg[0]);
			case 55:return trunc(arg[0]);
			case 56:return lgamma(arg[0]);
			case 57:return 1-cos(arg[0]);
			case 58:return 1+cos(arg[0]);
			case 59:return 1-sin(arg[0]);
			case 60:return 1+sin(arg[0]);
			case 61:return (1-cos(arg[0]))/2;
			case 62:return (1+cos(arg[0]))/2;
			case 63:return (1-sin(arg[0]))/2;
			case 64:return (1+sin(arg[0]))/2;
			case 65:return 1/cos(arg[0])-1;
			case 66:return 1/sin(arg[0])-1;
			case 67:return arg[0]*arg[0]*arg[0]*(10+arg[0]*(6*arg[0]-15));
			case 68:return 1/sinh(arg[0]);
			case 69:return 1/cosh(arg[0]);
			case 70:return 1/tanh(arg[0]);
			case 71:return asinh(1/arg[0]);
			case 72:return acosh(1/arg[0]);
			case 73:return atanh(1/arg[0]);
			case 74:return fma(arg[0],arg[1],arg[2]);
			default:{
				throw ProBug;
			}
    	}
	}
	catch(ErrType){
		throw;
	}
    return 0;
}
void expression::readToken()
{
    while(pos<length&&pression[pos]==' '){//Delete space
        ++pos;
    }
    if(pos>=length){
        tkType=TKT_ENDSIGN;
        return;
    }
    int pos_t=pos;
    char ch=pression[pos_t++];
    char ch_n=pos_t<length?pression[pos_t]:0;
    if(isdigit(ch)||(ch=='-'&&isdigit(ch_n)&&tkType!=TKT_NUMBER)){//number 
        if(ch=='-')++pos_t;
        while(pos_t<length&&isdigit(ch=pression[pos_t]))++pos_t;
        if(ch=='.'){
            ++pos_t;
            while(pos_t<length&&isdigit(pression[pos_t]))++pos_t;
        }
        tkType=TKT_NUMBER;
    }
	else if(-1!=getPtrIndex(string(1,ch))){//operator
        tkType=TKT_OPERATOR;
    }
	else if(isalpha(ch)){//function
        while(pos_t<length&&(isalnum(ch)||ch=='_')){
            ch=pression[++pos_t];
        }
        if(ch=='('){
            ++pos_t;
            if(-1!=getFunIndex(pression.substr(pos,pos_t-pos))){
                tkType=TKT_FUNCTION;
            }
			else tkType=TKT_UNKNOWN;
        }
		else tkType=TKT_UNKNOWN;
    }
	else tkType=TKT_UNKNOWN;
    token=pression.substr(pos,pos_t-pos);
    pos=pos_t;
}
bool expression::getArg(stack<cvector>&opnd,vector<cvector>&arg,int n)
{
	if(n>0){
		if(opnd.size()<n)return false;
		for(int i=n-1;i>=0;i--)arg.push_back(cvector());
    	for(int i=n-1;i>=0;i--){
        	arg[i]=opnd.top();
        	opnd.pop();
    	}
    	return true;
	}
    else{
    	if(opnd.size()<2)return false;
    	return true;
	}
}
void expression::getVal(cvector &res)
{
    stack<string>optr;//operates
    stack<cvector>opnd;//numbers
    optr.push("#");
    pos=0;
    readToken();
    while(tkType!=TKT_ENDSIGN||!optr.empty()){
        if(tkType==TKT_UNKNOWN){
            throw UnknownType;//unknown 
        }
        if(tkType==TKT_NUMBER){
            opnd.push(cvector(atof(token.c_str())));
            readToken();
        }
		else{
            int comRes=comaprePrece(optr.top(),token);
            switch(comRes){
                case -1:
                    optr.push(token);
                    readToken();
                    break;
                case 1:
                {
                    string ptr=optr.top();
                    optr.pop();
                    int idx=getPtrIndex(ptr),argCnt;
                    vector<cvector>arg;
                    if(idx!=-1){
                        argCnt=ptrArgCnt[idx];
                        if(cdebug)cout<<"Operator called:id="<<idx<<"\n";
                        if(argCnt!=0){
                        	if(!getArg(opnd,arg,argCnt))throw UnknownType;
                            res=calculate(ptr,arg);
                            opnd.push(res);
                        }
                    }
					else{
                        idx=getFunIndex(ptr);
                        argCnt=funArgCnt[idx];
                        if(cdebug)cout<<"Function called:id="<<idx<<"\n";
                        if(!getArg(opnd,arg,argCnt))throw UnknownWord;
                        vector<realn>arg2;
                        for(int i=0;i<arg.size();i++){
                        	if(!arg[i].ispure)throw DimErr;
                        	arg2.push_back(arg[i].data());	
						}
                        res=callFun(ptr,arg2);
                        opnd.push(res);
                        readToken();
                    }
                    break;
                }
                case 0:
                    optr.pop();
                    readToken();
                    break;
            }
        }
    }
    res=opnd.top();
    throw Nothing;
}
bool is_trigonometric(int id){
	if(id<=5||(id>=27&&id<=29)||(id>=57&&id<=66)||(id>=68&&id<=70))return true;
	return false;
}
