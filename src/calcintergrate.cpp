#include"calcintergrate.h"
timer ttime;
void CALCinfo(){
	cout<<title_color;
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
    for(int i=0;i<order.length();++i){
    	if(order[i]=='['||order[i]=='{')order[i]='(';
    	if(order[i]==']'||order[i]=='}')order[i]=')';
	}
	//()
	replace_all(order,"()","");//sin()->sin,but it's also an error,right?
	//jokes
	if(order=="")throw JokeErr;
	//save order
    lastorder=order;
	//get newtime
    ttime.reset();
    replace_all(order,"��","*");
    replace_all(order,"��","/");
    replace_all(order,"��","sqrt");
	replace_all(order,"_earth_",thisset.__earth__);
	replace_all(order,"_X_",thisset.variable_x);
    replace_all(order,"_pi_",thisset.__pi__);
    replace_all(order,"��",thisset.__pi__);
    replace_all(order,"_e_",thisset.__e__);
    replace_all(order,"_phi_",thisset.__phi__);
    replace_all(order,"��",thisset.__phi__);
    replace_all(order,"_hour_",to_string(ttime.newtime->tm_hour));
    replace_all(order,"_minute_",to_string(ttime.newtime->tm_min));
    replace_all(order,"_second_",to_string(ttime.newtime->tm_sec));
    uniform_real_distribution<>dis(0,1);
    replace_all(order,"_random_",to_string(dis(generatedseed)));
	replace_all(order,"ans",to_string(lastans.real));
    //units
    for(int i=0;i<UNIT_NUM;++i){
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
			uniform_int_distribution<> dis(65536,196608);
			long long temp=dis(generatedseed);
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
    	else if(order=="/exit"){
			cout<<"Do you want to save setting?(y/others)\n";
			string temp;
			cin>>temp;
			if(temp=="y"||temp=="Y"){
				if(thisset.createsave(file))cout<<"Setting saved successfully :)\n";
				else cout<<"Failed to save setting :(\n";
				system("pause");
			}
			exit(0);
		} 
    	else if(order=="/diary")readnotes("diary");
		else if(order=="/reset"){
			lastans=0;
			lastorder="";
		}
		else if(order=="/clear"){
			cls;
			ttime.showtime();
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
		else if(order=="/color"||order=="/colour"){
			readnotes("color_menu");
			unsigned short temp;
			cin>>temp;
			cout<<"\033[0m";
			setcolor(temp);
			thisset.calc_color=temp;
		}
		else if(order=="/dice"){
			uniform_int_distribution<>dis(1,6);
			long long temp=dis(generatedseed);
			readnotes("dice"+to_string(temp));
		}
		else if(order=="/random"){
			readnotes("random_menu");
			makerandom();
		}
		else if(order=="/mr")lastans=saved;
		else if(order=="/m+")saved=saved+lastans;
		else if(order=="/m-")saved=saved-lastans;
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
		else if(order=="/max"){
			int temp;
			realn a,b;
			cin>>temp;
			for(int i=0;i<temp;i++){
				cin>>a;
				cin.clear();
				if(i==1)b=a;
				if(b<a)b=a;
			}
			cout<<b;
		}
		else if(order=="/min"){
			int temp;
			realn a,b;
			cin>>temp;
			for(int i=0;i<temp;i++){
				cin>>a;
				cin.clear();
				if(i==1)b=a;
				if(b>a)b=a;
			}
			cout<<b;
		}
		else if(order=="/save"){
			if(thisset.createsave(file))cout<<"Saved Successfully:)";
			else cout<<"Failed to save setting:(";
		}
		else throw UnknownOrder;
	}
	catch(ErrType i){
		throw i;
	}
}
#define __temp_output for(unsigned int i=0;i<count;++i)cout<<dis(generatedseed)<<'\n'
void makerandom(){
	unsigned int choose,count;
	cin>>choose>>count;
	switch(choose){
		case 1:{
			long long left,right;
			cin>>left>>right;
			uniform_int_distribution<long long>dis(left,right);
			__temp_output;
			break;
		}
		case 2:{
			long double left,right;
			cin>>left>>right;
			uniform_real_distribution<long double>dis(left,right);
			__temp_output;
			break;
		}
		case 3:{
			long double temp;
			cin>>temp;
			bernoulli_distribution dis(temp);
			__temp_output;
			break;
		}
		case 4:{
			long long temp;
			double temp2;
			cin>>temp>>temp2;
			binomial_distribution<long long>dis(temp,temp2);
			__temp_output;
			break;
		}
		case 5:{
			long long temp;
			long double temp2;
			cin>>temp>>temp2;
			negative_binomial_distribution<long long>dis(temp,temp2);
			__temp_output;
			break;
		}
		case 6:{
			long double temp;
			cin>>temp;
			geometric_distribution<long long>dis(temp);
			__temp_output;
			break;
		}
		case 7:{
			long long temp;
			cin>>temp;
			poisson_distribution<long long>dis(temp);
			__temp_output;
			break;
		}
		case 8:{
			long double temp2;
			cin>>temp2;
			exponential_distribution<long double>dis(temp2);
			__temp_output;
			break;
		}
		case 9:{
			long double temp,temp2;
			cin>>temp>>temp2;
			gamma_distribution<long double>dis(temp,temp2);
			__temp_output;
			break;
		}
		case 10:{
			long double temp,temp2;
			cin>>temp>>temp2;
			weibull_distribution<long double>dis(temp,temp2);
			__temp_output;
			break;
		}
		case 11:{
			long double temp,temp2;
			cin>>temp>>temp2;
			extreme_value_distribution<long double>dis(temp,temp2);
			__temp_output;
			break;
		}
		case 12:{
			long double temp,temp2;
			cin>>temp>>temp2;
			normal_distribution<long double>dis(temp,temp2);
			__temp_output;
			break;
		}
		case 13:{
			long double temp,temp2;
			cin>>temp>>temp2;
			lognormal_distribution<long double>dis(temp,temp2);
			__temp_output;
			break;
		}
		case 14:{
			long double temp;
			cin>>temp;
			chi_squared_distribution<long double>dis(temp);
			__temp_output;
			break;
		}
		case 15:{
			long double temp;
			cin>>temp;
			cauchy_distribution<long double>dis(temp);
			__temp_output;
			break;
		}
		case 16:{
			long double temp;
			cin>>temp;
			fisher_f_distribution<long double>dis(temp);
			__temp_output;
			break;
		}
		case 17:{
			long double temp;
			cin>>temp;
			student_t_distribution<long double>dis(temp);
			__temp_output;
			break;
		}
		return;
	}
}
#undef __temp_output
