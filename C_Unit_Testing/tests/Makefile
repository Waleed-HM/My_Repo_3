# This global test makefile will run all the unit tests
# Each unit test will have its own makefile


#Define test component directories
TEST_DIRS = $(dir $(wildcard */))

#Default rule: run all tests
.PHONY: all $(TEST_DIRS)
all: $(TEST_DIRS)

# Run tests
# For each subdirectory found, run make from the context within a particular directory (-C) giving it that directory by the ($@)
$(TEST_DIRS):
	make -C $@

# Clean tests
.PHONY: clean
clean:
	$(foreach DIR, $(TEST_DIRS), make -C $(DIR) clean)

display:
	@echo $(TEST_DIRS)