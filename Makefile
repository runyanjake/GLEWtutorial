# $Id: Makefile,v 1.7 2016-07-25 20:09:21-07 - - $

# Evolutions Makefile
# github.com/runyanjake/evolutions Makefile
# @author Jake Runyan, adapted from Wesley Mackey's CMPS109

WARN     = -Wall -Wextra -Wold-style-cast
GPP      = g++ -std=gnu++14 -g -O0 ${WARN}

EXECBIN  = evolutions
DEPFILE  = Makefile.dep
HEADERS  = util.h debug.h tflow.h fileio.h graphics.h interp.h shape.h rgbcolor.h extern.h
CPPLIBS  = util.cpp debug.cpp tflow.cpp fileio.cpp graphics.cpp interp.cpp shape.cpp rgbcolor.cpp
CPPSRCS  = ${CPPLIBS} ${EXECBIN}.cpp
LIBOBJS  = ${CPPLIBS:.cpp=.o}
EVOOBJS  = ${EXECBIN}.o ${LIBOBJS}
OBJECTS  = ${EVOOBJS}
LISTING  = Listing.ps
SOURCES  = ${HEADERS} ${CPPSRCS} Makefile
FRAMEWORK= -framework SDL2 -framework OpenGL



all: ${DEPFILE} ${EXECBIN} 

evolutions: ${EVOOBJS}
	${GPP} -o $@ ${EVOOBJS} $(FRAMEWORK)
	#NOTE: IMPORTANT to link SDL lib with -framework for SDL to work.

%.o: %.cpp
	${GPP} -c $<

lis: all ${SOURCES} ${DEPFILE}
	mkpspdf ${LISTING} ${SOURCES} ${DEPFILE}

clean:
	- rm ${LISTING} ${LISTING:.ps=.pdf} ${OBJECTS} Makefile.dep

spotless: clean
	- rm ${EXECBIN}

test: ${EXECBIN}
	make
	chmod +x ${EXECBIN}
	-@echo
	-@echo
	-@echo
	./${EXECBIN}
	-@echo
	-@echo
	-@echo
	-@echo
	make spotless

dep:
	- rm ${DEPFILE}
	make --no-print-directory ${DEPFILE}

${DEPFILE}:
	${GPP} -MM ${CPPSRCS} >${DEPFILE}

again: ${SOURCES}
	make --no-print-directory spotless ci all lis

include ${DEPFILE}

