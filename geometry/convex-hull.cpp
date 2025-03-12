/*
código encontrar os pontos pertencentes ao convex hull dado um conjunto de pontos inteiros
 */

 int cross (tpoint p, tpoint q, tpoint r){
    return (q-p)^(r-q);
}

vector<tpoint> convex_hull(vector<tpoint> v){
    sort(v.begin(), v.end());
    vector<tpoint> lower, upper;

    for(int i=0; i<(int)v.size(); i++){
        while(lower.size()>1 && cross(lower.end()[-2], lower.end()[-1], v[i])<0){
            lower.pop_back();
        }
        lower.push_back(v[i]);
        
        while(upper.size()>1 && cross(upper.end()[-2], upper.end()[-1], v[i])>0){
            upper.pop_back();
        }
        upper.push_back(v[i]);
    }

	lower.pop_back(); upper.erase(upper.begin());
    for (tpoint i : upper) lower.push_back(i);
	return lower;
}
