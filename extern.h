// $Id: extern.h,v 1.2 2016-05-09 16:01:56-07 - - $

//global includes every file should have
#include <iostream>

//**** Determine Operating System
#if (defined (__WIN32__))
#define OPERATING_SYSTEM 1
#define OPERATING_SYSTEM_NAME "Windows32"
#elif (defined (__APPLE__))
#define OPERATING_SYSTEM 2
#define OPERATING_SYSTEM_NAME "Apple"
#elif (defined (__WIN64__))
#define OPERATING_SYSTEM 3
#define OPERATING_SYSTEM_NAME "Windows64"
#elif (defined (__linux__))
#define OPERATING_SYSTEM 4
#define OPERATING_SYSTEM_NAME "Linux"
#endif