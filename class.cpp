#include "class.h"

void gotoxy(int x, int y)
{
	COORD coord = { 0, 0 };
	coord.X = 2 * x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void GameStartFild()
{
	system("mode con cols=124 lines=40");

	//����â
	for (int i = 1; i < FIELD_WIDTH; i++)
	{
		gotoxy(i, 0);
		cout << "��";
		gotoxy(i, FIELD_HEIGHT);
		cout << "��";
	}
	for (int i = 1; i < FIELD_HEIGHT; i++)
	{
		gotoxy(0, i);
		cout << "��";
		gotoxy(FIELD_WIDTH, i);
		cout << "��";
	}
	gotoxy(0, 0);
	cout << "��";
	gotoxy(0, FIELD_HEIGHT);
	cout << "��";
	gotoxy(FIELD_WIDTH, 0);
	cout << "��";
	gotoxy(FIELD_WIDTH, FIELD_HEIGHT);
	cout << "��";

	//�ٺ�ġ �ڵ� ���� ���
	gotoxy(27, 18);
	cout << "DaVinci code";

	//Start �簢��
	for (int i = 24; i < 35; i++)
	{
		gotoxy(i, 19);
		cout << "��";
		gotoxy(i, 23);
		cout << "��";
	}
	for (int i = 19; i < 23; i++)
	{
		gotoxy(24, i);
		cout << "��";
		gotoxy(35, i);
		cout << "��";
	}

	gotoxy(24, 19);
	cout << "��";
	gotoxy(24, 23);
	cout << "��";
	gotoxy(35, 19);
	cout << "��";
	gotoxy(35, 23);
	cout << "��";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);   //���� �� �ٲ��ִ� �Լ� (�����)

	//��������_��
	gotoxy(1, 1);
	for (int i = 1; i <= 15; i++)
	{
		for (int j = 15; j > i; j--)
		{
			cout << "��";
		}
		for (int k = i; k < 15; k++)
		{
			cout << " ";
		}
		cout << "\n";
		gotoxy(1, i);
	}

	//����_��_��
	gotoxy(9, 1);
	for (int i = 10; i < 61; i++)
	{
		cout << "��";
	}

	//����_��_��
	gotoxy(1, 37);
	for (int i = 1; i < 60; i++)
	{
		cout << "��";
	}

	//����_����_�����
	gotoxy(1, 1);
	for (int i = 1; i <= 38; i++)
	{
		cout << "��";
		gotoxy(1, i);
	}

	//����_����_�����
	gotoxy(59, 1);
	for (int i = 1; i <= 38; i++)
	{
		cout << "��";
		gotoxy(59, i);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //���� �� �ٲ��ִ� �Լ� (������)
	gotoxy(26, 21);
	cout << "��  Game Start";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  	//���� �� �ٲ��ִ� �Լ� (���)
	gotoxy(23, 24);
	cout << "�����Ϸ��� Enter�� �����ּ���.";

	int enter;
	gotoxy(26, 21);
	enter = _getch();
	cin.ignore();
}

void GamesetFild()
{
	gotoxy(23, 18);
	for (int i = 18; i < 25; i++)
	{
		gotoxy(23, i);
		for (int j = 23; j < 53; j++)
		{
			cout << " ";
		}
	}
}

void Game_Record_Window_reset()
{
	for (int j = 14; j < 22; j++)
	{
		gotoxy(17, j);
		for (int i = 17; i < 71; i++)
		{
			cout << " ";
		}
	}

}

void Game_Record_Window() {
	//����â
	for (int i = 1; i < FIELD_WIDTH; i++)
	{
		gotoxy(i, 0);
		cout << "��";
		gotoxy(i, FIELD_HEIGHT);
		cout << "��";
	}
	for (int i = 1; i < FIELD_HEIGHT; i++)
	{
		gotoxy(0, i);
		cout << "��";
		gotoxy(FIELD_WIDTH, i);
		cout << "��";
	}
	gotoxy(0, 0);
	cout << "��";
	gotoxy(0, FIELD_HEIGHT);
	cout << "��";
	gotoxy(FIELD_WIDTH, 0);
	cout << "��";
	gotoxy(FIELD_WIDTH, FIELD_HEIGHT);
	cout << "��";

	//���â 
	for (int i = 15; i < 44; i++)
	{
		gotoxy(i, 12);
		cout << "��";
		gotoxy(i, 26);
		cout << "��";
	}
	for (int i = 12; i < 26; i++)
	{
		gotoxy(15, i);
		cout << "��";
		gotoxy(44, i);
		cout << "��";
	}
	gotoxy(15, 12);
	cout << "��";
	gotoxy(15, 26);
	cout << "��";
	gotoxy(44, 12);
	cout << "��";
	gotoxy(44, 26);
	cout << "��";

	gotoxy(28, 13);
	cout << "RECORD" << endl;

}

vector <string> Tile::get_tile_color()
{
	return tile_color;
}

vector <int> Tile::get_tile()
{
	return tile;
}

vector <bool> Tile::get_view()
{
	return view;
}

void Tile::clear()
{
	tile.clear();
	tile_color.clear();
	view.clear();
}

void Tile::number_push_back(int a)
{
	tile.push_back(a);
}

void Tile::view_push_back(bool b)
{
	view.push_back(b);
}

void Tile::color_push_back(string a)
{
	tile_color.push_back(a);
}

void Tile::number_pop_back()
{
	tile.pop_back();
}

void Tile::view_pop_back()
{
	view.pop_back();
}

void Tile::color_pop_back()
{
	tile_color.pop_back();
}

void Tile::tile_sort()
{
	sort(tile.begin(), tile.end());
}

void Tile::number_erase(int index)
{
	tile.erase(tile.begin() + index);
}

void Tile::view_erase(int index)
{
	view.erase(view.begin() + index);
}

void Tile::color_erase(int index)
{
	tile_color.erase(tile_color.begin() + index);
}

void Tile::number_insert(int index, int val)
{
	tile.insert(tile.begin() + index, val);
}

void Tile::view_insert(int index, bool val)
{
	view.insert(view.begin() + index, val);
}

void Tile::color_insert(int index, string val)
{
	tile_color.insert(tile_color.begin() + index, val);
}

int Tile::size_tile()
{
	return tile.size();
}

int Tile::number_getindex(int num, string color)
{
	auto it_num = find(tile.begin(), tile.end(), num);
	auto index_num = distance(tile.begin(), it_num);
	if (index_num + 1 < tile.size() && tile[index_num + 1] == num && color == "��") // �ڵ� ���� ���̰� ���� ã�� ���� ���� ����̶��
	{
		index_num++;
		return index_num;
	}
	else return index_num;
}

void Tile::first_sort(int number)
{
	for (int i = 0; i < number - 1; i++)
	{
		for (int j = i + 1; j < number; j++)
		{
			if (tile[i] > tile[j])
			{
				swap(tile[i], tile[j]);
				swap(tile_color[i], tile_color[j]);
			}
			if (tile[i] == tile[j] && tile_color[j] == "��")
			{
				swap(tile_color[i], tile_color[j]);
			}
		}
	}
}
//�����ڷ�, ������ �ߺ����Ƿ� ������ []��
//���ڸ� ��ȯ�ϱ� ������ ���� ��ȯ�ϱ� ���� ����Լ��̴�. 
//�ε����� �μ��� �ް� �� �ε����� ���� ��ȯ�Ѵ�.
string Tile::get_color(int i)
{
	return tile_color[i];
}

void Tile::leftshift_joker(int index)    //Tile Ŭ���� ���� leftshift_joker() ����Լ��� �����ϸ� �ε����� �μ��� �޴´�.
{
	string color;
	int see;
	color = tile_color[index + 1];
	see = view[index + 1];
	tile_color.erase(tile_color.begin() + index + 1);
	view.erase(view.begin() + index + 1);
	tile_color.insert(tile_color.begin() + index, color);
	view.insert(view.begin() + index, see);
}

void Tile::tile_open(int index)    //Ÿ���� ������ �ٲ۴� 
{
	view.erase(view.begin() + index);
	view.insert(view.begin() + index, 1); // ����
}

bool Tile::total_check()      //��ü �� �߿��� ���� �� �ִ� �а� �ִ��� Ȯ���ϴ� �Լ�
{
	for (int i : this->tile)
	{
		if (i != -1)
		{
			return 1; // ���� ����
		}
	}
	return 0; // �����
}

bool Tile::view_all_open()    //Player�� �а� ��� ��������� Ȯ���ϴ� �Լ��̴�
{
	for (bool a : view)
	{
		if (!a) return 0; // ������� �а� ����
	}
	return 1; // ��� ����
}

bool Tile::view_check(int sequence)  //���� ��ġ�� �μ��� �ް� �� �а� �����Ǿ����� Ȯ���ϴ� �Լ�
{
	if (view[sequence - 1] == 1) return false;
	else return true;
}

void Player::setname(string name)
{
	this->name = name;
}

void Player::sethav(Tile hav)
{
	this->hav = hav;
}

void Player::setrank(int rank)
{
	this->rank = rank;
}

void Player::setcheck(int check)
{
	this->check;
}

string Player::getname()
{
	return this->name;
}

Tile Player::gethav()
{
	return this->hav;
}

int Player::getrank()
{
	return this->rank;
}

int Player::getcheck()
{
	return this->check;
}
//����� 0���� ������ش� 
int Player::getrand_num()
{
	return this->rand_num;
}
//Player�� ������ ���� ����(����, ����, ��������)�� ��� �����.
void Player::tile_clear()
{
	this->hav.clear();
}
//
void Player::new_whitetile(Tile& total_Tile, int ctr)   //�޸���
{
	Tile Set_Tile = this->hav;
	int rand_number = 0;

	for (int i = 0; i < ctr; )
	{
		rand_number = rand() % 13; // 0 ~ 12 ������ ��
		if (total_Tile[rand_number] == -1)continue;
		Set_Tile.number_push_back(rand_number);
		total_Tile.number_erase(rand_number);
		total_Tile.number_insert(rand_number, -1); //���� ���� -1�� ǥ��
		Set_Tile.color_push_back("��");
		Set_Tile.view_push_back(0);
		i++;
	}

	this->rand_num = rand_number;
	this->rand_color = "��";
	this->hav = Set_Tile;
}

void Player::new_blacktile(Tile& total_Tile, int ctr)
{
	Tile Set_Tile = this->hav;
	int rand_number = 0;

	for (int i = 0; i < ctr; )
	{
		rand_number = rand() % 13; // 0 ~ 12 ������ ��
		if (total_Tile[rand_number] == -1)continue;
		Set_Tile.number_push_back(rand_number);
		total_Tile.number_erase(rand_number);
		total_Tile.number_insert(rand_number, -1); //���� ���� -1�� ǥ��
		Set_Tile.color_push_back("��");
		Set_Tile.view_push_back(0);
		i++;
	}

	this->rand_num = rand_number;
	this->rand_color = "��";
	this->hav = Set_Tile;
}

//�� ���� ������ �ǹ��ϴ� ���� �ϳ��� �μ��� �ް� Ŭ���� Tile ���� ����Լ� first_sort�Լ��� �����Ѵ�.
void Player::tile_firstsort(int first)     
{
	this->hav.first_sort(first);
}
//
int Player::jocker_check()
{
	Tile Set_Tile = this->gethav();
	int total = Set_Tile.size_tile();
	if (Set_Tile[total - 2] == 12 && Set_Tile.get_color(total - 2) == "��" && Set_Tile[total - 1] == 12 && Set_Tile.get_color(total - 1) == "��") // ��Ŀ�� �� �� �� ��������
	{
		return 2;
	}
	else if (Set_Tile[total - 1] == 12 && Set_Tile.get_color(total - 1) == "��") // ������ ��Ŀ�� ��������
	{
		return 0;
	}
	else if (Set_Tile[total - 1] == 12 && Set_Tile.get_color(total - 1) == "��") // ��� ��Ŀ�� ��������
	{
		return 1;
	}
	else return -1;
}

void Player::jocker_select(int first, int jocker_n, int jocker_index, string color)
{
	Tile Set_Tile = this->hav;
	int back;
	if (jocker_n == 2) back = 2;
	else back = 1;

	Set_Tile.number_erase(first - back);
	Set_Tile.color_erase(first - back);
	Set_Tile.view_erase(first - back);
	Set_Tile.number_insert(jocker_index, 12);
	Set_Tile.color_insert(jocker_index, color);
	Set_Tile.view_insert(jocker_index, 0);

	this->hav = Set_Tile;
}
//Tile Ŭ������ ���ں����� ũ�⸦ ��ȯ�Ѵ�.
int Player::get_tilenum()
{
	return this->hav.size_tile();
}

void Player::tile_fit(int joker_point)
{
	Tile Set_Tile = this->hav;
	Set_Tile.color_pop_back();
	Set_Tile.view_pop_back();
	if (joker_point == -1) // ��Ŀ �ƴҽ� + ������ �Ǿ��ִ� ���¿�����
	{
		this->check = Set_Tile.number_getindex(this->rand_num, this->rand_color);
	}
	else // ��Ŀ �Ͻ�
	{
		this->check = joker_point;
		Set_Tile.number_pop_back();
		Set_Tile.number_insert(this->check, this->rand_num);
	}
	Set_Tile.color_insert(this->check, this->rand_color);
	Set_Tile.view_insert(this->check, 0); // ��� ���� ���� 0�̴�.

	this->hav = Set_Tile;
}

void Player::tile_sort()
{
	this->hav.tile_sort();
}

void Player::leftshift_joker(int index)
{
	this->hav.leftshift_joker(index);
}

void Player::jocker_fit(int joker_point)
{
	this->hav.number_pop_back(); // �� ���� ��Ŀ ����
	this->hav.number_insert(joker_point, 12); // ��Ŀ ����ġ.
}

bool Player::view_check(int sequence)
{
	return this->hav.view_check(sequence);
}

int Player::predict_tile(Player& player, int sequence, int number, int check, int& score, int& result) // �����÷��̾�, ���°, ���� ��, ���� �Ͽ��� ���� ��, ����, ���
{
	int more;
	int enter;
	Tile tile = player.gethav();
	if (tile[sequence - 1] == number)
	{
		gotoxy(17, 17);
		cout << "���߼̽��ϴ�." << endl;
		tile.tile_open(sequence - 1);
		result = 1;
		while (1)
		{
			if (tile.view_all_open()) // ��� Ÿ���� �����Ǿ����� Ȯ��
			{
				gotoxy(17, 18);
				cout << "��� �и� ���߼̽��ϴ�.";
				gotoxy(17, 19);
				cout << "���� �Ѿ�ϴ�." << endl;
				more = 0;
				player.setrank(score);
				score--;
				break;
			}
			gotoxy(17, 18);
			cout << "�ѹ��� ���߽ðڽ��ϱ�?(�� = 1 �ƴϿ� = 0) : ";	cin >> more;
			while (cin.fail()) {   // ���࿡ error �� �߻��ϸ� 
				gotoxy(17, 19);
				cout << "���ڸ� �Է����ּ���";
				cin.clear();     //  error flag ���� Ŭ���� ��Ŵ 
				cin.ignore(INT_MAX, '\n');  // ���� ���� ������ INT_MAX �� ��ŭ
										  // (�����) \n�� ������ ���� ���۸� ����
				gotoxy(17, 18);
				cout << "�ѹ��� ���߽ðڽ��ϱ�?(�� = 1 �ƴϿ� = 0) : ";	cin >> more; // ���Է�
			}
			if (more <= 1 && more >= 0) break;
			else
			{
				gotoxy(17, 20);
				cout << more << "�� �Է��ϼ̽��ϴ�.";
				gotoxy(17, 21);
				cout << "�ٽ� �Է����ּ���.";
			}

		}

		player.sethav(tile);
		return more;
	}
	else
	{
		result = 0;
		tile = this->gethav();
		gotoxy(17, 17);
		cout << "Ʋ���̽��ϴ�.";
		gotoxy(17, 18);
		cout << "��� ������ �и� �����մϴ�.";
		tile.tile_open(check);
		this->sethav(tile);
		gotoxy(17, 19);
		cout << "���� �����ϰ� ���� ������ �Ѿ�ϴ�.(Enter)";
		enter = _getch();
		cin.ignore();
		return 0;
	}
}

bool Player::tile_check()
{
	Tile tile = this->hav;
	for (bool v : tile.get_view())
	{
		if (!v)
		{
			return 0;
		}
	}

	return 1;
}

void FourPlayer::Player1(Player p, int see)
{
	Tile Set_Tile = p.gethav();
	vector <string> tile_color = Set_Tile.get_tile_color();
	vector <int> tile = Set_Tile.get_tile();
	vector <bool> tile_view = Set_Tile.get_view();
	int tile_size = Set_Tile.size_tile();
	tile_size += 1;
	multiplication_num3 = 0;
	for (add_num3 = 2; add_num3 <= tile_size; add_num3++)  //add_num3�� ����ī��� �Ѿ �� �����ִ� ���� 
	{
		for (int i = Start_WIDTH * multiplication_num3 + add_num3; i < Start_WIDTH * (multiplication_num3 + 1) + add_num3; i++)
		{
			gotoxy(i, 1);
			cout << "��";
			gotoxy(i, Start_HEIGHT);
			cout << "��";
			gotoxy(i, 3);
			cout << "��";
			gotoxy(i - 1, 2);
		}
		if (tile_color[add_num3 - 2] == "��") cout << "�� B";
		else cout << "�� W";

		for (int i = 1; i < Start_HEIGHT; i++)
		{
			gotoxy(Start_WIDTH * multiplication_num3 + add_num3, i);
			cout << "��";
			gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, i);
			cout << "��";
		}
		gotoxy(Start_WIDTH * multiplication_num3 + add_num3 + 1, Start_HEIGHT - 1);
		if (see == 0)
		{
			if (tile_view[add_num3 - 2] == 1)
			{
				if (tile[add_num3 - 2] == 12)
				{
					cout << " - ";
				}
				else cout << tile[add_num3 - 2] << " ";
			}
			else if (tile_view[add_num3 - 2] == 0)
			{
				cout << "   ";
			}
		}
		else if (see == 1)
		{
			if (tile[add_num3 - 2] == 12)
			{
				cout << " - ";
			}
			else cout << tile[add_num3 - 2] << " ";
		}

		gotoxy(Start_WIDTH * multiplication_num3 + add_num3, 1);
		cout << "��";
		gotoxy(Start_WIDTH * multiplication_num3 + add_num3, Start_HEIGHT);
		cout << "��";
		gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, 1);
		cout << "��";
		gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, Start_HEIGHT);
		cout << "��";
		multiplication_num3++;
	}
	gotoxy(2, Start_HEIGHT + 1);
	cout << "��1P  name : ";
	cout << p.getname();
}

