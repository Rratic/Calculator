#include"calcintergrate.h"
void CALCinfo(){
	cout<<"\033[?25h"<<title_color;
    readnotes("menu_title");
    cout<<notice_color;
    readnotes("menu_info");
	cout<<"\033[0m";
}
bool doorder(){
	try{
	//#
	if(order.find("#")!=order.npos)throw UnknownWord;
	replace_all(order,"history",lastorder);
	//()[]{}
    for(int i=0;i<order.length();i++){
    	if(order[i]=='['||order[i]=='{')order[i]='(';
    	if(order[i]==']'||order[i]=='}')order[i]=')';
	}
	//save order
    lastorder=order;
	//get newtime
    ttime.reset();
    replace_all(order,"¡Á","*");
    replace_all(order,"¡Â","/");
    replace_all(order,"¡Ì","sqrt");
	replace_all(order,"_earth_",thisset.__earth__);
	replace_all(order,"_X_",thisset.variable_x);
    replace_all(order,"_pi_",thisset.__pi__);
    replace_all(order,"¦Ð",thisset.__pi__);
    replace_all(order,"_e_",thisset.__e__);
    replace_all(order,"_phi_",thisset.__phi__);
    replace_all(order,"¦Õ",thisset.__phi__);
    replace_all(order,"_hour_",to_string(ttime.newtime->tm_hour));
    replace_all(order,"_minute_",to_string(ttime.newtime->tm_min));
    replace_all(order,"_second_",to_string(ttime.newtime->tm_sec));
    replace_all(order,"_random_",to_string(rrand()/realn(INT_MAX)));
	replace_all(order,"ans",lastans.to_string());
    //units
    for(int i=0;i<UNIT_NUM;i++){
    	while(1){
    		int len=findalpha(order,unit_name[i]);
    		if(len==-1)break;
    		if(isalnum(order[len-1]))order.replace(len,unit_name[i].length(),"*"+unit_insert[i]);
    		else order.replace(len,unit_name[i].length(),unit_insert[i]);
		}
	}
	}
	catch(ErrType i){
		throw i;
	}
	return false;
}
void docommand(string file){
	try{
		int len=order.length();
		for(int i=1;i<len;++i)if(order[i]>='A'&&order[i]<='Z')order[i]=order[i]-'A'+'a';
		if(order=="/easteregg"){
			long long temp=65536+rrand()%131072;
			while(1){
				if(temp==1)break;
				if(temp%2==0)temp/=2;
				else temp=3*temp+1;
				cout<<temp<<'\n';
			}
		}
    	else if(order=="/help"){
        	readnotes("help_menu");
			cin>>order;
			cout<<notice_color;
			if(order=="0")readnotes("help_command");
			else if(order=="1")readnotes("help_operator");
			else if(order=="2")readnotes("help_func");
			else if(order=="3")readnotes("help_const");
			else if(order=="4")readnotes("help_q&a");
			else if(order=="5")readnotes("help_unit");
			else if(order=="6")readnotes("help_error");
			else throw JokeErr;
		}
    	else if(order=="/exit")exit(0);
    	else if(order=="/diary")readnotes("diary");
		else if(order=="/reset"){
			lastans=0;
			lastorder="";
		}
		else if(order=="/clear"){
			cls;
			ttime.showtime();
		}
		else if(order=="/example"){
			cout<<notice_color;
			readnotes("example");
		}
		else if(order=="/debug"){
			thisset.cdebug=true;
			if(thisset.cdebug)cout<<"Start Debuging\n";
		}
		else if(order=="/disdebug"){
			if(thisset.cdebug)cout<<"End Debuging\n";
			thisset.cdebug=false;
		}
		else if(order=="/information")CALCinfo();
		else if(order=="/time"){
			ttime.showtime();
			cout<<"\nRun Time:"<<ttime.delta()<<"seconds\n";
		}
		else if(order=="/echo"){
			getline(cin,order);
			if(doorder())throw JokeErr;
			cout<<order<<'\n';
		}
		else if(order=="/logo")CALClogo();
		else if(order=="/define"){
			readnotes("define_menu");
			string temp;
			getline(cin,temp);
			if(temp=="1")getline(cin,thisset.variable_x);
			if(temp=="2")getline(cin,thisset.__pi__);
			if(temp=="3")getline(cin,thisset.__e__);
			if(temp=="4")getline(cin,thisset.__phi__);
		}
		else if(order=="/color"){
			readnotes("color_menu");
			unsigned short temp;
			cin>>temp;
			cout<<"\033[0m";
			setcolor(temp);
			thisset.calc_color=temp;
		}
		else if(order=="/dice")readnotes("dice"+to_string(rrand()%6+1));
		else if(order=="/mr")lastans=saved;
		else if(order=="/m+")saved.plus(lastans);
		else if(order=="/m-")saved.minus(lastans);
		else if(order=="/ms")saved=lastans;
		else if(order=="/date")ttime.showdate();
		else if(order=="/rad")thisset.tri_type=TriRAD; 
		else if(order=="/deg")thisset.tri_type=TriDEG;
		else if(order=="/grad")thisset.tri_type=TriGRAD;
		else if(order=="/lang"){
			cout<<"language file example:"<<used_file<<'\n';
			getline(cin,order);
			if(!loadfile(order))cout<<"Failed to find file:(\n";
		}
		else if(order=="/bin")thisset.calc_base=2;
		else if(order=="/oct")thisset.calc_base=8;
		else if(order=="/dec")thisset.calc_base=10;
		else if(order=="/hex")thisset.calc_base=16;
		else if(order=="/base"){
			unsigned short temp;
			cin>>temp;
			if(temp<2||temp>16)throw OutOfRange;
			thisset.calc_base=temp;
		}
		else if(order=="/sort"){
			int temp;
			vector<realn>a;
			realn b;
			cin>>temp;
			for(int i=0;i<temp;i++){
				cin>>b;
				cin.clear();
				a.push_back(b);
			}
			sort(a.begin(),a.end());
			for(vector<realn>::iterator it=a.begin();it!=a.end();++it)cout<<(*it)<<'\n';
		}
		else if(order=="/sum"){
			int temp;
			realn a,b=0;
			cin>>temp;
			for(int i=0;i<temp;i++){
				cin>>a;
				cin.clear();
				b+=a;
			}
			cout<<b;
		}
		else if(order=="/average"){
			int temp;
			realn a,b=0;
			cin>>temp;
			for(int i=0;i<temp;i++){
				cin>>a;
				cin.clear();
				b+=a;
			}
			cout<<b/temp;
		}
		else if(order=="/save"){
			if(thisset.createsave(file))cout<<"Saved Successfully";
			else cout<<"Failed to save setting :(";
		}
		else throw UnknownOrder;
	}
	catch(ErrType i){
		throw i;
	}
}
