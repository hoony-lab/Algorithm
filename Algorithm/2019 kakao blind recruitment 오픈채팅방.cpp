#include <iostream> 
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
vector<string> solution(vector<string> record) {
	map<string, string> nickname;  /* �г��� */
	vector<string> result_id;      /* �̺�Ʈ�� �߻���Ų id */
	vector<bool> result_in;        /* Enter ���� */
	vector<string> answer;         /* ��� */

	for (auto r : record) {
		/* string�� space bar �������� ����� */
		istringstream iss(r);
		vector<string> cmds{ istream_iterator<string>{iss},
			istream_iterator<string>{} };
		
		/* � �������? */
		string cmd = cmds[0];
		if (cmd.compare("Enter") == 0) {
			result_id.push_back(cmds[1]);      /* �̺�Ʈ�� �߻���Ų ����� id */
			result_in.push_back(true);
			nickname[cmds[1]] = cmds[2];
		}
		else if (cmd.compare("Change") == 0) {
			nickname[cmds[1]] = cmds[2];
		}
		else {
			result_id.push_back(cmds[1]);
			result_in.push_back(false);
		}
	}

	for (int i = 0; i < result_id.size(); i++) {
		string res = nickname[result_id[i]] + "����";
		if (result_in[i])
			res += " �����̽��ϴ�.";
		else
			res += " �������ϴ�.";

		answer.push_back(res);
	}
	return answer;
}

int main() {
	vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo",
		"Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" };

	
	vector<string> ans = solution(record);       // ��, ��, ��, ��
	for (auto v : ans)
		cout << v << "\n";

	return 0;
}

/*

def solution(record):
	idDict = dict()
	answer = []
	logList = []

	for e in record:
		dataList = e.split(" ")

		if dataList[0] == "Leave":
			logList.append([dataList[1], "���� �������ϴ�."])
		elif dataList[0] == "Enter":
			idDict[dataList[1]] = dataList[2]
			logList.append([dataList[1], "���� ���Խ��ϴ�."])
		elif dataList[0] == "Change":
		idDict[dataList[1]] = dataList[2]
			print(logList)
	for log in logList:
		answer.append(idDict[log[0]] + log[1])

	return answer
*/