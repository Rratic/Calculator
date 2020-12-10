#ifndef calcreadfile_h
	#define calcreadfile_h
#include<iostream>
#include<fstream>
using namespace std;
extern string used_file;
bool make_used_file(string file);
bool loadfile(string file);
void readnotes(string sign);
#endif
