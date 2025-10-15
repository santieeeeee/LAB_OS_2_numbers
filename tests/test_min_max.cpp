#include "gtest/gtest.h"
#include "../LAB_OS_2_numbers/LAB_OS_2_numbers.h"
#include <vector>

using namespace std;

TEST(ComputeTests, MinMaxSimple) {
    vector<int> v = { 3,1,7,1,9 };
    int mn, mx;
    compute_min_max(v, mn, mx);
    EXPECT_EQ(mn, 1);
    EXPECT_EQ(mx, 9);
}

TEST(ComputeTests, AverageSimple) {
    vector<int> v = { 1,2,3,4 };
    double avg = compute_average(v);
    EXPECT_DOUBLE_EQ(avg, 2.5);
}

TEST(ComputeTests, ReplaceMinMax) {
    vector<int> v = { 1,2,3,1,3 };
    double avg = compute_average(v);
    replace_min_max_with_average(v, avg);
    vector<int> expected = { 2,2,2,2,2 };
    EXPECT_EQ(v, expected);
}

TEST(ComputeTests, EmptyVector) {
    vector<int> v;
    int mn, mx;
    compute_min_max(v, mn, mx);
    EXPECT_EQ(mn, 0);
    EXPECT_EQ(mx, 0);
    EXPECT_DOUBLE_EQ(compute_average(v), 0.0);
}
