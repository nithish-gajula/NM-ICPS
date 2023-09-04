ARCH := $(shell uname -m)

ifeq ($(ARCH), x86_64)
	MESSAGE := "Running on x86-64 architecture"

else ifeq ($(ARCH), armv7l)
	MESSAGE := "Running on ARMv7 architecture"

else
	MESSAGE := "Running on an unsupported architecture"
endif

# Target
print_message:
	@echo $(MESSAGE)
