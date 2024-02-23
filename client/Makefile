.PHONY: all clean

CC = gcc

BUILDDIR = ./build
SRCDIR = ./src
PRSDIR = ./parser
PRTDIR = ../common/proto
INCDIR = ./include
CMNDIR = ../common/
FLEXFILES = $(patsubst $(PRSDIR)/%.l, $(SRCDIR)/%.gen.c, $(wildcard $(PRSDIR)/*.l))
BISONFILES = $(patsubst $(PRSDIR)/%.y, $(SRCDIR)/%.gen.c, $(wildcard $(PRSDIR)/*.y))
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(wildcard $(SRCDIR)/*.c))
PRTFILES = $(patsubst $(PRTDIR)/%.proto, $(SRCDIR)/%.pb-c.c, $(wildcard $(PRTDIR)/*.proto))
CMNOBJECTS = $(patsubst $(CMNDIR)$(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(wildcard $(CMNDIR)$(SRCDIR)/*.c))

PRTLIB = `pkg-config --cflags --libs libprotobuf-c`

INC += -I$(INCDIR) -I$(CMNDIR)$(INCDIR)

COMPILE = $(CC) $(INC) -c $< -o $@
# не нашел способа адекватнее в мейке разделить на две директории
BISON = bison -o $@ --header=$(INCDIR)/$(basename $(notdir $@)).h $<
FLEX = flex -o $@ -i $<
LINK=$(CC) -o $@
PROTOC = protoc --c_out=$(SRCDIR) --proto_path=../common/proto/ $<

$(SRCDIR)/%.gen.c $(INCDIR)/%.gen.h: $(PRSDIR)/%.y
	$(BISON)

$(SRCDIR)/%.pb-c.c $(SRCDIR)/%.pb-c.h: $(PRTDIR)/%.proto
	$(PROTOC)
	mv $(basename $@).h $(INCDIR)/$(basename $(notdir $@)).h

$(SRCDIR)/%.gen.c: $(PRSDIR)/%.l
	$(FLEX)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(COMPILE)

$(BUILDDIR)/%.o: $(CMNDIR)$(SRCDIR)/%.c
	$(COMPILE)

main: $(FLEXFILES) $(BISONFILES) $(PRTFILES) $(CMNOBJECTS) $(OBJECTS)
	$(LINK) $(OBJECTS) $(CMNOBJECTS) $(PRTLIB)

clean:
	rm -rf $(BUILDDIR)/*.o
	rm -f $(MAIN_OBJ)
	rm -f $(SRCDIR)/*.gen.*
	rm -f $(SRCDIR)/*.pb-c.*
	rm -f $(INCDIR)/*.gen.*
	rm -f $(INCDIR)/*.pb-c.*

sub: $(FLEXFILES) $(BISONFILES) $(PRTFILES)
