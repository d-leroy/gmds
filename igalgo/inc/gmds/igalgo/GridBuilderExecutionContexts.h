#ifndef GMDS_GRIDBUILDEREXECUTIONCONTEXTS_H
#define GMDS_GRIDBUILDEREXECUTIONCONTEXTS_H

#include <Python.h>
#include <pybind11/embed.h>
#include <pybind11/stl.h>
#include <SciHook.h>

#include <gmds/igalgo/GridBuilder.h>
#include <gmds/igalgo/GridBuilderTriggers.h>
#include <set>
#include <sstream>


namespace gmds {
  class GridBuilder;
}


struct GmdsGridbuilderIsvalidExecutionContext : SciHook::SciHookExecutionContext
{
    const pybind11::object get_instance() const { if (instance != nullptr) return pybind11::cast(instance); else return pybind11::cast<pybind11::none>(Py_None); }

    const gmds::GridBuilder *instance = nullptr;

    GmdsGridbuilderIsvalidExecutionContext(
        const gmds::GridBuilder *instance,
        std::string name
    ) : SciHookExecutionContext(name),
        instance(instance)
        {}
};

struct GmdsGridbuilderExecuteExecutionContext : SciHook::SciHookExecutionContext
{
    const pybind11::object get_instance() const { if (instance != nullptr) return pybind11::cast(instance); else return pybind11::cast<pybind11::none>(Py_None); }
    const pybind11::object get_AXNb() const { if (AXNb != nullptr) return pybind11::cast(*AXNb); else return pybind11::cast<pybind11::none>(Py_None); }
    const pybind11::object get_AXStep() const { if (AXStep != nullptr) return pybind11::cast(*AXStep); else return pybind11::cast<pybind11::none>(Py_None); }
    const pybind11::object get_AYNb() const { if (AYNb != nullptr) return pybind11::cast(*AYNb); else return pybind11::cast<pybind11::none>(Py_None); }
    const pybind11::object get_AYStep() const { if (AYStep != nullptr) return pybind11::cast(*AYStep); else return pybind11::cast<pybind11::none>(Py_None); }
    const pybind11::object get_AZNb() const { if (AZNb != nullptr) return pybind11::cast(*AZNb); else return pybind11::cast<pybind11::none>(Py_None); }
    const pybind11::object get_AZStep() const { if (AZStep != nullptr) return pybind11::cast(*AZStep); else return pybind11::cast<pybind11::none>(Py_None); }

    gmds::GridBuilder *instance = nullptr;
    const gmds::TInt *AXNb = nullptr;
    const gmds::TCoord *AXStep = nullptr;
    const gmds::TInt *AYNb = nullptr;
    const gmds::TCoord *AYStep = nullptr;
    const gmds::TInt *AZNb = nullptr;
    const gmds::TCoord *AZStep = nullptr;

    GmdsGridbuilderExecuteExecutionContext(
        gmds::GridBuilder *instance,
        std::string name,
        const gmds::TInt *AXNb,
        const gmds::TCoord *AXStep,
        const gmds::TInt *AYNb,
        const gmds::TCoord *AYStep,
        const gmds::TInt *AZNb,
        const gmds::TCoord *AZStep
    ) : SciHookExecutionContext(name),
        instance(instance),
        AXNb(AXNb),
        AXStep(AXStep),
        AYNb(AYNb),
        AYStep(AYStep),
        AZNb(AZNb),
        AZStep(AZStep)
        {}
};

struct GmdsGridbuilderBuild2dExecutionContext : SciHook::SciHookExecutionContext
{
    const pybind11::object get_instance() const { if (instance != nullptr) return pybind11::cast(instance); else return pybind11::cast<pybind11::none>(Py_None); }
    const pybind11::object get_AXNb() const { if (AXNb != nullptr) return pybind11::cast(*AXNb); else return pybind11::cast<pybind11::none>(Py_None); }
    const pybind11::object get_AXStep() const { if (AXStep != nullptr) return pybind11::cast(*AXStep); else return pybind11::cast<pybind11::none>(Py_None); }
    const pybind11::object get_AYNb() const { if (AYNb != nullptr) return pybind11::cast(*AYNb); else return pybind11::cast<pybind11::none>(Py_None); }
    const pybind11::object get_AYStep() const { if (AYStep != nullptr) return pybind11::cast(*AYStep); else return pybind11::cast<pybind11::none>(Py_None); }

