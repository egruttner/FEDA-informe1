CC = g++
CFLAGS = -std=c++14 -O2

SRCS = main.cpp 
OBJS = $(SRCS:.cpp=.o)

TEST_CASES_NUMBER := $(shell seq 1 10) #rango de archivos de input y output

RANGE = 1 2 3 4 #distintos algoritmos a probar

# 1 SELECTION
# 2 MERGESORT
# 3 QUICKSORT
# 4 SORTSTL

INPUT_PREFIX := datasets/input$(foo)/input

OUTPUT_PREFIX := output1/output

all: program

	for j in $(RANGE); do \
		echo "Executing program with $$j"; \
		./program $$j; \
		for i in $(TEST_CASES_NUMBER); do \
			echo "./program --test $$j < $(INPUT_PREFIX)$$i.txt > $(OUTPUT_PREFIX)$$j$$i.txt"; \
			./program $$j --test < $(INPUT_PREFIX)$$i.txt > $(OUTPUT_PREFIX)$$j$$i.txt; \
		done; \
	done

program: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o program

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) program output*

