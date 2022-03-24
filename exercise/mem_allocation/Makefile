########################################################################
####################### Makefile Template ##############################
########################################################################

# Implicit Rules

# Make loves c compilation. And every time it expresses its love, 
# things get confusing. Perhaps the most confusing part 
# of Make is the magic/automatic rules that are made. 
# Make calls these "implicit" rules. I don't personally 
# agree with this design decision, and I don't recommend 
# using them, but they're often used and are thus useful 
# to know. Here's a list of implicit rules:

#     Compiling a C program: n.o is made automatically from n.c with 
# 			a command of the form $(CC) -c $(CPPFLAGS) $(CFLAGS)
#     Compiling a C++ program: n.o is made automatically from n.cc or n.cpp 
# 			with a command of the form $(CXX) -c $(CPPFLAGS) $(CXXFLAGS)
#     Linking a single object file: n is made automatically from n.o by 
# 			running the command $(CC) $(LDFLAGS) n.o $(LOADLIBES) $(LDLIBS)

# The important variables used by implicit rules are:

#     CC: Program for compiling C programs; default cc
#     CXX: Program for compiling C++ programs; default g++
#     CFLAGS: Extra flags to give to the C compiler
#     CXXFLAGS: Extra flags to give to the C++ compiler
#     CPPFLAGS: Extra flags to give to the C preprocessor
#     LDFLAGS: Extra flags to give to compilers when they are supposed to invoke the linker

# $@ -> command $? -> first prequisites $^ -> all presiquites

SHELL=/bin/bash

# Compiler settings - Can be customized.
CC = gcc
CXXFLAGS = -std=c11 -Wall
LDFLAGS = 

# Makefile settings - Can be customized.
APPNAME = mem_allocation
EXT = .c
SRCDIR = ./src
OBJDIR = ./dist

############## Do not change anything from here downwards! #############
SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=%.d)
# UNIX-based OS variables & settings
RM = rm
DELOBJ = $(OBJ)
# Windows OS variables & settings
DEL = del
EXE = .exe
WDELOBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)\\%.o)

########################################################################
####################### Targets beginning here #########################
########################################################################


all: $(APPNAME)

# run your binary
run: $(APPNAME)
	./$(APPNAME)

# Builds the app
$(APPNAME): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Creates the dependecy rules
%.d: $(SRCDIR)/%$(EXT)
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:%.d=$(OBJDIR)/%.o) >$@

# Includes all .h files
-include $(DEP)

# Building rule for .o files and its .c/.cpp in combination with all .h
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	$(CC) $(CXXFLAGS) -o $@ -c $<

################### Cleaning rules for Unix-based OS ###################
# Cleans complete project
.PHONY: clean
clean:
	$(RM) $(DELOBJ) $(DEP) $(APPNAME)

# Cleans only all files with the extension .d
.PHONY: cleandep
cleandep:
	$(RM) $(DEP)

#################### Cleaning rules for Windows OS #####################
# Cleans complete project
.PHONY: cleanw
cleanw:
	$(DEL) $(WDELOBJ) $(DEP) $(APPNAME)$(EXE)

# Cleans only all files with the extension .d
.PHONY: cleandepw
cleandepw:
	$(DEL) $(DEP)