// $Id: fileio.h,v 1.2 2016-05-09 16:01:56-07 - - $

#ifndef __FILEIO_H__
#define __FILEIO_H__

#include <string>
#include <vector>
#include <iostream> //ostream & cout

#include "extern.h"

/*
 * NOTE: FILESYSTEM EXPECTED to contain certain Folders
 *
 *	.../evolutions
 *			/bin	-> program-reserved items, REQUIRED for run.
 *			/data	-> user-created data NOT NECESSARY for run.
 *
 */

/*
 * Checks filesystem state. 
 * @return returns 1 if filesystem ok, 0 if in error.
 */
bool check_filesystem();
/*
 * Initializes whatever filesystem elements are missing.
 */
void init_filesystem();

//**** CLASSES ****

class iohandler_basic{
private:
	std::string filename; //empty string if anything other than filename.
public:
	iohandler_basic(std::string file); //default ctor override
	iohandler_basic(const iohandler_basic& io) = delete; //delete copy ctor
	iohandler_basic(iohandler_basic&& io) = delete; //delete move ctor
	iohandler_basic& operator=(const iohandler_basic& io) = delete; //delete copy opr
	iohandler_basic& operator=(iohandler_basic&& io) = delete; //delete move opr
	~iohandler_basic(); //default dtor override
	/*
	 * Closes current file if open and opens a file for reading. 
	 * @return true if a file is open, false otherwise.
	 */
	bool isopen();
	/*
	 * Closes current file if open and opens a file for reading. 
	 * @param filename: the file to be read from.
	 */
	std::string currentfile();
	/*
	 * Closes current file if open.
	 */
	void closefile();
	/*
	 * Closes current file if open and opens a file for reading. 
	 * @param filename: the file to be read from.
	 */
	void openfile(std::string file);
	/*
	 * Closes current file if open and opens a file for reading. 
	 * By defualt, this file returns a vector containing the lines of the file 
	 * exactly as they exist in the file.
	 * @param filename: the file to be read from.
	 * @NOTE: TO BE OVERRIDDEN IN SPECIALIZED CLASSES.
	 */
	std::vector<std::string> read();
	/*
	 * Writes to a currently open file, if one is open.
	 * @param data: data to be written, exactly how it should be written to the file.
	 *		(one line per vector entry.)
	 */
	void write(std::vector<std::string> data);

};






#endif