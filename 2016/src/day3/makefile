CP = g++
CPPFLAGS = -I./../../include -Wall -std=c++11 -pedantic -g
SRC = $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)

all: triangle

%.d: %.cpp
	$(CP) $(CPPFLAGS) -MM $^ > $@
-include $(SRC:.cpp=.d)

triangle: $(OBJS)
	$(CP) -o $@ $^ $(LDFLAGS)


.PHONY: clean
clean:
	rm -f *.o *.d triangle