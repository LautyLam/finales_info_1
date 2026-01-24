CC		=	gcc
CFLAGS	=	-c -Wall -g -fpack-struct -I$(HEADDIR)/
LDFLAGS	=	-Wall -g

VERSION	=	
CLASE	=	
OBJDIR	=	.
BINDIR	=	.
SRCDIR	=	.
HEADDIR	=	.
OBJS	=	$(OBJDIR)/main$(VERSION).o $(OBJDIR)/funciones$(VERSION).o
SOURCES	=	main$(VERSION).c funciones$(VERSION).c
HEADERS	=	funciones$(VERSION).h
EJEC	=	ejec


$(BINDIR)/$(EJEC): $(OBJS)
	mkdir -p $(BINDIR)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c Makefile
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(BINDIR)/$(EJEC)
	rm -r $(OBJDIR)
	rm -r $(BINDIR)

new: clean $(BINDIR)/$(EJEC)

git:
	git commit -m "Clase $(CLASE) Version $(VERSION)"
	git push