void FourPlayer::Player2(Player p, int see)
{
	Tile Set_Tile = p.gethav();
	vector <string> tile_color = Set_Tile.get_tile_color();
	vector <int> tile = Set_Tile.get_tile();
	vector <bool> tile_view = Set_Tile.get_view();
	int tile_size = Set_Tile.size_tile();
	tile_size += 1;
	multiplication_num3 = 0;
	for (add_num3 = 2; add_num3 <= tile_size; add_num3++)  //add_num3�� ����ī��� �Ѿ �� �����ִ� ���� 
	{
		for (int i = Start_WIDTH * multiplication_num3 + add_num3; i < Start_WIDTH * (multiplication_num3 + 1) + add_num3; i++)
		{
			gotoxy(i, Start_HEIGHT_Under);
			cout << "��";
			gotoxy(i, Start_HEIGHT_Under + Start_HEIGHT - 1);
			cout << "��";
			gotoxy(i, Start_HEIGHT_Under + 2);
			cout << "��";
			gotoxy(i - 1, Start_HEIGHT_Under + 1);
		}
		if (tile_color[add_num3 - 2] == "��") cout << "�� B";
		else cout << "�� W";

		for (int i = Start_HEIGHT_Under; i < Start_HEIGHT_Under + Start_HEIGHT - 1; i++)
		{
			gotoxy(Start_WIDTH * multiplication_num3 + add_num3, i);
			cout << "��";
			gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, i);
			cout << "��";
		}
		gotoxy(Start_WIDTH * multiplication_num3 + add_num3 + 1, Start_HEIGHT_Under + Start_HEIGHT - 2);
		if (see == 0)
		{
			if (tile_view[add_num3 - 2] == 1)
			{
				if (tile[add_num3 - 2] == 12)
				{
					cout << " - ";
				}
				else cout << tile[add_num3 - 2] << " ";
			}
			else if (tile_view[add_num3 - 2] == 0)
			{
				cout << "   ";
			}
		}
		else if (see == 1)
		{
			if (tile[add_num3 - 2] == 12)
			{
				cout << " - ";
			}
			else cout << tile[add_num3 - 2] << " ";
		}


		gotoxy(Start_WIDTH * multiplication_num3 + add_num3, Start_HEIGHT_Under);
		cout << "��";
		gotoxy(Start_WIDTH * multiplication_num3 + add_num3, Start_HEIGHT_Under + Start_HEIGHT - 1);
		cout << "��";
		gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, Start_HEIGHT_Under);
		cout << "��";
		gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, Start_HEIGHT_Under + Start_HEIGHT - 1);
		cout << "��";
		multiplication_num3++;
	}

	gotoxy(2, Start_HEIGHT_Under - 1);
	cout << "��2P  name : ";
	cout << p.getname();
}

