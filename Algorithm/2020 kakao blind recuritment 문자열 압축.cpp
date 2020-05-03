#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
	int answer = 1e9;

	for (int len = s.size() / 2; len > 0; --len) {
		
		int ans = 0;
		int start = 0;
		int cnt = 1;

		while(start + len < s.size()){

			string prev = s.substr(start, len);
			string post = s.substr(start + len, len);

			if (prev == post) {
				cnt++;
				if (s.size() <= start + len + len) 
					ans += to_string(cnt).length() + prev.length();
					
			}
			else {
				// has same group
				if (cnt > 1)
					ans += to_string(cnt).length();

				ans += prev.length();

				cnt = 1;

				// last
				if (s.size() <= start + len + len)
					ans += s.size() - start - len;
			}

			start += len;
		}
		//cout << ans << "\n";

		answer = ans < answer ? ans : answer;
	}
	return answer;
}

int main() {
	string s[10];
	s[0] = "aabbaccc";	//7
	s[1] = "ababcdcdababcdcd";	//9
	s[2] = "abcabcdede";	//8
	s[3] = "abcabcabcabcdededededede";	//14
	s[4] = "xababcdcdababcdcd"; // 17

	for (int i = 0; i < 5; ++i)
		cout << solution(s[i]) << '\n';

	return 0;
}

/*
#include <string>

using namespace std;

int solution(string s) {
	int answer = s.length();
	//����� �� Ž���ϱ�
	for (int i = 1; i <= s.length() / 2; i++) {
		int len = s.length();
		//���ڿ��� ��ü ���鼭 �ݺ�
		for (int j = 0; j < s.length(); j++) {
			//�κ� ���ϱ�
			for (int count = 0, z = i; j + z < s.length(); z += i){
				//�ںκа� ��ġ�Ѵٸ� count ����
				if (s.substr(j, i) == s.substr(j + z, i))    count++;
				//�ڿ��κ��� ��ġ�����ʴ´ٸ� countȮ���� �ߺ��Ǵ� ���ڿ���ŭ ��������
				//�߰��Ǵ� ���ڸ�ŭ ��������
				else {
					len -= i * count;
					if (count)     len += to_string(count + 1).length();
					j += z - 1;
					break;
				}
				// �ѹ��̶� ������ �Ȼ��¿��� �ڿ��� ����� �ȵȴٸ�
				//������ �߰��ϰ� �������� �ڿ� �߰�
				if (j + z + i >= s.length()) {
					len -= i * count;
					len += to_string(count + 1).length();
					j += z;
				}
			}
		}
		//���ڿ� ���̸� ���ؼ� �������ٸ� �����ɷ� ����
		if (len < answer)    answer = len;
	}
	return answer;
}
*/