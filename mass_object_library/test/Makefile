# *******************************************************************
# Copyright (c) University of Luxembourg 2023.
# Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
# ********************************************************************

CXX = g++  # C++ compiler
CXXFLAGS = -fsanitize=address -fsanitize=undefined -Wall -Wextra -O0 -g -I../include -I.
LDFLAGS =  -fsanitize=address -fsanitize=undefined -L../bin/ -lmassobjects -lgcov # linking flags
CXXFLAGS_FLAKY = -DFLAKY
RM = rm -f   # rm command
NAME = run_test  # target executable
SRCS = main.cpp tests.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) $(LDFLAGS) -o $(NAME)

flaky: $(SRCS)
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_FLAKY) $(SRCS) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(NAME)

