#include "algorithm.h"
#include "iostream"
#include <vector>
using namespace std;

void getAvailableAction(const MatchState& currentState, vector<Action>& actions)
{
	int i = 0, j = 0;
	for (i = 0; i < 15; i++)
	for (j = 0; j < 15; j++)
	{
		//���������Բ�������һ����ֶ�ȥ����ĺ�Զ�ĵط���һ��
		if (i >= 1 && j >= 1 && i <= 13 && j <= 13)
		{
			if (currentState.state[i][j] == 0)
			{
				if (currentState.state[i + 1][j] != 0 || currentState.state[i - 1][j] != 0 ||
					currentState.state[i][j + 1] != 0 || currentState.state[i][j - 1] != 0 ||
					currentState.state[i + 1][j + 1] != 0 || currentState.state[i - 1][j + 1] != 0 ||
					currentState.state[i + 1][j - 1] != 0 || currentState.state[i - 1][j - 1] != 0)
				{
					Action* temp = new Action;
					temp->row = i;
					temp->col = j;
					actions.push_back(*temp);
				}
			}
		}
		//֮��ҲҪ����һ���ڱ߽�ĵط����ӵĿ�����
		if (i == 0 && j != 0 && j != 14)
		{
			if (currentState.state[i][j] == 0)
			{
				if (currentState.state[i + 1][j] != 0 ||currentState.state[i][j + 1] != 0 || 
					currentState.state[i][j - 1] != 0 ||
					currentState.state[i + 1][j + 1] != 0 ||currentState.state[i + 1][j - 1] != 0)
				{
					Action* temp = new Action;
					temp->row = i;
					temp->col = j;
					actions.push_back(*temp);
				}
			}
		}
		else if (i == 0 && j == 0)
		{
			if (currentState.state[i][j] == 0)
			{
				if (currentState.state[i + 1][j] != 0 || currentState.state[i][j + 1] != 0 ||
					currentState.state[i + 1][j + 1] != 0)
				{
					Action* temp = new Action;
					temp->row = i;
					temp->col = j;
					actions.push_back(*temp);
				}
			}
		}
		else if (i == 0 && j == 14)
		{
			if (currentState.state[i][j] == 0)
			{
				if (currentState.state[i + 1][j] != 0 || currentState.state[i][j - 1] != 0 || 
					currentState.state[i + 1][j - 1] != 0)
				{
					Action* temp = new Action;
					temp->row = i;
					temp->col = j;
					actions.push_back(*temp);
				}
			}
		}

		if (i == 14 && j != 0 && j != 14)
		{
			if (currentState.state[i][j] == 0)
			{
				if (currentState.state[i - 1][j] != 0 || currentState.state[i][j + 1] != 0 || 
					currentState.state[i][j - 1] != 0 ||
					currentState.state[i - 1][j + 1] != 0 || currentState.state[i - 1][j - 1] != 0)
				{
					Action* temp = new Action;
					temp->row = i;
					temp->col = j;
					actions.push_back(*temp);
				}
			}
		}
		else if (i == 14 && j == 0)
		{
			if (currentState.state[i][j] == 0)
			{
				if (currentState.state[i - 1][j] != 0 || currentState.state[i][j + 1] != 0 || 
					currentState.state[i - 1][j + 1] != 0)
				{
					Action* temp = new Action;
					temp->row = i;
					temp->col = j;
					actions.push_back(*temp);
				}
			}
		}
		else if (i == 14 && j == 14)
		{
			if (currentState.state[i][j] == 0)
			{
				if (currentState.state[i - 1][j] != 0 || currentState.state[i][j - 1] != 0 || 
					currentState.state[i - 1][j - 1] != 0)
				{
					Action* temp = new Action;
					temp->row = i;
					temp->col = j;
					actions.push_back(*temp);
				}
			}
		}

		if (j == 0  && i != 0 && i != 14)
		{
			if (currentState.state[i][j] == 0)
			{
				if (currentState.state[i - 1][j] != 0 || currentState.state[i + 1][j] != 0 || 
					currentState.state[i][j + 1] != 0 ||
					currentState.state[i - 1][j + 1] != 0 || currentState.state[i + 1][j + 1] != 0)
				{
					Action* temp = new Action;
					temp->row = i;
					temp->col = j;
					actions.push_back(*temp);
				}
			}
		}
		if (j == 14 && i != 0 && i != 14)
		{
			if (currentState.state[i][j] == 0)
			{
				if (currentState.state[i - 1][j] != 0 || currentState.state[i + 1][j] != 0 || 
					currentState.state[i][j - 1] != 0 ||
					currentState.state[i - 1][j - 1] != 0 || currentState.state[i + 1][j - 1] != 0)
				{
					Action* temp = new Action;
					temp->row = i;
					temp->col = j;
					actions.push_back(*temp);
				}
			}
		}

	}
}

