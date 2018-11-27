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

test=MEKD_Test_ttbb

all: $(test)




######################
### Building block ###
######################

$(test):
	$(CXX) $(CXXFLAGS) $(test).cpp -o $(BIN_DIRL)/$(test) -L. $(LIBFLAGS) \
-l MEKD



.PHONY: clean

clean:
	rm -f $(BIN_DIRL)/$(test)
