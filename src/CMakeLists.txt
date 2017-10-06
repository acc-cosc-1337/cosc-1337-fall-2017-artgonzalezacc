project(payroll_library)


set(HEADER_FILES Payroll.h Menu.h)

set(SOURCE_FILES Payroll.cpp Menu.cpp)

add_library(payroll_library ${SOURCE_FILES} ${HEADER_FILES})
