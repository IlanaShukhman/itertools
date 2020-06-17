#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include "range.hpp"
#include "accumulate.hpp"
#include "filterfalse.hpp"
#include "compress.hpp"
 
using namespace itertools;


TEST_CASE("range"){
	int arr[20];
	int j=0;
	for (int i : range (0,50)){
		CHECK(i==j);
		j++;
	}
}


TEST_CASE("accumulate"){
	int arr[10];
	int j=0;
	
	for (int i: accumulate(range(5,12))){
		arr[j] = i;
		j++;
	}

	CHECK(arr[0] == 5);
	CHECK(arr[1] == 11);
	CHECK(arr[2] == 18);
	CHECK(arr[3] == 26);
	CHECK(arr[4] == 35);
	CHECK(arr[5] == 45);
	CHECK(arr[6] == 56);
	CHECK(arr[7] == 68);
	CHECK(arr[8] == 81);

	vector<string> vecString = {"Hello", "Bye", "Adam","See","You","Later"};
	string stringarr[10];
	j=0;
	
	for (auto i: accumulate(vecString) ){
		stringarr[j] = i;
	}

	CHECK(stringarr[0] == "Hello");
	CHECK(stringarr[1] == "HelloBye");
	CHECK(stringarr[2] == "HelloByeAdam");
	CHECK(stringarr[3] == "HelloByeAdamSee");
	CHECK(stringarr[4] == "HelloByeAdamSeeYou");
	CHECK(stringarr[5] == "HelloByeAdamSeeYouLater");
	
	j=0;
	for (int i: accumulate(range(1,9), [](int x, int y){return x*y;})){
		arr[j] = i;
		j++;
	}	

	CHECK(arr[0] == 1);
	CHECK(arr[1] == 2);
	CHECK(arr[2] == 6);
	CHECK(arr[3] == 24);
	CHECK(arr[4] == 120);
	CHECK(arr[5] == 720);
	CHECK(arr[6] == 5040);
	CHECK(arr[7] == 40320);
	CHECK(arr[8] == 362880);

	
	

	vector<float> vecFloat = {-1, 0.3, 5.2, -8.3, 64.4, 0, -12, 40320};
	float farr[10];
	j=0;

	for (auto i: accumulate(vecFloat, [](int x){return x/2;}))
		farr[j++] = i;

	CHECK(arr[0] == -0.5);
	CHECK(arr[1] == 0.15);
	CHECK(arr[2] == 2.6);
	CHECK(arr[3] == -4.15);
	CHECK(arr[4] == 32.2);
	CHECK(arr[5] == 0);
	CHECK(arr[6] == -6);
	CHECK(arr[7] == 20160);

}


TEST_CASE("filterfalse"){
	vector<int> vecInt = {1,2,3,4,-5,5,16,0,7,100,8,-2,22};
	int arr[10];
	int j=0;
	for (auto i: filterfalse([](int i){return i<3;}, vecInt) ){
		arr[j] = i;
		j++;
	}
	CHECK(arr[0] == 3);
	CHECK(arr[1] == 4);
	CHECK(arr[2] == 5);
	CHECK(arr[3] == 16);
	CHECK(arr[4] == 7);
	CHECK(arr[5] == 100);
	CHECK(arr[6] == 8);
	CHECK(arr[7] == 22);

	j=0;
	for (auto i: filterfalse([](int i){return i%2==0;}, range(5,20)) )
		arr[j++] = i;

	CHECK(arr[0] == 5);
	CHECK(arr[1] == 7);
	CHECK(arr[2] == 9);
	CHECK(arr[3] == 11);
	CHECK(arr[4] == 13);
	CHECK(arr[5] == 15);
	CHECK(arr[6] == 17);
	CHECK(arr[7] == 19);	



}


TEST_CASE("compress"){

	int j=0;
	string sarr[10];
	for (auto i: compress(string("abcd"), vector<bool>({true,true,false,true})) )
		sarr[j++] = i;

	CHECK(sarr[0] == "a");
	CHECK(sarr[1] == "b");
	CHECK(sarr[2] == "d");
	

	int arr[10];
	j=0;
	for (auto i: compress(range(1,9), vector<bool>({true,true,false,true,true,false,false,true})) )
		arr[j++] = i;

	CHECK(arr[0] == 1);
	CHECK(arr[1] == 2);
	CHECK(arr[2] == 4);
	CHECK(arr[3] == 5);
	CHECK(arr[4] == 8);

}

