void FourPlayer::Player3(Player p, int see)
{
	Tile Set_Tile = p.gethav();
	vector <string> tile_color = Set_Tile.get_tile_color();
	vector <int> tile = Set_Tile.get_tile();
	vector <bool> tile_view = Set_Tile.get_view();
	int tile_size = Set_Tile.size_tile();
	tile_size += 12;
	multiplication_num3 = 7;
	for (add_num3 = 13; add_num3 <= tile_size; add_num3++)  //add_num3�� ����ī��� �Ѿ �� �����ִ� ���� 
	{
		for (int i = Start_WIDTH * multiplication_num3 + add_num3; i < Start_WIDTH * (multiplication_num3 + 1) + add_num3; i++)
		{
			gotoxy(i, 1);
			cout << "��";
			gotoxy(i, Start_HEIGHT);
			cout << "��";
			gotoxy(i, 3);
			cout << "��";
			gotoxy(i - 1, 2);
		}
		if (tile_color[add_num3 - 13] == "��") cout << "�� B";
		else cout << "�� W";

		for (int i = 1; i < Start_HEIGHT; i++)
		{
			gotoxy(Start_WIDTH * multiplication_num3 + add_num3, i);
			cout << "��";
			gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, i);
			cout << "��";
		}
		gotoxy(Start_WIDTH * multiplication_num3 + add_num3 + 1, Start_HEIGHT - 1);
		if (see == 0)
		{
			if (tile_view[add_num3 - 13] == 1)
			{
				if (tile[add_num3 - 13] == 12)
				{
					cout << " - ";
				}
				else cout << tile[add_num3 - 13] << " ";
			}
			else if (tile_view[add_num3 - 13] == 0)
			{
				cout << "   ";
			}
		}
		else if (see == 1)
		{
			if (tile[add_num3 - 13] == 12)
			{
				cout << " - ";
			}
			else cout << tile[add_num3 - 13] << " ";
		}

		gotoxy(Start_WIDTH * multiplication_num3 + add_num3, 1);
		cout << "��";
		gotoxy(Start_WIDTH * multiplication_num3 + add_num3, Start_HEIGHT);
		cout << "��";
		gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, 1);
		cout << "��";
		gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, Start_HEIGHT);
		cout << "��";
		multiplication_num3++;
	}
	gotoxy(Start_WIDTH_Under + 1, Start_HEIGHT + 1);
	cout << "��3P  name : ";
	cout << p.getname();
}

