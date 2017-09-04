// $Id: fileio.cpp,v 1.2 2016-05-09 16:01:56-07 - - $

#include "fileio.h"

using namespace std;

bool check_filesystem(){
	const char* ls_cmd = "ls ./data";
	try{
		
   		if (popen (ls_cmd, "r")) { cout << "no data" << endl; }
   		
	}catch(exception e){
		cout << "error caught" << endl;
	}
   	cout << "done w test" << endl;
	return 1;
}

void init_filesystem(){

}

//Class implementations

iohandler_basic::iohandler_basic(string file){
	filename = file;
	//iohandler = {file, ios_base::in | ios_base::out };
}

iohandler_basic::~iohandler_basic(){
	filename = "";
}

bool iohandler_basic::isopen(){
	if(filename != "") return true;
	return false;
}

string iohandler_basic::currentfile(){
	return filename;
}

void iohandler_basic::closefile(){
	filename = "";
}

void iohandler_basic::openfile(string file){
	if(isopen()){
		closefile();
	}
	filename = file;
}

vector<string> iohandler_basic::read(){
	vector<string> ans;
	return ans;
}

void iohandler_basic::write(vector<string> data){
	for(string s : data){

	}
}

