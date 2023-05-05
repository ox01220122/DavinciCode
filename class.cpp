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

	//게임창
	for (int i = 1; i < FIELD_WIDTH; i++)
	{
		gotoxy(i, 0);
		cout << "─";
		gotoxy(i, FIELD_HEIGHT);
		cout << "─";
	}
	for (int i = 1; i < FIELD_HEIGHT; i++)
	{
		gotoxy(0, i);
		cout << "│";
		gotoxy(FIELD_WIDTH, i);
		cout << "│";
	}
	gotoxy(0, 0);
	cout << "┌";
	gotoxy(0, FIELD_HEIGHT);
	cout << "└";
	gotoxy(FIELD_WIDTH, 0);
	cout << "┐";
	gotoxy(FIELD_WIDTH, FIELD_HEIGHT);
	cout << "┘";

	//다빈치 코드 글자 출력
	gotoxy(27, 18);
	cout << "DaVinci code";

	//Start 사각형
	for (int i = 24; i < 35; i++)
	{
		gotoxy(i, 19);
		cout << "─";
		gotoxy(i, 23);
		cout << "─";
	}
	for (int i = 19; i < 23; i++)
	{
		gotoxy(24, i);
		cout << "│";
		gotoxy(35, i);
		cout << "│";
	}

	gotoxy(24, 19);
	cout << "┌";
	gotoxy(24, 23);
	cout << "└";
	gotoxy(35, 19);
	cout << "┐";
	gotoxy(35, 23);
	cout << "┘";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);   //글자 색 바꿔주는 함수 (노랑색)

	//오른쪽위_별
	gotoxy(1, 1);
	for (int i = 1; i <= 15; i++)
	{
		for (int j = 15; j > i; j--)
		{
			cout << "＊";
		}
		for (int k = i; k < 15; k++)
		{
			cout << " ";
		}
		cout << "\n";
		gotoxy(1, i);
	}

	//가로_위_별
	gotoxy(9, 1);
	for (int i = 10; i < 61; i++)
	{
		cout << "＊";
	}

	//가로_밑_별
	gotoxy(1, 37);
	for (int i = 1; i < 60; i++)
	{
		cout << "＊";
	}

	//세로_왼쪽_별찍기
	gotoxy(1, 1);
	for (int i = 1; i <= 38; i++)
	{
		cout << "＊";
		gotoxy(1, i);
	}

	//세로_왼쪽_별찍기
	gotoxy(59, 1);
	for (int i = 1; i <= 38; i++)
	{
		cout << "＊";
		gotoxy(59, i);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //글자 색 바꿔주는 함수 (빨강색)
	gotoxy(26, 21);
	cout << "★  Game Start";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  	//글자 색 바꿔주는 함수 (흰색)
	gotoxy(23, 24);
	cout << "시작하려면 Enter를 눌러주세요.";

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
	//게임창
	for (int i = 1; i < FIELD_WIDTH; i++)
	{
		gotoxy(i, 0);
		cout << "─";
		gotoxy(i, FIELD_HEIGHT);
		cout << "─";
	}
	for (int i = 1; i < FIELD_HEIGHT; i++)
	{
		gotoxy(0, i);
		cout << "│";
		gotoxy(FIELD_WIDTH, i);
		cout << "│";
	}
	gotoxy(0, 0);
	cout << "┌";
	gotoxy(0, FIELD_HEIGHT);
	cout << "└";
	gotoxy(FIELD_WIDTH, 0);
	cout << "┐";
	gotoxy(FIELD_WIDTH, FIELD_HEIGHT);
	cout << "┘";

	//기록창 
	for (int i = 15; i < 44; i++)
	{
		gotoxy(i, 12);
		cout << "─";
		gotoxy(i, 26);
		cout << "─";
	}
	for (int i = 12; i < 26; i++)
	{
		gotoxy(15, i);
		cout << "│";
		gotoxy(44, i);
		cout << "│";
	}
	gotoxy(15, 12);
	cout << "┌";
	gotoxy(15, 26);
	cout << "└";
	gotoxy(44, 12);
	cout << "┐";
	gotoxy(44, 26);
	cout << "┘";

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
	if (index_num + 1 < tile.size() && tile[index_num + 1] == num && color == "흰") // 뒤도 같은 수이고 내가 찾는 패의 색이 흰색이라면
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
			if (tile[i] == tile[j] && tile_color[j] == "검")
			{
				swap(tile_color[i], tile_color[j]);
			}
		}
	}
}
//접근자로, 연산자 중복정의로 정의한 []는
//숫자만 반환하기 때문에 색을 반환하기 위한 멤버함수이다. 
//인덱스를 인수로 받고 그 인덱스의 값을 반환한다.
string Tile::get_color(int i)
{
	return tile_color[i];
}