void FourPlayer::Player4(Player p, int see)
{
	Tile Set_Tile = p.gethav();
	vector <string> tile_color = Set_Tile.get_tile_color();
	vector <int> tile = Set_Tile.get_tile();
	vector <bool> tile_view = Set_Tile.get_view();
	int tile_size = Set_Tile.size_tile();
	tile_size += 12;
	multiplication_num3 = 7;
	for (add_num3 = 13; add_num3 <= tile_size; add_num3++)  //add_num3�� ����ī��� �Ѿ �� �����ִ� ���� 
	{
		for (int i = Start_WIDTH * multiplication_num3 + add_num3; i < Start_WIDTH * (multiplication_num3 + 1) + add_num3; i++)
		{
			gotoxy(i, Start_HEIGHT_Under);
			cout << "��";
			gotoxy(i, Start_HEIGHT_Under + Start_HEIGHT - 1);
			cout << "��";
			gotoxy(i, Start_HEIGHT_Under + 2);
			cout << "��";
			gotoxy(i - 1, Start_HEIGHT_Under + 1);
		}
		if (tile_color[add_num3 - 13] == "��") cout << "�� B";
		else cout << "�� W";

		for (int i = Start_HEIGHT_Under; i < Start_HEIGHT_Under + Start_HEIGHT - 1; i++)
		{
			gotoxy(Start_WIDTH * multiplication_num3 + add_num3, i);
			cout << "��";
			gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, i);
			cout << "��";
		}
		gotoxy(Start_WIDTH * multiplication_num3 + add_num3 + 1, Start_HEIGHT_Under + Start_HEIGHT - 2);
		if (see == 0)
		{
			if (tile_view[add_num3 - 13] == 1)
			{
				if (tile[add_num3 - 13] == 12)
				{
					cout <<  " - ";
				}
				else cout << tile[add_num3 - 13] << " ";
			}
			else if (tile_view[add_num3 - 13] == 0)
			{
				cout << "   ";
			}
		}
		else if (see == 1)
		{
			if (tile[add_num3 - 13] == 12)
			{
				cout << " - ";
			}
			else cout << tile[add_num3 - 13] << " ";
		}

		gotoxy(Start_WIDTH * multiplication_num3 + add_num3, Start_HEIGHT_Under);
		cout << "��";
		gotoxy(Start_WIDTH * multiplication_num3 + add_num3, Start_HEIGHT_Under + Start_HEIGHT - 1);
		cout << "��";
		gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, Start_HEIGHT_Under);
		cout << "��";
		gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, Start_HEIGHT_Under + Start_HEIGHT - 1);
		cout << "��";
		multiplication_num3++;
	}
	gotoxy(Start_WIDTH_Under + 1, Start_HEIGHT_Under - 1);
	cout << "��4P  name : ";
	cout << p.getname();
}

