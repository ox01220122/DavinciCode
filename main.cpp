#include "class.h"

int main()
{
	srand((unsigned)time(NULL));
	int enter;

	GameStartFild(); // 엔터키를 받으면 함수를 나옴
	GamesetFild();

	Tile total_WTile; // 전체 흰색 타일
	Tile total_BTile; // 전체 검은색 타일

	int number; // 참가자 수

	while (1)
	{
		gotoxy(24, 19);
		cout << "참가자 수(2 - 4인) : ";	cin >> number;
		while (cin.fail()) {   // 만약에 error 가 발생하면 
			gotoxy(24, 20);
			cout << "숫자를 입력해주세요";
			cin.clear();     //  error flag 들을 클리어 시킴 
			cin.ignore(INT_MAX, '\n');  // 현재 읽은 값에서 INT_MAX 개 만큼
									  // (충분히) \n을 만날때 까지 버퍼를 버림 
			gotoxy(24, 19);
			cout << "참가자 수(2 - 4인) : ";	cin >> number; // 재입력
		}
		if (number > 1 && number < 5) break;
		else
		{
			gotoxy(24, 21);
			cout << number << " 를 입력하셨습니다.";
			gotoxy(24, 22);
			cout << "다시 입력해주세요.";
		}
	}

	FourPlayer* pF = new FourPlayer;

	// 참가수에 맞게 동적할당
	Player* pPlayer = new Player[number];

	int white, black;
	string player_name;
	int joker_point[4]{ -1,-1,-1,-1 }; //흰색 조커의 위치 0, 흰색 조커를 가진 플레이어넘버 1, 검은색 조커의 위치 2, 검은색 조커를 가진 플레이어넘버3
	int first; // 4인이면 3, 3인 이하면 4

	if (number == 4) first = 3;
	else first = 4;

	system("cls");
	Game_Record_Window();

	for (int i = 0; i < number; i++) // 인원 수만큼 이름과 첫 패를 결정
	{		
		gotoxy(17, 14);
		cout << "한 플레이어만 봐주세요.";
		gotoxy(17, 15);
		cout << "플레이어 " << i + 1 << "의 이름을 입력해주세요 : ";	cin >> player_name;

		Game_Record_Window_reset();

		pPlayer[i].setname(player_name); // 이름 설정
		pPlayer[i].tile_clear(); // 패 셋팅 전 임시값 지우기

		while (1)
		{
			gotoxy(17, 14);
			cout << first << "개의 패를 가져올 수 있습니다.";
			gotoxy(17, 15);
			cout << "흰색과 검은색을 각각 몇 개씩 가져올까요?";
			gotoxy(17, 16);
			cout << "흰색 : ";	cin >> white;
			while (cin.fail()) {   // 만약에 error 가 발생하면 
				gotoxy(17, 18);
				cout << "숫자를 입력해주세요";
				cin.clear();     //  error flag 들을 클리어 시킴 
				cin.ignore(INT_MAX, '\n');  // 현재 읽은 값에서 INT_MAX 개 만큼
										  // (충분히) \n을 만날때 까지 버퍼를 버림 
				gotoxy(17, 16);
				cout << "흰색 : ";	cin >> white; // 재입력
			}
			gotoxy(17, 17);
			cout << "검은색 : ";	cin >> black;
			while (cin.fail()) {   // 만약에 error 가 발생하면 
				gotoxy(17, 18);
				cout << "숫자를 입력해주세요";
				cin.clear();     //  error flag 들을 클리어 시킴 
				cin.ignore(INT_MAX, '\n');  // 현재 읽은 값에서 INT_MAX 개 만큼
										  // (충분히) \n을 만날때 까지 버퍼를 버림
				gotoxy(17, 17);
				cout << "검은색 : ";	cin >> black; // 재입력
			}

			if (!(white > first || black > first || white < 0 || black < 0 || white + black != first)) break;
			else
			{
				Game_Record_Window_reset();
				gotoxy(17, 18);
				cout << "수가 맞지 않습니다.";
				gotoxy(17, 19);
				cout<< "다시 입력해주세요.";
			}
		}

		pPlayer[i].new_whitetile(total_WTile, white);

		pPlayer[i].new_blacktile(total_BTile, black);

		pPlayer[i].tile_firstsort(first); // 정렬

		Game_Record_Window_reset();

		if (!i) pF->Player1(pPlayer[i], 1);
		else if (i == 1) pF->Player2(pPlayer[i], 1);
		else if (i == 2) pF->Player3(pPlayer[i], 1);
		else if (i == 3) pF->Player4(pPlayer[i], 1);

		if (pPlayer[i].jocker_check() == 2) // 조커가 두 개 다 뽑혔을때
		{
			while (1) //검은색 조커
			{
				gotoxy(17, 14);
				cout << "검은색 조커의 위치를 결정해주세요(왼쪽에서 몇번째) : ";	cin >> joker_point[2];
				while (cin.fail()) {   // 만약에 error 가 발생하면 
					gotoxy(17, 15);
					cout << "숫자를 입력해주세요";
					cin.clear();     //  error flag 들을 클리어 시킴 
					cin.ignore(INT_MAX, '\n');  // 현재 읽은 값에서 INT_MAX 개 만큼
											  // (충분히) \n을 만날때 까지 버퍼를 버림
					gotoxy(17, 14);
					cout << "검은색 조커의 위치를 결정해주세요(왼쪽에서 몇번째) : ";	cin >> joker_point[2]; // 재입력
				}
				if (joker_point[2] == first - 1) break; // 같은 위치면 탈출
				else if (joker_point[2] > 0 && joker_point[2] < first + 1) // 제대로 된 입력일시
				{
					joker_point[2]--; // 인덱스값으로 변경
					pPlayer[i].jocker_select(first, 2, joker_point[2], "검");
					joker_point[3] = i; // 검은색 조커를 가진 플레이어가 누군지 기록
					break;
				}
				else
				{
					gotoxy(17, 16);
					cout << "잘못된 위치입니다.";
					gotoxy(17, 17);
					cout << "다시 입력해주세요.";
				}

			}

			Game_Record_Window_reset();
			
			if (!i) pF->Player1(pPlayer[i], 1);
			else if (i == 1) pF->Player2(pPlayer[i], 1);
			else if (i == 2) pF->Player3(pPlayer[i], 1);
			else if (i == 3) pF->Player4(pPlayer[i], 1);

			while (1) // 흰색 조커
			{
				gotoxy(17, 15);
				cout << "흰색 조커의 위치를 결정해주세요(왼쪽에서 몇번째) : ";	cin >> joker_point[0];
				while (cin.fail()) {   // 만약에 error 가 발생하면 
					gotoxy(17, 16);
					cout << "숫자를 입력해주세요";
					cin.clear();     //  error flag 들을 클리어 시킴 
					cin.ignore(INT_MAX, '\n');  // 현재 읽은 값에서 INT_MAX 개 만큼
											  // (충분히) \n을 만날때 까지 버퍼를 버림
					gotoxy(17, 15);
					cout << "흰색 조커의 위치를 결정해주세요(왼쪽에서 몇번째) : ";	cin >> joker_point[0]; // 재입력
				}
				if (joker_point[0] == first) break;
				else if (joker_point[0] > 0 && joker_point[0] < first + 1)
				{
					joker_point[0]--; // 인덱스값으로 변경
					pPlayer[i].jocker_select(first, 1, joker_point[0], "흰");
					joker_point[1] = i; // 흰색 조커를 가진 플레이어가 누군지 기록
					break;
				}
				else
				{
					gotoxy(17, 17);
					cout << "잘못된 위치입니다.";
					gotoxy(17, 18);
					cout << "다시 입력해주세요.";
				}
			}
			
		}
		else if (pPlayer[i].jocker_check() == 0) // 검은색 조커만 뽑혔을때
		{				
			while (1)
			{
				gotoxy(17, 14);
				cout << "검은색 조커의 위치를 결정해주세요(왼쪽에서 몇번째) : ";	cin >> joker_point[2];
				while (cin.fail()) {   // 만약에 error 가 발생하면 
					gotoxy(17, 15);
					cout << "숫자를 입력해주세요";
					cin.clear();     //  error flag 들을 클리어 시킴 
					cin.ignore(INT_MAX, '\n');  // 현재 읽은 값에서 INT_MAX 개 만큼
											  // (충분히) \n을 만날때 까지 버퍼를 버림
					gotoxy(17, 14);
					cout << "검은색 조커의 위치를 결정해주세요(왼쪽에서 몇번째) : ";	cin >> joker_point[2]; // 재입력
				}
				if (joker_point[2] == first) break; // 같은 위치면 탈출
				else if (joker_point[2] > 0 && joker_point[2] < first + 1) // 제대로 된 입력일시
				{
					joker_point[2]--; // 인덱스값으로 변경
					pPlayer[i].jocker_select(first, 1, joker_point[2], "검");
					joker_point[3] = i; // 검은색 조커를 가진 플레이어가 누군지 기록
					break;
				}
				else
				{
					gotoxy(17, 16);
					cout << "잘못된 위치입니다.";
					gotoxy(17, 17);
					cout << "다시 입력해주세요.";
				}

			}
			
		}
		else if (pPlayer[i].jocker_check() == 1) // 흰색 조커만 뽑혔을때
		{			
			while (1) // 흰색 조커 뽑혔을때
			{
				gotoxy(17, 14);
				cout << "흰색 조커의 위치를 결정해주세요(왼쪽에서 몇번째) : ";	cin >> joker_point[0];
				while (cin.fail()) {   // 만약에 error 가 발생하면 
					gotoxy(17, 15);
					cout << "숫자를 입력해주세요";
					cin.clear();     //  error flag 들을 클리어 시킴 
					cin.ignore(INT_MAX, '\n');  // 현재 읽은 값에서 INT_MAX 개 만큼
											  // (충분히) \n을 만날때 까지 버퍼를 버림
					gotoxy(17, 14);
					cout << "흰색 조커의 위치를 결정해주세요(왼쪽에서 몇번째) : ";	cin >> joker_point[0]; // 재입력
				}
				if (joker_point[0] == first) break;
				else if (joker_point[0] > 0 && joker_point[0] < first + 1)
				{
					joker_point[0]--; // 인덱스값으로 변경
					pPlayer[i].jocker_select(first, 1, joker_point[0], "흰");
					joker_point[1] = i; // 흰색 조커를 가진 플레이어가 누군지 기록
					break;
				}
				else
				{
					gotoxy(17, 16);
					cout << "잘못된 위치입니다.";
					gotoxy(17, 17);
					cout << "다시 입력해주세요.";
				}
			}
			
		}

		Game_Record_Window_reset();
		if (!i) pF->Player1(pPlayer[i], 0);
		else if (i == 1) pF->Player2(pPlayer[i], 0);
		else if (i == 2) pF->Player3(pPlayer[i], 0);
		else if (i == 3) pF->Player4(pPlayer[i], 0);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////// 셋팅 끝, 게임 시작.

	int player_number = 0;
	int color = 0, check = 0, next = 1, result = 0;
	int choice_se, choice_num;
	int score = number; // 꼴등부터

	// 본 게임
	while (1)
	{
		if (score == 1) // 모든 승패가 갈리면 게임 끝
		{
			for (int i = 0; i < number; i++)
			{
				if (!pPlayer[i].getrank())
				{
					pPlayer[i].setrank(score);
					break;
				}
			}
			break;
		}

		if (pPlayer[player_number].tile_check() && !pPlayer[player_number].getrank())
		{
			gotoxy(17, 21);
			cout << pPlayer[player_number].getname() << "님은 패가 모두 공개되었습니다.(Enter)";
			enter = _getch();
			cin.ignore();
			player_number++; //다음 플레이어 차례
			if (player_number == number) player_number = 0;
			continue; // 다음 플레이어 턴으로
		}

		Game_Record_Window_reset();

		gotoxy(17, 22 + player_number); // 지우는 용도
		for (int i = 17; i < 71; i++)
		{
			cout << " ";
		}

		gotoxy(17, 14);
		cout << pPlayer[player_number].getname() << " 님의 순서입니다.(Enter)";	enter = _getch(); // 다른 플레이어가 패를 보지 않도록 방지.
		cin.ignore();
		cout << endl;

		if (!player_number) pF->Player1(pPlayer[player_number], 1);
		else if (player_number == 1) pF->Player2(pPlayer[player_number], 1);
		else if (player_number == 2) pF->Player3(pPlayer[player_number], 1);
		else if (player_number == 3) pF->Player4(pPlayer[player_number], 1);

		if (total_BTile.total_check() || total_WTile.total_check()) // 어느 한쪽이라도 남으면 뽑는다.
		{
			while (1)
			{
				if (!total_BTile.total_check())
				{
					gotoxy(17, 14);
					cout << "남은 패는 흰색 밖에 없습니다.";
					gotoxy(17, 15);
					cout << "자동으로 흰색을 선택합니다.(Enter)";
					color = 0;
					enter = _getch();
					cin.ignore();
					break;
				}
				else if (!total_WTile.total_check())
				{
					gotoxy(17, 14);
					cout << "남은 패는 검은색 밖에 없습니다.";
					gotoxy(17, 15);
					cout << "자동으로 검은색을 선택합니다.(Enter)";
					color = 1;
					enter = _getch();
					cin.ignore();
					break;
				}
				else
				{
					gotoxy(17, 14);
					cout << "뽑으실 색상을 선택해주세요.(흰색 - 0, 검은색 - 1) : ";	cin >> color;
					while (cin.fail()) {   // 만약에 error 가 발생하면 
						gotoxy(17, 15);
						cout << "숫자를 입력해주세요";
						cin.clear();     //  error flag 들을 클리어 시킴 
						cin.ignore(INT_MAX, '\n');  // 현재 읽은 값에서 INT_MAX 개 만큼
												  // (충분히) \n을 만날때 까지 버퍼를 버림
						gotoxy(17, 14);
						cout << "뽑으실 색상을 선택해주세요.(흰색 - 0, 검은색 - 1) : ";	cin >> color; // 재입력
					}
					if (!color || color == 1) break;
					else
					{
						gotoxy(17, 16);
						cout << color << " 를 입력하셨습니다.";
						gotoxy(17, 17);
						cout << "다시 입력해주세요.";
					}
						
				}
			}

			Game_Record_Window_reset();

			if (!color) // 흰색
			{
				pPlayer[player_number].new_whitetile(total_WTile, 1); // 새 패 뽑기

				if (!player_number) pF->Player1(pPlayer[player_number], 1);
				else if (player_number == 1) pF->Player2(pPlayer[player_number], 1);
				else if (player_number == 2) pF->Player3(pPlayer[player_number], 1);
				else if (player_number == 3) pF->Player4(pPlayer[player_number], 1);

				if (pPlayer[player_number].jocker_check() == 1) // 흰색 조커 뽑혔을때
				{
					while (1)
					{
						gotoxy(17, 14);
						cout << "흰색 조커의 위치를 결정해주세요(왼쪽에서 몇번째) : ";	cin >> joker_point[0];
						while (cin.fail()) {   // 만약에 error 가 발생하면 
							gotoxy(17, 15);
							cout << "숫자를 입력해주세요";
							cin.clear();     //  error flag 들을 클리어 시킴 
							cin.ignore(INT_MAX, '\n');  // 현재 읽은 값에서 INT_MAX 개 만큼
													  // (충분히) \n을 만날때 까지 버퍼를 버림
							gotoxy(17, 14);
							cout << "흰색 조커의 위치를 결정해주세요(왼쪽에서 몇번째) : ";	cin >> joker_point[0]; // 재입력
						}
						if (joker_point[0] == pPlayer[player_number].get_tilenum()) // 같은 위치면 탈출
						{
							joker_point[0]--; // 인덱스로 변경
							joker_point[1] = player_number; // 흰색 조커를 가진 플레이어가 누군지 기록
							break;
						}
						else if (joker_point[0] > 0 && joker_point[0] < pPlayer[player_number].get_tilenum() + 1) // 제대로 된 입력일시
						{
							joker_point[0]--; // 인덱스값으로 변경
							pPlayer[player_number].tile_fit(joker_point[0]);
							joker_point[1] = player_number; // 흰색 조커를 가진 플레이어가 누군지 기록
							break;
						}
						else
						{
							gotoxy(17, 16);
							cout << "잘못된 위치입니다.";
							gotoxy(17, 17);
							cout << "다시 입력해주세요.";
						}
							

					}
				}
				else // 조커가 아닐 때
				{
					pPlayer[player_number].tile_sort(); // 재정렬, 중간에 조커는 맨 뒤로
					pPlayer[player_number].tile_fit();
				}
			}
			else if (color) // 검은색
			{
				pPlayer[player_number].new_blacktile(total_BTile, 1); // 새 패 뽑기

				if (!player_number) pF->Player1(pPlayer[player_number], 1);
				else if (player_number == 1) pF->Player2(pPlayer[player_number], 1);
				else if (player_number == 2) pF->Player3(pPlayer[player_number], 1);
				else if (player_number == 3) pF->Player4(pPlayer[player_number], 1);

				if (pPlayer[player_number].jocker_check() == 0) // 검은색 조커 뽑혔을때
				{
					while (1)
					{
						gotoxy(17, 14);
						cout << "검은색 조커의 위치를 결정해주세요(왼쪽에서 몇번째) : ";	cin >> joker_point[2];
						while (cin.fail()) {   // 만약에 error 가 발생하면 
							gotoxy(17, 15);
							cout << "숫자를 입력해주세요";
							cin.clear();     //  error flag 들을 클리어 시킴 
							cin.ignore(INT_MAX, '\n');  // 현재 읽은 값에서 INT_MAX 개 만큼
													  // (충분히) \n을 만날때 까지 버퍼를 버림
							gotoxy(17, 14);
							cout << "검은색 조커의 위치를 결정해주세요(왼쪽에서 몇번째) : ";	cin >> joker_point[2]; // 재입력
						}
						if (joker_point[2] == pPlayer[player_number].get_tilenum()) // 같은 위치면 탈출
						{
							joker_point[2]--; // 인덱스로 변경
							joker_point[3] = player_number; // 검은색 조커를 가진 플레이어가 누군지 기록
							break;
						}
						else if (joker_point[2] > 0 && joker_point[2] < pPlayer[player_number].get_tilenum() + 1) // 제대로 된 입력일시
						{
							joker_point[2]--; // 인덱스값으로 변경
							pPlayer[player_number].tile_fit(joker_point[2]);
							joker_point[3] = player_number; // 검은색 조커를 가진 플레이어가 누군지 기록
							break;
						}
						else
						{
							gotoxy(17, 16);
							cout << "잘못된 위치입니다.";
							gotoxy(17, 17);
							cout << "다시 입력해주세요.";
						}

					}
				}
				else // 조커가 아닐 때
				{
					pPlayer[player_number].tile_sort(); // 재정렬, 중간에 조커는 맨 뒤로
					pPlayer[player_number].tile_fit();
				}
			}
			if (!player_number) pF->Player1(pPlayer[player_number], 1);
			else if (player_number == 1) pF->Player2(pPlayer[player_number], 1);
			else if (player_number == 2) pF->Player3(pPlayer[player_number], 1);
			else if (player_number == 3) pF->Player4(pPlayer[player_number], 1);

			check = pPlayer[player_number].getcheck();

			if (player_number == joker_point[1] && pPlayer[player_number].getrand_num() != 12) // 흰색 조커를 가진 플레이어이고 뽑은 패가 조커가 아닐때
			{
				if (check == joker_point[0]) // 조커와 뽑은 패의 위치인덱스가 일치
				{
					Game_Record_Window_reset();

					gotoxy(17, 14);
					cout << "뽑으신 패와 흰색 조커의 위치가 일치합니다.";
					gotoxy(17, 15);
					cout << "조커의 위치를 재결정해주세요.";
					while (1)
					{
						gotoxy(17, 16);
						cout << "새로 뽑으신 패("<< pPlayer[player_number].getrand_num() <<")의 왼쪽(0) 또는 오른쪽(1) : ";	cin >> enter; // 변수 재활용
						while (cin.fail()) {   // 만약에 error 가 발생하면 
							gotoxy(17, 17);
							cout << "숫자를 입력해주세요";
							cin.clear();     //  error flag 들을 클리어 시킴 
							cin.ignore(INT_MAX, '\n');  // 현재 읽은 값에서 INT_MAX 개 만큼
													  // (충분히) \n을 만날때 까지 버퍼를 버림
							gotoxy(17, 16);
							cout << "새로 뽑으신 패(" << pPlayer[player_number].getrand_num() << ")의 왼쪽(0) 또는 오른쪽(1) : ";	cin >> enter; // 재입력
						}
						if (enter == 0 || enter == 1) break;
						else
						{
							gotoxy(17, 18);
							cout << enter << " 입력하셨습니다.";
							gotoxy(17, 19);
							cout << "다시 입력해주세요";
						}
					}
					
					if (enter == 1)joker_point[0]++; // 오른쪽이면 인덱스 증가			
					else // 왼쪽일 경우
					{
						check++;
						pPlayer[player_number].setcheck(check);
						pPlayer[player_number].leftshift_joker(joker_point[0]);
					}
				}
				else if (joker_point[0] > check) // 흰색 조커가 뽑은 패의 뒤쪽일 때
				{
					joker_point[0]++; // 인덱스 증가
				}
				pPlayer[player_number].jocker_fit(joker_point[0]); // 조커 재위치
			}
			else if (player_number == joker_point[3] && pPlayer[player_number].getrand_num() != 12) // 검은색 조커를 가진 플레이어이고 뽑은 패가 조커가 아닐때
			{
				if (check == joker_point[2]) // 조커와 뽑은 패의 위치인덱스가 일치
				{
					if (!player_number) pF->Player1(pPlayer[player_number], 1);
					else if (player_number == 1) pF->Player2(pPlayer[player_number], 1);
					else if (player_number == 2) pF->Player3(pPlayer[player_number], 1);
					else if (player_number == 3) pF->Player4(pPlayer[player_number], 1);

					Game_Record_Window_reset();

					gotoxy(17, 14);
					cout << "뽑으신 패와 검은색 조커의 위치가 일치합니다.";
					gotoxy(17, 15);
					cout << "조커의 위치를 재결정해주세요.";
					while (1)
					{
						gotoxy(17, 16);
						cout << "새로 뽑으신 패(" << pPlayer[player_number].getrand_num() << ")의 왼쪽(0) 또는 오른쪽(1) : ";	cin >> enter; // 변수 재활용
						while (cin.fail()) {   // 만약에 error 가 발생하면 
							gotoxy(17, 17);
							cout << "숫자를 입력해주세요";
							cin.clear();     //  error flag 들을 클리어 시킴 
							cin.ignore(INT_MAX, '\n');  // 현재 읽은 값에서 INT_MAX 개 만큼
													  // (충분히) \n을 만날때 까지 버퍼를 버림
							gotoxy(17, 16);
							cout << "새로 뽑으신 패(" << pPlayer[player_number].getrand_num() << ")의 왼쪽(0) 또는 오른쪽(1) : ";	cin >> enter; // 재입력
						}
						if (enter == 0 || enter == 1) break;
						else
						{
							gotoxy(17, 18);
							cout << enter << " 입력하셨습니다.";
							gotoxy(17, 19);
							cout << "다시 입력해주세요";
						}
					}
					
					if (enter == 1) joker_point[2]++; // 오른쪽이면 인덱스 증가
					else // 왼쪽일 경우
					{
						check++;
						pPlayer[player_number].setcheck(check);
						pPlayer[player_number].leftshift_joker(joker_point[2]);
					}
				}
				else if (joker_point[2] > check) // 흰색 조커가 뽑은 패의 뒤쪽일 때
				{
					joker_point[2]++; // 인덱스 증가
				}
				pPlayer[player_number].jocker_fit(joker_point[2]); // 조커 재위치
			}
		}

		Game_Record_Window_reset();

		if (!player_number) pF->Player1(pPlayer[player_number], 1);
		else if (player_number == 1) pF->Player2(pPlayer[player_number], 1);
		else if (player_number == 2) pF->Player3(pPlayer[player_number], 1);
		else if (player_number == 3) pF->Player4(pPlayer[player_number], 1);

		next = 1;
		while (next) // 맞추면 한번 더 맞출 기회생김
		{
			Game_Record_Window_reset();
			if (number != 2) // 참가자 수가 3명이상
			{
				while (1)
				{
					gotoxy(17, 14);
					cout << "어떤 플레이어의 패를 맞추시겠습니까?(숫자) : ";	cin >> enter; // 변수 재활용
					while (cin.fail()) {   // 만약에 error 가 발생하면 
						gotoxy(17, 15);
						cout << "숫자를 입력해주세요";
						cin.clear();     //  error flag 들을 클리어 시킴 
						cin.ignore(INT_MAX, '\n');  // 현재 읽은 값에서 INT_MAX 개 만큼
												  // (충분히) \n을 만날때 까지 버퍼를 버림
						gotoxy(17, 14);
						cout << "어떤 플레이어의 패를 맞추시겠습니까?(숫자) : ";	cin >> enter; // 재입력
					}
					enter--; // 인덱스로 변경
					if (enter == player_number)
					{
						Game_Record_Window_reset();
						gotoxy(17, 15);
						cout << "자기 자신을 선택할 순 없습니다.";
						gotoxy(17, 16);
						cout << "다시 입력해주세요.";
					}
					else if (enter < 0 || enter >= number)
					{
						Game_Record_Window_reset();
						gotoxy(17, 15);
						cout << enter + 1 << " 입력하셨습니다.";
						gotoxy(17, 16);
						cout << "다시 입력해주세요.";
					}
					else break;
				}
			}
			else if (!player_number)
			{
				enter = 1;
			}
			else enter = 0;

			Game_Record_Window_reset();

			while (1)
			{
				try {
					gotoxy(17, 14);
					cout << enter + 1 << "P의 몇번째 타일을 맞추시겠습니까? : ";	cin >> choice_se;
					while (cin.fail()) {   // 만약에 error 가 발생하면 
						gotoxy(17, 15);
						cout << "숫자를 입력해주세요";
						cin.clear();     //  error flag 들을 클리어 시킴 
						cin.ignore(INT_MAX, '\n');  // 현재 읽은 값에서 INT_MAX 개 만큼
												  // (충분히) \n을 만날때 까지 버퍼를 버림
						gotoxy(17, 14);
						cout << enter + 1 << "P의 몇번째 타일을 맞추시겠습니까? : ";	cin >> choice_se; // 재입력
					}
					if (choice_se < 1 || choice_se > pPlayer[enter].get_tilenum()) throw choice_se; // 범위에 벗어난 수이면
					if (!pPlayer[enter].view_check(choice_se))
					{
						gotoxy(17, 15);
						cout << "이미 공개된 패입니다." << endl;
						throw choice_se;
					}
					gotoxy(17, 16);
					cout << "추정하는 수를 입력해주세요. (조커는 12) : ";	cin >> choice_num;
					while (cin.fail()) {   // 만약에 error 가 발생하면 
						gotoxy(17, 17);
						cout << "숫자를 입력해주세요";
						cin.clear();     //  error flag 들을 클리어 시킴 
						cin.ignore(INT_MAX, '\n');  // 현재 읽은 값에서 INT_MAX 개 만큼
												  // (충분히) \n을 만날때 까지 버퍼를 버림
						gotoxy(17, 16);
						cout << "추정하는 수를 입력해주세요. (조커는 12) : ";	cin >> choice_num; // 재입력
					}
					if (choice_num < 0 || choice_num > 12) throw choice_num; // 범위에 벗어난 수라면
					break;
				}
				catch (int c)
				{
					Game_Record_Window_reset();
					gotoxy(17, 18);
					cout << c << " 입력하셨습니다.";
					gotoxy(17, 19);
					cout << "다시 입력해주세요.";
				}
			}
			next = pPlayer[player_number].predict_tile(pPlayer[enter], choice_se, choice_num, check, score, result); // 추정결과

			if (!enter) pF->Player1(pPlayer[enter], 0);
			else if (enter == 1) pF->Player2(pPlayer[enter], 0);
			else if (enter == 2) pF->Player3(pPlayer[enter], 0);
			else if (enter == 3) pF->Player4(pPlayer[enter], 0);
			
			gotoxy(17, 22+player_number); // 지우는 용도
			for (int i = 17; i < 71; i++)
			{
				cout << " ";
			}
			gotoxy(17, 22 + player_number);
			cout << player_number + 1 << "P" << " --> " << enter + 1 << "P : " << choice_se << " ==> " << choice_num << " :" << (result == 0 ? " X " : " 0 ");
		}
		if (!player_number) pF->Player1(pPlayer[player_number], 0);
		else if (player_number == 1) pF->Player2(pPlayer[player_number], 0);
		else if (player_number == 2) pF->Player3(pPlayer[player_number], 0);
		else if (player_number == 3) pF->Player4(pPlayer[player_number], 0);
		player_number++; //다음 플레이어 차례
		if (player_number == number) player_number = 0;
	}

	Game_Record_Window_reset();
	string* pranking;
	pranking = new string[number];
	int rank;

	gotoxy(17, 14);
	cout << "모든 순위가 결정되었습니다.(Enter)";	enter = _getch();
	cin.ignore();
	for (int i = 0; i < number; i++)
	{
		rank = pPlayer[i].getrank();
		pranking[rank - 1] = pPlayer[i].getname();
	}

	pF->GameEndFild();

	gotoxy(25, 16);
	for (int i = 0; i < number; i++)
	{
		cout << i + 1 << "위 " << pranking[i];
		gotoxy(25, 16 + 3 * (i + 1));
	}

	gotoxy(24, 31);
	cout << "Enter를 누르면 종료합니다.";	enter = _getch();

	gotoxy(60, 39);

	delete[]pPlayer;
	delete pF;
	delete[]pranking;


	return 0;
}