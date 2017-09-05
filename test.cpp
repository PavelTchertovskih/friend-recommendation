#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "friend_recommendation.h"
using namespace std;
TEST(fr_test, test_01)
{
	stringstream in;
	in << "A 0" << endl;
	in << "A 1" << endl;
	in << "A 2" << endl;
	in << "A 3" << endl;
	in << "A 4" << endl;
	in << "A 5" << endl;
	in << "A 6" << endl;
	in << "A 7" << endl;
	in << "A 8" << endl;
	in << "A 9" << endl;
	in << "B 0" << endl; // 1/10
	in << "C 0" << endl;
	in << "C 1" << endl; // 2/10
	in << "D 0" << endl;
	in << "D 1" << endl;
	in << "D 2" << endl; // 3/10
	in << "E 0" << endl;
	in << "E 1" << endl;
	in << "E 2" << endl;
	in << "E 3" << endl; // 4/10
	in << "F 0" << endl;
	in << "F 1" << endl;
	in << "F 2" << endl;
	in << "F 3" << endl;
	in << "F 4" << endl; // 5/10
	in << "G 0" << endl;
	in << "G 1" << endl;
	in << "G 2" << endl;
	in << "G 3" << endl;
	in << "G 4" << endl;
	in << "G 5" << endl; // 6/10
	in << "H 0" << endl;
	in << "H 1" << endl;
	in << "H 2" << endl;
	in << "H 3" << endl;
	in << "H 4" << endl;
	in << "H 5" << endl;
	in << "H 6" << endl; // 7/10
	in << "L 0" << endl;
	in << "L 1" << endl;
	in << "L 2" << endl;
	in << "L 3" << endl;
	in << "L 4" << endl;
	in << "L 5" << endl;
	in << "L 6" << endl;
	in << "L 7" << endl; //8/10
	in << "M 0" << endl;
	in << "M 1" << endl;
	in << "M 2" << endl;
	in << "M 3" << endl;
	in << "M 4" << endl;
	in << "M 5" << endl;
	in << "M 6" << endl;
	in << "M 7" << endl;
	in << "M 8" << endl; //9/10
	in << "N 0" << endl;
	in << "N 1" << endl;
	in << "N 2" << endl;
	in << "N 3" << endl;
	in << "N 4" << endl;
	in << "N 5" << endl;
	in << "N 6" << endl;
	in << "N 7" << endl;
	in << "N 8" << endl;
	in << "N 9";//10/10
	friend_recommendation fr;
	fr.read_friendships(in);
	//fr.print_friendships(cout);
	auto l = fr.recommend_friends("A");
	//cout << l;
	stringstream out;
	out << l;
	stringstream ch;
	ch << "N" << endl;
	ch << "M" << endl;
	ch << "L" << endl;
	ch << "H" << endl;
	ch << "G" << endl;
	ch << "F" << endl;
	ch << "E" << endl;
	ch << "D" << endl;
	ch << "C" << endl;
	ch << "B";
	while (out.good())
	{
		string s1, s2;
		getline(ch, s1);
		getline(out, s2);
		EXPECT_TRUE(s1 == s2);
	}
	l = fr.recommend_friends("N");
	//cout << l;
	//stringstream out;
	out << l;
	//stringstream ch;
	ch << "A" << endl;
	ch << "M" << endl;
	ch << "L" << endl;
	ch << "H" << endl;
	ch << "G" << endl;
	ch << "F" << endl;
	ch << "E" << endl;
	ch << "D" << endl;
	ch << "C" << endl;
	ch << "B";
	while (out.good())
	{
		string s1, s2;
		getline(ch, s1);
		getline(out, s2);
		EXPECT_TRUE(s1 == s2);
	}
}
TEST(fr_test, test_02)
{
	stringstream in;
	in << "1 2" << endl;
	in << "1 3" << endl;
	in << "2 4" << endl;
	in << "2 5" << endl;
	in << "3 6" << endl;
	in << "3 7" << endl;
	in << "4 8" << endl;
	in << "4 9" << endl;
	in << "5 10" << endl;
	in << "5 11" << endl;
	in << "6 12" << endl;
	in << "6 13" << endl;
	in << "7 14" << endl;
	in << "7 15" << endl;
	friend_recommendation fr;
	fr.read_friendships(in);
	auto l = fr.recommend_friends("1");
	//cout << l;
	stringstream out;
	out << l;
	stringstream ch;
	ch << "4" << endl;
	ch << "5" << endl;
	ch << "6" << endl;
	ch << "7";
	while (out.good())
	{
		string s1, s2;
		getline(ch, s1);
		getline(out, s2);
		EXPECT_TRUE(s1 == s2);
	}
	l = fr.recommend_friends("2");
	//cout << l;
	out << l;
	ch << "3" << endl;
	ch << "8" << endl;
	ch << "9" << endl;
	ch << "10" << endl;
	ch << "11";
	while (out.good())
	{
		string s1, s2;
		getline(ch, s1);
		getline(out, s2);
		EXPECT_TRUE(s1 == s2);
	}
	l = fr.recommend_friends("3");
	//cout << l;
	out << l;
	ch << "15" << endl;
	ch << "2" << endl;
	ch << "12" << endl;
	ch << "13" << endl;
	ch << "14";
	while (out.good())
	{
		string s1, s2;
		getline(ch, s1);
		getline(out, s2);
		EXPECT_TRUE(s1 == s2);
	}
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
