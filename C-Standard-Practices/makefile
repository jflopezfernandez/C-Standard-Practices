
# Implicit Rules
#
# Compiling C Programs
# n.o: n.c
#     $(CC) $(CPPFLAGS) $(CFLAGS) -c
#
# Compiling C++ Programs
# n.o: n.cpp
#     $(CXX) $(CPPFLAGS) $(CXXFLAGS) -c
#
# Assembling and Preprocessing Assembler Programs
# n.o: n.s
#     $(AS) $(ASFLAGS)
#
# Linking a Single Object File (Made automatically by running the linker 'ld'
# via the C Compiler)
# n: n.o
#     $(CC) $(LDFLAGS) n.o $(LOADLIBES) $(LDLIBES)

.SUFFIXES: .c .o

vpath %.h include
vpath %.c src

CFLAGS := -std=c11 -Wall -Wextra -pedantic
CPPFLAGS := -I include

SRCS := main.c file.c
OBJS := $(patsubst %.c, %.o, $(SRCS))

PROGRAM := stdc.exe

.PHONY: all
all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	cc $(CFLAGS) $^ -o $@

$(OBJS): %.o: %.c
	cc -c $(CFLAGS) $(CPPFLAGS) $< -o $@

%.d: %.c
	@set -e; rm -f $@; \
	cc -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

include $(SRCS:.c=.d)

.PHONY: clean
clean:
	rm -rf *.d *.o *.exe
