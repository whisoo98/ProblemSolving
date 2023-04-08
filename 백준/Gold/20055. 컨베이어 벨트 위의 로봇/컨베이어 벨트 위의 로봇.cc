#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int durability[201];
int visited[201];
queue<int> robots;
int head, tail;

void move_belt(int N) {

	head = head - 1;
	if (head == 0) {
		head = 2 * N;
	}

	tail = tail - 1;
	if (tail == 0) {
		tail = 2 * N;
	}
}

int move_robots(int N) {
	int robots_size = robots.size();

	int cur_pos, next_pos, num_zero = 0;

	for (int i = 0; i < robots_size; i++) {
		cur_pos = robots.front();
		robots.pop();

		next_pos = cur_pos + 1;

		if (next_pos == 2 * N + 1) {
			next_pos = 1;
		}

		if (!visited[next_pos] && durability[next_pos] != 0) {

			if (next_pos == tail) {
				visited[cur_pos] = false;
				durability[next_pos]--;

				if (durability[next_pos] == 0) {
					num_zero++;
				}
			}
			else {
				visited[cur_pos] = false;
				visited[next_pos] = true;
				durability[next_pos]--;

				if (durability[next_pos] == 0) {
					num_zero++;
				}
				robots.push(next_pos);
			}
		}
		else {
			robots.push(cur_pos);
		}
	}

	return num_zero;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	head = 1, tail = N;

	for (int i = 1; i <= 2 * N; i++) {
		cin >> durability[i];
	}

	int step = 1;
	int num_zero = 0;

	while (1) {
		move_belt(N);

		// cout << head << "  " << tail << "\n";

		if (visited[tail]) {
			visited[tail] = false;
			robots.pop();
		}

		num_zero += move_robots(N);

		if (durability[head] != 0 && !visited[head]) {
			durability[head]--;
			robots.push(head);
			visited[head] = true;
			if (durability[head] == 0) {
				num_zero++;
			}
		}

		if (num_zero >= K) {
			break;
		}

		step++;

	}

	cout << step;


	return 0;
}