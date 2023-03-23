OBJS = tokenizer.o ui.o history.o
CFLAGS= -g -O3
all : tokenizer
tokenizer : $(OBJS)
	cc -o tokenizer $(CFLAGS) $(OBJS)
clean :
	rm -f *.o * ~ * -g *.gch tokenizer

run : tokenizer
	./tokenizer
