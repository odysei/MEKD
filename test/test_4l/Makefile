# System type
UNAME := $(shell uname)

#############################################
### Project location and makefile commons ###
#############################################

PROJECT_DIR=../../

include $(PROJECT_DIR)/makefiles/include.mk
include $(PROJECT_DIR)/makefiles/flags.mk



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

test=$(BIN_DIRL)/MEKD_Test
test2=$(BIN_DIRL)/MEKD_Test_v3
# test3=$(BIN_DIRL)/MEKD_Test_HiggsPO

all: $(test) $(test2) #$(test3)




######################
### Building block ###
######################

# objects = main.o check_models.o functionality.o
objects2 = main_v3.o check_models_v3.o functionality_v3.o
# objects3 = main.o check_models.o functionality.o

ifeq ($(MEKD_COMPILE_WITH_ROOT), Yes)

$(test):
	$(CXX) $(CXXFLAGS) `$(ROOTSYS)/bin/root-config --ldflags` \
-I $(ROOTINCLUDES) $(test).cpp -o $(BIN_DIRL)/$(test) -L. $(LIBFLAGS) \
-L $(ROOTLIB) `$(ROOTSYS)/bin/root-config --libs --glibs` -l MEKD
else

$(test):
	echo '${test} does not compile without ROOT.'
endif


$(test2): $(objects2)
	$(CXX) $(CXXFLAGS) -o $(test2) $(objects2) -L. $(LIBFLAGS) -l MEKD


$(test3):
	$(CXX) $(CXXFLAGS) -o $(test3) $(objects3) -L. $(LIBFLAGS) -l MEKD



.PHONY: clean

clean:
	rm -f $(objects)
	rm -f $(test)
	rm -f $(objects2)
	rm -f $(test2)
	rm -f $(objects3)
	rm -f $(test3)
