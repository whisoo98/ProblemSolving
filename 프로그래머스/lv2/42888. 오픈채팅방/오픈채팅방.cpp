#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <queue>
using namespace std;

vector<string> solution(vector<string> record) {
	map<string, string> matching;
	queue<pair<string,string>> log;
	for (auto iter : record) {
		stringstream ss;
		ss << iter;
		string cmd, uid, nickname;
		ss >> cmd;
		ss >> uid;
		log.push({ uid, cmd });
		if (cmd == "Leave") {
			continue;
		}
		ss >> nickname;
		matching[uid] = nickname;
	}
	vector<string> answer;
	while (log.size()) {
		string nickname = matching[log.front().first];
		string cmd = log.front().second;
		log.pop();
		if (cmd == "Enter") {
			string ans = nickname + "님이 들어왔습니다.";
			answer.push_back(ans);
		}
		else if (cmd == "Leave") {
			string ans = nickname + "님이 나갔습니다.";
			answer.push_back(ans);
		}

	}
	return answer;
}