MatchState* actionResult(const MatchState& currentState, Action action, const int player)
{
	MatchState* result = new MatchState;
	int i = 0;
	int j = 0;
	for (i = 0; i < 15; i++)
	for (j = 0; j < 15; j++)
	{
		result->state[i][j] = currentState.state[i][j];
	}
	int row = action.row;
	int col = action.col;
	result->state[row][col] = player;
	return result;
}

int Max_Value(MatchState& current_state, int depth, int alpha, int beta);
int Min_Value(MatchState& current_state, int depth, int alpha, int beta);

int Terminal_test(MatchState& current_state)
{
	//���������Ǽ��践��1�Ļ��Ǽ����Ӯ������-1�����Ӯ��
	//����2��ƽ�֣�����0��������Ϸ
	int i = 0;
	int j = 0;
	int num = 0;
	for (i = 0; i < 15; i++)
	for (j = 0; j < 15; j++)
	{
		if (current_state.state[i][j] == 0)
			num++;
		//ˮƽ������
		int cnt = 1;
		for (int k = j - 1; k >= 0; k--)
		{
			if (current_state.state[i][k] != current_state.state[i][j])
				break;
			else
				cnt++;
		}
		for (int k = j + 1; k < 15; k++)
		{
			if (current_state.state[i][k] != current_state.state[i][j])
				break;
			else
				cnt++;
		}
		if (cnt >= 5)
			return current_state.state[i][j];

		//��ֱ������
		cnt = 1;
		for (int k = i - 1; k >= 0; k--)
		{
			if (current_state.state[k][j] != current_state.state[i][j])
				break;
			else
				cnt++;
		}
		for (int k = i + 1; k <= 15; k++)
		{
			if (current_state.state[k][j] != current_state.state[i][j])
				break;
			else
				cnt++;
		}
		if (cnt >= 5)
			return current_state.state[i][j];

		//�Խ��߷�����
		cnt = 1;
		int m = i + 1;
		for (int k = j - 1; k >= 0; k--)
		{
			if (m >= 15)
				break;
			if (current_state.state[m][k] != current_state.state[i][j])
				break;
			else
				cnt++;
			m++;
		}
		m = i - 1;
		for (int k = j + 1; k < 15; k++)
		{
			if (m < 0)
				break;
			if (current_state.state[m][k] != current_state.state[i][j])
				break;
			else
				cnt++;
			m--;
		}
		if (cnt >= 5)
			return current_state.state[i][j];

		cnt = 1;
		m = i - 1;
		for (int k = j - 1; k >= 0; k--)
		{
			if (m < 0)
				break;
			if (current_state.state[m][k] != current_state.state[i][j])
				break;
			else
				cnt++;
			m--;
		}
		m = i + 1;
		for (int k = j + 1; k < 15; k++)
		{
			if (m >= 15)
				break;
			if (current_state.state[m][k] != current_state.state[i][j])
				break;
			else
				cnt++;
			m++;
		}
		if (cnt >= 5)
			return current_state.state[i][j];

	}
	if (num == 0)
		return 2;
	else
		return 0;
}

