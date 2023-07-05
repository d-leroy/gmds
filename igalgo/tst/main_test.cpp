/*----------------------------------------------------------------------------*/
#include <gtest/gtest.h>
/*----------------------------------------------------------------------------*/
// Files containing the different test suites to launch

#include "BoundaryOpTestSuite.h"
#include "BoundaryExtractorTestSuite.h"
#include "GridBuilderTestSuite.h"
#include <SciHook.h>

/*----------------------------------------------------------------------------*/
PYBIND11_EMBEDDED_MODULE(gridbuildertest, m) {
	py::module_::import("GridBuilder");
}

int main(int argc, char ** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  if (argc >= 2) {
    std::vector<std::string> python_path = { argv[1] };
    std::vector<std::string> python_script = { argv[2] };
    SciHook::initialize_scihook(python_path, python_script, "gridbuildertest");
  }
  return RUN_ALL_TESTS();
}
/*----------------------------------------------------------------------------*/

