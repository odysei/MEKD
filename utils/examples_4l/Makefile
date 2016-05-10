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




################################
### Include objects to build ###
################################

include Makefile_objects




###################
### All targets ###
###################

example1=runKD_MAD
example2=eval_MEs_model_HiggsPO

all: $(example1) $(example2)




######################
### Building block ###
######################

$(example1): $(example1).o
	$(CXX) $(CXXFLAGS) -o $(BIN_DIRL)/$(example1) $(example1).o \
	-L. $(LIBFLAGS) -l MEKD

$(example2): $(example2).o $(objects2)
	$(CXX) $(CXXFLAGS) -o $(BIN_DIRL)/$(example2) $(example2).o \
	$(objects2) -L. $(LIBFLAGS) -l MEKD


.PHONY: clean

clean:
	rm -f $(objects2); \
	rm -f $(BIN_DIRL)/$(example1).o; \
	rm -f $(BIN_DIRL)/$(example1); \
	rm -f $(BIN_DIRL)/$(example2).o; \
	rm -f $(BIN_DIRL)/$(example2)
