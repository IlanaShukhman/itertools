#pragma once
#include <iostream>

namespace itertools{

	template <typename T, typename BooleanT>
	class compress{
		T container;
		BooleanT b;
		public:	
		compress(T c, BooleanT _b):container(c),b(_b){}
		

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
