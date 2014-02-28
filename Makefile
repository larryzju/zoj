TARGET=$(patsubst %.c, %, $(wildcard *.c)) 

all:$(TARGET)

%:%.c
	gcc -o $@ $^ -std=c89 -lm -ansi -g -Wall

.PHONY:

clean:
	@rm -f $(TARGET)
