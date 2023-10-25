#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "src/search_pattern_string.hpp"

struct PatternTest: public ::testing::Test {
	
	void SetUp() {}
	void TearDown() {}

	int number_position_pattern = 0;
	char pattern[6] = "World";
};

TEST_F(PatternTest, Positiv_1_ts) {

	char text[] = "Hello World";
	number_position_pattern = strstr(text, pattern);

	EXPECT_EQ(6, number_position_pattern);
}

TEST_F(PatternTest, Positiv_2_ts) {

	char text[] = "_World34jt";
	number_position_pattern = strstr(text, pattern);

	EXPECT_EQ(1, number_position_pattern);
}

TEST_F(PatternTest, Positiv_3_ts) {

	char text[] = "dhdhdr445";
	char pattern_2[] = "";
	number_position_pattern = strstr(text, pattern_2);

	EXPECT_EQ(0, number_position_pattern);
}

TEST_F(PatternTest, Positiv_4_ts) {

	char text[] = "fj35Wor_lds34jt";
	number_position_pattern = strstr(text, pattern);

	EXPECT_EQ(-1, number_position_pattern);
}

TEST_F(PatternTest, Positiv_5_ts) {

	char text[] = "";
	number_position_pattern = strstr(text, pattern);

	EXPECT_EQ(-1, number_position_pattern);
}

TEST_F(PatternTest, Positiv_6_ts) {

	char text[] = "WorlWorlWorlWorld";
	number_position_pattern = strstr(text, pattern);

	EXPECT_EQ(12, number_position_pattern);
}

TEST_F(PatternTest, Negativ_ts) {

	char text[] = "fj35Wor_lds34jt";
	number_position_pattern = strstr(text, pattern);

	EXPECT_EQ(1, number_position_pattern);
}
int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
} 
