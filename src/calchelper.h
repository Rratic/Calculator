#ifndef calchelper_h
	#define calchelper_h
#include<string>
#include<iostream>
#include<ctime>
#include<unistd.h>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<vector>
#include<limits.h>

#ifndef __linux
	#define cls system("cls")
#endif
#ifdef __linux
	#define cls system("clear")
#endif
using namespace std;
typedef long double realn;
string title_color;
string notice_color;
string error_color;
string answer_color;
string __earth__="9.8N";
string __pi__="3.1415926535897932384626433832795";
string __e__="2.7182818284590452354";
string __phi__="1.618033988749894";
void light(string line);
void CALClogo();
int findalpha(string base,string fi);
void readarray(vector<string>&arrayn);
void replace_all(string &basic,string find,string replace);
void setcolor(unsigned short number);
bool isint(realn test);
long long gcd(long long a,long long b);
long long lcm(long long a,long long b);
/* Timer */
class timer{
    private:
    time_t nowtime;
    int old1;
    public:
    tm *newtime;
    timer();
    void reset();
    int delta();
    void showtime();
    void showdate();
};
#endif
