class Solution {
public:
    int canCompleteCircuit_BF(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i < gas.size(); ++i)
        {
            bool cando = true;
            int accum = 0;
            for (int j = 0; j < gas.size(); ++j)
            {
                int cur = (i + j) % gas.size();
                accum += gas[cur] - cost[cur];
                if (accum < 0)
                {
                    cando = false;
                    break;
                }
            }
            if (cando)
                return i;
        }
        return -1;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //return canCompleteCircuit_BF(gas, cost);
        int accum[gas.size()];
        int minAccum = INT_MAX;
        for (int j = 0; j < gas.size(); ++j)
        {
            accum[j] = (j > 0 ? accum[j - 1] : 0) + gas[j] - cost[j];
            minAccum = min(minAccum, accum[j]);
        }
        int allAccum = accum[gas.size() - 1];
        if (allAccum < 0) return -1;
        for (int i = 0; i < gas.size(); ++i)
        {
            if (minAccum >= 0) return i;
            minAccum = min(minAccum - (gas[i] - cost[i]), allAccum);
        }
        return -1; // impossible here?
    }
};