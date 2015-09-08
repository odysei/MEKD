###############################
### Src and build locations ###
###############################

export BIN_DIR=../bin




###############################
### Where tests are located ###
###############################

TEST_1=test_4l

TEST=$(TEST_1)

# Otherwise make is not happy if such names exist in PWD
.PHONY: $(TEST)




###############################
### All utils for build all ###
###############################

all:	MEKD $(TEST)




############################################
### Way to build individual utils blocks ###
############################################

MEKD:
	$(MAKE) -C ../


$(TEST_1):
	$(MAKE) -C $(TEST_1)




#####################
### House janitor ###
#####################

.PHONY: clean

clean:
	$(MAKE) -C $(TEST_1) clean
