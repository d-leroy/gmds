#==============================================================================
# LIBRARY DEFINTION (SOURCE FILES)
#==============================================================================
# Nommer tout en GMDS_MODULE_NAME, GMDS_SRC, ... dans les composants
set(GMDS_LIB ${LIB_GMDS_CLAIRE})
set(GMDS_LIB_PREFIX gmds/claire)

set(GMDS_INC
		${CMAKE_BINARY_DIR}/exports/${GMDS_LIB}_export.h
		inc/gmds/claire/Smooth2D.h
		inc/gmds/claire/Grid_Smooth2D.h
		inc/gmds/claire/DistanceMap.h
        inc/gmds/claire/LevelSetCombined.h
        inc/gmds/claire/GradientComputation_2D.h
		inc/gmds/claire/GradientComputation_3D.h
        inc/gmds/claire/LeastSquaresGradientComputation.h
        inc/gmds/claire/AdvectedPointRK4_2D.h
        inc/gmds/claire/Params.h
		inc/gmds/claire/AbstractAeroPipeline.h
        inc/gmds/claire/AeroPipeline_2D.h
		inc/gmds/claire/AeroPipeline_3D.h
		inc/gmds/claire/AbstractLevelSet.h
		inc/gmds/claire/LevelSetEloi.h
		inc/gmds/claire/LevelSetExtended.h
		inc/gmds/claire/AdvectedPointRK4_3D.h
		inc/gmds/claire/Utils.h
		inc/gmds/claire/AbstractAeroBoundaries.h
		inc/gmds/claire/AeroBoundaries_2D.h
		inc/gmds/claire/AeroBoundaries_3D.h
		inc/gmds/claire/AeroMeshQuality.h
		inc/gmds/claire/AeroExtrusion_2D.h
		inc/gmds/claire/AeroException.h
		inc/gmds/claire/Front.h
		inc/gmds/claire/SmoothingPaving_2D.h
		inc/gmds/claire/FastLocalize.h
		inc/gmds/claire/SU2Writer.h
		inc/gmds/claire/IntervalAssignment_2D.h
		inc/gmds/claire/AbstractSmoothLineSweeping_2D.h
		inc/gmds/claire/SmoothLineSweepingYao.h
		inc/gmds/claire/SmoothLineSweepingOrtho.h
		inc/gmds/claire/RefinementBeta.h
		inc/gmds/claire/RefinementBetaBlocking.h
		inc/gmds/claire/AeroEllipticSmoothing_2D.h
		inc/gmds/claire/DiffusionEquation2D.h
		inc/gmds/claire/Front_3D.h
		inc/gmds/claire/AeroExtrusion_3D.h
		inc/gmds/claire/FrontEdgesNodesClassification_3D.h
		inc/gmds/claire/NodeNeighbourhoodOnFront_3D.h
		inc/gmds/claire/MeshAlignment_2D.h
		)
set(GMDS_SRC
		src/main.cpp
		src/Smooth2D.cpp
        src/Grid_Smooth2D.cpp
		src/DistanceMap.cpp
        src/LevelSetCombined.cpp
        src/GradientComputation_2D.cpp
		src/GradientComputation_3D.cpp
        src/LeastSquaresGradientComputation.cpp
        src/AdvectedPointRK4_2D.cpp
        src/AbstractAeroPipeline.cpp
        src/AeroPipeline_2D.cpp
		src/AeroPipeline_3D.cpp
		src/AbstractLevelSet.cpp
		src/LevelSetEloi.cpp
		src/LevelSetExtended.cpp
		src/AdvectedPointRK4_3D.cpp
        src/Utils.cpp
		src/AbstractAeroBoundaries.cpp
		src/AeroBoundaries_2D.cpp
		src/AeroBoundaries_3D.cpp
		src/AeroMeshQuality.cpp
		src/AeroExtrusion_2D.cpp
		src/AeroException.cpp
		src/Front.cpp
		src/FastLocalize.cpp
		src/SmoothingPaving_2D.cpp
        src/SU2Writer.cpp
		src/IntervalAssignment_2D.cpp
		src/AbstractSmoothLineSweeping_2D.cpp
		src/SmoothLineSweepingYao.cpp
		src/SmoothLineSweepingOrtho.cpp
		src/RefinementBeta.cpp
		src/RefinementBetaBlocking.cpp
		src/AeroEllipticSmoothing_2D.cpp
		src/DiffusionEquation2D.cpp
		src/Front_3D.cpp
		src/AeroExtrusion_3D.cpp
		src/FrontEdgesNodesClassification_3D.cpp
		src/NodeNeighbourhoodOnFront_3D.cpp
		src/MeshAlignment_2D.cpp)
#==============================================================================
add_library(${GMDS_LIB} ${GMDS_INC} ${GMDS_SRC})
#==============================================================================
include(GenerateExportHeader)
generate_export_header(${GMDS_LIB}
		EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/exports/${GMDS_LIB}_export.h
		EXPORT_MACRO_NAME ${GMDS_LIB}_API)
#==============================================================================
# TARGET DEFINITION
#==============================================================================
include(GNUInstallDirs)

#LIBRARY TO INSTALL
target_link_libraries(${GMDS_LIB} PUBLIC
		${LIB_GMDS_IG}
		${LIB_GMDS_IO}
		${LIB_GMDS_IG_ALGO}
		${LIB_GMDS_CAD}
		${LIB_GMDS_CADFAC}
		${LIB_GMDS_SMOOTHY}
		${LIB_GMDS_BLOCKING}
		ANN
		)

target_compile_features(${GMDS_LIB} PUBLIC cxx_std_14)

# INCLUDE TO INSTALL
target_include_directories(${GMDS_LIB} PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		)
set_target_properties(${GMDS_LIB} PROPERTIES PUBLIC_HEADER "${GMDS_INC}")

install(TARGETS ${GMDS_LIB}
		EXPORT GMDS_SUITE
		PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${GMDS_LIB_PREFIX}
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
		RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

#==============================================================================
if(WITH_TEST)
	add_subdirectory(tst)
endif(WITH_TEST)

#==============================================================================
# EXECUTABLE
#==============================================================================
add_executable(Aero src/main.cpp)
target_link_libraries(Aero PRIVATE ${GMDS_LIB})
target_compile_features(Aero PUBLIC cxx_std_14)
install(TARGETS Aero)

add_executable(Claire_dev src/main_dev.cpp)
target_link_libraries(Claire_dev PRIVATE ${GMDS_LIB})
target_compile_features(Claire_dev PUBLIC cxx_std_14)
