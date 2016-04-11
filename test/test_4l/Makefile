# System type
UNAME := $(shell uname)

#############################################
### Project location and makefile commons ###
#############################################

PROJECT_DIR=../../

include $(PROJECT_DIR)/Makefile_includes
include $(PROJECT_DIR)/Makefile_flags



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
test2=MEKD_Test_v3
test3=MEKD_Test_HiggsPO

all: $(test) $(test2) $(test3)




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
	echo '${test} does not compile without ROOT.'
endif


$(test2):
	$(CXX) $(CXXFLAGS) $(test2).cpp -o $(BIN_DIRL)/$(test2) -L. \
$(LIBFLAGS) -l MEKD


$(test3):
	$(CXX) $(CXXFLAGS) $(test3).cpp -o $(BIN_DIRL)/$(test3) -L. \
$(LIBFLAGS) -l MEKD



.PHONY: clean

clean:
	rm -f $(BIN_DIRL)/$(test)
