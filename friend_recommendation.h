#ifndef FRIEND_RECOMMENDATION_H
#define FRIEND_RECOMMENDATION_H
#include <list>
#include <map>
#include <string>
#include <istream>
#include <ostream>
using std::istream;
using std::ostream;
using std::list;
using std::map;
using std::string;
using std::pair;
class friend_recommendation
{
	struct user_data;
	map<string, user_data> users;
	struct user_data
	{
		int fofc;
		//double match;
		list<map<string, user_data>::iterator> friends_list;
	};
	/*map<string, Friends>::iterator selected;
	int selected_friends_count;*/
	bool find_in_list(list<map<string, user_data>::iterator>&, map<string, user_data>::iterator&);
	static bool cmp_by_match(map<string, user_data>::iterator&, map<string, user_data>::iterator&);
public:
	//void add_user(const string& user, const list<string>& friends);
	void read_friendships(istream& is);
	void print_friendships(ostream& os) const;
	void add_friendship(const string&, const string&);
	list<string> recommend_friends(const string&);
};
ostream& operator<<(ostream& out, const list<string>& l);
#endif
