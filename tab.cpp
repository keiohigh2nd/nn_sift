#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include "k-nn1.hpp"
#include <fstream>

using namespace std;

int main()
{
    const std::string g_file_name = "../good_desc.txt";
    std::ifstream g_file(g_file_name.c_str());
    if (!g_file){
	cerr << "Failed to open file: file name=" << g_file_name << endl;
	return 1;
    }

    std::string g_temp;
    vector<vector<double> > a;
    int i_a = 0;
    while (std::getline(g_file, g_temp)) {
           	a.push_back(vector<double> ()); 
	   	stringstream ss(g_temp);
           	for (double x; ss>>x;) {
	     		a.back().push_back(x);
	  }
	}
	
	
    const std::string m_file_name = "../mal_desc.txt";
    std::ifstream m_file(m_file_name.c_str());
    std::string m_temp;
    vector<vector<double> > b;
    while (std::getline(m_file, m_temp)) {
	     	b.push_back(vector<double>());
	     	stringstream ss(m_temp);
	     	for (double x; ss>>x;) {	  
	     		b.back().push_back(x);
	   }
	 }
	
		
    const std::string q_file_name = "../query_desc.txt";
    std::ifstream q_file(q_file_name.c_str());
    std::string q_temp;
    vector<vector<double> > p;
    while(std::getline(q_file, q_temp)) {
      		p.push_back(vector<double>());
      		stringstream ss(q_temp);
      		for (double x; ss>>x;){
      			p.back().push_back(x);
      }
     }

    int k = 13;
    double start = gettimeofday_sec();

    vector<int> ret = k_nn(a,b,p,k);	
    ofstream ofs( "text.txt" );
    std::cout << ret.size() << "-----tab size" << std::endl;
    for (size_t it = 0; it < ret.size(); ++it) {
	if (ret[it] == 0){
	    ofs <<ret[it]<< endl;
	}else if (ret[it] == 1) {
	    ofs <<ret[it]<< endl;
	}		
    }
    
    /*
    int res_int = nn(a,b,p);
    std::ofstream ofs1( "nbnn_test.txt", std::ios::app );
    ofs1 << res_int << std::endl;
    */

    double end = gettimeofday_sec();
    cout << "Time = " << end - start << " sec." << endl;
	return 0;
}
