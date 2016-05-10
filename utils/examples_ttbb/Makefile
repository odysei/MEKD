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

example=produce_lgKDs

all: $(example)




######################
### Building block ###
######################

$(example): $(example).o $(objects)
	$(CXX) $(CXXFLAGS) -o $(BIN_DIRL)/$(example) $(example).o $(objects) \
	-L. $(LIBFLAGS) -l MEKD


.PHONY: clean

clean:
	rm -f $(objects); \
	rm -f $(example).o; \
	rm -f $(BIN_DIRL)/$(example)
