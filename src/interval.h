#include <ostream>

#ifndef __INTERVAL_H
#define __INTERVAL_H

/**
 *  Interval arithmetic allows you to perform mathematical operations on ranges
 *  of numbers (thus including measurement errors, rounding errors, and
 *  tolerances automatically.
 *  
 *  Operations are defined as:
 *      [a, b] + [c, d] = [a + c, b + d]
 *      [a, b] - [c, d] = [a - d, b - c]
 *      [a, b] * [c, d] = [min(ac, ad, bc, bd), max(ac, ad, bc, bd)]
 *      [a, b] / [c, d] = [min(a/c, a/d, b/c, b/d), max(ac, ad, bc, bd)]
 *          when zero is not in [c, d]
 */

class Interval {
public:
    ////  CONSTRUCTORS  ////////////////////////////////////////////////////////
    /*  An interval consists of a left-hand side and a right-hand side,
     *      lhs <= rhs.
     *  Since this operation is not well-defined for complex numbers, we will
     *  omit complex interval arithmetic from this class (although it does
     *  exist).
     */
    Interval() {};

    /** If necessary, we have to swap the upper and lower bounds to be
     *  consistent with the real number line.  However, both bounds can be the
     *  same number.
     */
    Interval( double lower_bound,
              double upper_bound )
            : a( lower_bound < upper_bound ? lower_bound : upper_bound ),
              b( lower_bound < upper_bound ? upper_bound : lower_bound )
    { }
    
    ////  OPERATORS  ///////////////////////////////////////////////////////////
    Interval operator +  ( const Interval& );
    Interval operator *  ( const Interval& );
    
    bool     operator == ( const Interval& );
    
    ////  OUTPUT  //////////////////////////////////////////////////////////////
    virtual std::ostream& dump(std::ostream& strm) const {
      return strm << "[" << this->a << "," << this->b << "]";
   }
    
    ////  MEMBER VARIABLES  ////////////////////////////////////////////////////
    double a, b;
};

std::ostream& operator << (std::ostream &strm, const Interval& param);

Interval exp(Interval x);
Interval log(Interval x);
#endif /* __INTERVAL_H */