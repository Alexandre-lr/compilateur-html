project(bison_html)
cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    add_compile_options(-Wall -Wpedantic)
endif()

find_package(BISON)
find_package(FLEX)

include_directories(parser html ${CMAKE_CURRENT_BINARY_DIR})
file(GLOB HTML_HEADERS
    html/attribut.hh
    html/baliseCommentaire.hh
    html/baliseImage.hh
    html/baliseParagraphe.hh
    html/baliseStyle.hh
    html/baliseTitre.hh
    html/constante.hh
    html/contexte.hh
    html/couleur.hh
    html/noeud.hh
    html/noeudCorps.hh
    html/noeudElement.hh
    html/noeudEnTete.hh
    html/page.hh
    html/propriete.hh
    html/style.hh
    html/text.hh
    html/variable.hh
)

add_library(html
    html/attribut.cc
    html/baliseCommentaire.cc
    html/baliseImage.cc
    html/baliseParagraphe.cc
    html/baliseStyle.cc
    html/baliseTitre.cc
    html/constante.cc
    html/contexte.cc
    html/couleur.cc
    html/noeudCorps.cc
    html/noeudElement.cc
    html/noeudEnTete.cc
    html/page.cc
    html/propriete.cc
    html/style.cc
    html/text.cc
    html/variable.cc
   ${HTML_HEADERS}
)

BISON_TARGET(parser parser/parser.yy ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp VERBOSE ${CMAKE_CURRENT_BINARY_DIR}/automate.txt)
FLEX_TARGET(scanner parser/scanner.ll  ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp)
ADD_FLEX_BISON_DEPENDENCY(scanner parser)
add_executable(${PROJECT_NAME}
    parser/main.cc
    parser/driver.hh
    parser/driver.cc
    parser/scanner.hh
    parser/scanner.ll
    parser/parser.yy
    ${BISON_parser_OUTPUTS}
    ${FLEX_scanner_OUTPUTS}
)
target_link_libraries(${PROJECT_NAME} html)

add_executable(exemple_source
    exemple_source/main.cc)
target_link_libraries(exemple_source html)
