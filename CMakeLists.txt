cmake_minimum_required(VERSION 3.25)
project(ClickBeyondFramesAPI)

find_package(Geode REQUIRED)

# API-only mod: no sources, just headers
geode_add_mod(
    TARGET ClickBeyondFramesAPI
    INCLUDES include
)

geode_finalize_mod()
