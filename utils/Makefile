###############################
### Src and build locations ###
###############################

export BIN_DIR=../bin




###################################
### Where utilities are located ###
###################################

UTILS_1=examples_4l

UTILS=$(UTILS_1)

# Otherwise make is not happy if such names exist in PWD
.PHONY: $(UTILS)




###############################
### All utils for build all ###
###############################

all:	MEKD $(UTILS)




############################################
### Way to build individual utils blocks ###
############################################

MEKD:
	$(MAKE) -C ../


$(UTILS_1):
	$(MAKE) -C $(UTILS_1)




#####################
### House janitor ###
#####################

.PHONY: clean

clean:
	$(MAKE) -C $(UTILS_1) clean