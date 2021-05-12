/* date = March 26th 2021 1:01 pm */
#ifndef _RINGLISTE_H
#define _RINGLISTE_H

#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <vector>
#include <math.h>
#include <string>

class Ringliste{
		
		private:
		int readPos = 0;
		int writePos = 0;
		int capacity = 0;
		int used = 0;
		
		std::vector<int> list;
		std::vector<int>& getList();
		
		public:
		Ringliste();
		Ringliste(int size);
		
		~Ringliste();
		
		Ringliste& operator<<(Ringliste& r);
		Ringliste& operator<<(int num);
		Ringliste& operator+=(int insertNum);
		bool operator==(Ringliste r);
		std::string toString();
		
};

/////////////////////////////////////////////////////////////////

class istTeilerVon_n{
		int teiler;
		
		public:
		istTeilerVon_n(int n): teiler(n){} //constructor
		
		bool operator()(int zahl) const;
		bool operator()(int n, int zahl) const;
		
		~istTeilerVon_n(){}
};

/////////////////////////////////////////////////////////////////

class istNahe{
		    double tolerance;
		    double hinterlegt;
		
		public:
		    istNahe(double in): hinterlegt(in), tolerance(pow(10, -4)){} //constructor
		    istNahe(double in, double tolerance): hinterlegt(in), tolerance(tolerance){} //constructor
		
		    bool operator()(double in1) const;
		    bool operator()(double in1, double in2) const;

            ~istNahe(){}
};

/////////////////////////////////////////////////////////////////

class istKuerzerAls{
		public:
		    bool operator()(std::string obj1, std::string obj2)const;
};

/////////////////////////////////////////////////////////////////

class besitztMehrWorteAls{
    private:
        std::string obj1;

    public:    
        besitztMehrWorteAls(std::string obj1): obj1(obj1){}

        bool operator()(std::string obj2)const;
        int countWords(std::string sent)const;
};
#endif //_RINGLISTE_H
