class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();

        // P[i] = alternating sum of first i elements
        // P[0] = 0
        vector<long long> P(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                P[i + 1] = P[i] + nums[i];
            else
                P[i + 1] = P[i] - nums[i];
        }

        // No operation
        long long ans = P[n];

        const long long NEG_INF = -(1LL << 60);

        // maxP[l] = maximum P[l] for each parity of l
        long long maxP[2] = {NEG_INF, NEG_INF};

        for (int r = 1; r < n; r++) {

            /*
             * We are considering l < r.
             *
             * Add current possible l = r - 1.
             */
            int l = r - 1;

            maxP[l % 2] = max(maxP[l % 2], P[l]);

            /*
             * Case 1:
             * l and r have the same parity.
             *
             * gain = 2 * (P[l + 1] - P[r + 1])
             *
             * l + 1 has opposite parity to l.
             */
            int parity = l % 2;

            if (maxP[parity] != NEG_INF) {
                /*
                 * We need maximum P[l + 1].
                 *
                 * Since l has parity `parity`,
                 * l + 1 has parity `1 - parity`.
                 *
                 * We maintain this separately below.
                 */
            }
        }

        /*
         * Cleaner implementation:
         *
         * bestA[p] = max P[l] where l has parity p
         * bestB[p] = max P[l+1] where l has parity p
         */
        long long bestA[2] = {NEG_INF, NEG_INF};
        long long bestB[2] = {NEG_INF, NEG_INF};

        ans = P[n];

        for (int r = 1; r < n; r++) {

            int l = r - 1;

            // Add l as a possible left endpoint.
            bestA[l % 2] = max(bestA[l % 2], P[l]);

            // P[l + 1]
            bestB[l % 2] = max(bestB[l % 2], P[l + 1]);

            // Case 1: l and r have the same parity
            if (bestB[r % 2] != NEG_INF) {
                long long gain =
                    2LL * (bestB[r % 2] - P[r + 1]);

                ans = max(ans, P[n] + gain);
            }

            // Case 2: l and r have different parity
            if (bestA[1 - (r % 2)] != NEG_INF) {
                long long gain =
                    2LL * (bestA[1 - (r % 2)] - P[r + 1]);

                ans = max(ans, P[n] + gain);
            }
        }

        return ans;
    }
};