CP = g++
CPPFLAGS = -I./../../include -Wall -std=c++11 -pedantic -g
LDFLAGS = -lssl -lcrypto
SRC = $(wildcard *.cpp)
SRC += ./../utils/utils.cpp
OBJS = $(SRC:.cpp=.o)

all: signals

%.d: %.cpp
	$(CP) $(CPPFLAGS) -MM $^ > $@
-include $(SRC:.cpp=.d)

signals: $(OBJS)
	$(CP) -o $@ $^ $(LDFLAGS)


.PHONY: clean
clean:
	rm -f *.o *.d signals