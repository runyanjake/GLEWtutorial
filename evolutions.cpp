// $Id: evolutions.cpp,v 1.2 2016-05-09 16:01:56-07 - - $

#include "extern.h"

#include "debug.h"
#include "fileio.h"
#include "graphics.h"

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

int main(int argc, char *argv[]){
	DEBUGF(OPERATING_SYSTEM_NAME << " operating system detected.");

   //Check filesystem setup.
   if(!check_filesystem()){
      DEBUGF("Filesystem check ended in error. Performing first time filesystem setup...");
      //create /evolutions/bin, /evolutions/data
   }

	scan_options(argc, argv);

   //Initialize Graphics Stuff
   SDL_Init(SDL_INIT_EVERYTHING);
   SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
   SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
   SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
   SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
   SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32); //hold all pixel attributes
   SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
   //The following 2 lines may only be needed on non-O SX computers.
   //"Basically, since OpenGL is a core feature of OSX, you don't need to include GLEW."
   //GLenum glew_status = glewInit();
   //if(glew_status != GLEW_OK){ ERRORF("Glew failed to initialize."); }

   basic_window win("test window", 640, 480);

   while(!win.isclosed()){
      glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);
      win.swapbuffers();
   }

   //Destroy all Graphics Stuff


   return 0;
}