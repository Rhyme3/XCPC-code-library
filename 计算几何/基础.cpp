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