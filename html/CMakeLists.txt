cmake_minimum_required(VERSION 3.5)

project(html LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(html noeud.hh page.hh noeudCorps.hh noeudEnTete.hh contexte.hh variable.hh noeudElement.hh baliseStyle.hh baliseImage.hh baliseTitre.hh baliseParagrahpe.hh baliseCommentaire.hh attribut.hh text.hh couleur.hh propriete.hh style.hh constante.hh noeud.cc page.cc noeudCorps.cc noeudEnTete.cc contexte.cc variable.cc noeudElement.cc baliseStyle.cc baliseImage.cc baliseTitre.cc baliseParagrahpe.cc baliseCommentaire.cc attribut.cc text.cc couleur.cc propriete.cc style.cc constante.cc main.cc)

install(TARGETS html
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
