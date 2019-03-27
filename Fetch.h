#pragma once
#include "InterStateBuffers.h"

#include <bitset>
#include <map>
#include <fstream>
#include <sstream>

// TODO 
#define MEM_SRC "machineCode.txt"
#define REG_WIDTH 32

using namespace std;

//Change Here, Global Interstate Buffer ka object
// extern InterStateBuffers buf;

class Fetch {
	
	private:
		map <int , bitset <REG_WIDTH> > mem_map;
		map <int , int> itype_map;

	public:
	Fetch() {
		ifstream inpFile (MEM_SRC);
		string line;
		while(getline (inpFile , line ) ){
			string lineNo, command , type;
			stringstream ss (line);
			ss >> lineNo >> command >> type;
			bitset<REG_WIDTH> bitset(command.c_str());
			mem_map[atoi(lineNo.c_str())] = bitset;
			itype_map[atoi(lineNo.c_str())] = atoi (type.c_str());
		}
		
	}
	
	
	void get(InterStateBuffers & buf) {
	//	cout<<" $$$$$$ "<<mem_map[buf.PC]<<endl;
		buf.IR.writeBitset ( mem_map[buf.PC]);
		buf.insType = itype_map[ buf.PC ];
		
	}

};
