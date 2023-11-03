#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cstddef>
#include <stdlib.h>
#include <time.h>
#include "src/sorting_array.hpp"

using ::testing::ElementsAreArray;
using ::testing::WhenSorted;
using ::testing::WhenSortedBy;
using ::testing::Each;
using ::testing::AllOf;
using ::testing::Gt;
using ::testing::Lt;

struct TestArraySorting : public ::testing::Test {

	void SetUp() {

		min_number = new int;
		max_number = new int;
		len = new unsigned;
	}

	void TearDown() {

		delete min_number, max_number, len;
	}

	int array[10];
	int *min_number;
	int *max_number;
	unsigned *len;

};

TEST_F(TestArraySorting, Positive_1) {
	
	*len = 10;
	*min_number = -10001;
	*max_number = 10000;
	srand(time(NULL));
	
	for (size_t i = 0; i < *len; ++i) {
		array[i] = (*min_number) + rand()%((*max_number) + 1 - (*min_number));
	}

	int array_before_sorting[sizeof(array)/sizeof(array[0])];

	for (size_t i = 0; i < *len; ++i) {
		array_before_sorting[i] = array[i];
	}

	sorting_array(array, len);
	
	ASSERT_THAT(array, Each(AllOf(Gt(-10001), Lt(10000))));
	ASSERT_THAT(array_before_sorting, WhenSorted(ElementsAreArray(array)));

}

TEST_F(TestArraySorting, Negative_1) {

	*len = 10;
	*min_number = -1000;
	*max_number = 1000;
	srand(time(NULL));
	
	for (size_t i = 0; i < *len; ++i) {
		array[i] = (*min_number) + rand()%((*max_number) + 1 - (*min_number));
	}

	int array_before_sorting[sizeof(array)/sizeof(array[0])];

	for (size_t i = 0; i < *len; ++i) {
		array_before_sorting[i] = array[i];
	}

	sorting_array(array, len);
	
	EXPECT_THAT(array_before_sorting, WhenSortedBy(std::greater<int>(), ElementsAreArray(array)));

}


int main(int argc, char **argn) {
	testing::InitGoogleTest(&argc, argn);
	return RUN_ALL_TESTS();
}
