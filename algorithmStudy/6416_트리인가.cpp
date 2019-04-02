#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int arr[100001], parent, son,cnt,nodes;
vector<pair<int, int>> v;
bool flag, visit[100001];
int main(void)
{
	for(int c=1;;c++)
	{
		while (1)
		{
			cin >> parent >> son;
			if (parent == 0 && son == 0) break;
			else if (parent == -1 && son == -1) return 0;
			v.push_back(make_pair(parent, son));
			if (arr[son]) flag = true;
			else arr[son] = parent;
		}
		if (flag) cout << "Case "<<c<<" is not a tree.\n";
		else {
			for (int i = 0; i < v.size(); i++)
			{
				if (!visit[v[i].first])
				{
					if(arr[v[i].first]) cnt++;
					visit[v[i].first] = true;
					nodes++;
				}
			}
			if (cnt + 1 == nodes || nodes == 0) cout << "Case " << c << " is a tree.\n";
			else cout << "Case " << c << " is not a tree.\n";
		}
		cnt = nodes = 0;
		flag = false;
		v.clear();
		memset(arr, 0, sizeof(arr));
		memset(visit, 0, sizeof(visit));
	}
	return 0;
}