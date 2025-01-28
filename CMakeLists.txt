# project(bison_expressions)
# cmake_minimum_required(VERSION 3.5)
#
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED on)
# set(CMAKE_CXX_EXTENSIONS off)
# if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
#     add_compile_options(-Wall -Wpedantic)
# endif()
#
# find_package(BISON)
# find_package(FLEX)
#
#
# include_directories(parser html ${CMAKE_CURRENT_BINARY_DIR})
# file(GLOB HTML_HEADERS
#     html/noeud.hh
#     html/page.hh
#     html/noeudCorps.hh
#     html/noeudEnTete.hh
#     html/contexte.hh
#     html/variable.hh
#     html/noeudElement.hh
#     html/baliseStyle.hh
#     html/baliseImage.hh
#     html/baliseTitre.hh
#     html/baliseParagrahpe.hh
#     html/baliseCommentaire.hh
#     html/attribut.hh
#     html/text.hh
#     html/couleur.hh
#     html/propriete.hh
#     html/style.hh
#     html/constante.hh
#     )
#
# add_library(html
#     html/main.cc
#     html/noeud.cc
#     html/page.cc
#     html/noeudCorps.cc
#     html/noeudEnTete.cc
#     html/contexte.cc
#     html/variable.cc
#     html/noeudElement.cc
#     html/baliseStyle.cc
#     html/baliseImage.cc
#     html/baliseTitre.cc
#     html/baliseParagrahpe.cc
#     html/baliseCommentaire.cc
#     html/attribut.cc
#     html/text.cc
#     html/couleur.cc
#     html/propriete.cc
#     html/style.cc
#     html/constante.cc
#     ${HTML_HEADERS}
#     )
#
# BISON_TARGET(parser parser/parser.yy ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp VERBOSE ${CMAKE_CURRENT_BINARY_DIR}/automate.txt)
# FLEX_TARGET(scanner parser/scanner.ll  ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp)
# ADD_FLEX_BISON_DEPENDENCY(scanner parser)
# add_executable(${PROJECT_NAME}
#     parser/main.cc
#     parser/driver.hh
#     parser/driver.cc
#     parser/scanner.hh
#     parser/scanner.ll
#     parser/parser.yy
#     ${BISON_parser_OUTPUTS}
#     ${FLEX_scanner_OUTPUTS}
# )
# target_link_libraries(${PROJECT_NAME} html)
#
# # add_executable(exemple_expression
# #     exemple_expression/main.cc)
# # target_link_libraries(exemple_expression expressions)

cmake_minimum_required(VERSION 3.5)

project(html LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(html
    html/noeud.hh
    html/page.hh
    html/noeudCorps.hh
    html/noeudEnTete.hh
    html/contexte.hh
    html/variable.hh
    html/noeudElement.hh
    html/baliseStyle.hh
    html/baliseImage.hh
    html/baliseTitre.hh
    html/baliseParagrahpe.hh
    html/baliseCommentaire.hh
    html/attribut.hh
    html/text.hh
    html/couleur.hh
    html/propriete.hh
    html/style.hh
    html/constante.hh

    html/main.cc
    html/noeud.cc
    html/page.cc
    html/noeudCorps.cc
    html/noeudEnTete.cc
    html/contexte.cc
    html/variable.cc
    html/noeudElement.cc
    html/baliseStyle.cc
    html/baliseImage.cc
    html/baliseTitre.cc
    html/baliseParagrahpe.cc
    html/baliseCommentaire.cc
    html/attribut.cc
    html/text.cc
    html/couleur.cc
    html/propriete.cc
    html/style.cc
    html/constante.cc
)

target_include_directories(html PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS html
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}/html
)

install(TARGETS html
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

