#------------------------------------------------------------------------------

SOURCE=Kernel/Kernel.cpp Kernel/Kernel.h Interface/Interface.cpp Interface/Interface.h Grammar/Grammar.h Grammar/Grammar.cpp Control/Control.h Control/Control.cpp main.cpp 
TEST1 = Kernel/Test1.cpp
TEST1P = test1
MYPROGRAM=Calculadora


CC=g++

#------------------------------------------------------------------------------



all: $(MYPROGRAM)
test1: $(TEST1)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


$(MYPROGRAM): $(SOURCE)

	$(CC) -I$(MYINCLUDES) $(SOURCE) -o$(MYPROGRAM) 

$(TEST1): $(SOURCE) $(TEST1)

	$(CC) -I$(MYINCLUDES) $(SOURCE) $(TEST1) -o$(TEST1P) 


clean:

	rm -f $(MYPROGRAM)

