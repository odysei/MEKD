###############################
### Src and build locations ###
###############################

LIBDIR=$(PROJECT_DIR)/lib

INCDIR0=$(PROJECT_DIR)/interface
INCDIR1=$(PROJECT_DIR)/src
INCDIR2=$(PROJECT_DIR)/src/MG5_aMCNLO
INCDIR2_0=$(INCDIR2)/Commons
INCDIR2_1=$(INCDIR2)/HEF_MEKD
INCDIR2_2=$(INCDIR2)/HEF_UFO_Unitary
INCDIR2_3=$(INCDIR2)/HEFTU
INCDIR2_4=$(INCDIR2)/sm-full
INCDIR2_5=$(INCDIR2)/HiggsPO_UFO
INCDIR2_6=$(INCDIR2)/Leptophilic_UFO

INCDIR2_1_src=$(INCDIR2_1)/src
INCDIR2_2_src=$(INCDIR2_2)/src
INCDIR2_3_src=$(INCDIR2_3)/src
INCDIR2_4_src=$(INCDIR2_4)/src
INCDIR2_5_src=$(INCDIR2_5)/src
INCDIR2_6_src=$(INCDIR2_6)/src

INCDIR3=$(PROJECT_DIR)/src/Extra_code

PDF_DIR=$(PROJECT_DIR)/src/PDF_tables


########## ROOT PART ##########
# Makefile_flags does the job now
#ROOTLIB=$(ROOTSYS)/lib
# OR
# root-config --libs
#ROOTINCLUDES=$(ROOTSYS)/include
# OR
# root-config --incdir
###############################
