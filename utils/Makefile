###############################
### Src and build locations ###
###############################

export BIN_DIR=../bin




###################################
### Where utilities are located ###
###################################

UTILS_1=examples_4l
UTILS_2=examples_ttbb

UTILS=$(UTILS_1) $(UTILS_2)

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


$(UTILS_1): $(BIN_DIR)
	$(MAKE) -C $(UTILS_1)


$(UTILS_2): $(BIN_DIR)
	$(MAKE) -C $(UTILS_2)


$(BIN_DIR):
	mkdir -p ${BIN_DIR}


#####################
### House janitor ###
#####################

.PHONY: clean

clean:
	$(MAKE) -C $(UTILS_1) clean
	$(MAKE) -C $(UTILS_2) clean
