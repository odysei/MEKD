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

test=$(BIN_DIRL)/MEKD_Test_ttbb

all: $(test)




######################
### Building block ###
######################

objects = main.o check_models.o functionality.o

$(test): $(objects)
	$(CXX) $(CXXFLAGS) -o $(test) $(objects) -L. $(LIBFLAGS) -l MEKD



.PHONY: clean

clean:
	rm -f $(objects)
	rm -f $(test)
