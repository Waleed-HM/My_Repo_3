# Global tests makefile

# Define test component directories
TEST_DIRS = $(dir $(wildcard */))


# Default rule : run all tests
all: $(TEST_DIRS)

# Run tests
# For each subdirectory found, run make from their respective context
$(TEST_DIRS):
	make -C $@

clean:
	$(foreach DIR, $(TEST_DIRS), make -C $(DIR) clean;)


dispaly:
	@echo $(TEST_DIRS)

.PHONY: all clean dispaly $(TEST_DIRS)