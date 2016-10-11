
# Compiler Flags
#-c: compile (only) into object, if used  with -o specifies output object file name
#-o: link object files into executable
#-Wall: This enables all the warnings about constructions that some users
# consider questionable, and that are easy to avoid (or modify to prevent the warning), even in conjunction with macros
#-Wfatal-errors: This option causes the compiler to abort compilation on the first error occurred rather than trying to
# keep going and printing further error messages.
# -Wextra: This enables some extra warning flags that are not enabled by -Wall

# Automatic Variables
# $@ The file name of the target of the rule
# $< The name of the first prerequisite
# $^ The names of all the prerequisites, with spaces between them (unique, dupes not copied, order not guaranteed).
# $| The names of all the order-only prerequisites, with spaces between them.

# Pattern Rule
# You define an implicit rule by writing a pattern rule. A pattern rule looks like an ordinary rule, except that its
# target contains the character ‘%’ (exactly one of them). The target is considered a pattern for matching file names;
# the ‘%’ can match any nonempty substring, while other characters match only themselves. The prerequisites likewise
# use ‘%’ to show how their names relate to the target name.
# Thus, a pattern rule ‘%.o : %.c’ says how to make any file stem.o from another file stem.c.

TARGET_PREFIX=
CC        := $(TARGET_PREFIX)gcc
AS        := $(TARGET_PREFIX)as
LD        := $(TARGET_PREFIX)ld
NM        := $(TARGET_PREFIX)nm
OBJDUMP   := $(TARGET_PREFIX)objdump
OBJCOPY   := $(TARGET_PREFIX)objcopy
SIZE      := $(TARGET_PREFIX)size

TOP=$(shell pwd)
TARGET=run
C_SOURCE_FILES +=  	main.c         \
					linkedlist.c   \

OBJ=$(C_SOURCE_FILES:.c=.o)

INC_PATHS +=.

CFLAGS  = -c
# CFLAGS += -Wall
# CFLAGS += -Wextra
CFLAGS += -ggdb
CFLAGS += $(addprefix -I, $(INC_PATHS))

all: clean $(TARGET)

%.o:%.c
	$(CC) $(CFLAGS)  $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@
	./$(TARGET)

clean:
	@find $(TOP) -type f -name "*.o"  -delete
	@rm -f $(TARGET)
	@echo "cleaned."

.PHONY: clean