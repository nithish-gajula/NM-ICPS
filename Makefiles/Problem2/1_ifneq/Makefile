# Target operating system
OS := $(shell uname -s)

ifneq ($(OS), Linux)
	MESSAGE := "Operating system is not Linux"
else
	MESSAGE := "Running on Linux"
endif

# Target
print_message:
	@echo $(MESSAGE)
