class Solution {
public:
    double eps = 1e-7;
    double dist(vector<int>& p1, vector<int>& p2) {
        return sqrt((p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]));
    }
    double eq(double x, double y) {
        return fabs(x - y) < eps;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<double> line;
        line.push_back(dist(p1, p2));
        line.push_back(dist(p1, p3));
        line.push_back(dist(p1, p4));
        line.push_back(dist(p2, p3));
        line.push_back(dist(p2, p4));
        line.push_back(dist(p3, p4));
        sort(line.begin(), line.end());
        
        for(int i = 0; i < 6; i++)
            if(line[i] == 0) return false;
        
        return eq(line[0], line[1]) && eq(line[1], line[2]) && eq(line[2], line[3]) && eq(sqrt(2)*line[3], line[4]) && eq(sqrt(2)*line[3], line[5]);
    }
};