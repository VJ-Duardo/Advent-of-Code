CP = g++
CPPFLAGS = -I./../../include -Wall -std=c++11 -pedantic -g
LDFLAGS = -lssl -lcrypto
SRC = $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)

all: password

%.d: %.cpp
	$(CP) $(CPPFLAGS) -MM $^ > $@
-include $(SRC:.cpp=.d)

password: $(OBJS)
	$(CP) -o $@ $^ $(LDFLAGS)


.PHONY: clean
clean:
	rm -f *.o *.d password