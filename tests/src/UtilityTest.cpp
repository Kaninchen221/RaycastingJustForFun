#include "UtilityTest.h"

TEST(UtilityGetRecurrenceTest, tests) {

	getRecurrenceAndAssert(10, 1, {0, 10u});
	getRecurrenceAndAssert(56.213f, 2.f, { 0.213f, 23u });

}