#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include <ctime>
#include <algorithm>
#include <conio.h>

#define FIELD_WIDTH 60 // 게임창 사이즈 폭
#define FIELD_HEIGHT 38 // 게임창 사이즈 높이
#define Start_WIDTH 3 //위쪽 카드 사이즈 폭
#define Start_HEIGHT 5 // 위쪽 카드 사이즈 높이 
#define Start_WIDTH_Under 33   //아랫쪽 카드 사이즈 폭 시작
#define Start_HEIGHT_Under 33  //아랫쪽 카드 사이즈 높이 시작 
#define Start_WIDTH_3P 2  //3p용 오른쪽 카드 폭 시작 
using namespace std;

void gotoxy(int x, int y);
void GameStartFild();
void GamesetFild();
void Game_Record_Window_reset();
void Game_Record_Window();

class Tile {
	vector <string> tile_color;
	vector <int> tile; // 2인 - 10턴, 13, 13 // 3인 - 6턴, 9, 9, 8 // 4인 - 5턴, 7, 7, 6, 6
	vector <bool> view; // 공개는 1, 비공개는 0

public:
	// 게임 내 존재하는 패
	Tile()
	{
		for (int i = 0; i < 13; i++) // 0-11 12는 조커 총 13개
		{
			tile.push_back(i);
		}
	}
	// 플레이어가 가지는 패
	Tile(int a)
	{
		tile.push_back(a);
		tile_color.push_back("임시");
		view.push_back(0);
	}
	~Tile()
	{

	}

	vector <string> get_tile_color();

	vector <int> get_tile();
	// 공개 1 비공개 0
	vector <bool> get_view();

	void clear();

	void number_push_back(int a);

	void view_push_back(bool b);

	void color_push_back(string a);

	void number_pop_back();

	void view_pop_back();

	void color_pop_back();

	void tile_sort();

	void number_erase(int index);

	void view_erase(int index);

	void color_erase(int index);

	void number_insert(int index, int val);

	void view_insert(int index, bool val);

	void color_insert(int index, string val);

	// 숫자 벡터의 크기
	int size_tile();

	// 숫자 벡터의 인덱스 추출 - 숫자는 정렬되어있지만 색은 맨뒤임
	int number_getindex(int num, string color);

	// 첫 턴 숫자, 색깔 정렬 셋팅 number는 3 or 4
	void first_sort(int number);

	string get_color(int i);

	// 인수는 조커 위치
	void leftshift_joker(int index);

	void tile_open(int index);

	// 패 확인 남아있음 1 비어있음 0
	bool total_check();

	// 1 - 모두 공개, 0 - 비공개 패 존재
	bool view_all_open();

	// 이미 공개된 패인지 확인 공개 = 0 비공개 = 1/ 순서
	bool view_check(int sequence);

	int& operator[](int i)
	{
		if (i >= tile.size())
		{
			cout << "잘못된 인덱스 : ";
			return tile[0];
		}
		return tile[i];
	}

	friend ostream& operator<<(ostream& os, const Tile& t)
	{
		if (!t.tile.empty())
		{
			os << "[ ";
			for (auto& a : t.tile)
			{
				if (a == 12) os << "-" << " ";
				else os << a << " ";
			}
			os << "]";
			os << endl;
			if (!t.tile_color.empty())
			{
				os << "[";
				for (auto& a : t.tile_color)
				{
					os << a << " ";
				}
				os << "]";
				os << endl;
			}
			if (!t.view.empty())
			{
				os << "[";
				for (auto a : t.view)
				{
					os << a << " ";
				}
				os << "]";
				os << endl;
			}
		}
		else os << "noting" << endl;

		return os;
	}
};

class Player {
	string name; // 이름
	Tile hav; // 패
	int rank; // 순위
	int rand_num; // 방금 뽑은 수
	string rand_color; // 방금 뽑은 수의 색상
	int check; // 방금 뽑은 수의 위치(인덱스)
public:
	Player() :name{ "p" }, hav{ -1 }, rank{ 0 }, rand_num{ -1 }, rand_color{ "흰" }, check{ -1 }{}
	Player(Tile start_T, string name = "p", int rank = 0, int rand_num = -1, string rand_color = "흰", int check = -1) :hav{ start_T }, name{ name }, rank{ rank }, rand_num{ rand_num },
		rand_color{ rand_color }, check{ check }{}

	void setname(string name);
	void sethav(Tile hav);
	void setrank(int rank);
	void setcheck(int check);

	string getname();
	Tile gethav();
	int getrank();
	int getcheck();
	int getrand_num();

	void tile_clear();

	//새로 흰색 패 뽑기(숫자, 색, 공개유무) - 흰색 전체 타일 넣을것, 몇개 뽑는지
	void new_whitetile(Tile& total_Tile, int ctr);

	//새로 검은색 패 뽑기(숫자,색,공개유무) - 검은색 전체 타일 넣을것, 몇개 뽑는지
	void new_blacktile(Tile& total_Tile, int ctr);

	//초기셋팅 정렬
	void tile_firstsort(int first);

	//조커 유무 확인 - 2 = 둘 다 / 1 = 흰 / 0 = 검
	int jocker_check();

	//조커 입력 - 총 패수, 조커 개수, 조커 위치, 색깔 // 조커가 맨 뒤에 있다는 전제 필요
	void jocker_select(int first, int jocker_n, int jocker_index, string color);

	//가진 패의 총 갯수
	int get_tilenum();

	// 조커(뽑은 수) 원하는 위치로 넣는 함수(인수) + 뽑은 수의 색상과 공개유무 제대로 넣기(-1)
	void tile_fit(int joker_point = -1);

	// 숫자 정렬
	void tile_sort();

	//조커의 색과 공개유무 재위치
	void leftshift_joker(int index);

	// 조커 재위치
	void jocker_fit(int joker_point);

	// 이미 공개된 패인지 확인
	bool view_check(int sequence);

	//다른 플레이어선택하여 맞추기.
	int predict_tile(Player& player, int sequence, int number, int check, int& score, int& result); // 선택플레이어, 몇번째, 무슨 수, 현재 턴에서 뽑은 패, 순위, 결과

	//자신의 패가 모두 공개되었는지 확인 비공개가 있으면 0 모두 공개면 1
	bool tile_check();

};

class FourPlayer{
private:
	int multiplication_num3, add_num3;
public:
	FourPlayer(int m = 0, int a = 2) : multiplication_num3{ m }, add_num3{ a }{}
	~FourPlayer(){}

	void Player1(Player p, int see);

	void Player2(Player p, int see);

	void Player3(Player p, int see);

	void Player4(Player p, int see);

	void GameEndFild();
};


