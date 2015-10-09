/**
 * Author: Unknown
 * Description: Matrix tree theorem. Counts the number of spanning trees in an undirected graph.
 * Source: Unknown
 * Date: 2014-11-27
 * Usage:
 *  vector<vi> mat(N, vi(N));
 *  addEdge(mat, u, v); // for each edge (u, v)
 *  int nSpanningTrees = det(reduce(mat));
 */

ll det(vector<vi>& a) { // integer determinant
	ll ans = 1;
	rep(i,0,a.size()) {
		rep(j,i+1,a.size()) {
			while (a[j][i] != 0) {
				int t = a[i][i] / a[j][i];
				rep(k,i,a.size())
					a[i][k] = (a[i][k] - a[j][k] * t);
				rep(k,0,a.size())
					swap(a[i][k], a[j][k]);
				ans = -ans;
			}
		}
		if (!a[i][i]){
			return 0;
		}
		ans *= a[i][i];
	}
	return ans;
}

void addEdge(vector<vi>& mat, int a, int b){
	mat[a][a]++; mat[b][b]++;
	mat[a][b]--; mat[b][a]--;
}

vector<vi> reduce(vector<vi>& mat){
	vector<vi> ret = mat;
	ret.pop_back();
	trav(r, ret) r.pop_back();
	return ret;
}