    gmds::GridBuilder *instance = nullptr;
    const gmds::TInt *AXNb = nullptr;
    const gmds::TCoord *AXStep = nullptr;
    const gmds::TInt *AYNb = nullptr;
    const gmds::TCoord *AYStep = nullptr;

    GmdsGridbuilderBuild2dExecutionContext(
        gmds::GridBuilder *instance,
        std::string name,
        const gmds::TInt *AXNb,
        const gmds::TCoord *AXStep,
        const gmds::TInt *AYNb,
        const gmds::TCoord *AYStep
    ) : SciHookExecutionContext(name),
        instance(instance),
        AXNb(AXNb),
        AXStep(AXStep),
        AYNb(AYNb),
        AYStep(AYStep)
        {}
};

struct GmdsGridbuilderBuild3dExecutionContext : SciHook::SciHookExecutionContext
{
    const pybind11::object get_instance() const { if (instance != nullptr) return pybind11::cast(instance); else return pybind11::cast<pybind11::none>(Py_None); }
    const pybind11::object get_AXNb() const { if (AXNb != nullptr) return pybind11::cast(*AXNb); else return pybind11::cast<pybind11::none>(Py_None); }
    const pybind11::object get_AXStep() const { if (AXStep != nullptr) return pybind11::cast(*AXStep); else return pybind11::cast<pybind11::none>(Py_None); }
    const pybind11::object get_AYNb() const { if (AYNb != nullptr) return pybind11::cast(*AYNb); else return pybind11::cast<pybind11::none>(Py_None); }
    const pybind11::object get_AYStep() const { if (AYStep != nullptr) return pybind11::cast(*AYStep); else return pybind11::cast<pybind11::none>(Py_None); }
    const pybind11::object get_AZNb() const { if (AZNb != nullptr) return pybind11::cast(*AZNb); else return pybind11::cast<pybind11::none>(Py_None); }
    const pybind11::object get_AZStep() const { if (AZStep != nullptr) return pybind11::cast(*AZStep); else return pybind11::cast<pybind11::none>(Py_None); }

    gmds::GridBuilder *instance = nullptr;
    const gmds::TInt *AXNb = nullptr;
    const gmds::TCoord *AXStep = nullptr;
    const gmds::TInt *AYNb = nullptr;
    const gmds::TCoord *AYStep = nullptr;
    const gmds::TInt *AZNb = nullptr;
    const gmds::TCoord *AZStep = nullptr;

    GmdsGridbuilderBuild3dExecutionContext(
        gmds::GridBuilder *instance,
        std::string name,
        const gmds::TInt *AXNb,
        const gmds::TCoord *AXStep,
        const gmds::TInt *AYNb,
        const gmds::TCoord *AYStep,
        const gmds::TInt *AZNb,
        const gmds::TCoord *AZStep
    ) : SciHookExecutionContext(name),
        instance(instance),
        AXNb(AXNb),
        AXStep(AXStep),
        AYNb(AYNb),
        AYStep(AYStep),
        AZNb(AZNb),
        AZStep(AZStep)
        {}
};

