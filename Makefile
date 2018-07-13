GTKWAVE:= which gtkwave

all: alu

alu:prerequisites
	@echo 'building file $(@F)'
	$(CXX) -I/usr/local/systemc-2.3.2/include -O0 -g3 -Wall -c alu.cc driver.cc monitor.cc nand.cc  main.cpp
	$(CXX) -L/usr/local/systemc-2.3.2/lib-linux64 -o "alu" alu.o driver.o monitor.o nand.o  main.o -lsystemc
	./alu
	gtkwave -c 4 vcd_trace.vcd

prerequisites: 
ifneq ('$(GTKWAVE)', "/usr/bin/gtkwave")
	@echo $(GTKWAVE)
	@echo 'installing gtkwave, please be patient'
	sudo apt-get install -y gtkwave
endif

clean:
	rm -f alu *.o vcd_trace.vcd
.PHONY: alu
