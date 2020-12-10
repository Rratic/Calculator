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
#include<random>

#ifndef __linux
	#define cls system("cls")
#endif
#ifdef __linux
	#define cls system("clear")
#endif
using namespace std;
typedef long double realn;
extern string title_color;
extern string notice_color;
extern string error_color;
extern string answer_color;
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
