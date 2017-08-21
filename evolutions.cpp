// $Id: evolutions.cpp,v 1.2 2016-05-09 16:01:56-07 - - $

#include <iostream>

#include "debug.h"

using namespace std;

void scan_options (int argc, char** argv) {
   opterr = 0;
   for (;;) {
      int option = getopt (argc, argv, "@:w:h:");
      if (option == EOF) break;
      switch (option) {
         case '@': 
         	break;
         case 'w': 
         	break;
         case 'h': 
         	break;
         default:
            cerr << "-" << char (optopt) << ": invalid option" << endl;
            break;
      }
   }
}

int main(int argc, char** argv){
	DEBUGF( OPERATING_SYSTEM_NAME << " operating system detected.");

	scan_options(argc, argv);



}