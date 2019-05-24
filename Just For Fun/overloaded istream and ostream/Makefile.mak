CPP    = g++
WINDRES= windres
RM     = rm -f
OBJS   = main.o \
         Array.o \
         AppResource.res

LIBS   =
CFLAGS =

.PHONY: Array\ Class.exe clean clean-after

all: Array\ Class.exe

clean:
	$(RM) $(OBJS) Array\ Class.exe

clean-after:
	$(RM) $(OBJS)

Array\ Class.exe: $(OBJS)
	$(CPP) -Wall -s -O2 -o '$@' $(OBJS) $(LIBS)

main.o: main.cpp Array.h
	$(CPP) -Wall -s -O2 -c $< -o $@ $(CFLAGS)

Array.o: Array.cpp Array.h
	$(CPP) -Wall -s -O2 -c $< -o $@ $(CFLAGS)

AppResource.res: AppResource.rc
	$(WINDRES) -i AppResource.rc -J rc -o AppResource.res -O coff

