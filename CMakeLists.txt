cmake_minimum_required(VERSION 2.6)
project(cxx_templates)

include_directories(include/)
include_directories(/home/jightuse/projects/cpp/boost_1_63_0/)

find_package(Boost 1.62 REQUIRED)

add_compile_options("-Wall")
add_compile_options("-Wextra")
add_compile_options("-Weffc++")

add_executable(hana_intro src/hana_intro.cxx)

add_executable(function_template_max src/max.cxx)
add_executable(function_template_overloading src/max2.cxx)

add_executable(class_template_stack src/stack.cxx)
add_executable(class_template_partial_spec src/parital_specialization.cxx)
add_executable(class_template_default_args src/default_arguments.cxx)
add_executable(non_type_template_parameters src/non_type_template_parameters.cxx)

add_executable(inclusion_model
    src/print_typeof_main.cpp)
