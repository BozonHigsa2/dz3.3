#include <iostream>
#include <string>
using namespace std;

enum seasons
{
	spring,
	summer,
	autumn,
	winter,
};
int a = spring;
class basicSeasons
{
public:
	enum seasons
	{
		spring,
		summer,
		autumn,
		winter,
	};

	//int a = spring;
	virtual void change() = 0;

	int nowSeason()
	{
		return a;
	}
	basicSeasons()
	{
		cout << "cb\n";//constructor base
	}
	virtual ~basicSeasons()
	{
		cout << "db\n";//destructor base
	}
};
class reverseSeasons : public basicSeasons
{
public:

	void change()override
	{
		a--;
	}
	reverseSeasons()
	{
		cout << "cs\n";//constructor season
	}
	~reverseSeasons() override
	{
		cout << "ds\n";//destructor season
	}
};
class Seasons : public basicSeasons
{
public:

	void change()override
	{
		a++;
	}


};


int main()
{
	//basicSeasons b;
	Seasons s;
	reverseSeasons r;
	basicSeasons* change_ptr = &s;
	change_ptr->change();
	change_ptr->change();
	change_ptr->change();
	basicSeasons* change_ptrRev = &r;
	change_ptrRev->change();

	switch (s.nowSeason())
	{
	case seasons::spring:
		cout << "spring\n";
		break;
	case seasons::summer:
		cout << "summer\n";
		break;
	case seasons::autumn:
		cout << "autumn\n";
		break;
	case seasons::winter:
		cout << "winter\n";
		break;
	}
	/*cout << endl;
	basicSeasons* bas = new Seasons();
	delete bas;*/
}