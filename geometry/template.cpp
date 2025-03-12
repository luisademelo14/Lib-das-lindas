struct tpoint
{
    double x, y;

    tpoint operator +(tpoint q) const
    {
        return {x + q.x, y + q.y};
    }
    tpoint operator -(tpoint q) const
    {
        return {x - q.x, y - q.y};
    }

    bool operator<(const tpoint& q) const {
        if(x != q.x) return x<q.x;
        return y<q.y;
    }
    double operator ~() const 
    {
        return hypot(x, y);
    }
    double operator *(tpoint q) const 
    {
        return (x*q.x + y*q.y);
    }
    double operator ^(tpoint q) const 
    {
        return (x*q.y - y*q.x);
    }
};

struct Func
{
	int a, b;
	int val(int x)
	{
		return a*x + b;
	}
};
