CC = g++
CFLAGS = -std=c++14 -O2

SRCS = main.cpp 
OBJS = $(SRCS:.cpp=.o)

TEST_CASES_NUMBER := $(shell seq 1 10) #rango de archivos de input y output

RANGE = 1 2 #distintos algoritmos a probar

INPUT_PREFIX := datasets/input

OUTPUT_PREFIX := output/output

all: program
	for j in $(RANGE); do \
		for i in $(TEST_CASES_NUMBER); do \
			echo "./program --test $$j < $(INPUT_PREFIX)$$i.txt > $(OUTPUT_PREFIX)$$j$$i.txt"; \
			./program $$j --test < $(INPUT_PREFIX)$$i.txt > $(OUTPUT_PREFIX)$$j$$i.txt; \
		done; \
		echo "Executing program with $$j"; \
		./program $$j; \
	done

program: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o program

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) program output*