void FourPlayer::GameEndFild()
{
	system("cls");

	//����â
	for (int i = 1; i <= FIELD_WIDTH; i++)
	{
		gotoxy(i, 0);
		cout << "��";
		gotoxy(i, FIELD_HEIGHT);
		cout << "��";
	}
	for (int i = 1; i <= FIELD_HEIGHT; i++)
	{
		gotoxy(0, i);
		cout << "��";
		gotoxy(FIELD_WIDTH, i);
		cout << "��";
	}
	gotoxy(0, 0);
	cout << "��";
	gotoxy(0, FIELD_HEIGHT);
	cout << "��";
	gotoxy(FIELD_WIDTH, 0);
	cout << "��";
	gotoxy(FIELD_WIDTH, FIELD_HEIGHT);
	cout << "��";

	//Start �簢��
	for (int i = 20; i < 39; i++)
	{
		gotoxy(i, 11);
		cout << "��";
		gotoxy(i, 30);
		cout << "��";
	}
	for (int i = 11; i < 30; i++)
	{
		gotoxy(20, i);
		cout << "��";
		gotoxy(39, i);
		cout << "��";
	}

	gotoxy(20, 11);
	cout << "��";
	gotoxy(20, 30);
	cout << "��";
	gotoxy(39, 11);
	cout << "��";
	gotoxy(39, 30);
	cout << "��";

	gotoxy(27, 12);
	cout << "NAME & SCORE";

	for (int i = 24; i < 35; i++)
	{
		gotoxy(i, 17);
		cout << "��";
		gotoxy(i, 20);
		cout << "��";
		gotoxy(i, 23);
		cout << "��";
		gotoxy(i, 26);
		cout << "��";
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //���� �� �ٲ��ִ� �Լ� (������)
	//�ٺ�ġ �ڵ� ���� ���
	gotoxy(27, 5);
	cout << "��Game End ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);   //���� �� �ٲ��ִ� �Լ� (�����)

	//���� ��
	gotoxy(10, 11);
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << "��";
		}
		cout << "\n";
		gotoxy(10, 11 + i);
	}

	//������ ��
	gotoxy(40, 11);
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << "��";
		}
		cout << "\n";
		gotoxy(40, 11 + i);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);   //���� �� �ٲ��ִ� �Լ� (���)

	for (int i = 0; i < 8; i++)
	{
		cout << "\n";
	}
}
