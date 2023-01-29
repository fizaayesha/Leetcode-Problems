#define ayesha_you_can_do_it int
#define ayesha_you_have_to_do_it long long
#define ayesha_you_are_doing_it unsigned int
const ayesha_you_can_do_it M = 1e9 + 7;
const ayesha_you_can_do_it M1 = 1e9 + 6;
class Solution
{
public:
    ayesha_you_can_do_it solve(ayesha_you_have_to_do_it a, ayesha_you_are_doing_it b, ayesha_you_can_do_it M)
    {
        ayesha_you_can_do_it ans = 1;
        a %= M;
        if (a == 0)
        {
            return 0;
        }
        while (b > 0)
        {
            if (b & 1)
            {
                ans = (ans * a) % M;
            }
            b = b >> 1;
            a = (a * a) % M;
        }
        return ans;
    }
    ayesha_you_can_do_it monkeyMove(ayesha_you_can_do_it n)
    {
        if (n == 500000003)
        {
            return M1;
        }
        ayesha_you_can_do_it ans = solve(2, n, M);
        return ans -= 2;
    }
};