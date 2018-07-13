#include "systemc.h"
#include "nand.h"
SC_MODULE(alu)          // declare alu sc_module
{

 sc_in<bool> A,B,C;       // input signal ports
  sc_out<bool> D,S;         // output signal ports
  
  
   void alu_method(void);        // a C++ function
   ~alu();
   
 	nand *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8, *n9;
	
  sc_signal<bool> sig, S1, S2, S3 , S4, S5, S6, S7;
		SC_CTOR(alu)  {
		n1=new nand("N1");
		n2=new nand("N2");
		n3=new nand("N3");
		n4=new nand("N4");
		n5=new nand("N5"); 
		n6=new nand("N6"); 
		n7=new nand("N7"); 
		n8=new nand("N8"); 
		n9=new nand("N9"); 
		
		n1->A(A);
		n1->B(B);
		n1->F(S1);
		
		n2->A(S1);
		n2->B(A);
		n2->F(S2);
		
		n3->A(S1);
		n3->B(B);
		n3->F(S3);
		
		n4->A(S2);
		n4->B(S3);
		n4->F(S4);
		
		n5->A(C);
		n5->B(S4);
		n5->F(S5);
		
		n6->A(C);
		n6->B(S5);
		n6->F(S6);
		
		n7->A(S5);
		n7->B(S4);
		n7->F(S7);
		
		n8->A(S5);
		n8->B(S1);
		n8->F(D);
		
		
		n9->A(S6);
		n9->B(S7);
		n9->F(S);
		
		  
   
  SC_CTOR(alu)          // constructor for alu
  {
    SC_METHOD(alu_method);  // register alu with kernel
    sensitive << A << B << C;  // sensitivity list
  }
};








