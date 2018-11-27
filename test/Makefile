###############################
### Src and build locations ###
###############################

export BIN_DIR=bin




###############################
### Where tests are located ###
###############################

TEST_1=test_4l
TEST_2=test_ttbb

TEST=$(TEST_1) $(TEST_2)

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


$(TEST_1): $(BIN_DIR)
	$(MAKE) -C $(TEST_1)


$(TEST_2): $(BIN_DIR)
	$(MAKE) -C $(TEST_2)


$(BIN_DIR):
	mkdir -p ${BIN_DIR}



#####################
### House janitor ###
#####################

.PHONY: clean

clean:
	$(MAKE) -C $(TEST_1) clean
	$(MAKE) -C $(TEST_2) clean
