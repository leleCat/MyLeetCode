//
// String to Integer (atoi)
//
// Required:
// Implement atoi to convert a string to an integer.
//
// Hint:
// Carefully consider all possible input cases.
// If you want a challenge, please do not see below and ask yourself what are the possible input cases.
//
// Notes:
// It is intended for this problem to be specified vaguely (ie, no given input specs).
// You are responsible to gather all the input requirements up front.
//
// Requirements for atoi:
// The function first discards as many whitespace characters as necessary until the first non-whitespace character is found.
// Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
// The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
// If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
// If no valid conversion could be performed, a zero value is returned.
// If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long result = 0;

        bool is_negative = false;
        bool is_start_space = true;
        for (char i : str) {
            if (i <= '9' && i >= '0') {
                is_start_space = false;

                if (is_negative) {
                    result = result * 10 - i + '0';
                } else {
                    result = result * 10 + i - '0';
                }

            } else if (is_start_space && i == '-') {
                is_start_space = false;
                is_negative = true;

            } else if (is_start_space && i == '+') {
                is_start_space = false;

            } else if (is_start_space && i == ' ') {

            } else {
                break;
            }

            if (result < INT_MIN) {
                return INT_MIN;
            } else if (result > INT_MAX) {
                return INT_MAX;
            }
        }

        return (int) result;
    }
};