int Utility(MatchState& current_state)
{
	int i = 0;
	int j = 0;
	int utility_num = 0;
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			//ˮƽ������
			int cnt = 1;
			int zero1 = 0;
			int zero2 = 0;
			if (current_state.state[i][j] == 0)
				continue;
			for (int k = j - 1; k >= 0; k--)
			{
				if (current_state.state[i][k] != current_state.state[i][j])
				{
					if (current_state.state[i][k] == 0)
						zero1 = 1;
					break;
				}
				else
					cnt++;
			}
			for (int k = j + 1; k < 15; k++)
			{
				if (current_state.state[i][k] != current_state.state[i][j])
				{
					if (current_state.state[i][k] == 0)
						zero2 = 1;
					break;
				}
				else
					cnt++;
			}
			if (cnt == 2 && (zero1 && zero2))
				utility_num += 2 * current_state.state[i][j];
			if (cnt == 4 && (zero1 && zero2))
			{
				if (current_state.state[i][j] == 1)
					utility_num += 10;
				else
					utility_num += -10;
			}
			else if (cnt == 3 && (zero1 && zero2))
			{
				if (current_state.state[i][j] == 1)
					utility_num += 10;
				else
					utility_num += -10;
			}
			else if (cnt >= 5)
				utility_num += 5 * current_state.state[i][j];

			//��ֱ������
			cnt = 1;
			zero1 = 0;
			zero2 = 0;
			for (int k = i - 1; k >= 0; k--)
			{
				if (current_state.state[k][j] != current_state.state[i][j])
				{
					if (current_state.state[k][j] == 0)
						zero1 = 1;
					break;
				}
				else
					cnt++;
			}
			for (int k = i + 1; k <= 15; k++)
			{
				if (current_state.state[k][j] != current_state.state[i][j])
				{
					if (current_state.state[k][j] == 0)
						zero2 = 1;
					break;
				}
				else
					cnt++;
			}
			if (cnt == 2 && (zero1 && zero2))
				utility_num += 2 * current_state.state[i][j];
			if (cnt == 4 && (zero1 && zero2))
			{
				if (current_state.state[i][j] == 1)
					utility_num += 10;
				else
					utility_num += -10;
			}
			else if (cnt == 3 && (zero1 && zero2))
			{
				if (current_state.state[i][j] == 1)
					utility_num += 10;
				else
					utility_num += -10;
			}
			else if (cnt >= 5)
				utility_num += 5 * current_state.state[i][j];

			//�Խ��߷�����
			cnt = 1;
			zero1 = 0;
			zero2 = 0;
			int m = i + 1;
			for (int k = j - 1; k >= 0; k--)
			{
				if (m >= 15)
					break;
				if (current_state.state[m][k] != current_state.state[i][j])
				{
					if (current_state.state[m][k] == 0)
						zero1 = 1;
					break;
				}
				else
					cnt++;
				m++;
			}
			m = i - 1;
			for (int k = j + 1; k < 15; k++)
			{
				if (m < 0)
					break;
				if (current_state.state[m][k] != current_state.state[i][j])
				{
					if (current_state.state[m][k] == 0)
						zero2 = 1;
					break;
				}
				else
					cnt++;
				m--;
			}
			if (cnt == 2 && (zero1 && zero2))
				utility_num += 2 * current_state.state[i][j];
			if (cnt == 4 && (zero1 && zero2))
			{
				if (current_state.state[i][j] == 1)
					utility_num += 10;
				else
					utility_num += -10;
			}
			else if (cnt == 3 && (zero1 && zero2))
			{
				if (current_state.state[i][j] == 1)
					utility_num += 10;
				else
					utility_num += -10;
			}
			else if (cnt >= 5)
				utility_num += 5 * current_state.state[i][j];

			cnt = 1;
			zero1 = 0;
			zero2 = 0;
			m = i - 1;
			for (int k = j - 1; k >= 0; k--)
			{
				if (m < 0)
					break;
				if (current_state.state[m][k] != current_state.state[i][j])
				{
					if (current_state.state[m][k] == 0)
						zero1 = 1;
					break;
				}
				else
					cnt++;
				m--;
			}
			m = i + 1;
			for (int k = j + 1; k < 15; k++)
			{
				if (m >= 15)
					break;
				if (current_state.state[m][k] != current_state.state[i][j])
				{
					if (current_state.state[m][k] == 0)
						zero2 = 1;
					break;
				}
				else
					cnt++;
				m++;
			}
			if (cnt == 2 && (zero1 && zero2))
				utility_num += 2 * current_state.state[i][j];
			if (cnt == 4 && (zero1 && zero2))
			{
				if (current_state.state[i][j] == 1)
					utility_num += 10;
				else
					utility_num += -10;
			}
			else if (cnt == 3 && (zero1 && zero2))
			{
				if (current_state.state[i][j] == 1)
					utility_num += 10;
				else
					utility_num += -10;
			}
			else if (cnt >= 5)
				utility_num += 5 * current_state.state[i][j];
		}
	}
	if (utility_num != 0)
		return utility_num;
	return -1;
}

int Max_Value(MatchState& current_state, int depth, int alpha, int beta)
{   
	if (depth == 3)
		return Utility(current_state);
	depth++;
	if (Terminal_test(current_state))
		return Utility(current_state);

	int v = -1000;
	vector<Action> actions;
	getAvailableAction(current_state, actions);
	int number = actions.size();
	for (int i = 0; i < number; i++)
	{
		MatchState * a = actionResult(current_state, actions[i], 1);
		int min_value = Min_Value(*a, depth, alpha, beta);
		if (min_value > v)
			v = min_value;
		if (v >= beta)
			return v;
		if (alpha < v)
			alpha = v;
	}
	return v;
}


