// $Id: fileio.cpp,v 1.2 2016-05-09 16:01:56-07 - - $

#include "fileio.h"

bool check_filesystem(){
	// const char* ls_cmd = "ls ./data";
	// try{
		
 //   		if (popen (ls_cmd, "r")) { std::cout << "no data" << std::endl; }
   		
	// }catch(std::exception e){
	// 	std::cout << "error caught" << std::endl;
	// }
 //   	std::cout << "done w test" << std::endl;
	return 1;
}

void init_filesystem(){

}

//Class implementations

iohandler_basic::iohandler_basic(std::string file){
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

std::string iohandler_basic::currentfile(){
	return filename;
}

void iohandler_basic::closefile(){
	filename = "";
}

void iohandler_basic::openfile(std::string file){
	if(isopen()){
		closefile();
	}
	filename = file;
}

std::vector<std::string> iohandler_basic::read(){
	std::vector<std::string> ans;
	return ans;
}

void iohandler_basic::write(std::vector<std::string> data){
	for(std::string s : data){

	}
}

