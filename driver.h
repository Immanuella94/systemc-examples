#include <systemc.h>

SC_MODULE(driver){
	sc_out<bool> d_A,d_B,d_C;
	
	void drive(void);
	
	SC_CTOR(driver){
	}
};
