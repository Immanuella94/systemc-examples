GTKWAVE:= which gtkwave

all: 4bit

4bit:
	@echo 'building file $(@F)'
	$(CXX) -I/usr/local/systemc-2.3.2/include -O0 -g3 -Wall -c sr.cpp driver.cpp  main.cpp
	$(CXX) -L/usr/local/systemc-2.3.2/lib-linux64 -o "4bit" sr.o driver.o  main.o  -lsystemc
	./4bit
	gtkwave -c 4 vcd_trace.vcd

prerequisites: 
ifneq ('$(GTKWAVE)', "/usr/bin/gtkwave")
	@echo $(GTKWAVE)
	@echo 'installing gtkwave, please be patient'
	sudo apt-get install -y gtkwave
endif

clean:
	rm -f 4bit *.o vcd_trace.vcd
.PHONY: 4bit