int Min_Value(MatchState& current_state, int depth, int alpha, int beta)
{
	if (depth == 3)
		return Utility(current_state);
	depth++;
	if (Terminal_test(current_state))
		return Utility(current_state);
	int v = 1000;

	vector<Action> actions;
	getAvailableAction(current_state, actions);
	int number = actions.size();
	for (int i = 0; i < number; i++)
	{
		MatchState * a = actionResult(current_state, actions[i], -1);
		int max_value = Max_Value(*a, depth, alpha, beta);
		if (max_value < v)
			v = max_value;
		if (v <= alpha)
			return v;
		if (beta > v)
			beta = v;
	}
	return v;
}

void miniMaxSearchForFive(const MatchState& currentState, int& r, int& c)
{
	vector<Action> actions;
	vector<double> values;
	int t = 0;
	//����Ӧ���ȼ���һ���Ƿ������Σ�յľ��أ�Ҳ����ʧ��֮�������龰
	t = guarantee(currentState, r, c);
	if (t != 0)
		return;
	getAvailableAction(currentState, actions); 
	int depth = 0;
	//��������Ҫ�������Ƽ���С���������
	//Ϊ���ܹ�����������ʱ�临�Ӷȣ����������alpha beta��֦����
	for (int i = 0; i < (int)actions.size(); ++i)
	{   
		values.push_back(Min_Value(*actionResult(currentState, actions[i], 1), depth, -10000, 10000));
	}
	int max_idx = 0;
	double max_val = values[max_idx];
	for (int i = 1; i < (int)values.size(); ++i)
	{
		if (values[i] > max_val)
		{
			max_idx = i;
			max_val = values[i];
		}
	}
	r = actions[max_idx].row;
	c = actions[max_idx].col;
}


