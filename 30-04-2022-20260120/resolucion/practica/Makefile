CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
OBJS= func_plogic.o plogic.o
HEADERS=*.h
EXE=plogic
MAKEFILE=Makefile

$(EXE): $(OBJS)
	@echo "### Generando el ejecutable"
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.c $(MAKEFILE) $(HEADERS)
	@echo "### Compilando " $<
	$(CC) $(CFLAGS) $< -o $@

clean:
	@echo "### Borrando todo"
	rm -f $(OBJS)
	rm -f $(EXE)

all: clean $(EXE)


