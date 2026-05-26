# Compiler to use
CC = gcc

# Compiler flags:
#
# -Wall: enable all warning messages
# -Wextra: enable extra warning flags
# -g : include debugging information
# -fsanitize=address,undefined: sanitizers
# -fno-omit-frame-pointer: always maintain and use the frame pointer register
CFLAGS = -Wall -Wextra -g -fsanitize=address,undefined -fno-omit-frame-pointer -Icipher

# Target executable name
TARGET = cipher

# Specify the build directory
BUILD_DIR = build

# Source files
SRCS = main.c cipher/affine.c

# Object files (replace .c with .o)
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)


.PHONY: clean all

# Default rule to build the target
all: $(BUILD_DIR)/$(TARGET)

# Link object files to create the executable
$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Compile source into object files
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Order-only prerequisite — create dir if missing
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm  -rf $(BUILD_DIR)
