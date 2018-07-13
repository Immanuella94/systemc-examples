#include<systemc.h>

SC_MODULE(monitor){
	sc_in<bool> m_A,m_B,m_C,m_D, m_S;
	
	void mon(void);
	
	SC_CTOR(monitor){
		SC_METHOD(mon);
		sensitive<<m_A<<m_B<<m_C<<m_D<< m_S;
		dont_initialize();
	}
};
