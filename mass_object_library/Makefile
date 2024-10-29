# *******************************************************************
# Copyright (c) University of Luxembourg 2023.
# Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
# ********************************************************************
#without coverage
CC = clang++ # C++ compiler
CXXFLAGS = -g -fsanitize=fuzzer-no-link -fno-sanitize=undefined -fprofile-instr-generate -fcoverage-mapping -Wl,--no-as-needed -Wl,-ldl -Wl,-lm -Wno-unused-command-line-argument # C++ flags with sanitizers and PIC for shared library
LDFLAGS_SHARED = -shared -fsanitize=fuzzer-no-link -fsanitize=undefined # linking flags for shared library
LDFLAGS_STATIC = -fsanitize=fuzzer-no-link -fsanitize=undefined # linking flags for static library
RM = rm -f # rm command
TARGET_LIB_SHARED = ./libmassobjects.so # target shared library (in parent directory)
TARGET_LIB_STATIC = ./libmassobjects.a # target static library (in parent directory)

SRCS = src/circle.cpp \
    src/rectangle.cpp \
    src/square.cpp \
    src/triangle.cpp \
    src/error.cpp

OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all: ${TARGET_LIB_SHARED} ${TARGET_LIB_STATIC}

# Build shared library
$(TARGET_LIB_SHARED): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS_SHARED) -o $@

# Build static library
$(TARGET_LIB_STATIC): $(OBJS)
	ar rcs $@ $^

# Dependency generation
$(SRCS:.cpp=.d): %.d: %.cpp
	$(CC) $(CXXFLAGS) -MM $< > $@

include $(SRCS:.cpp=.d)

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB_SHARED} ${TARGET_LIB_STATIC} ${OBJS} $(SRCS:.cpp=.d)


