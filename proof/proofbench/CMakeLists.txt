############################################################################
# CMakeLists.txt file for building ROOT proof/proofbench package
############################################################################

ROOT_GLOB_HEADERS(headers inc/TProof*.h)
ROOT_GLOB_SOURCES(sources src/TProof*.cxx)


ROOT_GENERATE_DICTIONARY(G__ProofBench ${headers} MODULE ProofBench LINKDEF LinkDef.h DEPENDENCIES Hist Gpad ProofPlayer)

ROOT_LINKER_LIBRARY(ProofBench ${sources} G__ProofBench.cxx LIBRARIES Core  DEPENDENCIES Hist Gpad ProofPlayer)
ROOT_INSTALL_HEADERS(FILTER "TSel")

# Generation and installation of the PAR files required by the benchmark 
add_custom_target(ProofBenchPARFiles ALL DEPENDS ${CMAKE_BINARY_DIR}/etc/proof/proofbench/ProofBenchCPUSel.par
                                                 ${CMAKE_BINARY_DIR}/etc/proof/proofbench/ProofBenchDataSel.par)
add_dependencies(ProofBenchPARFiles move_artifacts)
add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/etc/proof/proofbench/ProofBenchCPUSel.par
                          ${CMAKE_BINARY_DIR}/etc/proof/proofbench/ProofBenchDataSel.par
    COMMAND etc/proof/utils/makepbenchpars.sh ARGS ProofBenchCPUSel ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} 
    COMMAND etc/proof/utils/makepbenchpars.sh ARGS ProofBenchDataSel ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} 
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
install(DIRECTORY ${CMAKE_BINARY_DIR}/etc/proof/proofbench DESTINATION ${CMAKE_INSTALL_SYSCONFDIR}/proof USE_SOURCE_PERMISSIONS)
