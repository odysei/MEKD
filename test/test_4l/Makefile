# System type
UNAME := $(shell uname)

###############################
### Src and build locations ###
###############################

LIBDIR=../../lib

INCDIR0=../../interface

########## ROOT PART ##########
ROOTLIB=$(ROOTSYS)/lib
ROOTINCLUDES=$(ROOTSYS)/include
###############################




######################
### Compiler flags ###
######################

CXXFLAGS= -std=c++11 -pedantic -Wunused-variable -Werror=sign-compare \
-Wunused-but-set-variable -Werror=return-type -Werror=missing-braces -fPIC -O \
-I $(INCDIR0)
CFLAGS= -pedantic -Wunused-variable -Werror=sign-compare \
-Wunused-but-set-variable -Werror=return-type -Werror=missing-braces -fPIC \
-std=c99
LIBFLAGS=-L $(LIBDIR)




####################
### Custom flags ###
####################

ifeq ($(MEKD_STANDALONE), Yes)
CXXFLAGS+= -D MEKD_STANDALONE
endif

ifeq ($(MEKD_COMPILE_WITH_ROOT), Yes)
CXXFLAGS+= -D MEKD_with_ROOT -std=c++0x
endif



#######################
### Target location ###
#######################

# Local BIN_DIR
ifeq ($(strip $(BIN_DIR)),)
	BIN_DIRL=.
else
	BIN_DIRL=../$(BIN_DIR)
endif



###################
### All targets ###
###################

test=MEKD_Test

all: $(test)




######################
### Building block ###
######################

ifeq ($(MEKD_COMPILE_WITH_ROOT), Yes)

$(test):
	$(CXX) $(CXXFLAGS) `$(ROOTSYS)/bin/root-config --ldflags` \
-I $(ROOTINCLUDES) $(test).cpp -o $(BIN_DIRL)/$(test) -L. $(LIBFLAGS) \
-L $(ROOTLIB) `$(ROOTSYS)/bin/root-config --libs --glibs` -l MEKD
else

$(test):
	$(CXX) $(CXXFLAGS) $(test).cpp -o $(BIN_DIRL)/$(test) -L. $(LIBFLAGS) \
-l MEKD
endif



.PHONY: clean

clean:
	rm -f $(BIN_DIRL)/$(test)
