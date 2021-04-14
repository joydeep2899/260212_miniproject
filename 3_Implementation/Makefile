# Name of the project
PROJECT_NAME = huffman

# Output directory
BUILD = build


ifdef OS
   RM = del 
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif


# All source code files
SRC = main.c\
src/huffman.c

# All test source files
TEST_SRC = src/huffman.c\
test/test.c\
unity/unity.c\

TEST_OUTPUT = $(BUILD)/Test_$(PROJECT_NAME)

# All include folders with header files
INC	= -Iinc\
-Iunity\

#Library Inlcudes
#INCLUDE_LIBS = 
INCLUDE_LIBS = -lcunit

# Project Output name
PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME)

# Document files
DOCUMENTATION_OUTPUT = documentation

# coverage 
COV_SRC = test.c


# Default target built
$(PROJECT_NAME):all






# Run the target even if the matching name exists
.PHONY: run clean test doc all

all: $(SRC) $(BUILD)
	gcc $(SRC) $(INC) -o $(PROJECT_OUTPUT).$(EXEC)

# Call `make run` to run the application
run:$(PROJECT_NAME)
	./$(PROJECT_OUTPUT).$(EXEC)

# Document the code using Doxygen
doc:$(DOCUMENTATION_OUTPUT)/doc
	doxygen $(DOCUMENTATION_OUTPUT)/doc

# Build and run the unit tests
test:$(BUILD)
	gcc $(TEST_SRC) $(INC) -o $(TEST_OUTPUT) 
	./$(TEST_OUTPUT).$(EXEC)



coverage:
	cp test/test.c .
	gcc -fprofile-arcs -ftest-coverage  $(INC)   unity/unity.c test/test.c src/huffman.c -o $(call FixPath, $(TEST_OUTPUT).$(EXEC))
	$(call FixPath, ./$(TEST_OUTPUT).$(EXEC))
	gcov -a $(COV_SRC)
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov
	$(RM) test.c


debug:
	gcc $(INC) $(SRC) -g -o ./$(PROJECT_OUTPUT).out
	gdb  ./$(PROJECT_OUTPUT).out
valgrind:
	valgrind ./$(PROJECT_OUTPUT).out
cppcheck:
	cppcheck  $(SRC)  $(INC)  --enable=all --suppress=missingIncludeSystem 




# Remove all the built files, invoke by `make clean`
clean:
	rm -rf $(BUILD) $(DOCUMENTATION_OUTPUT)/html $(DOCUMENTATION_OUTPUT)/latex

# Create new build folder if not present
$(BUILD):
	mkdir build
