/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int gcd(int a, int b)
    {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    
    int maxPoints_Pruned(vector<Point>& points) {
        if (points.empty()) return 0;
        auto zeroPair = make_pair(0, 0);
        int ans = 0;
        int n = points.size();
        bool visited[n][n];
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; ++i)
        {
            map<pair<int, int>, vector<int>> gradients;
            for (int j = i + 1; j < n; ++j)
            {
                if (visited[i][j]) continue;
                int deltax = points[j].x - points[i].x;
                int deltay = points[j].y - points[i].y;
                int common = gcd(deltax, deltay);
                if (common == 0) common = 1; // same coordinate
                auto keyPair = make_pair(deltax / common, deltay / common);
                if (keyPair.second < 0 || keyPair.second == 0 && keyPair.first < 0)
                    keyPair.first = -keyPair.first, keyPair.second = -keyPair.second;
                gradients[keyPair].push_back(j);
            }
            int sameCoords = gradients[zeroPair].size();
            gradients[zeroPair].clear();
            for (auto && gr : gradients)
            {
                ans = max(ans, 1 + (int)gr.second.size() + sameCoords);
                for (int k = 0; k < gr.second.size(); ++k)
                    for (int l = k + 1; l < gr.second.size(); ++l)
                    {
                        int a = gr.second[k], b = gr.second[l];
                        if (!(points[a].x == points[b].x && points[a].y == points[b].y))
                            visited[a][b] = true;
                    }
            }
        }
        return ans;
    }

    int maxPoints(vector<Point>& points) {
        //return maxPoints_Pruned(points);
        if (points.empty()) return 0;
        auto zeroPair = make_pair(0, 0);
        int ans = 0;
        int n = points.size();
        for (int i = 0; i < n; ++i)
        {
            map<pair<int, int>, int> gradients;
            for (int j = i + 1; j < n; ++j)
            {
                int deltax = points[j].x - points[i].x;
                int deltay = points[j].y - points[i].y;
                int common = gcd(deltax, deltay);
                if (common == 0) common = 1; // same coordinate
                auto keyPair = make_pair(deltax / common, deltay / common);
                gradients[keyPair] = 1 + (gradients.find(keyPair) == gradients.end() ? 0 : gradients[keyPair]);
            }
            int sameCoords = gradients.find(zeroPair) == gradients.end() ? 0 : gradients[zeroPair];
            gradients[zeroPair] = 0;
            for (auto && gr : gradients)
            {
                ans = max(ans, 1 + gr.second + sameCoords);
            }
        }
        return ans;
    }
};