#include"calchelper.h"
string title_color;
string notice_color;
string error_color;
string answer_color;
#ifndef __linux
void cls(){
	system("cls");
}
#endif
#ifdef __linux
void cls(){
	system("clear");
}
#endif
int findalpha(string base,string fi){
	int len1=base.length();
	int len2=fi.length();
	//Do not read the first
	for(int i=0;i<len1-len2;++i){
		if(!isalpha(base[i])){
			string temp=base.substr(i+1,len2);
			if(temp==fi&&(i+len2==len1-1||!isalpha(base[i+len2+1]))){
				return i+1;
			}
		}
	}
	return -1;
}
void replace_all(string &basic,string find,string replace){
	while(1){
        int len=basic.find(find);
        if(len==basic.npos)break;
        basic.replace(len,find.length(),replace);
    }
}
void setcolor(unsigned short number){
	if(number==1){
		title_color="\033[93m";
		notice_color="\033[33m";
		error_color="\033[31m";
		answer_color="\033[96m\033[4m";
		return;
	}
	if(number==2){
		title_color="";
		notice_color="";
		error_color="";
		answer_color="";
		return;
	}
	if(number==3){
		title_color="\033[43m\033[37m";
		notice_color="\033[101m\033[37m";
		error_color="\033[47m\033[91m";
		answer_color="\033[106m\033[93m";
		return;
	}
	return;
}
bool isint(realn test){
	if(test==floor(test))return 1;
	return 0;
}
long long gcd(long long a,long long b){
    while(b^=a^=b^=a%=b);
    return a;
}
long long lcm(long long a,long long b){
	return a/gcd(a,b)*b;
}
timer::timer(){
	time(&nowtime);
	newtime=localtime(&nowtime);
	old1=3600*newtime->tm_hour+60*newtime->tm_min+newtime->tm_sec;
}
void timer::reset(){
	time(&nowtime);
	newtime=localtime(&nowtime);
	old1=3600*newtime->tm_hour+60*newtime->tm_min+newtime->tm_sec;
}
int timer::delta(){
	time(&nowtime);
	newtime=localtime(&nowtime);
	int new1=3600*newtime->tm_hour+60*newtime->tm_min+newtime->tm_sec;
	return new1-old1;
}
void timer::showtime(){
	time(&nowtime);
	newtime=localtime(&nowtime);
	cout<<newtime->tm_hour<<":";
	int temp=newtime->tm_min;
	if(temp>=10)cout<<temp;
	else cout<<"0"<<temp;
}
void timer::showdate(){
	time(&nowtime);
	newtime=localtime(&nowtime);
	cout<<newtime->tm_year+1900<<'/'<<newtime->tm_mon+1<<"/"<<newtime->tm_mday;
}
