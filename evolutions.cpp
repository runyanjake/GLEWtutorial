// $Id: evolutions.cpp,v 1.2 2016-05-09 16:01:56-07 - - $

#include "extern.h"

#include "debug.h"
#include "fileio.h"
#include "graphics.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "transform.h"

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

   basic_window win(_PROG_NAME, 640, 480);


   //TEST

   Vertex verts[] = {Vertex(glm::vec3(-0.5,-0.5,0), glm::vec2(0.0,0.0)),
                        Vertex(glm::vec3(0,0.5,0), glm::vec2(0.5,1.0)),
                        Vertex(glm::vec3(0.5,-0.5,0), glm::vec2(1.0,0.0)), };

   Mesh mesh(verts , (sizeof(verts)) / (sizeof(verts[0])) );
   Shader shader("./data/basicShader");
   Texture texture("./data/vinod.jpg");
   Transform transform;

   float counter = 0.0f;

   while(!win.isclosed()){
      win.clear(0.0f,0.15f,0.3f,1.0f);

      float sinctr = sinf(counter);
      float cosctr = cosf(counter);
      transform.getPos().x = sinf(counter);
      transform.getRot().z = counter;
      transform.setScale(glm::vec3(cosctr, cosctr, cosctr));
      
      shader.Bind();  
      texture.Bind(0);
      shader.Update(transform);
      mesh.draw();
      
      win.Update();
      counter += 0.1f; //Multiplier on counter updates.
   }

   //Destroy all Graphics Stuff


   return 0;
}