// BOJ 1713

#include<iostream>
#include<list>
using namespace std;
struct recStudent {
	int studentNum;
	int order;
	int vote;
};
bool compStuNum(const recStudent& s1, const recStudent& s2) {
	return s1.studentNum < s2.studentNum;
}
bool compSeq(const recStudent& s1, const recStudent& s2) {
	return s1.order > s2.order;
}
bool comVote(const recStudent& s1, const recStudent& s2) {
	return s1.vote > s2.vote;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int rec;
	int order = 0;
	list<recStudent> frame;
	list<recStudent>::iterator iter;
	cin >> n;
	cin >> rec;
	int recStu;
	bool flag;
	for (int i = 0; i < rec; ++i) {
		flag = false;
		cin >> recStu;
		for (iter = frame.begin(); iter != frame.end(); ++iter) {
			if ((*iter).studentNum == recStu) {
				++(*iter).vote;
				flag = true;
				break;
			}
		}
		if (!flag) {
			if (frame.size() >= n) {
				frame.sort(compSeq);
				frame.sort(comVote);
				frame.pop_back();
			}
			recStudent temp;
			temp.studentNum = recStu;
			temp.vote = 1;
			temp.order = order;
			++order;
			frame.push_back(temp);
		}
	}
	frame.sort(compStuNum);
	for (iter = frame.begin(); iter != frame.end(); ++iter) {
		cout << (*iter).studentNum << " ";
	}
	return 0;
}