PYBIND11_EMBEDDED_MODULE(GridBuilder, m)
{
  pybind11::class_<GmdsGridbuilderIsvalidExecutionContext, std::shared_ptr<GmdsGridbuilderIsvalidExecutionContext>, SciHook::SciHookExecutionContext>(m, "GmdsGridbuilderIsvalidExecutionContext")
    .def_property_readonly("instance", &GmdsGridbuilderIsvalidExecutionContext::get_instance)
    .def("__str__", [](GmdsGridbuilderIsvalidExecutionContext &self)
    {
      std::ostringstream oss;
      oss << "[" << self.name << "]";
      return oss.str();
    })
    .def("__repr__", [](GmdsGridbuilderIsvalidExecutionContext &self)
    {
      std::ostringstream oss;
      oss << "[" << self.name << "]";
      return oss.str();
    });
  pybind11::class_<GmdsGridbuilderExecuteExecutionContext, std::shared_ptr<GmdsGridbuilderExecuteExecutionContext>, SciHook::SciHookExecutionContext>(m, "GmdsGridbuilderExecuteExecutionContext")
    .def_property_readonly("instance", &GmdsGridbuilderExecuteExecutionContext::get_instance)
    .def_property_readonly("AXNb", &GmdsGridbuilderExecuteExecutionContext::get_AXNb)
    .def_property_readonly("AXStep", &GmdsGridbuilderExecuteExecutionContext::get_AXStep)
    .def_property_readonly("AYNb", &GmdsGridbuilderExecuteExecutionContext::get_AYNb)
    .def_property_readonly("AYStep", &GmdsGridbuilderExecuteExecutionContext::get_AYStep)
    .def_property_readonly("AZNb", &GmdsGridbuilderExecuteExecutionContext::get_AZNb)
    .def_property_readonly("AZStep", &GmdsGridbuilderExecuteExecutionContext::get_AZStep)
    .def("__str__", [](GmdsGridbuilderExecuteExecutionContext &self)
    {
      std::ostringstream oss;
      oss << "[" << self.name << "]";
      return oss.str();
    })
    .def("__repr__", [](GmdsGridbuilderExecuteExecutionContext &self)
    {
      std::ostringstream oss;
      oss << "[" << self.name << "]";
      return oss.str();
    });
  pybind11::class_<GmdsGridbuilderBuild2dExecutionContext, std::shared_ptr<GmdsGridbuilderBuild2dExecutionContext>, SciHook::SciHookExecutionContext>(m, "GmdsGridbuilderBuild2dExecutionContext")
    .def_property_readonly("instance", &GmdsGridbuilderBuild2dExecutionContext::get_instance)
    .def_property_readonly("AXNb", &GmdsGridbuilderBuild2dExecutionContext::get_AXNb)
    .def_property_readonly("AXStep", &GmdsGridbuilderBuild2dExecutionContext::get_AXStep)
    .def_property_readonly("AYNb", &GmdsGridbuilderBuild2dExecutionContext::get_AYNb)
    .def_property_readonly("AYStep", &GmdsGridbuilderBuild2dExecutionContext::get_AYStep)
    .def("__str__", [](GmdsGridbuilderBuild2dExecutionContext &self)
    {
      std::ostringstream oss;
      oss << "[" << self.name << "]";
      return oss.str();
    })
    .def("__repr__", [](GmdsGridbuilderBuild2dExecutionContext &self)
    {
      std::ostringstream oss;
      oss << "[" << self.name << "]";
      return oss.str();
    });
  pybind11::class_<GmdsGridbuilderBuild3dExecutionContext, std::shared_ptr<GmdsGridbuilderBuild3dExecutionContext>, SciHook::SciHookExecutionContext>(m, "GmdsGridbuilderBuild3dExecutionContext")
    .def_property_readonly("instance", &GmdsGridbuilderBuild3dExecutionContext::get_instance)
    .def_property_readonly("AXNb", &GmdsGridbuilderBuild3dExecutionContext::get_AXNb)
    .def_property_readonly("AXStep", &GmdsGridbuilderBuild3dExecutionContext::get_AXStep)
    .def_property_readonly("AYNb", &GmdsGridbuilderBuild3dExecutionContext::get_AYNb)
    .def_property_readonly("AYStep", &GmdsGridbuilderBuild3dExecutionContext::get_AYStep)
    .def_property_readonly("AZNb", &GmdsGridbuilderBuild3dExecutionContext::get_AZNb)
    .def_property_readonly("AZStep", &GmdsGridbuilderBuild3dExecutionContext::get_AZStep)
    .def("__str__", [](GmdsGridbuilderBuild3dExecutionContext &self)
    {
      std::ostringstream oss;
      oss << "[" << self.name << "]";
      return oss.str();
    })
    .def("__repr__", [](GmdsGridbuilderBuild3dExecutionContext &self)
    {
      std::ostringstream oss;
      oss << "[" << self.name << "]";
      return oss.str();
    });
}
#endif
