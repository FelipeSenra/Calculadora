#------------------------------------------------------------------------------

SOURCE=Kernel/Kernel.cpp Kernel/Kernel.h Grammar/Grammar.h
TEST1 = Kernel/Test1.cpp
TEST1P = test1
MYPROGRAM=Calculadora


CC=g++

#------------------------------------------------------------------------------



all: $(MYPROGRAM)
test1: $(TEST1)


$(MYPROGRAM): $(SOURCE)

	$(CC) -I$(MYINCLUDES) $(SOURCE) -o$(MYPROGRAM) 

$(TEST1): $(SOURCE) $(TEST1)

	$(CC) -I$(MYINCLUDES) $(SOURCE) $(TEST1) -o$(TEST1P) 


clean:

	rm -f $(MYPROGRAM)

