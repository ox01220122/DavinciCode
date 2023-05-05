#include "class.h"

int main()
{
	srand((unsigned)time(NULL));
	int enter;

	GameStartFild(); // ����Ű�� ������ �Լ��� ����
	GamesetFild();

	Tile total_WTile; // ��ü ��� Ÿ��
	Tile total_BTile; // ��ü ������ Ÿ��

	int number; // ������ ��

	while (1)
	{
		gotoxy(24, 19);
		cout << "������ ��(2 - 4��) : ";	cin >> number;
		while (cin.fail()) {   // ���࿡ error �� �߻��ϸ� 
			gotoxy(24, 20);
			cout << "���ڸ� �Է����ּ���";
			cin.clear();     //  error flag ���� Ŭ���� ��Ŵ 
			cin.ignore(INT_MAX, '\n');  // ���� ���� ������ INT_MAX �� ��ŭ
									  // (�����) \n�� ������ ���� ���۸� ���� 
			gotoxy(24, 19);
			cout << "������ ��(2 - 4��) : ";	cin >> number; // ���Է�
		}
		if (number > 1 && number < 5) break;
		else
		{
			gotoxy(24, 21);
			cout << number << " �� �Է��ϼ̽��ϴ�.";
			gotoxy(24, 22);
			cout << "�ٽ� �Է����ּ���.";
		}
	}

	FourPlayer* pF = new FourPlayer;

	// �������� �°� �����Ҵ�
	Player* pPlayer = new Player[number];

	int white, black;
	string player_name;
	int joker_point[4]{ -1,-1,-1,-1 }; //��� ��Ŀ�� ��ġ 0, ��� ��Ŀ�� ���� �÷��̾�ѹ� 1, ������ ��Ŀ�� ��ġ 2, ������ ��Ŀ�� ���� �÷��̾�ѹ�3
	int first; // 4���̸� 3, 3�� ���ϸ� 4

	if (number == 4) first = 3;
	else first = 4;

	system("cls");
	Game_Record_Window();

	for (int i = 0; i < number; i++) // �ο� ����ŭ �̸��� ù �и� ����
	{		
		gotoxy(17, 14);
		cout << "�� �÷��̾ ���ּ���.";
		gotoxy(17, 15);
		cout << "�÷��̾� " << i + 1 << "�� �̸��� �Է����ּ��� : ";	cin >> player_name;

		Game_Record_Window_reset();

		pPlayer[i].setname(player_name); // �̸� ����
		pPlayer[i].tile_clear(); // �� ���� �� �ӽð� �����

		while (1)
		{
			gotoxy(17, 14);
			cout << first << "���� �и� ������ �� �ֽ��ϴ�.";
			gotoxy(17, 15);
			cout << "����� �������� ���� �� ���� �����ñ��?";
			gotoxy(17, 16);
			cout << "��� : ";	cin >> white;
			while (cin.fail()) {   // ���࿡ error �� �߻��ϸ� 
				gotoxy(17, 18);
				cout << "���ڸ� �Է����ּ���";
				cin.clear();     //  error flag ���� Ŭ���� ��Ŵ 
				cin.ignore(INT_MAX, '\n');  // ���� ���� ������ INT_MAX �� ��ŭ
										  // (�����) \n�� ������ ���� ���۸� ���� 
				gotoxy(17, 16);
				cout << "��� : ";	cin >> white; // ���Է�
			}
			gotoxy(17, 17);
			cout << "������ : ";	cin >> black;
			while (cin.fail()) {   // ���࿡ error �� �߻��ϸ� 
				gotoxy(17, 18);
				cout << "���ڸ� �Է����ּ���";
				cin.clear();     //  error flag ���� Ŭ���� ��Ŵ 
				cin.ignore(INT_MAX, '\n');  // ���� ���� ������ INT_MAX �� ��ŭ
										  // (�����) \n�� ������ ���� ���۸� ����
				gotoxy(17, 17);
				cout << "������ : ";	cin >> black; // ���Է�
			}

			if (!(white > first || black > first || white < 0 || black < 0 || white + black != first)) break;
			else
			{
				Game_Record_Window_reset();
				gotoxy(17, 18);
				cout << "���� ���� �ʽ��ϴ�.";
				gotoxy(17, 19);
				cout<< "�ٽ� �Է����ּ���.";
			}
		}

		pPlayer[i].new_whitetile(total_WTile, white);

		pPlayer[i].new_blacktile(total_BTile, black);

		pPlayer[i].tile_firstsort(first); // ����

		Game_Record_Window_reset();

		if (!i) pF->Player1(pPlayer[i], 1);
		else if (i == 1) pF->Player2(pPlayer[i], 1);
		else if (i == 2) pF->Player3(pPlayer[i], 1);
		else if (i == 3) pF->Player4(pPlayer[i], 1);

		if (pPlayer[i].jocker_check() == 2) // ��Ŀ�� �� �� �� ��������
		{
			while (1) //������ ��Ŀ
			{
				gotoxy(17, 14);
				cout << "������ ��Ŀ�� ��ġ�� �������ּ���(���ʿ��� ���°) : ";	cin >> joker_point[2];
				while (cin.fail()) {   // ���࿡ error �� �߻��ϸ� 
					gotoxy(17, 15);
					cout << "���ڸ� �Է����ּ���";
					cin.clear();     //  error flag ���� Ŭ���� ��Ŵ 
					cin.ignore(INT_MAX, '\n');  // ���� ���� ������ INT_MAX �� ��ŭ
											  // (�����) \n�� ������ ���� ���۸� ����
					gotoxy(17, 14);
					cout << "������ ��Ŀ�� ��ġ�� �������ּ���(���ʿ��� ���°) : ";	cin >> joker_point[2]; // ���Է�
				}
				if (joker_point[2] == first - 1) break; // ���� ��ġ�� Ż��
				else if (joker_point[2] > 0 && joker_point[2] < first + 1) // ����� �� �Է��Ͻ�
				{
					joker_point[2]--; // �ε��������� ����
					pPlayer[i].jocker_select(first, 2, joker_point[2], "��");
					joker_point[3] = i; // ������ ��Ŀ�� ���� �÷��̾ ������ ���
					break;
				}
				else
				{
					gotoxy(17, 16);
					cout << "�߸��� ��ġ�Դϴ�.";
					gotoxy(17, 17);
					cout << "�ٽ� �Է����ּ���.";
				}

			}

			Game_Record_Window_reset();
			
			if (!i) pF->Player1(pPlayer[i], 1);
			else if (i == 1) pF->Player2(pPlayer[i], 1);
			else if (i == 2) pF->Player3(pPlayer[i], 1);
			else if (i == 3) pF->Player4(pPlayer[i], 1);

			while (1) // ��� ��Ŀ
			{
				gotoxy(17, 15);
				cout << "��� ��Ŀ�� ��ġ�� �������ּ���(���ʿ��� ���°) : ";	cin >> joker_point[0];
				while (cin.fail()) {   // ���࿡ error �� �߻��ϸ� 
					gotoxy(17, 16);
					cout << "���ڸ� �Է����ּ���";
					cin.clear();     //  error flag ���� Ŭ���� ��Ŵ 
					cin.ignore(INT_MAX, '\n');  // ���� ���� ������ INT_MAX �� ��ŭ
											  // (�����) \n�� ������ ���� ���۸� ����
					gotoxy(17, 15);
					cout << "��� ��Ŀ�� ��ġ�� �������ּ���(���ʿ��� ���°) : ";	cin >> joker_point[0]; // ���Է�
				}
				if (joker_point[0] == first) break;
				else if (joker_point[0] > 0 && joker_point[0] < first + 1)
				{
					joker_point[0]--; // �ε��������� ����
					pPlayer[i].jocker_select(first, 1, joker_point[0], "��");
					joker_point[1] = i; // ��� ��Ŀ�� ���� �÷��̾ ������ ���
					break;
				}
				else
				{
					gotoxy(17, 17);
					cout << "�߸��� ��ġ�Դϴ�.";
					gotoxy(17, 18);
					cout << "�ٽ� �Է����ּ���.";
				}
			}
			
		}
		else if (pPlayer[i].jocker_check() == 0) // ������ ��Ŀ�� ��������
		{				
			while (1)
			{
				gotoxy(17, 14);
				cout << "������ ��Ŀ�� ��ġ�� �������ּ���(���ʿ��� ���°) : ";	cin >> joker_point[2];
				while (cin.fail()) {   // ���࿡ error �� �߻��ϸ� 
					gotoxy(17, 15);
					cout << "���ڸ� �Է����ּ���";
					cin.clear();     //  error flag ���� Ŭ���� ��Ŵ 
					cin.ignore(INT_MAX, '\n');  // ���� ���� ������ INT_MAX �� ��ŭ
											  // (�����) \n�� ������ ���� ���۸� ����
					gotoxy(17, 14);
					cout << "������ ��Ŀ�� ��ġ�� �������ּ���(���ʿ��� ���°) : ";	cin >> joker_point[2]; // ���Է�
				}
				if (joker_point[2] == first) break; // ���� ��ġ�� Ż��
				else if (joker_point[2] > 0 && joker_point[2] < first + 1) // ����� �� �Է��Ͻ�
				{
					joker_point[2]--; // �ε��������� ����
					pPlayer[i].jocker_select(first, 1, joker_point[2], "��");
					joker_point[3] = i; // ������ ��Ŀ�� ���� �÷��̾ ������ ���
					break;
				}
				else
				{
					gotoxy(17, 16);
					cout << "�߸��� ��ġ�Դϴ�.";
					gotoxy(17, 17);
					cout << "�ٽ� �Է����ּ���.";
				}

			}
			
		}
		else if (pPlayer[i].jocker_check() == 1) // ��� ��Ŀ�� ��������
		{			
			while (1) // ��� ��Ŀ ��������
			{
				gotoxy(17, 14);
				cout << "��� ��Ŀ�� ��ġ�� �������ּ���(���ʿ��� ���°) : ";	cin >> joker_point[0];
				while (cin.fail()) {   // ���࿡ error �� �߻��ϸ� 
					gotoxy(17, 15);
					cout << "���ڸ� �Է����ּ���";
					cin.clear();     //  error flag ���� Ŭ���� ��Ŵ 
					cin.ignore(INT_MAX, '\n');  // ���� ���� ������ INT_MAX �� ��ŭ
											  // (�����) \n�� ������ ���� ���۸� ����
					gotoxy(17, 14);
					cout << "��� ��Ŀ�� ��ġ�� �������ּ���(���ʿ��� ���°) : ";	cin >> joker_point[0]; // ���Է�
				}
				if (joker_point[0] == first) break;
				else if (joker_point[0] > 0 && joker_point[0] < first + 1)
				{
					joker_point[0]--; // �ε��������� ����
					pPlayer[i].jocker_select(first, 1, joker_point[0], "��");
					joker_point[1] = i; // ��� ��Ŀ�� ���� �÷��̾ ������ ���
					break;
				}
				else
				{
					gotoxy(17, 16);
					cout << "�߸��� ��ġ�Դϴ�.";
					gotoxy(17, 17);
					cout << "�ٽ� �Է����ּ���.";
				}
			}
			
		}

		Game_Record_Window_reset();
		if (!i) pF->Player1(pPlayer[i], 0);
		else if (i == 1) pF->Player2(pPlayer[i], 0);
		else if (i == 2) pF->Player3(pPlayer[i], 0);
		else if (i == 3) pF->Player4(pPlayer[i], 0);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////// ���� ��, ���� ����.

	int player_number = 0;
	int color = 0, check = 0, next = 1, result = 0;
	int choice_se, choice_num;
	int score = number; // �õ����

	// �� ����
	while (1)
	{
		if (score == 1) // ��� ���а� ������ ���� ��
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
			cout << pPlayer[player_number].getname() << "���� �а� ��� �����Ǿ����ϴ�.(Enter)";
			enter = _getch();
			cin.ignore();
			player_number++; //���� �÷��̾� ����
			if (player_number == number) player_number = 0;
			continue; // ���� �÷��̾� ������
		}

		Game_Record_Window_reset();

		gotoxy(17, 22 + player_number); // ����� �뵵
		for (int i = 17; i < 71; i++)
		{
			cout << " ";
		}

		gotoxy(17, 14);
		cout << pPlayer[player_number].getname() << " ���� �����Դϴ�.(Enter)";	enter = _getch(); // �ٸ� �÷��̾ �и� ���� �ʵ��� ����.
		cin.ignore();
		cout << endl;

		if (!player_number) pF->Player1(pPlayer[player_number], 1);
		else if (player_number == 1) pF->Player2(pPlayer[player_number], 1);
		else if (player_number == 2) pF->Player3(pPlayer[player_number], 1);
		else if (player_number == 3) pF->Player4(pPlayer[player_number], 1);

		if (total_BTile.total_check() || total_WTile.total_check()) // ��� �����̶� ������ �̴´�.
		{
			while (1)
			{
				if (!total_BTile.total_check())
				{
					gotoxy(17, 14);
					cout << "���� �д� ��� �ۿ� �����ϴ�.";
					gotoxy(17, 15);
					cout << "�ڵ����� ����� �����մϴ�.(Enter)";
					color = 0;
					enter = _getch();
					cin.ignore();
					break;
				}
				else if (!total_WTile.total_check())
				{
					gotoxy(17, 14);
					cout << "���� �д� ������ �ۿ� �����ϴ�.";
					gotoxy(17, 15);
					cout << "�ڵ����� �������� �����մϴ�.(Enter)";
					color = 1;
					enter = _getch();
					cin.ignore();
					break;
				}
				else
				{
					gotoxy(17, 14);
					cout << "������ ������ �������ּ���.(��� - 0, ������ - 1) : ";	cin >> color;
					while (cin.fail()) {   // ���࿡ error �� �߻��ϸ� 
						gotoxy(17, 15);
						cout << "���ڸ� �Է����ּ���";
						cin.clear();     //  error flag ���� Ŭ���� ��Ŵ 
						cin.ignore(INT_MAX, '\n');  // ���� ���� ������ INT_MAX �� ��ŭ
												  // (�����) \n�� ������ ���� ���۸� ����
						gotoxy(17, 14);
						cout << "������ ������ �������ּ���.(��� - 0, ������ - 1) : ";	cin >> color; // ���Է�
					}
					if (!color || color == 1) break;
					else
					{
						gotoxy(17, 16);
						cout << color << " �� �Է��ϼ̽��ϴ�.";
						gotoxy(17, 17);
						cout << "�ٽ� �Է����ּ���.";
					}
						
				}
			}

			Game_Record_Window_reset();

			if (!color) // ���
			{
				pPlayer[player_number].new_whitetile(total_WTile, 1); // �� �� �̱�

				if (!player_number) pF->Player1(pPlayer[player_number], 1);
				else if (player_number == 1) pF->Player2(pPlayer[player_number], 1);
				else if (player_number == 2) pF->Player3(pPlayer[player_number], 1);
				else if (player_number == 3) pF->Player4(pPlayer[player_number], 1);

				if (pPlayer[player_number].jocker_check() == 1) // ��� ��Ŀ ��������
				{
					while (1)
					{
						gotoxy(17, 14);
						cout << "��� ��Ŀ�� ��ġ�� �������ּ���(���ʿ��� ���°) : ";	cin >> joker_point[0];
						while (cin.fail()) {   // ���࿡ error �� �߻��ϸ� 
							gotoxy(17, 15);
							cout << "���ڸ� �Է����ּ���";
							cin.clear();     //  error flag ���� Ŭ���� ��Ŵ 
							cin.ignore(INT_MAX, '\n');  // ���� ���� ������ INT_MAX �� ��ŭ
													  // (�����) \n�� ������ ���� ���۸� ����
							gotoxy(17, 14);
							cout << "��� ��Ŀ�� ��ġ�� �������ּ���(���ʿ��� ���°) : ";	cin >> joker_point[0]; // ���Է�
						}
						if (joker_point[0] == pPlayer[player_number].get_tilenum()) // ���� ��ġ�� Ż��
						{
							joker_point[0]--; // �ε����� ����
							joker_point[1] = player_number; // ��� ��Ŀ�� ���� �÷��̾ ������ ���
							break;
						}
						else if (joker_point[0] > 0 && joker_point[0] < pPlayer[player_number].get_tilenum() + 1) // ����� �� �Է��Ͻ�
						{
							joker_point[0]--; // �ε��������� ����
							pPlayer[player_number].tile_fit(joker_point[0]);
							joker_point[1] = player_number; // ��� ��Ŀ�� ���� �÷��̾ ������ ���
							break;
						}
						else
						{
							gotoxy(17, 16);
							cout << "�߸��� ��ġ�Դϴ�.";
							gotoxy(17, 17);
							cout << "�ٽ� �Է����ּ���.";
						}
							

					}
				}
				else // ��Ŀ�� �ƴ� ��
				{
					pPlayer[player_number].tile_sort(); // ������, �߰��� ��Ŀ�� �� �ڷ�
					pPlayer[player_number].tile_fit();
				}
			}
			else if (color) // ������
			{
				pPlayer[player_number].new_blacktile(total_BTile, 1); // �� �� �̱�

				if (!player_number) pF->Player1(pPlayer[player_number], 1);
				else if (player_number == 1) pF->Player2(pPlayer[player_number], 1);
				else if (player_number == 2) pF->Player3(pPlayer[player_number], 1);
				else if (player_number == 3) pF->Player4(pPlayer[player_number], 1);

				if (pPlayer[player_number].jocker_check() == 0) // ������ ��Ŀ ��������
				{
					while (1)
					{
						gotoxy(17, 14);
						cout << "������ ��Ŀ�� ��ġ�� �������ּ���(���ʿ��� ���°) : ";	cin >> joker_point[2];
						while (cin.fail()) {   // ���࿡ error �� �߻��ϸ� 
							gotoxy(17, 15);
							cout << "���ڸ� �Է����ּ���";
							cin.clear();     //  error flag ���� Ŭ���� ��Ŵ 
							cin.ignore(INT_MAX, '\n');  // ���� ���� ������ INT_MAX �� ��ŭ
													  // (�����) \n�� ������ ���� ���۸� ����
							gotoxy(17, 14);
							cout << "������ ��Ŀ�� ��ġ�� �������ּ���(���ʿ��� ���°) : ";	cin >> joker_point[2]; // ���Է�
						}
						if (joker_point[2] == pPlayer[player_number].get_tilenum()) // ���� ��ġ�� Ż��
						{
							joker_point[2]--; // �ε����� ����
							joker_point[3] = player_number; // ������ ��Ŀ�� ���� �÷��̾ ������ ���
							break;
						}
						else if (joker_point[2] > 0 && joker_point[2] < pPlayer[player_number].get_tilenum() + 1) // ����� �� �Է��Ͻ�
						{
							joker_point[2]--; // �ε��������� ����
							pPlayer[player_number].tile_fit(joker_point[2]);
							joker_point[3] = player_number; // ������ ��Ŀ�� ���� �÷��̾ ������ ���
							break;
						}
						else
						{
							gotoxy(17, 16);
							cout << "�߸��� ��ġ�Դϴ�.";
							gotoxy(17, 17);
							cout << "�ٽ� �Է����ּ���.";
						}

					}
				}
				else // ��Ŀ�� �ƴ� ��
				{
					pPlayer[player_number].tile_sort(); // ������, �߰��� ��Ŀ�� �� �ڷ�
					pPlayer[player_number].tile_fit();
				}
			}
			if (!player_number) pF->Player1(pPlayer[player_number], 1);
			else if (player_number == 1) pF->Player2(pPlayer[player_number], 1);
			else if (player_number == 2) pF->Player3(pPlayer[player_number], 1);
			else if (player_number == 3) pF->Player4(pPlayer[player_number], 1);

			check = pPlayer[player_number].getcheck();

			if (player_number == joker_point[1] && pPlayer[player_number].getrand_num() != 12) // ��� ��Ŀ�� ���� �÷��̾��̰� ���� �а� ��Ŀ�� �ƴҶ�
			{
				if (check == joker_point[0]) // ��Ŀ�� ���� ���� ��ġ�ε����� ��ġ
				{
					Game_Record_Window_reset();

					gotoxy(17, 14);
					cout << "������ �п� ��� ��Ŀ�� ��ġ�� ��ġ�մϴ�.";
					gotoxy(17, 15);
					cout << "��Ŀ�� ��ġ�� ��������ּ���.";
					while (1)
					{
						gotoxy(17, 16);
						cout << "���� ������ ��("<< pPlayer[player_number].getrand_num() <<")�� ����(0) �Ǵ� ������(1) : ";	cin >> enter; // ���� ��Ȱ��
						while (cin.fail()) {   // ���࿡ error �� �߻��ϸ� 
							gotoxy(17, 17);
							cout << "���ڸ� �Է����ּ���";
							cin.clear();     //  error flag ���� Ŭ���� ��Ŵ 
							cin.ignore(INT_MAX, '\n');  // ���� ���� ������ INT_MAX �� ��ŭ
													  // (�����) \n�� ������ ���� ���۸� ����
							gotoxy(17, 16);
							cout << "���� ������ ��(" << pPlayer[player_number].getrand_num() << ")�� ����(0) �Ǵ� ������(1) : ";	cin >> enter; // ���Է�
						}
						if (enter == 0 || enter == 1) break;
						else
						{
							gotoxy(17, 18);
							cout << enter << " �Է��ϼ̽��ϴ�.";
							gotoxy(17, 19);
							cout << "�ٽ� �Է����ּ���";
						}
					}
					
					if (enter == 1)joker_point[0]++; // �������̸� �ε��� ����			
					else // ������ ���
					{
						check++;
						pPlayer[player_number].setcheck(check);
						pPlayer[player_number].leftshift_joker(joker_point[0]);
					}
				}
				else if (joker_point[0] > check) // ��� ��Ŀ�� ���� ���� ������ ��
				{
					joker_point[0]++; // �ε��� ����
				}
				pPlayer[player_number].jocker_fit(joker_point[0]); // ��Ŀ ����ġ
			}
			else if (player_number == joker_point[3] && pPlayer[player_number].getrand_num() != 12) // ������ ��Ŀ�� ���� �÷��̾��̰� ���� �а� ��Ŀ�� �ƴҶ�
			{
				if (check == joker_point[2]) // ��Ŀ�� ���� ���� ��ġ�ε����� ��ġ
				{
					if (!player_number) pF->Player1(pPlayer[player_number], 1);
					else if (player_number == 1) pF->Player2(pPlayer[player_number], 1);
					else if (player_number == 2) pF->Player3(pPlayer[player_number], 1);
					else if (player_number == 3) pF->Player4(pPlayer[player_number], 1);

					Game_Record_Window_reset();

					gotoxy(17, 14);
					cout << "������ �п� ������ ��Ŀ�� ��ġ�� ��ġ�մϴ�.";
					gotoxy(17, 15);
					cout << "��Ŀ�� ��ġ�� ��������ּ���.";
					while (1)
					{
						gotoxy(17, 16);
						cout << "���� ������ ��(" << pPlayer[player_number].getrand_num() << ")�� ����(0) �Ǵ� ������(1) : ";	cin >> enter; // ���� ��Ȱ��
						while (cin.fail()) {   // ���࿡ error �� �߻��ϸ� 
							gotoxy(17, 17);
							cout << "���ڸ� �Է����ּ���";
							cin.clear();     //  error flag ���� Ŭ���� ��Ŵ 
							cin.ignore(INT_MAX, '\n');  // ���� ���� ������ INT_MAX �� ��ŭ
													  // (�����) \n�� ������ ���� ���۸� ����
							gotoxy(17, 16);
							cout << "���� ������ ��(" << pPlayer[player_number].getrand_num() << ")�� ����(0) �Ǵ� ������(1) : ";	cin >> enter; // ���Է�
						}
						if (enter == 0 || enter == 1) break;
						else
						{
							gotoxy(17, 18);
							cout << enter << " �Է��ϼ̽��ϴ�.";
							gotoxy(17, 19);
							cout << "�ٽ� �Է����ּ���";
						}
					}
					
					if (enter == 1) joker_point[2]++; // �������̸� �ε��� ����
					else // ������ ���
					{
						check++;
						pPlayer[player_number].setcheck(check);
						pPlayer[player_number].leftshift_joker(joker_point[2]);
					}
				}
				else if (joker_point[2] > check) // ��� ��Ŀ�� ���� ���� ������ ��
				{
					joker_point[2]++; // �ε��� ����
				}
				pPlayer[player_number].jocker_fit(joker_point[2]); // ��Ŀ ����ġ
			}
		}

		Game_Record_Window_reset();

		if (!player_number) pF->Player1(pPlayer[player_number], 1);
		else if (player_number == 1) pF->Player2(pPlayer[player_number], 1);
		else if (player_number == 2) pF->Player3(pPlayer[player_number], 1);
		else if (player_number == 3) pF->Player4(pPlayer[player_number], 1);

		next = 1;
		while (next) // ���߸� �ѹ� �� ���� ��ȸ����
		{
			Game_Record_Window_reset();
			if (number != 2) // ������ ���� 3���̻�
			{
				while (1)
				{
					gotoxy(17, 14);
					cout << "� �÷��̾��� �и� ���߽ðڽ��ϱ�?(����) : ";	cin >> enter; // ���� ��Ȱ��
					while (cin.fail()) {   // ���࿡ error �� �߻��ϸ� 
						gotoxy(17, 15);
						cout << "���ڸ� �Է����ּ���";
						cin.clear();     //  error flag ���� Ŭ���� ��Ŵ 
						cin.ignore(INT_MAX, '\n');  // ���� ���� ������ INT_MAX �� ��ŭ
												  // (�����) \n�� ������ ���� ���۸� ����
						gotoxy(17, 14);
						cout << "� �÷��̾��� �и� ���߽ðڽ��ϱ�?(����) : ";	cin >> enter; // ���Է�
					}
					enter--; // �ε����� ����
					if (enter == player_number)
					{
						Game_Record_Window_reset();
						gotoxy(17, 15);
						cout << "�ڱ� �ڽ��� ������ �� �����ϴ�.";
						gotoxy(17, 16);
						cout << "�ٽ� �Է����ּ���.";
					}
					else if (enter < 0 || enter >= number)
					{
						Game_Record_Window_reset();
						gotoxy(17, 15);
						cout << enter + 1 << " �Է��ϼ̽��ϴ�.";
						gotoxy(17, 16);
						cout << "�ٽ� �Է����ּ���.";
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
					cout << enter + 1 << "P�� ���° Ÿ���� ���߽ðڽ��ϱ�? : ";	cin >> choice_se;
					while (cin.fail()) {   // ���࿡ error �� �߻��ϸ� 
						gotoxy(17, 15);
						cout << "���ڸ� �Է����ּ���";
						cin.clear();     //  error flag ���� Ŭ���� ��Ŵ 
						cin.ignore(INT_MAX, '\n');  // ���� ���� ������ INT_MAX �� ��ŭ
												  // (�����) \n�� ������ ���� ���۸� ����
						gotoxy(17, 14);
						cout << enter + 1 << "P�� ���° Ÿ���� ���߽ðڽ��ϱ�? : ";	cin >> choice_se; // ���Է�
					}
					if (choice_se < 1 || choice_se > pPlayer[enter].get_tilenum()) throw choice_se; // ������ ��� ���̸�
					if (!pPlayer[enter].view_check(choice_se))
					{
						gotoxy(17, 15);
						cout << "�̹� ������ ���Դϴ�." << endl;
						throw choice_se;
					}
					gotoxy(17, 16);
					cout << "�����ϴ� ���� �Է����ּ���. (��Ŀ�� 12) : ";	cin >> choice_num;
					while (cin.fail()) {   // ���࿡ error �� �߻��ϸ� 
						gotoxy(17, 17);
						cout << "���ڸ� �Է����ּ���";
						cin.clear();     //  error flag ���� Ŭ���� ��Ŵ 
						cin.ignore(INT_MAX, '\n');  // ���� ���� ������ INT_MAX �� ��ŭ
												  // (�����) \n�� ������ ���� ���۸� ����
						gotoxy(17, 16);
						cout << "�����ϴ� ���� �Է����ּ���. (��Ŀ�� 12) : ";	cin >> choice_num; // ���Է�
					}
					if (choice_num < 0 || choice_num > 12) throw choice_num; // ������ ��� �����
					break;
				}
				catch (int c)
				{
					Game_Record_Window_reset();
					gotoxy(17, 18);
					cout << c << " �Է��ϼ̽��ϴ�.";
					gotoxy(17, 19);
					cout << "�ٽ� �Է����ּ���.";
				}
			}
			next = pPlayer[player_number].predict_tile(pPlayer[enter], choice_se, choice_num, check, score, result); // �������

			if (!enter) pF->Player1(pPlayer[enter], 0);
			else if (enter == 1) pF->Player2(pPlayer[enter], 0);
			else if (enter == 2) pF->Player3(pPlayer[enter], 0);
			else if (enter == 3) pF->Player4(pPlayer[enter], 0);
			
			gotoxy(17, 22+player_number); // ����� �뵵
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
		player_number++; //���� �÷��̾� ����
		if (player_number == number) player_number = 0;
	}

	Game_Record_Window_reset();
	string* pranking;
	pranking = new string[number];
	int rank;

	gotoxy(17, 14);
	cout << "��� ������ �����Ǿ����ϴ�.(Enter)";	enter = _getch();
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
		cout << i + 1 << "�� " << pranking[i];
		gotoxy(25, 16 + 3 * (i + 1));
	}

	gotoxy(24, 31);
	cout << "Enter�� ������ �����մϴ�.";	enter = _getch();

	gotoxy(60, 39);

	delete[]pPlayer;
	delete pF;
	delete[]pranking;


	return 0;
}