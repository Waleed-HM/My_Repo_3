#Define test component directories
TEST_DIRS = $(dir $(wildcard */))

#Default rule: run all tests
.PHONY: all $(TEST_DIRS)
all: $(TEST_DIRS)

# Run tests
$(TEST_DIRS):
	make -C $@