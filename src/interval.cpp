#include <algorithm>
#include <cmath>

#include "interval.h"

/**
 *  Addition
 *  [a, b] + [c, d] = [a + c, b + d]
 */
Interval Interval::operator + (const Interval& param) {
    Interval temp;
    temp.a = this->a + param.a;
    temp.b = this->b + param.b;
    return temp;
}

/**
 *  Multiplication
 *  [a, b] * [c, d] = [min(ac, ad, bc, bd), max(a/c, a/d, b/c, b/d)]
 */
Interval Interval::operator * (const Interval& param) {
    double a = this->a,
           b = this->b,
           c = param.a,
           d = param.b;
    double min_lhs = std::min(std::min(a*c, a*d), std::min(b*c, b*d));
    double max_rhs = std::max(std::max(a/c, a/d), std::max(b/c, b/d));
    
    return Interval(min_lhs, max_rhs);
}

/**
 *  Equality
 *  a == b and c ==d  =>  [a, b] == [c, d]
 */
bool Interval::operator == (const Interval& param) {
    return this->a == param.a and this->b == param.b;
}

/**
 *  Output
 *  
 */
std::ostream& operator<<(std::ostream &strm, const Interval& param) {
  return param.dump(strm);
}

/**
 *  Exponentiation
 *  exp([a, b]) = [exp(a), exp(b)]
 */
Interval exp(Interval x) {
    return Interval(exp(x.a), exp(x.b));
}

/**
 *  Logarithm
 *  log([a, b]) = [log(a), log(b)] for a, b > 1
 */
Interval log(Interval x) {
    return Interval(log(x.a), log(x.b));
}