void Tile::leftshift_joker(int index)    //Tile 클래스 내의 leftshift_joker() 멤버함수를 실행하며 인덱스를 인수로 받는다.
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

void Tile::tile_open(int index)    //타일을 공개로 바꾼다 
{
	view.erase(view.begin() + index);
	view.insert(view.begin() + index, 1); // 공개
}

bool Tile::total_check()      //전체 패 중에서 뽑을 수 있는 패가 있는지 확인하는 함수
{
	for (int i : this->tile)
	{
		if (i != -1)
		{
			return 1; // 남아 있음
		}
	}
	return 0; // 비었음
}

bool Tile::view_all_open()    //Player의 패가 모두 공개됬는지 확인하는 함수이다
{
	for (bool a : view)
	{
		if (!a) return 0; // 비공개된 패가 존재
	}
	return 1; // 모두 공개
}

bool Tile::view_check(int sequence)  //패의 위치를 인수로 받고 그 패가 공개되었는지 확인하는 함수
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
//사이즈를 0으로 만들어준다 
int Player::getrand_num()
{
	return this->rand_num;
}
//Player가 가지는 패의 정보(숫자, 색깔, 공개여부)를 모두 지운다.
void Player::tile_clear()
{
	this->hav.clear();
}
//
void Player::new_whitetile(Tile& total_Tile, int ctr)   //메모장
{
	Tile Set_Tile = this->hav;
	int rand_number = 0;

	for (int i = 0; i < ctr; )
	{
		rand_number = rand() % 13; // 0 ~ 12 까지의 수
		if (total_Tile[rand_number] == -1)continue;
		Set_Tile.number_push_back(rand_number);
		total_Tile.number_erase(rand_number);
		total_Tile.number_insert(rand_number, -1); //뽑힌 수는 -1로 표시
		Set_Tile.color_push_back("흰");
		Set_Tile.view_push_back(0);
		i++;
	}

	this->rand_num = rand_number;
	this->rand_color = "흰";
	this->hav = Set_Tile;
}

void Player::new_blacktile(Tile& total_Tile, int ctr)
{
	Tile Set_Tile = this->hav;
	int rand_number = 0;

	for (int i = 0; i < ctr; )
	{
		rand_number = rand() % 13; // 0 ~ 12 까지의 수
		if (total_Tile[rand_number] == -1)continue;
		Set_Tile.number_push_back(rand_number);
		total_Tile.number_erase(rand_number);
		total_Tile.number_insert(rand_number, -1); //뽑힌 수는 -1로 표시
		Set_Tile.color_push_back("검");
		Set_Tile.view_push_back(0);
		i++;
	}

	this->rand_num = rand_number;
	this->rand_color = "검";
	this->hav = Set_Tile;
}

