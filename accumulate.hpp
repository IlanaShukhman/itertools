#pragma once
#include <iostream>
#include <vector>

namespace itertools{

	typedef struct {
		template <typename T>
		T operator ()(T x, T y) const{
			return x+y;
		}
	}plus;

	
	template <typename T, typename Function = plus>
	class accumulate{
		T container;
		Function f;
		public:	
		accumulate(T c, Function f=plus()):container(c),f(f){}
		

		class iterator{	
			public:
			int pointed;
			iterator(){};
			iterator(int _pointed): pointed(_pointed){}

			auto operator*(){
			}

			const iterator& operator++(){

			}

			bool operator!=(const iterator& other) const {
				
			}   
			int operator + (iterator i){
				
			}


		};









		
		typename T::iterator begin(){return container.begin();}
		typename T::iterator end(){return container.end();}

	};

}
