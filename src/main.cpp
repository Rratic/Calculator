#include"calcintergrate.h"
//,/max,/min,/median,/range,/roots
//conj,isnan,isinf future
int main(int argc,char *argv[])
{
	system("title Calculator");
	cls;//to activate the \033 system(?)
	if(!thisset.loadfrom(*argv)){
		if(!make_used_file(*argv)){
			cerr<<"Default language file unfound:"<<used_file<<"\nInput the file name\n";
			getline(cin,order);
			if(!loadfile(order))cout<<"Failed to find file:(\nTrying to load without files...\n";
		}
	}
	setcolor(thisset.calc_color);
    CALCinfo();
    unsigned short count=0;
	for(size_t turner=0;true;){
		place_get_order:if(count==3){
			cls;
			count=0;
		}
		if(thisset.cdebug)cout<<"\n<TURN"<<turner<<">";
		turner++;
		message="";
		order="";
		cout<<"\n\033[0mInput--->";
		cin.clear();
		cin.sync();
		getline(cin,order);
		cvector res;
	    try{
			replace_all(order," ","");
			if(order==""){
				count++;
				goto place_get_order;
			} 
			if(order[0]=='/'){
				docommand(*argv);
				goto place_get_order;
			}
			if(doorder())goto place_get_order;
			expression num(order);
			num.getVal(res);
			if(res.isnan())throw Nan;
			if(res.isinf())throw Inf;
		}
	    catch(ErrType i){
			if(i==Nothing){
				cout<<"ans="<<answer_color;
				if(thisset.cdebug)res.output_info();
				else{
					if(thisset.calc_base!=10)res.output(thisset.calc_base);
					else res.output();
				} 
				lastans=res;
			}
			else{
				cout<<error_color;
				if(thisset.cdebug)cout<<"Error found:id="<<i<<'\n';
				message=cmessages[i];
				lastorder="";
			}
		}
	    cout<<message<<"\033[0m\n\n";
	    if(thisset.cdebug)cout<<"</TURN"<<turner<<">\n\n";
	}
    return 0;
}
