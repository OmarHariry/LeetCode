class Solution {
public:
    int square(int n) {
        int sum = 0;
        while(n) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        
        do {
            slow = square(slow);
            fast = square(square(fast));
        }
        while(slow != fast && fast != 1);
        
        return fast == 1;
    }
};