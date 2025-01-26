#define y1 yy1
#define ld long double
#define pi acos(-1.0)
const ld eps = 1e-10;
struct point
{
    ld x, y;
    explicit point(ld x = 0, ld y = 0): x(x), y(y) {}
};
struct line
{
    point s, t;
    line() {}
    line(point s, point t): s(s), t(t) {}
};
int sgn(ld x)
{
    return fabs(x) < eps ? 0 : (x > 0 ? 1 : -1);
}
point operator + (const point& a, const point& b) { return point(a.x + b.x, a.y + b.y); }
point operator - (const point& a, const point& b) { return point(a.x - b.x, a.y - b.y); }
point operator * (const point& a, ld k) { return point(a.x * k, a.y * k); }
point operator / (const point& a, ld k) { return point(a.x / k, a.y / k); }
inline bool operator < (const point& a, const point& b)
{
    return sgn(a.x - b.x) < 0 || (sgn(a.x - b.x) == 0 && sgn(a.y - b.y) < 0);
}
bool operator == (const point& a, const point& b)
{
    return !sgn(a.x - b.x) && !sgn(a.y - b.y);
}
ld dist(const point& p) { return sqrt(p.x * p.x + p.y * p.y); } //直线距离
ld dot(const point& a, const point& b) { return a.x * b.x + a.y * b.y; } //点积投影
ld det(const point& a, const point& b) { return a.x * b.y - a.y * b.x; } //叉积面积
ld cross(const point& s, const point& t, const point& o = point()) { return det(s - o, t - o); } //面积和夹角··
