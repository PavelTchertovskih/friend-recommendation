#include <iostream>
#include "friend_recommendation.h"
/*void friend_recommendation::add_user(const string& user, const list<string>& friends)
{
	auto u_ret = users.insert(pair<string, user_data>(user, {}));
	for (auto& i: friends)
	{
		auto ret = users.insert(pair<string, user_data>(i, {}));
		u_ret.first->second.friends_list.push_back(ret.first);
		ret.first->second.friends_list.push_back(u_ret.first);
	}
}*/
void friend_recommendation::print_friendships(ostream& os) const
{
	for (auto& i: users)
	{
		os << i.first << ":";
		for (auto& j: i.second.friends_list)
		{
			os << " " << j->first;
		}
		os << std::endl;
	}
}
void friend_recommendation::read_friendships(istream& is)
{
	string s1, s2;
	while(is.good())
	{
		is >> s1;
		is >> s2;
		if (!s1.empty() && !s2.empty())
		{
			add_friendship(s1, s2);
		}
	}
}
void friend_recommendation::add_friendship(const string& user1, const string& user2)
{
	auto ret1 = users.insert(pair<string, user_data>(user1, {}));
	auto ret2 = users.insert(pair<string, user_data>(user2, {}));
	ret1.first->second.friends_list.push_back(ret2.first);
	ret2.first->second.friends_list.push_back(ret1.first);
}
bool friend_recommendation::find_in_list(list<map<string, user_data>::iterator>& l, map<string, user_data>::iterator& i)
{
	for (auto& j: l)
	{
		if (j == i)//found
			return true;
	}
	return false;
}
bool friend_recommendation::cmp_by_match(map<string, user_data>::iterator& i1, map<string, user_data>::iterator& i2)
{
	return i1->second.fofc > i2->second.fofc;
}
list<string> friend_recommendation::recommend_friends(const string& uid)
{
	auto selected = users.find(uid);
	//int fc = selected->second.friends_list.size();
	selected->second.fofc = -1;
	list<map<string, user_data>::iterator>& fs = selected->second.friends_list;
	list<map<string, user_data>::iterator> fofs;
	for (auto& i: fs)
	{
		for (auto& j: i->second.friends_list)
		{
			if (j != selected && !find_in_list(fs, j) && !find_in_list(fofs, j))
				fofs.push_back(j);
		}
	}	
	/*for (auto& j: fs)
	{
		std::cout << j->first << " ";
	}
	std::cout << std::endl;
	for (auto& j: fofs)
	{
		std::cout << j->first << " ";
	}
	std::cout << std::endl;*/
	for (auto& i: fofs)
	{
		for (auto& j: i->second.friends_list)
		{
			if (find_in_list(fs, j))
				i->second.fofc++;
		}
	}	
	fofs.sort(this->cmp_by_match);
	list<string> rez;
	for (auto& i: fofs)
	{
		rez.push_back(i->first);
	}	
	return rez;
}
ostream& operator<<(ostream& out, const list<string>& l)
{
	for (auto& i: l)
	{
		out << i << std::endl;
	}
	return out;
}
