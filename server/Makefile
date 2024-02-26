.PHONY: all clean

CC = gcc
WCC = x86_64-w64-mingw32-gcc

BUILDDIR = ./build
SRCDIR = ./src
INCDIR = ./include
PRTDIR = ../common/proto
CMNDIR = ../common/
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(wildcard $(SRCDIR)/*.c))
PRTFILES = $(patsubst $(PRTDIR)/%.proto, $(SRCDIR)/%.pb-c.c, $(wildcard $(PRTDIR)/*.proto))
CMNOBJECTS = $(patsubst $(CMNDIR)$(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(wildcard $(CMNDIR)$(SRCDIR)/*.c))

PRTLIB = `pkg-config --cflags --libs libprotobuf-c`

INC += -I$(INCDIR) -I$(CMNDIR)$(INCDIR)

COMPILE = $(CC) $(INC) -c $< -o $@ -g
LINK=$(CC) -o $@
PROTOC = protoc --c_out=$(SRCDIR) --proto_path=../common/proto/ $<

$(SRCDIR)/%.pb-c.c $(SRCDIR)/%.pb-c.h: $(PRTDIR)/%.proto
	$(PROTOC);
	mv $(basename $@).h $(INCDIR)/$(basename $(notdir $@)).h

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(COMPILE)

$(BUILDDIR)/%.o: $(CMNDIR)$(SRCDIR)/%.c
	$(COMPILE)

main: $(PRTFILES) $(CMNOBJECTS) $(OBJECTS)
	$(LINK) $(OBJECTS) $(CMNOBJECTS) $(PRTLIB)

clean:
	rm -rf $(BUILDDIR)/*.o
	rm -f $(MAIN_OBJ)
	rm -f $(SRCDIR)/*.gen.*
	rm -f $(SRCDIR)/*.pb-c.*
	rm -f $(INCDIR)/*.gen.*
	rm -f $(INCDIR)/*.pb-c.*

sub: $(PRTFILES)