//총 패의 개수를 의미하는 정수 하나를 인수로 받고 클래스 Tile 내의 멤버함수 first_sort함수를 실행한다.
void Player::tile_firstsort(int first)     
{
	this->hav.first_sort(first);
}
//
int Player::jocker_check()
{
	Tile Set_Tile = this->gethav();
	int total = Set_Tile.size_tile();
	if (Set_Tile[total - 2] == 12 && Set_Tile.get_color(total - 2) == "검" && Set_Tile[total - 1] == 12 && Set_Tile.get_color(total - 1) == "흰") // 조커가 두 개 다 뽑혔을때
	{
		return 2;
	}
	else if (Set_Tile[total - 1] == 12 && Set_Tile.get_color(total - 1) == "검") // 검은색 조커만 뽑혔을때
	{
		return 0;
	}
	else if (Set_Tile[total - 1] == 12 && Set_Tile.get_color(total - 1) == "흰") // 흰색 조커만 뽑혔을때
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
//Tile 클래스의 숫자벡터의 크기를 반환한다.
int Player::get_tilenum()
{
	return this->hav.size_tile();
}

void Player::tile_fit(int joker_point)
{
	Tile Set_Tile = this->hav;
	Set_Tile.color_pop_back();
	Set_Tile.view_pop_back();
	if (joker_point == -1) // 조커 아닐시 + 정렬이 되어있는 상태여야함
	{
		this->check = Set_Tile.number_getindex(this->rand_num, this->rand_color);
	}
	else // 조커 일시
	{
		this->check = joker_point;
		Set_Tile.number_pop_back();
		Set_Tile.number_insert(this->check, this->rand_num);
	}
	Set_Tile.color_insert(this->check, this->rand_color);
	Set_Tile.view_insert(this->check, 0); // 방금 뽑은 수라 0이다.

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
	this->hav.number_pop_back(); // 맨 뒤의 조커 삭제
	this->hav.number_insert(joker_point, 12); // 조커 재위치.
}

bool Player::view_check(int sequence)
{
	return this->hav.view_check(sequence);
}

int Player::predict_tile(Player& player, int sequence, int number, int check, int& score, int& result) // 선택플레이어, 몇번째, 무슨 수, 현재 턴에서 뽑은 패, 순위, 결과
{
	int more;
	int enter;
	Tile tile = player.gethav();
	if (tile[sequence - 1] == number)
	{
		gotoxy(17, 17);
		cout << "맞추셨습니다." << endl;
		tile.tile_open(sequence - 1);
		result = 1;
		while (1)
		{
			if (tile.view_all_open()) // 모든 타일이 공개되었는지 확인
			{
				gotoxy(17, 18);
				cout << "모든 패를 맞추셨습니다.";
				gotoxy(17, 19);
				cout << "턴이 넘어갑니다." << endl;
				more = 0;
				player.setrank(score);
				score--;
				break;
			}
			gotoxy(17, 18);
			cout << "한번더 맞추시겠습니까?(예 = 1 아니오 = 0) : ";	cin >> more;
			while (cin.fail()) {   // 만약에 error 가 발생하면 
				gotoxy(17, 19);
				cout << "숫자를 입력해주세요";
				cin.clear();     //  error flag 들을 클리어 시킴 
				cin.ignore(INT_MAX, '\n');  // 현재 읽은 값에서 INT_MAX 개 만큼
										  // (충분히) \n을 만날때 까지 버퍼를 버림
				gotoxy(17, 18);
				cout << "한번더 맞추시겠습니까?(예 = 1 아니오 = 0) : ";	cin >> more; // 재입력
			}
			if (more <= 1 && more >= 0) break;
			else
			{
				gotoxy(17, 20);
				cout << more << "를 입력하셨습니다.";
				gotoxy(17, 21);
				cout << "다시 입력해주세요.";
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
		cout << "틀리셨습니다.";
		gotoxy(17, 18);
		cout << "방금 뽑으신 패를 공개합니다.";
		tile.tile_open(check);
		this->sethav(tile);
		gotoxy(17, 19);
		cout << "턴을 종료하고 다음 순서로 넘어갑니다.(Enter)";
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
	for (add_num3 = 2; add_num3 <= tile_size; add_num3++)  //add_num3은 다음카드로 넘어갈 때 더해주는 숫자 
	{
		for (int i = Start_WIDTH * multiplication_num3 + add_num3; i < Start_WIDTH * (multiplication_num3 + 1) + add_num3; i++)
		{
			gotoxy(i, 1);
			cout << "─";
			gotoxy(i, Start_HEIGHT);
			cout << "─";
			gotoxy(i, 3);
			cout << "─";
			gotoxy(i - 1, 2);
		}
		if (tile_color[add_num3 - 2] == "검") cout << "■ B";
		else cout << "□ W";

		for (int i = 1; i < Start_HEIGHT; i++)
		{
			gotoxy(Start_WIDTH * multiplication_num3 + add_num3, i);
			cout << "│";
			gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, i);
			cout << "│";
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
		cout << "┌";
		gotoxy(Start_WIDTH * multiplication_num3 + add_num3, Start_HEIGHT);
		cout << "└";
		gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, 1);
		cout << "┐";
		gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, Start_HEIGHT);
		cout << "┘";
		multiplication_num3++;
	}
	gotoxy(2, Start_HEIGHT + 1);
	cout << "★1P  name : ";
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
	for (add_num3 = 2; add_num3 <= tile_size; add_num3++)  //add_num3은 다음카드로 넘어갈 때 더해주는 숫자 
	{
		for (int i = Start_WIDTH * multiplication_num3 + add_num3; i < Start_WIDTH * (multiplication_num3 + 1) + add_num3; i++)
		{
			gotoxy(i, Start_HEIGHT_Under);
			cout << "─";
			gotoxy(i, Start_HEIGHT_Under + Start_HEIGHT - 1);
			cout << "─";
			gotoxy(i, Start_HEIGHT_Under + 2);
			cout << "─";
			gotoxy(i - 1, Start_HEIGHT_Under + 1);
		}
		if (tile_color[add_num3 - 2] == "검") cout << "■ B";
		else cout << "□ W";

		for (int i = Start_HEIGHT_Under; i < Start_HEIGHT_Under + Start_HEIGHT - 1; i++)
		{
			gotoxy(Start_WIDTH * multiplication_num3 + add_num3, i);
			cout << "│";
			gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, i);
			cout << "│";
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
		cout << "┌";
		gotoxy(Start_WIDTH * multiplication_num3 + add_num3, Start_HEIGHT_Under + Start_HEIGHT - 1);
		cout << "└";
		gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, Start_HEIGHT_Under);
		cout << "┐";
		gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, Start_HEIGHT_Under + Start_HEIGHT - 1);
		cout << "┘";
		multiplication_num3++;
	}

	gotoxy(2, Start_HEIGHT_Under - 1);
	cout << "★2P  name : ";
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
	for (add_num3 = 13; add_num3 <= tile_size; add_num3++)  //add_num3은 다음카드로 넘어갈 때 더해주는 숫자 
	{
		for (int i = Start_WIDTH * multiplication_num3 + add_num3; i < Start_WIDTH * (multiplication_num3 + 1) + add_num3; i++)
		{
			gotoxy(i, 1);
			cout << "─";
			gotoxy(i, Start_HEIGHT);
			cout << "─";
			gotoxy(i, 3);
			cout << "─";
			gotoxy(i - 1, 2);
		}
		if (tile_color[add_num3 - 13] == "검") cout << "■ B";
		else cout << "□ W";

		for (int i = 1; i < Start_HEIGHT; i++)
		{
			gotoxy(Start_WIDTH * multiplication_num3 + add_num3, i);
			cout << "│";
			gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, i);
			cout << "│";
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
		cout << "┌";
		gotoxy(Start_WIDTH * multiplication_num3 + add_num3, Start_HEIGHT);
		cout << "└";
		gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, 1);
		cout << "┐";
		gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, Start_HEIGHT);
		cout << "┘";
		multiplication_num3++;
	}
	gotoxy(Start_WIDTH_Under + 1, Start_HEIGHT + 1);
	cout << "★3P  name : ";
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
	for (add_num3 = 13; add_num3 <= tile_size; add_num3++)  //add_num3은 다음카드로 넘어갈 때 더해주는 숫자 
	{
		for (int i = Start_WIDTH * multiplication_num3 + add_num3; i < Start_WIDTH * (multiplication_num3 + 1) + add_num3; i++)
		{
			gotoxy(i, Start_HEIGHT_Under);
			cout << "─";
			gotoxy(i, Start_HEIGHT_Under + Start_HEIGHT - 1);
			cout << "─";
			gotoxy(i, Start_HEIGHT_Under + 2);
			cout << "─";
			gotoxy(i - 1, Start_HEIGHT_Under + 1);
		}
		if (tile_color[add_num3 - 13] == "검") cout << "■ B";
		else cout << "□ W";

		for (int i = Start_HEIGHT_Under; i < Start_HEIGHT_Under + Start_HEIGHT - 1; i++)
		{
			gotoxy(Start_WIDTH * multiplication_num3 + add_num3, i);
			cout << "│";
			gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, i);
			cout << "│";
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
		cout << "┌";
		gotoxy(Start_WIDTH * multiplication_num3 + add_num3, Start_HEIGHT_Under + Start_HEIGHT - 1);
		cout << "└";
		gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, Start_HEIGHT_Under);
		cout << "┐";
		gotoxy(Start_WIDTH * (multiplication_num3 + 1) + add_num3, Start_HEIGHT_Under + Start_HEIGHT - 1);
		cout << "┘";
		multiplication_num3++;
	}
	gotoxy(Start_WIDTH_Under + 1, Start_HEIGHT_Under - 1);
	cout << "★4P  name : ";
	cout << p.getname();
}

