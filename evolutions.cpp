// $Id: evolutions.cpp,v 1.2 2016-05-09 16:01:56-07 - - $

#include <iostream>
#include <GL/glew.h>

#include "debug.h"
#include "fileio.h"

//** NOTE: DEBUGF TOGGLE in DEBUG.h **

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
            std::cerr << "-" << char (optopt) << ": invalid option" << std::endl;
            break;
      }
   }
}

int main(int argc, char** argv){
	DEBUGF(OPERATING_SYSTEM_NAME << " operating system detected.");

   //Check filesystem setup.
   if(!check_filesystem()){
      DEBUGF("Filesystem check ended in error. Performing first time filesystem setup...");
      //create /evolutions/bin, /evolutions/data
   }

	scan_options(argc, argv);



}