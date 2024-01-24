#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <ctime>
#include <climits>
#include <tuple>
#define N 150'000
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define INF INT_MAX
using namespace std;

vector<tuple<int, ll, ll>> room;


ll paramSearch(ll left, ll right, int num_room, ll atk) {
	ll ans = LLONG_MAX;
	while (left <= right) {
		ll hp_max = (left + right) / 2;
		ll atk_cur = atk;
		ll hp_cur = hp_max;
		int is_alive = 1;
		for (int i = 0; i < num_room && is_alive; i++) {
			int room_info = get<0>(room[i]);
			if (room_info == 1) { // monster room
				ll monster_atk= get<1>(room[i]);
				ll monster_hp = get<2>(room[i]);
				
				// do battle
				//while (is_alive) {
				//	monster_hp -= atk_cur;
				//	if (monster_hp <= 0) {
				//		// go to next room
				//		break; 
				//	}
				//	hp_cur -= monster_atk;
				//	if (hp_cur <= 0) {
				//		is_alive = 0;
				//	}
				//}

				ll monster_mok = monster_hp / atk_cur;
				ll monster_rest = monster_hp % atk_cur;

				ll warrior_mok = hp_cur / monster_atk;
				ll warrior_rest = hp_cur % monster_atk;

				if (monster_rest) monster_mok++;
				if (warrior_rest) warrior_mok++;

				if (monster_mok > warrior_mok) {
					is_alive = 0;
				}
				else {
					monster_mok--;
					if(monster_mok)
						hp_cur -= (monster_mok * monster_atk);
				}
			}
			else if (room_info == 2) { // potion room
				ll potion_atk = get<1>(room[i]);
				ll potion_hp = get<2>(room[i]);

				// drink potion
				atk_cur += potion_atk;
				hp_cur = min(hp_max, hp_cur + potion_hp);
			}
		}
		if(is_alive){
			ans = min(ans, hp_max);
			right = hp_max - 1;
		}
		else {
			left = hp_max + 1;
		}
	}
	return ans;
}

void Solution(int num_room, ll atk) {
	ll ans = paramSearch(1, 987654321987654321, num_room, atk);
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll num_room, atk; cin >> num_room >> atk;
	for (int i = 0; i < num_room; i++) {
		ll a, b, c; cin >> a >> b >> c;
		room.push_back({ (int)a,b,c });
	}
	Solution(num_room, atk);
	return 0;
}