//
// Created by otiko nozadze on 11.10.26.
//
#include <criterion/criterion.h>
#define ARRAY_HELPER
#include "dynamic_array.h"


Test(empty_array, int_array) {
    int * arr_int;
    ARRAY_CREATE(int,arr_int);
    cr_assert_eq(ARRAY_SIZE(arr_int), 0);
    cr_assert_eq(ARRAY_CAP(arr_int), 0);
}

Test(push_arry, testing_push) {
    int * arr_int;
    ARRAY_CREATE(int,arr_int);
    int test_values[5] = {1,2,3,4,5};
    for (int i = 0;i<5;i++) {
        ARRAY_PUSH(arr_int,test_values[i]);
    }
    cr_assert_eq(ARRAY_SIZE(arr_int), 5);

    for (int i = 0;i<ARRAY_SIZE(arr_int);i++) {
        cr_assert_eq(arr_int[i], test_values[i]);
    }
}

Test(arrayPop, testing_pop) {
    int * nums;
    ARRAY_CREATE(int, nums);
    ARRAY_PUSH(nums, 10);
    ARRAY_PUSH(nums, 20);
    ARRAY_PUSH(nums, 30);

    cr_assert_eq(*(int*)ARRAY_POP(nums,sizeof(int)),30);
    cr_assert_eq(*(int*)ARRAY_POP(nums,sizeof(int)),20);
    ARRAY_PUSH(nums,99999);
    cr_assert_eq(*(int*)ARRAY_POP(nums,sizeof(int)),99999);
    cr_assert_eq(*(int*)ARRAY_POP(nums,sizeof(int)),10);
    cr_assert_eq((int*)ARRAY_POP(nums,sizeof(int)),NULL);
}
