#ifndef calcset_h
	#define calcset_h
#include"calcreadfile.h"
enum TriType{
	TriRAD,TriDEG,TriGRAD,
};
class setting{
	private:
	public:
		string version;
		string this_used_file;
		bool cdebug;
		unsigned int calc_base;//base default=10
		unsigned int tri_type;//rad,deg,grad default=rad
		unsigned int calc_color; 
		string variable_x;
		string __earth__;
		string __pi__;
		string __e__;
		string __phi__;
		setting();//default
		bool loadfrom(string file);
		bool createsave(string file);
};
#endif 
