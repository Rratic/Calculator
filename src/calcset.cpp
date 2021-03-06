#include"calcset.h"
setting::setting(){
	//version="0.7.0";
	this_used_file=used_file;
	cdebug=false;
	calc_base=10;
	tri_type=TriDEG;//it is found that most people are used to degree mode
	calc_color=1;
	variable_x="0";
	__earth__="9.8(m/s^2)";
	__pi__="3.1415926535897932385";
	__e__="2.7182818284590452354";
	__phi__="1.618033988749894";
}
bool setting::loadfrom(string file){
	ifstream fin;
	fin.open("save\\setting.data",ios::in);
	if(!fin.is_open())return false;
	string temp;
	while(fin>>temp){
		if(fin.fail())return false;
		if(temp=="this_used_file"){
			fin>>this_used_file;
			used_file=this_used_file;
		}
		if(temp=="cdebug")fin>>cdebug;
		if(temp=="calc_base")fin>>calc_base;
		if(temp=="tri_type")fin>>tri_type;
		if(temp=="calc_color")fin>>calc_color;
		if(temp=="variable_x")fin>>variable_x;
		if(temp=="_earth_")fin>>__earth__;
		if(temp=="_pi_")fin>>__pi__;
		if(temp=="_e_")fin>>__e__;
		if(temp=="_phi_")fin>>__phi__;
	}
	fin.close();
	return true;
}
bool setting::createsave(string file){
	ofstream fout;
	fout.open("save\\setting.data",ios::out);
	if(!fout.is_open())return false;
	fout<<"this_used_file "<<used_file<<'\n';
	fout<<"cdebug "<<cdebug<<'\n';
	fout<<"calc_base "<<calc_base<<'\n';
	fout<<"tri_type "<<tri_type<<'\n';
	fout<<"calc_color "<<calc_color<<'\n';
	fout<<"variable_x "<<variable_x<<'\n';
	fout<<"_earth_ "<<__earth__<<'\n';
	fout<<"_pi_ "<<__pi__<<'\n';
	fout<<"_e_ "<<__e__<<'\n';
	fout<<"_phi_ "<<__phi__<<'\n';
	fout.close();
	return true;
}
void setting::reset(){
	this_used_file=used_file;
	cdebug=false;
	calc_base=10;
	tri_type=TriDEG;
	calc_color=1;
	variable_x="0";
	__earth__="9.8(m/s^2)";
	__pi__="3.1415926535897932385";
	__e__="2.7182818284590452354";
	__phi__="1.618033988749894";
}