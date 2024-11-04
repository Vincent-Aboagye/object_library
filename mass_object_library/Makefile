# *******************************************************************
# Copyright (c) University of Luxembourg 2023.
# Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
# ********************************************************************
#without coverage
CC = clang++ # C++ compiler

# C++ flags with sanitizers, PIC, and LLVM bitcode generation
CXXFLAGS = -fsanitize=address -fsanitize=undefined -Wall -Wextra -O2 -g -Iinclude -fPIC -emit-llvm 

LDFLAGS_SHARED = -shared -fsanitize=address -fsanitize=undefined # linking flags for shared library
LDFLAGS_STATIC = -fsanitize=address -fsanitize=undefined # linking flags for static library
RM = rm -f # rm command

TARGET_LIB_SHARED = ./libmassobjects.so # target shared library
TARGET_LIB_STATIC = ./libmassobjects.a # target static library
TARGET_LIB_BC = ./libmassobjects.a.bc # target bitcode library

SRCS = src/circle.cpp \
    src/rectangle.cpp \
    src/square.cpp \
    src/triangle.cpp \
    src/error.cpp

# Generate .bc files for each source file
BC_OBJS = $(SRCS:.cpp=.bc)

# Compile .bc (LLVM bitcode) files instead of .o files
%.bc: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

.PHONY: all
all: ${TARGET_LIB_SHARED} ${TARGET_LIB_STATIC} ${TARGET_LIB_BC}

# Build shared library (without LLVM bitcode)
$(TARGET_LIB_SHARED): $(BC_OBJS)
	$(CC) $(LDFLAGS_SHARED) -o $@ $(BC_OBJS)

# Build static library (without LLVM bitcode)
$(TARGET_LIB_STATIC): $(BC_OBJS)
	ar rcs $@ $^

# Build single bitcode file from all .bc files
$(TARGET_LIB_BC): $(BC_OBJS)
	llvm-link $(BC_OBJS) -o $@

# Dependency generation
$(SRCS:.cpp=.d): %.d: %.cpp
	$(CC) $(CXXFLAGS) -MM $< > $@

include $(SRCS:.cpp=.d)

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB_SHARED} ${TARGET_LIB_STATIC} ${TARGET_LIB_BC} $(BC_OBJS) $(SRCS:.cpp=.d)



