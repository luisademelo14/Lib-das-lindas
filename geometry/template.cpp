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