int guarantee(const MatchState& current_state, int& r, int& c)
{
	int i = 0;
	int j = 0;
	int priority = 0;
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			//ˮƽ������
			int cnt = 1;
			int row1 = 0;
			int col1 = 0;
			int row2 = 0;
			int col2 = 0;
			int zero1 = 0;
			int zero2 = 0;
			if (current_state.state[i][j] == 0)
				continue;
			for (int k = j - 1; k >= 0; k--)
			{
				if (current_state.state[i][k] != current_state.state[i][j])
				{
					if (current_state.state[i][k] == 0)
					{
						row1 = i;
						col1 = k;
						zero1 = 1;
					}
					break;
				}
				else
					cnt++;
			}
			for (int k = j + 1; k < 15; k++)
			{
				if (current_state.state[i][k] != current_state.state[i][j])
				{
					if (current_state.state[i][k] == 0)
					{
						row2 = i;
						col2 = k;
						zero2 = 1;
					}
					break;
				}
				else
					cnt++;
			}
			//��������г��ĵ�������ô�ͱ�������
			if (cnt == 4 && (zero1 && zero2))
			{
				r = row1;
				c = col1;
				priority = 5;
			}
			//��Ȼû�г��ģ�����Ҳ���ܹ���֮������龳
			else if (cnt == 4 && (zero1 || zero2))
			{
				if (zero1 == 1)
				{
					r = row1;
					c = col1;
					priority = 5;
				}
				else
				{
					r = row2;
					c = col2;
					priority = 5;
				}
			}
			//����˫�������
			else if (cnt == 3 && (zero1 && zero2))
			{
				r = row1;
				c = col1;
				//������Լ���˫��������֣�Ӧ�����ȹ�ռ�����ȶȸ�һ��
				if (current_state.state[i][j] == 1)
					priority = 4;
				else
					priority = 3;
			}

			//��ֱ������
			cnt = 1;
			row1 = 0;
			col1 = 0;
			row2 = 0;
			col2 = 0;
			zero1 = 0;
			zero2 = 0;
			for (int k = i - 1; k >= 0; k--)
			{
				if (current_state.state[k][j] != current_state.state[i][j])
				{
					if (current_state.state[k][j] == 0)
					{
						row1 = k;
						col1 = j;
						zero1 = 1;
					}
					break;
				}
				else
					cnt++;
			}
			for (int k = i + 1; k <= 15; k++)
			{
				if (current_state.state[k][j] != current_state.state[i][j])
				{
					if (current_state.state[k][j] == 0)
					{
						row2 = k;
						col2 = j;
						zero2 = 1;
					}
					break;
				}
				else
					cnt++;
			}
			if (cnt == 4 && (zero1 && zero2))
			{
				if (priority < 5)
				{
					r = row1;
					c = col1;
					priority = 5;
				}
			}
			else if (cnt == 4 && (zero1 || zero2))
			{
				if (priority < 5)
				{
					if (zero1 == 1)
					{
						r = row1;
						c = col1;
						priority = 5;
					}
					else
					{
						r = row2;
						c = col2;
						priority = 5;
					}
				}
			}
			else if (cnt == 3 && (zero1 && zero2))
			{
				if (current_state.state[i][j] == 1)
				{
					r = row1;
					c = col1;
					priority = 4;
				}
				else if (priority <= 3)
				{
					r = row1;
					c = col1;
					priority = 3;
				}
			}

			//�Խ��߷�����
			cnt = 1;
			row1 = 0;
			col1 = 0;
			row2 = 0;
			col2 = 0;
			zero1 = 0;
			zero2 = 0;
			int m = i + 1;
			for (int k = j - 1; k >= 0; k--)
			{
				if (m >= 15)
					break;
				if (current_state.state[m][k] != current_state.state[i][j])
				{
					if (current_state.state[m][k] == 0)
					{
						row1 = m;
						col1 = k;
						zero1 = 1;
					}
					break;
				}
				else
					cnt++;
				m++;
			}
			m = i - 1;
			for (int k = j + 1; k < 15; k++)
			{
				if (m < 0)
					break;
				if (current_state.state[m][k] != current_state.state[i][j])
				{
					if (current_state.state[m][k] == 0)
					{
						row2 = m;
						col2 = k;
						zero2 = 1;
					}
					break;
				}
				else
					cnt++;
				m--;
			}
			if (cnt == 4 && (zero1 && zero2))
			{
				if (priority < 5)
				{
					r = row1;
					c = col1;
					priority = 5;
				}
			}
			else if (cnt == 4 && (zero1 || zero2))
			{
				if (priority < 5)
				{
					if (zero1 == 1)
					{
						r = row1;
						c = col1;
						priority = 5;
					}
					else
					{
						r = row2;
						c = col2;
						priority = 5;
					}
				}
			}
			else if (cnt == 3 && (zero1 && zero2))
			{
				if (current_state.state[i][j] == 1)
				{
					r = row1;
					c = col1;
					priority = 4;
				}
				else if (priority <= 3)
				{
					r = row1;
					c = col1;
					priority = 3;
				}
			}

			cnt = 1;
			row1 = 0;
			col1 = 0;
			row2 = 0;
			col2 = 0;
			zero1 = 0;
			zero2 = 0;
			m = i - 1;
			for (int k = j - 1; k >= 0; k--)
			{
				if (m < 0)
					break;
				if (current_state.state[m][k] != current_state.state[i][j])
				{
					if (current_state.state[m][k] == 0)
					{
						row1 = m;
						col1 = k;
						zero1 = 1;
					}
					break;
				}
				else
					cnt++;
				m--;
			}
			m = i + 1;
			for (int k = j + 1; k < 15; k++)
			{
				if (m >= 15)
					break;
				if (current_state.state[m][k] != current_state.state[i][j])
				{
					if (current_state.state[m][k] == 0)
					{
						row2 = m;
						col2 = k;
						zero2 = 1;
					}
					break;
				}
				else
					cnt++;
				m++;
			}
			if (cnt == 4 && (zero1 && zero2))
			{
				if (priority < 5)
				{
					r = row1;
					c = col1;
					priority = 5;
				}
			}
			else if (cnt == 4 && (zero1 || zero2))
			{
				if (priority < 5)
				{
					if (zero1 == 1)
					{
						r = row1;
						c = col1;
						priority = 5;
					}
					else
					{
						r = row2;
						c = col2;
						priority = 5;
					}
				}
			}
			else if (cnt == 3 && (zero1 && zero2))
			{
				if (current_state.state[i][j] == 1)
				{
					r = row1;
					c = col1;
					priority = 4;
				}
				else if (priority <= 3)
				{
					r = row1;
					c = col1;
					priority = 3;
				}
			}
		}
	}
	if (priority != 0)
		return priority;
	return 0;
}

GameJudge::GameJudge()
{
	this->gameState = MatchState();
}

