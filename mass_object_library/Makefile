# *******************************************************************
# Copyright (c) University of Luxembourg 2023.
# Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
# ********************************************************************
#without coverage
CC = clang++ # C++ compiler
CXXFLAGS = -fsanitize=address -fsanitize=undefined -Wall -Wextra -O2 -g -Iinclude -fPIC # C++ flags with sanitizers and PIC for shared library
LDFLAGS_SHARED = -shared -fsanitize=address -fsanitize=undefined # linking flags for shared library
LDFLAGS_STATIC = -fsanitize=address -fsanitize=undefined # linking flags for static library
RM = rm -f # rm command
TARGET_LIB_SHARED = ./libmassobjects.so # target shared library (in parent directory)
TARGET_LIB_STATIC = ./libmassobjects.a # target static library (in parent directory)
TARGET_LIB_BC = ./libmassobjects.a.bc

SRCS = src/circle.cpp \
    src/rectangle.cpp \
    src/square.cpp \
    src/triangle.cpp \
    src/error.cpp

OBJS = $(SRCS:.cpp=.o)
BC_OBJS = $(SRCS:.cpp=.bc)


# Compile object files  
%.o: %.cpp  
	$(CC) $(CXXFLAGS) -c $< -o $@

.PHONY: all
all: ${TARGET_LIB_SHARED} ${TARGET_LIB_STATIC}

# Build shared library
$(TARGET_LIB_SHARED): $(OBJS)
	$(CC) $(LDFLAGS_SHARED) -o $@ $^

# Build static library
$(TARGET_LIB_STATIC): $(OBJS)
	ar rcs $@ $^
	
$(TARGET_LIB_BC): $(BC_OBJS)
	llvm-link $(BC_OBJS) -o $@

# Dependency generation
$(SRCS:.cpp=.d): %.d: %.cpp
	$(CC) $(CXXFLAGS) -MM $< > $@

include $(SRCS:.cpp=.d)

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB_SHARED} ${TARGET_LIB_STATIC} ${TARGET_LIB_BC} ${OBJS} $(BC_OBJS) $(SRCS:.cpp=.d)