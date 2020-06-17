#pragma once

#include <iostream>
#include <vector>
using namespace std;
namespace itertools{

	class range {
		int b,e;
		int p;

		public:
		range(){};
		range(int _p) : p(_p) {}
		range(int _b, int _e){
			b=_b;
			e=_e;
			p= b;		
		}
		class iterator{	
			public:
			int pointed;
			iterator(){};
			iterator(int _pointed): pointed(_pointed){}

			int operator*(){
				return pointed;
			}

			const iterator& operator++(){
				pointed++;
				return *this;
			}

			bool operator!=(const iterator& other) const {
				return this->pointed != other.pointed;
			}   
			int operator + (iterator i){
				return (this->pointed + i.pointed);
			}


		};

		iterator begin() {return b; }
		iterator end() {return e;}
	};
}
