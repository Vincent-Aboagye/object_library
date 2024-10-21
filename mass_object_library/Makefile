# *******************************************************************
# Copyright (c) University of Luxembourg 2023.
# Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
# ********************************************************************

CC = g++ # C compiler
CXXFLAGS = -fsanitize=address -fsanitize=undefined -Wall -Wextra -O0 -g -Iinclude -fprofile-arcs -ftest-coverage -fPIC # C++ flags
LDFLAGS = -fsanitize=address -fsanitize=undefined -lgcov # linking flags
RM = rm -f # rm command
TARGET_LIB = ./bin/libmassobjects.a # target lib
AR = ar
MKDIR = mkdir -p

SRCS = src/circle.cpp \
    src/rectangle.cpp \
    src/square.cpp \
    src/triangle.cpp \
    src/error.cpp

OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all: ${TARGET_LIB}

$(TARGET_LIB): $(OBJS)
	$(MKDIR) bin
	$(AR) rcs $@ $^

$(SRCS:.cpp=.d):%.d:%.cpp
	$(CXX) $(CXXFLAGS) -MM $< >$@

include $(SRCS:.cpp=.d)

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJS} $(SRCS:.cpp=.d) $(SRCS:.cpp=.gcno) $(SRCS:.cpp=.gcda) $(SRCS:.cpp=.gcov)
