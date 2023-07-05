#ifndef GMDS_GRIDBUILDERTRIGGERS_H
#define GMDS_GRIDBUILDERTRIGGERS_H

#include <gmds/igalgo/GridBuilderExecutionContexts.h>

#define DECLARE_GMDS_GRIDBUILDER_EVENTS \
private: \
  size_t GMDS_GRIDBUILDER_ISVALID_BEFORE; \
  size_t GMDS_GRIDBUILDER_ISVALID_AFTER; \
  size_t GMDS_GRIDBUILDER_EXECUTE_BEFORE; \
  size_t GMDS_GRIDBUILDER_EXECUTE_AFTER; \
  size_t GMDS_GRIDBUILDER_BUILD2D_BEFORE; \
  size_t GMDS_GRIDBUILDER_BUILD2D_AFTER; \
  size_t GMDS_GRIDBUILDER_BUILD3D_BEFORE; \
  size_t GMDS_GRIDBUILDER_BUILD3D_AFTER; 


#define INITIALIZE_GMDS_GRIDBUILDER_EVENTS \
GMDS_GRIDBUILDER_ISVALID_BEFORE = SciHook::register_base_event("Gmds.Gridbuilder.Isvalid.Before"); \
GMDS_GRIDBUILDER_ISVALID_AFTER = SciHook::register_base_event("Gmds.Gridbuilder.Isvalid.After"); \
GMDS_GRIDBUILDER_EXECUTE_BEFORE = SciHook::register_base_event("Gmds.Gridbuilder.Execute.Before"); \
GMDS_GRIDBUILDER_EXECUTE_AFTER = SciHook::register_base_event("Gmds.Gridbuilder.Execute.After"); \
GMDS_GRIDBUILDER_BUILD2D_BEFORE = SciHook::register_base_event("Gmds.Gridbuilder.Build2d.Before"); \
GMDS_GRIDBUILDER_BUILD2D_AFTER = SciHook::register_base_event("Gmds.Gridbuilder.Build2d.After"); \
GMDS_GRIDBUILDER_BUILD3D_BEFORE = SciHook::register_base_event("Gmds.Gridbuilder.Build3d.Before"); \
GMDS_GRIDBUILDER_BUILD3D_AFTER = SciHook::register_base_event("Gmds.Gridbuilder.Build3d.After"); 


#define TRIGGER_GMDS_GRIDBUILDER_ISVALID_BEFORE \
std::shared_ptr<GmdsGridbuilderIsvalidExecutionContext> ctx(new GmdsGridbuilderIsvalidExecutionContext(this, "GmdsGridbuilderIsvalidExecutionContext")); \
SciHook::trigger(GMDS_GRIDBUILDER_ISVALID_BEFORE, ctx);

#define TRIGGER_GMDS_GRIDBUILDER_ISVALID_AFTER \
SciHook::trigger(GMDS_GRIDBUILDER_ISVALID_AFTER, ctx);

#define TRIGGER_GMDS_GRIDBUILDER_EXECUTE_BEFORE \
std::shared_ptr<GmdsGridbuilderExecuteExecutionContext> ctx(new GmdsGridbuilderExecuteExecutionContext(this, "GmdsGridbuilderExecuteExecutionContext", &AXNb, &AXStep, &AYNb, &AYStep, &AZNb, &AZStep)); \
SciHook::trigger(GMDS_GRIDBUILDER_EXECUTE_BEFORE, ctx);

#define TRIGGER_GMDS_GRIDBUILDER_EXECUTE_AFTER \
SciHook::trigger(GMDS_GRIDBUILDER_EXECUTE_AFTER, ctx);

#define TRIGGER_GMDS_GRIDBUILDER_BUILD2D_BEFORE \
std::shared_ptr<GmdsGridbuilderBuild2dExecutionContext> ctx(new GmdsGridbuilderBuild2dExecutionContext(this, "GmdsGridbuilderBuild2dExecutionContext", &AXNb, &AXStep, &AYNb, &AYStep)); \
SciHook::trigger(GMDS_GRIDBUILDER_BUILD2D_BEFORE, ctx);

#define TRIGGER_GMDS_GRIDBUILDER_BUILD2D_AFTER \
SciHook::trigger(GMDS_GRIDBUILDER_BUILD2D_AFTER, ctx);

#define TRIGGER_GMDS_GRIDBUILDER_BUILD3D_BEFORE \
std::shared_ptr<GmdsGridbuilderBuild3dExecutionContext> ctx(new GmdsGridbuilderBuild3dExecutionContext(this, "GmdsGridbuilderBuild3dExecutionContext", &AXNb, &AXStep, &AYNb, &AYStep, &AZNb, &AZStep)); \
SciHook::trigger(GMDS_GRIDBUILDER_BUILD3D_BEFORE, ctx);

#define TRIGGER_GMDS_GRIDBUILDER_BUILD3D_AFTER \
SciHook::trigger(GMDS_GRIDBUILDER_BUILD3D_AFTER, ctx);

#endif