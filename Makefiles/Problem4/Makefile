# Original filenames
SRCS = main.c utils.c foo.c

# Example usage of subst
SUBST_SRCS = $(subst .c,.o,$(SRCS))
# Result: SUBST_SRCS = main.o utils.o foo.o

# Example usage of patsubst
PATSUBST_SRCS = $(patsubst %.c,%.o,$(SRCS))
# Result: PATSUBST_SRCS = main.o utils.o foo.o

all:
	@echo $(SUBST_SRCS)
	@echo $(PATSUBST_SRCS)
