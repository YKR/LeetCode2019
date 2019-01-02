class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> triplet(3);
        map<int, int> nmap;
        for (auto && nn : nums)
        {
            auto found = nmap.find(nn);
            if (found != nmap.end())
                ++found->second;
            else
                nmap[nn] = 1;
        }
        for (auto i = nmap.begin(); i != nmap.end(); ++i)
        {
            auto j = i; ++j;
            for (; j != nmap.end(); ++j)
            {
                if (i->second >= 2 && (i->first << 1) == -j->first)
                {
                    triplet[0] = i->first;
                    triplet[1] = i->first;
                    triplet[2] = j->first;
                    ret.push_back(triplet);
                }
                int target = -(i->first + j->first);
                if (target < j->first) continue;
                if (target == j->first)
                {
                    if (j->second >= 2)
                    {
                        triplet[0] = i->first;
                        triplet[1] = j->first;
                        triplet[2] = j->first;
                        ret.push_back(triplet);
                    }
                    continue;
                }
                auto found = nmap.find(target);
                if (found != nmap.end())
                {
                    triplet[0] = i->first;
                    triplet[1] = j->first;
                    triplet[2] = target;
                    ret.push_back(triplet);
                }
            }
            if (i->first == 0 && i->second >= 3)
            {
                triplet[0] = 0;
                triplet[1] = 0;
                triplet[2] = 0;
                ret.push_back(triplet);
            }
        }
        return ret;
    }
};