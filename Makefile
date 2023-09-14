# List of directories to clean
DIRECTORIES = ./Bit_Fields /Bitwise_Operators /C_Programs /Memory /Pointers /review /Unions

# List of file extensions to keep
EXTENSIONS = .c

# Define the clean target
clean:
	@for dir in $(DIRECTORIES); do \
		echo "Cleaning files with extensions other than $(EXTENSIONS) in $$dir..."; \
		find $$dir -type f ! -name "*$(EXTENSIONS)" -exec rm -f {} \;; \
		echo "Cleanup complete for $$dir."; \
	done

