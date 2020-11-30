#include"calcset.h"
setting::setting(){
	string this_used_file=used_file;
	bool cdebug=false;
	unsigned int calc_base=10;
	unsigned int tri_type=TriRAD;
	string variable_x="0";
	string __earth__="9.8N";
	string __pi__="3.1415926535897932385";
	string __e__="2.7182818284590452354";
	string __phi__="1.618033988749894";
}
bool setting::loadfrom(string file){
	file=file.substr(0,file.find_last_of('\\'));
	file=file.substr(0,file.find_last_of('\\'));
	ifstream fin;
	fin.open(file+"\\save\\setting.txt",ios::in);
	if(!fin.is_open())return false;
	string temp;
	while(1){
		if(!getline(fin,temp))break;
		if(fin.fail())return false;
		if(temp=="this_used_file")fin>>this_used_file;
		if(temp=="cdebug")fin>>cdebug;
		if(temp=="calc_base")fin>>calc_base;
	}
	return true;
}