void FourPlayer::GameEndFild()
{
	system("cls");

	//게임창
	for (int i = 1; i <= FIELD_WIDTH; i++)
	{
		gotoxy(i, 0);
		cout << "─";
		gotoxy(i, FIELD_HEIGHT);
		cout << "─";
	}
	for (int i = 1; i <= FIELD_HEIGHT; i++)
	{
		gotoxy(0, i);
		cout << "│";
		gotoxy(FIELD_WIDTH, i);
		cout << "│";
	}
	gotoxy(0, 0);
	cout << "┌";
	gotoxy(0, FIELD_HEIGHT);
	cout << "└";
	gotoxy(FIELD_WIDTH, 0);
	cout << "┐";
	gotoxy(FIELD_WIDTH, FIELD_HEIGHT);
	cout << "┘";

	//Start 사각형
	for (int i = 20; i < 39; i++)
	{
		gotoxy(i, 11);
		cout << "─";
		gotoxy(i, 30);
		cout << "─";
	}
	for (int i = 11; i < 30; i++)
	{
		gotoxy(20, i);
		cout << "│";
		gotoxy(39, i);
		cout << "│";
	}

	gotoxy(20, 11);
	cout << "┌";
	gotoxy(20, 30);
	cout << "└";
	gotoxy(39, 11);
	cout << "┐";
	gotoxy(39, 30);
	cout << "┘";

	gotoxy(27, 12);
	cout << "NAME & SCORE";

	for (int i = 24; i < 35; i++)
	{
		gotoxy(i, 17);
		cout << "─";
		gotoxy(i, 20);
		cout << "─";
		gotoxy(i, 23);
		cout << "─";
		gotoxy(i, 26);
		cout << "─";
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //글자 색 바꿔주는 함수 (빨강색)
	//다빈치 코드 글자 출력
	gotoxy(27, 5);
	cout << "★Game End ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);   //글자 색 바꿔주는 함수 (노랑색)

	//왼쪽 별
	gotoxy(10, 11);
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << "＊";
		}
		cout << "\n";
		gotoxy(10, 11 + i);
	}

	//오른쪽 별
	gotoxy(40, 11);
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << "＊";
		}
		cout << "\n";
		gotoxy(40, 11 + i);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);   //글자 색 바꿔주는 함수 (흰색)

	for (int i = 0; i < 8; i++)
	{
		cout << "\n";
	}
}
