#include<iostream>
using namespace std;
class unitConverter {
public:
	double ratti(int grams) { return grams / 0.1302; };
	double masha(int grams) { return grams / 1.0417; };
	double tola(int grams) { return grams / 12.5; };
	double chhatank(int grams) { return grams /	62.5; };
	double pao(int grams) { return grams / 250; };
	double sair(int grams) { return grams / 1000; };
	double man(int grams) { return grams / 40000; };
	double ton(int grams) { return grams / 1000000; };
};
class PAKUnits {
	public:
		double sirsahi(int sft);
		double marla(int sft);
		double kanal(int sft);
		double acar(int sft);
};
double PAKUnits::acar(int sft) {
	return sft / 43560;
}
double PAKUnits::kanal(int sft) {
	return sft / 5445;
}
double PAKUnits::marla(int sft) {
	return sft / 272.25;
}
double PAKUnits::sirsahi(int sft) {
	return sft / 30.5;
}


int main() {
	PAKUnits p1;
	unitConverter u1;
	int sft, grams,select;
	while (true) {
		cout << " 1) area conversion.\n";
		cout << " 2) mass conversion.\n";
		cout << " 3) exit\n";
		cout << "..."; cin >> select;
		switch (select) {
		case 1:
			cout << "enter area in square feet: "; cin >> sft;
			cout << sft << " square feet = " << p1.sirsahi(sft) << " sirsahi, " << p1.marla(sft) << " marla, " << p1.kanal(sft) << " kanal, " << p1.acar(sft) << " acar.\n\n\n";
			break;
		case 2:
			cout << "enter mass in grams: "; cin >> grams;
			cout << grams << " grams = \n";
			cout << u1.ton(grams) << " Ton, " << u1.man(grams) << " Man, " << u1.sair(grams) << " Sair, " << u1.pao(grams) << " Pao, " << u1.chhatank(grams) << " Chattank, " << u1.tola(grams) << " Tola, " << u1.masha(grams) << " Masha, " << u1.ratti(grams) << " Ratti.\n\n\n";
			break;
		case 3:
			exit(0);
		}
	}


}