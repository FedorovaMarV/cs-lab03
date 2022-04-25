#include "histogram.h"

#include <cassert>


void
test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void
test_negative ()
{
    double min=0;
    double max=0;
    find_minmax({-1,-2,-3},min,max);
    assert(min == -3);
    assert(max == -1);
}

void
test_similar ()
{
    double min=0;
    double max=0;
    find_minmax({1,1,1},min,max);
    assert(min == 1);
    assert(max == 1);

}

void
test_single()
{
    double min=0;
    double max=0;
    find_minmax({1},min,max);
    assert(min == 1);
    assert(max == 1);
}

void
test_empty ()
{
    double min=0;
    double max=0;
    find_minmax({},min,max);
}

void test1()
{
    vector <size_t> z = {20, 28, 52};
    vector <size_t> y = procent (25, {5,7,13});
    assert(z == y);
    return;
}

void test2()
{
    vector <size_t> z = {100};
    vector <size_t> y = procent (1, {1});
    assert(z == y);
    return;
}


int
main() {
    test_positive();
    test_negative ();
    test_similar ();
    test_single ();
    test_empty ();
    test1();
    test2();
}