void GameJudge::makeAMove(const int& r, const int& c, const int player)
{
	//player = 1 for computer, play = -1 for human
	//1 stands for circle, -1 stands for cross, 0 stands for empty space
	// computer uses circle, human uses cross
	this->gameState.state[r][c] = player;
}

int GameJudge::checkGameStatus()
{
	int i = 0;
	int j = 0;
	int num = 0;
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			if (this->gameState.state[i][j] == 0)
			{
				num++;
				continue;
			}
			//ˮƽ������
			int cnt = 1;
			for (int k = j - 1; k >= 0; k--)
			{
				if (this->gameState.state[i][k] != this->gameState.state[i][j])
					break;
				else
					cnt++;
			}
			for (int k = j + 1; k < 15; k++)
			{
				if (this->gameState.state[i][k] != this->gameState.state[i][j])
					break;
				else
					cnt++;
			}
			if (cnt >= 5)
				return this->gameState.state[i][j];
			//��ֱ������
			cnt = 1;
			for (int k = i - 1; k >= 0; k--)
			{
				if (this->gameState.state[k][j] != this->gameState.state[i][j])
					break;
				else
					cnt++;
			}
			for (int k = i + 1; k <= 15; k++)
			{
				if (this->gameState.state[k][j] != this->gameState.state[i][j])
					break;
				else
					cnt++;
			}
			if (cnt >= 5)
				return this->gameState.state[i][j];
			//�Խ��߷�����
			cnt = 1;
			int m = i + 1;
			for (int k = j - 1; k >= 0; k--)
			{
				if (m >= 15)
					break;
				if (this->gameState.state[m][k] != this->gameState.state[i][j])
					break;
				else
					cnt++;
				m++;
			}
			m = i - 1;
			for (int k = i + 1; k < 15; k++)
			{
				if (m < 0)
					break;
				if (this->gameState.state[m][k] != this->gameState.state[i][j])
					break;
				else
					cnt++;
				m--;
			}
			if (cnt >= 5)
				return this->gameState.state[i][j];
			cnt = 1;
			m = i - 1;
			for (int k = j - 1; k >= 0; k--)
			{
				if (m < 0)
					break;
				if (this->gameState.state[m][k] != this->gameState.state[i][j])
					break;
				else
					cnt++;
				m--;
			}
			m = i + 1;
			for (int k = i + 1; k < 15; k++)
			{
				if (m >= 15)
					break;
				if (this->gameState.state[m][k] != this->gameState.state[i][j])
					break;
				else
					cnt++;
				m++;
			}
			if (cnt >= 5)
				return this->gameState.state[i][j];
		}
	}
	if (num == 0)
		return 0;
	else
		return 2;
}

void GameJudge::humanInput(int& r, int& c)
{
	cout << "Input the row and column index of your move " << endl;
	cout << "1,0 means draw a cross on the row 1, col 0" << endl;
	string str;
	bool succ = false;
	while (!succ)
	{
		cin >> str;
		sscanf(str.c_str(), "%d,%d", &r, &c);
		if (r < 0 || r > 14 || c < 0 || c > 14)
		{
			succ = false;
			cout << " Invalidate input, the two numbers should >> 0 and << 2" << endl;
		}
		else if (this->gameState.state[r][c] != 0)
		{
			succ = false;
			cout << " You can not put cross on this place " << endl;
		}
		else
		{
			succ = true;
		}
	}
}

void GameJudge::printStatus(const int player, const int status)
{
	cout << "------------------------------" << endl;
	for (int r = 0; r < 15; r++)
	{
		for (int c = 0; c < 15; c++)
		{
			if (this->gameState.state[r][c] == 1)
			{
				cout << "[O]";
			}
			if (this->gameState.state[r][c] == -1)
			{
				cout << "[X]";
			}
			else if (this->gameState.state[r][c] == 0)
			{
				cout << "[ ]";
			}

		}
		cout << endl;
	}
	if (player == 1)
	{
		cout << "Last move was conducted by computer " << endl;
	}
	else if (player == -1)
	{
		cout << "Last move was conducted by you " << endl;
	}
	if (status == 1)
	{
		cout << "Computer wins " << endl;
	}
	else if (status == -1)
	{
		cout << " You win " << endl;
	}
	else if (status == 2)
	{
		cout << " Game going on " << endl;
	}
	else if (status == 0)
	{
		cout << " Draw " << endl;
	}
}

MatchState GameJudge::getGameStatus()
{
	return this->gameState;
}