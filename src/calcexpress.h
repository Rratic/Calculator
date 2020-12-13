#ifndef calcexpress_h
	#define calcexpress_h
#include"calchelper.h"
#include"calcdim.h"
#include"calcset.h"
#include<stack>
#include<cstdlib>
#include<map>
#include<algorithm>
#include<cstdio>
#define EXP_PTR_NUM 11
#define EXP_FUN_NUM 76
extern random_device thisseed;
extern mt19937 generatedseed;
extern string order;
extern string lastorder;
extern string message;
extern cvector lastans,saved;
extern setting thisset;
/*TokenType*/
enum TokenType{
    TKT_NUMBER,
    TKT_OPERATOR,
    TKT_FUNCTION,
    TKT_ENDSIGN,
    TKT_UNKNOWN,
};
/*Expression*/
class expression
{
public:
    expression(string &exp);
    void getVal(cvector &res);
private:
    string pression;
    string token;
    TokenType tkType; 
    int pos,length;
    /*Data*/
    static string ptrList[];
    static int ptrArgCnt[];
    static string funList[];
    static int funArgCnt[];
    static int preceMap[][EXP_PTR_NUM];
    /*Read Next Token*/
    void readToken();
    /*Compare Prece*/
    int comaprePrece(string &ptr1,string &ptr2);
    /*Calc Operator One Step*/
    cvector calculate(string &ptr,vector<cvector>&arg);
    /*Calc Function One Step*/
    cvector callFun(string &fun,vector<realn>&arg);
    /*Get id of Operator*/
    int getPtrIndex(const string &ptr);
    /*Get id of Func*/
    int getFunIndex(const string &fun);
    /*Get Args from Stack*/
    bool getArg(stack<cvector>&opnd,vector<cvector>&arg,int n);
};
bool is_trigonometric(int id);
#endif
