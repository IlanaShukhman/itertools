#pragma once
#include <iostream>
#include <vector>

namespace itertools{

	
	template <typename T, typename Function>
	class filterfalse{
		T container;
		Function f;
		public:	
		filterfalse(Function f, T c):container(c),f(f){}
		

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
