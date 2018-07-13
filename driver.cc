#include "driver.h"

void driver::drive(void){
	while(1){
		d_A=0;
		d_B=0;
		d_C=0;
		wait(5,SC_NS);
		d_A=0;
		d_B=0;
		d_C=1;
		wait(5,SC_NS);
		d_A=0;
		d_B=1;
		d_C=0;
		wait(5,SC_NS);
		d_A=0;
		d_B=1;
		d_C=1;
		wait(5,SC_NS);
		d_A=1;
		d_B=0;
		d_C=0;
		wait(5,SC_NS);
		d_A=1;
		d_B=0;
		d_C=1;
		wait(5,SC_NS);
		d_A=1;
		d_B=1;
		d_C=0;
		wait(5,SC_NS);
		d_A=1;
		d_B=1;
		d_C=1;
		wait(5,SC_NS);
}
}
