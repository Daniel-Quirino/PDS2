CC := g++
SRCDIR := src
TSTDIR := tests
OBJDIR := build
BINDIR := bin
INCDIR := include

MAIN := main.cpp


SRCEXT := cpp

SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
INCLUDES := $(addprefix -I ,$(addsuffix /,$(shell find $(INCDIR) -type d)))
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
TSTSOURCES := $(shell find $(TSTDIR) -type f -name *.$(SRCEXT))

# -g debug, --coverage para cobertura
CFLAGS := --coverage -g -Wall -O3 -std=c++11
INC := $(INCLUDES) -I third_party/

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

main: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $(MAIN) $^  -o $(BINDIR)/main 

all: main

run: main
	$(BINDIR)/main

coverage:
	@mkdir -p coverage/
	@gcov $(SOURCES) -rlpo build/
	@$(RM) *.gcda *.gcno

clean:
	$(RM) -r $(OBJDIR)/* $(BINDIR)/* coverage/* *.gcda *.gcno

.PHONY: clean coverage
