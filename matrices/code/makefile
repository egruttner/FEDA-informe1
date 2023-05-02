CC = g++
CFLAGS = -std=c++14 -O2

SRCS = main.cpp 
OBJS = $(SRCS:.cpp=.o)

TEST_CASES_NUMBER := $(shell seq 1 10) #rango de archivos de input y output

RANGE = 1 2 3 #distintos algoritmos a probar

# 1 STANDARD
# 2 TRANSPOSE
# 3 STRASSEN

INPUT_PREFIX := datasets/input$(num_dataset)/input

OUTPUT_PREFIX := output/output$(num_dataset)/output

all: program
	for j in $(RANGE); do \
		echo "Executing program with $$j --head $$num_dataset"; \
		./program $$j --head $$num_dataset; \
		for i in $(TEST_CASES_NUMBER); do \
			echo "./program --test $$j $$num_dataset < $(INPUT_PREFIX)$$i.txt > $(OUTPUT_PREFIX)$$j$$i.txt"; \
			./program $$j --test $$num_dataset < $(INPUT_PREFIX)$$i.txt > $(OUTPUT_PREFIX)$$j$$i.txt; \
		done; \
	done

program: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o program

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) program output*
