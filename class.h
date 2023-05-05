#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include <ctime>
#include <algorithm>
#include <conio.h>

#define FIELD_WIDTH 60 // ����â ������ ��
#define FIELD_HEIGHT 38 // ����â ������ ����
#define Start_WIDTH 3 //���� ī�� ������ ��
#define Start_HEIGHT 5 // ���� ī�� ������ ���� 
#define Start_WIDTH_Under 33   //�Ʒ��� ī�� ������ �� ����
#define Start_HEIGHT_Under 33  //�Ʒ��� ī�� ������ ���� ���� 
#define Start_WIDTH_3P 2  //3p�� ������ ī�� �� ���� 
using namespace std;

void gotoxy(int x, int y);
void GameStartFild();
void GamesetFild();
void Game_Record_Window_reset();
void Game_Record_Window();

class Tile {
	vector <string> tile_color;
	vector <int> tile; // 2�� - 10��, 13, 13 // 3�� - 6��, 9, 9, 8 // 4�� - 5��, 7, 7, 6, 6
	vector <bool> view; // ������ 1, ������� 0

public:
	// ���� �� �����ϴ� ��
	Tile()
	{
		for (int i = 0; i < 13; i++) // 0-11 12�� ��Ŀ �� 13��
		{
			tile.push_back(i);
		}
	}
	// �÷��̾ ������ ��
	Tile(int a)
	{
		tile.push_back(a);
		tile_color.push_back("�ӽ�");
		view.push_back(0);
	}
	~Tile()
	{

	}

	vector <string> get_tile_color();

	vector <int> get_tile();
	// ���� 1 ����� 0
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

	// ���� ������ ũ��
	int size_tile();

	// ���� ������ �ε��� ���� - ���ڴ� ���ĵǾ������� ���� �ǵ���
	int number_getindex(int num, string color);

	// ù �� ����, ���� ���� ���� number�� 3 or 4
	void first_sort(int number);

	string get_color(int i);

	// �μ��� ��Ŀ ��ġ
	void leftshift_joker(int index);

	void tile_open(int index);

	// �� Ȯ�� �������� 1 ������� 0
	bool total_check();

	// 1 - ��� ����, 0 - ����� �� ����
	bool view_all_open();

	// �̹� ������ ������ Ȯ�� ���� = 0 ����� = 1/ ����
	bool view_check(int sequence);

	int& operator[](int i)
	{
		if (i >= tile.size())
		{
			cout << "�߸��� �ε��� : ";
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
	string name; // �̸�
	Tile hav; // ��
	int rank; // ����
	int rand_num; // ��� ���� ��
	string rand_color; // ��� ���� ���� ����
	int check; // ��� ���� ���� ��ġ(�ε���)
public:
	Player() :name{ "p" }, hav{ -1 }, rank{ 0 }, rand_num{ -1 }, rand_color{ "��" }, check{ -1 }{}
	Player(Tile start_T, string name = "p", int rank = 0, int rand_num = -1, string rand_color = "��", int check = -1) :hav{ start_T }, name{ name }, rank{ rank }, rand_num{ rand_num },
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

	//���� ��� �� �̱�(����, ��, ��������) - ��� ��ü Ÿ�� ������, � �̴���
	void new_whitetile(Tile& total_Tile, int ctr);

	//���� ������ �� �̱�(����,��,��������) - ������ ��ü Ÿ�� ������, � �̴���
	void new_blacktile(Tile& total_Tile, int ctr);

	//�ʱ���� ����
	void tile_firstsort(int first);

	//��Ŀ ���� Ȯ�� - 2 = �� �� / 1 = �� / 0 = ��
	int jocker_check();

	//��Ŀ �Է� - �� �м�, ��Ŀ ����, ��Ŀ ��ġ, ���� // ��Ŀ�� �� �ڿ� �ִٴ� ���� �ʿ�
	void jocker_select(int first, int jocker_n, int jocker_index, string color);

	//���� ���� �� ����
	int get_tilenum();

	// ��Ŀ(���� ��) ���ϴ� ��ġ�� �ִ� �Լ�(�μ�) + ���� ���� ����� �������� ����� �ֱ�(-1)
	void tile_fit(int joker_point = -1);

	// ���� ����
	void tile_sort();

	//��Ŀ�� ���� �������� ����ġ
	void leftshift_joker(int index);

	// ��Ŀ ����ġ
	void jocker_fit(int joker_point);

	// �̹� ������ ������ Ȯ��
	bool view_check(int sequence);

	//�ٸ� �÷��̾���Ͽ� ���߱�.
	int predict_tile(Player& player, int sequence, int number, int check, int& score, int& result); // �����÷��̾�, ���°, ���� ��, ���� �Ͽ��� ���� ��, ����, ���

	//�ڽ��� �а� ��� �����Ǿ����� Ȯ�� ������� ������ 0 ��� ������ 1
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


