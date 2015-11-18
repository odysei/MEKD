# System type
UNAME := $(shell uname)

###############################
### Src and build locations ###
###############################

LIBDIR=lib

INCDIR0=interface
INCDIR1=src
INCDIR2=src/Extra_code
INCDIR3=src/higgs_properties
INCDIR4=src/MG5_aMCNLO
INCDIR4_0=$(INCDIR4)/Commons
INCDIR4_1=$(INCDIR4)/HEF_UFO_Unitary
INCDIR4_2=$(INCDIR4)/HEF_MEKD
INCDIR4_3=$(INCDIR4)/sm-full
INCDIR4_3_=$(INCDIR4)/sm-full/src

PDF_DIR=src/PDF_tables




######################
### Compiler flags ###
######################

CXXFLAGS= -std=c++11 -pedantic -Wunused-variable -Werror=sign-compare \
-Wunused-but-set-variable -Werror=return-type -Werror=missing-braces -fPIC -O \
-I $(INCDIR0) -I $(INCDIR1) -I $(INCDIR2) -I $(INCDIR3) -I $(INCDIR4) \
-I $(INCDIR4_0) -I $(INCDIR4_1) -I $(INCDIR4_3_)
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




################################
### Include objects to build ###
################################

include Makefile_objects



###################
### All targets ###
###################

targetlib=$(LIBDIR)/libMEKD.so

all: $(targetlib)




############################
### Linux building block ###
############################

ifeq ($(UNAME), Linux)
# do something Linux-y

$(targetlib): $(objects)
	$(CXX) $(CXXFLAGS) -fPIC -shared -Wl,-soname,libMEKD.so \
-o $(targetlib) $(objects) $(LIBFLAGS)
endif




#############################
### Mac OS building block ###
#############################

ifeq ($(UNAME), $(filter $(UNAME),OSX Darwin))
# do something OSX-y

$(targetlib): $(objects)
	$(CXX) $(CXXFLAGS) -shared -Wl,-install_name,libMEKD.so \
-o $(targetlib) $(objects) $(LIBFLAGS)
endif



.PHONY: clean

clean:
	rm -f $(targetlib); \
	rm -f $(objects)
