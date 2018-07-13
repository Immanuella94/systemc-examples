#include <systemc.h>
#include "alu.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[])
{
	sc_signal<bool> s_A, s_B,s_C,s_D,s_S;

	alu alu1("alu");
	driver dr("driver");
	monitor mon("monitor");

	dr.d_A(s_A);
	alu1.A(s_A);
	mon.m_A(s_A);
	
	dr.d_B(s_B);
	alu1.B(s_B);
	mon.m_B(s_B);
	
	dr.d_C(s_C);
	alu1.C(s_C);
	mon.m_C(s_C);
	
	alu1.D(s_D);
	mon.m_D(s_D);
	
	
	alu1.S(s_S);
	mon.m_S(s_S);
	

	
	sc_trace_file *fp;
	fp=sc_create_vcd_trace_file("vcd_trace");
	fp->set_time_unit(1, SC_NS);
	
	sc_trace(fp, s_A, "a");
	sc_trace(fp, s_B, "b");
	sc_trace(fp, s_C, "c");
	sc_trace(fp, s_D, "d");
	sc_trace(fp, s_S, "s");
	
	
	sc_start(20, SC_NS);
	sc_close_vcd_trace_file(fp);
	return 0;
}
};
