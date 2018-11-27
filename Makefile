# System type
UNAME := $(shell uname)

#############################################
### Project location and makefile commons ###
#############################################

PROJECT_DIR=.

include $(PROJECT_DIR)/makefiles/include.mk
include $(PROJECT_DIR)/makefiles/flags.mk




################################
### Include objects to build ###
################################

include makefiles/objects.mk



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
