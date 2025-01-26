// 无法处理凸包退化，或者精度较差的情况：这些情况需要特殊处理
vector<point> minkovski(vector<vector<point> > a) 
{
	// a[0], a[1]:起点为左下的逆时针凸包
	For(i, 0, 1) a[i].push_back(a[i].front());
	int i[2] = {0, 0},
		len[2] = {sz(a[0]) - 1, sz(a[1]) - 1};
	vector <point> ret;
	ret.push_back(a[0][0] + a[1][0]);
	do { //输入退化时会死循环，需特判
		int d = sgn(det(a[1][i[1] + 1]- a[1][i[1]],
					a[0][i[0] + 1]- a[0][i[0]])) >= 0;
		ret.push_back(a[d][i[d] + 1]- a[d][i[d]] + ret.back());
		i[d] = (i[d] + 1) % len[d];
	} while(i[0] || i[1]);
	return ret; //结果不是严格凸包
}