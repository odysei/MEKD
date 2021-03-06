######################
### Compiler flags ###
######################

CXXFLAGS= -std=c++11 -pedantic -Wunused-variable -Werror=sign-compare \
-Wunused-but-set-variable -Werror=return-type -Werror=missing-braces \
-Werror=delete-non-virtual-dtor -Werror=maybe-uninitialized \
-fPIC -O \
-I $(PROJECT_DIR) \
-I $(INCDIR0) -I $(INCDIR1) -I $(INCDIR2) -I $(INCDIR2_0) \
-I $(INCDIR2_1_src) -I $(INCDIR2_2_src) -I $(INCDIR2_3_src) \
-I $(INCDIR2_4_src) -I $(INCDIR2_5_src) -I $(INCDIR2_6_src) -I $(INCDIR3)
CFLAGS= -pedantic -Wunused-variable -Werror=sign-compare \
-Wunused-but-set-variable -Werror=return-type -Werror=missing-braces \
-Werror=delete-non-virtual-dtor -Werror=maybe-uninitialized \
-fPIC -std=c99
LIBFLAGS=-L $(LIBDIR)




####################
### Custom flags ###
####################

ifeq ($(MEKD_STANDALONE), Yes)
CXXFLAGS+= -D MEKD_STANDALONE
endif

ifeq ($(MEKD_COMPILE_WITH_ROOT), Yes)
CXXFLAGS+= -D MEKD_with_ROOT
#CXXFLAGS+= -I $(shell root-config --incdir)
CXXFLAGS+= $(shell root-config --cflags)
CXXFLAGS+= $(shell root-config --ldflags)
LIBFLAGS+= $(shell root-config --libs --glibs)
endif
