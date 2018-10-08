#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <stdlib.h>


#define MEM_DATA_FILE "mem.txt"
#define INSTR_DATA_FILE "instr.txt"
#define REGISTER_LIST_SIZE 32

int program_counter;


//tested
void printv(std::vector <std::string> v){
	for(std::vector <std::string>::iterator i=v.begin(); i!=v.end(); i++)
		std::cout << *i << std::endl;
}
//tested
template <typename T>
void print(T word){
	std::cout << word << std::endl;
}

//tested
int file_size(std::string file_name){
	int size = 0;
	std::string tmp;
	std::ifstream file(file_name); 
    if (file.is_open())
        while (getline(file, tmp))
        	size++;
    file.close();
    return size;
}

//tested
template <typename T>
void read(std::vector <T> &data, std::string file_name){
	std::ifstream file(file_name); 
	int i=0;
    if (file.is_open()){
        if(file_name == MEM_DATA_FILE)
        	while(i<REGISTER_LIST_SIZE){
        		getline(file, data[i]);
        		i++;
        	}
        else
        	while (getline(file, data[i]))
        		i++;
        }
    file.close();
}
void write();

//tested
int instruction_size(std::string s, std::string sep=", "){
	int pos = 0;
	int size;
	while((pos=s.find(sep))!=std::string::npos){
		size++;
		s.erase(0, pos + sep.length());
	}
	size++;
	return size;
}
//tested
std::vector<std::string> universal_parser(std::string s, std::string sep){
	int pos;
	std::vector<std::string> v;
	if((pos=s.find(";"))!=std::string::npos)
		s.erase(pos, pos+1);
	while((pos=s.find(sep))!=std::string::npos){
			v.push_back(s.substr(0,pos));
			s.erase(0, pos + sep.length());
		}
	v.push_back(s);
	return v;
}

//tested
std::vector <std::string> instruction_parser(std::string s){
	std::string sep = ", ";
	std::vector<std::string> v (instruction_size(s, sep));
	v = universal_parser(s, sep);
	sep = " ";
	std::vector<std::string> w(instruction_size(v[0], sep));
	w = universal_parser(v[0], sep);
	std::vector<std::string> x;
	for(auto i = 0; i<w.size(); i++)
		x.push_back(w[i]);
	for(auto i=1; i<v.size(); i++)
		x.push_back(v[i]);
	return x;
}





int main(int argc, char const *argv[])
{
	
	return 0;
}