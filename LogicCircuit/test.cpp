#include"InputPortElement.h"
#include"BinaryElement.h"
#include"UnaryElement.h"
#include"CombinationalCircuit.h"
#include"CircuitSimulator.h"

void mux_4_1(std::string fname) {
	INPUT(adr0);
	INPUT(adr1);
	INPUT(D0);
	INPUT(D1);
	INPUT(D2);
	INPUT(D3);
	UNELEMENT(not_adr0, adr0_e, INVERTOR);
	UNELEMENT(not_adr1, adr1_e, INVERTOR);
	TERELEMENT(expd0, not_adr0, not_adr1, D0_e, AND);
	TERELEMENT(expd1, not_adr0, adr1_e, D1_e, AND);
	TERELEMENT(expd2, adr0_e, not_adr1,D2_e,AND);
	TERELEMENT(expd3, not_adr0, not_adr1, D2_e, AND);
	BINELEMENT(f_half, expd0, expd1, OR);
	BINELEMENT(s_half, expd2,expd3,OR);
	BINELEMENT(res, f_half, s_half, OR);
	OUTPUT(F, res);
	CIRCUIT(crct)({adr0,adr1,D0,D1,D2,D3,F},//ports
		{ 
		adr0_e,adr1_e,
		not_adr0,not_adr1,
		D0_e,D1_e,D2_e,D3_e,
		expd0,expd1,expd2,expd3,
		f_half,s_half,
		res 
		});
	CircuitSimulator p(fname, crct);
	p.Simulate();
	delete crct;
}


int main(){
	mux_4_1("fg.txt");
	system("pause");
}
