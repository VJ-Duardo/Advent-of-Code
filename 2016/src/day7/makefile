CP = g++
CPPFLAGS = -I./../../include -Wall -std=c++11 -pedantic -g
SRC = $(wildcard *.cpp)
SRC += ./../utils/utils.cpp
OBJS = $(SRC:.cpp=.o)

all: ip

%.d: %.cpp
	$(CP) $(CPPFLAGS) -MM $^ > $@
-include $(SRC:.cpp=.d)

ip: $(OBJS)
	$(CP) -o $@ $^ $(LDFLAGS)


.PHONY: clean
clean:
	rm -f *.o *.d ip