#include"calcreadfile.h"
bool make_used_file(string file){
	file=file.substr(0,file.find_last_of('\\'));
	file=file.substr(0,file.find_last_of('\\'));
	ifstream fin;
	used_file=file+"\\resource\\en-uk.txt";
	fin.open(used_file,ios::in);
	if(fin.is_open())return true;
	used_file=file+"\\resource\\zh-CN.txt";
	fin.open(used_file,ios::in);
	if(fin.is_open())return true;
	return false;
}
bool loadfile(string file){
	ifstream fin;
	fin.open(file,ios::in);
	if(fin.is_open()){
		used_file=file;
		return true;
	}
	return false;
}
void readnotes(string sign){
	string temp1="<"+sign+">";
	string temp2="</"+sign+">";
	ifstream fin;
	fin.open(used_file,ios::in);
	string temp;
	bool flag=false;
	while(getline(fin,temp)){
		if(temp==temp2)break;
		if(flag)cout<<temp<<endl;
		if(temp==temp1)flag=true;
	}
	return;
} 
