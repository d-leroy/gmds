/*----------------------------------------------------------------------------*/
#include <gtest/gtest.h>
/*----------------------------------------------------------------------------*/
// Files containing the different test suites to launch

#include "BlockQualityTestSuite.h"
/*----------------------------------------------------------------------------*/
int main(int argc, char ** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
/*----------------------------------------------------------------------------*/

