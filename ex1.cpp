//#include <iostream>
//#include <fstream>
//using namespace std;
//
//int main() {
//	fstream inout;
//
//	inout.open("city.txt", ios::out);
//	inout << "Dallas" << " " << "Houston" << " " << "Atlanta" << " ";
//	inout.close();
//
//	inout.open("city.txt", ios::out | ios::app);
//	inout << "Savannah" << " " << "Austin" << " " << "Chicago";
//	inout.close();
//
//	string city;
//	inout.open("city.txt", ios::in);
//	while (!inout.eof()) {
//		inout >> city;
//		cout << city << " ";
//	}
//	inout.close();
//	return 0;
//}