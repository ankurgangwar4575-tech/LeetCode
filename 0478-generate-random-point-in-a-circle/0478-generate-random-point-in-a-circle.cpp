class Solution {
private:
    double radius, x_center, y_center;

public:
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }

    vector<double> randPoint() {

        double r1 = (double)rand() / RAND_MAX, r2 = (double)rand() / RAND_MAX;
        double r = radius * sqrt(r1);
        double x = x_center + r * cos(2 * M_PI * r2),
               y = y_center + r * sin(2 * M_PI * r2);
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */