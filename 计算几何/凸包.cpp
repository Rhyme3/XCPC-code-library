//扫描线法(极角序Graham)
vector<point> convex_hull(vector<point> a) 
{
	if (a.size() <= 2) return a; //或者return {};
	point base = *min_element(a.begin(), a.end()); //字典序: less <pair>
	sort(a.begin(), a.end(), [&](auto u, auto v) 
	{
		int s = sgn(det(u - base, v - base));
		if (s) return s > 0;
		else return sgn(dis(u, base) - dis(v, base)) < 0;
	});
	vector<point> ret;
	for(auto i : a) 
	{
		while(sz(ret) > 1 && !cross(ret[sz(ret) - 1], i, ret[sz(ret) - 2])) ret.pop_back();
		ret.push_back(i);
	}
	return ret; //或者在ret.size() <= 2时return {};
}

//扫描线法(字典序Andrew)(常用)
vector<point> convex_hull(vector <point> a) 
{
	if (a.size() <= 2) return a; //或者return {};
	sort(a.begin(), a.end()); //字典序: less <pair>
	vector<point> ret;
	//for(int i = 0; i < (int)a.size(); i++) 
	For(i, 0, sz(a) - 1)
	{
		while(sz(ret) > 1 && !cross(ret[sz(ret) - 1], a[i]), ret[sz(ret) - 2]) ret.pop_back();
		ret.push_back(a[i]);
	}
	int fixed = sz(ret);
	//for(int i = (int)a.size()- 2; i >= 0; --i) 
	rof(i, sz(a) - 2, 0)
	{
		while(sz(ret) > fixed && !cross(ret[sz(ret) - 1], a[i], ret[sz(ret) - 2])) ret.pop_back();
		ret.push_back(a[i]);
	}
	ret.pop_back(); 
	return ret; //或者在ret.size() <= 2时return {};
}

//点到凸包切线(二分)(cpp17, 严格凸包, 点在凸包外)
int search(auto f) 
{
	int l = 0, r = sz(a) - 1;
	if(f(a[0], a.back())) 
	{
		while(l + 1 < r) 
		{
			int mid = (l + r) / 2;
			if(f(a[mid], a[l]) && f(a[mid], a[mid- 1])) l = mid;
			else r = mid;
		} 
		return l;
	} 
	else 
	{
		while(l + 1 < r) 
		{
			int mid = (l + r) / 2;
			if (f(a[mid], a[r]) && f(a[mid], a[mid + 1])) r = mid;
			else l = mid;
		} 
		return r;
	}
}
vector<point> get_tan(point u) 
{
	return { a[search([&](auto x, auto y) {return cross(y, x, u);})], 
			 a[search([&](auto x, auto y) {return cross(x, y, u);})] };
}