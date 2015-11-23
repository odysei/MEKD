# System type
UNAME := $(shell uname)

#############################################
### Project location and makefile commons ###
#############################################

PROJECT_DIR=.

include $(PROJECT_DIR)/Makefile_includes
include $(PROJECT_DIR)/Makefile_flags




################################
### Include objects to build ###
################################

include Makefile_objects



###################
### All targets ###
###################

targetlib=$(LIBDIR)/libMEKD.so

all: $(targetlib)



#######################
### Special targets ###
#######################

# consecutive execution
core:
	$(MAKE) clean_core
	$(MAKE) $(targetlib)




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



.PHONY: clean clean_core

clean:
	rm -f $(targetlib); \
	rm -f $(objects)

clean_core:
	rm -f $(targetlib); \
	rm -f $(objects0)
