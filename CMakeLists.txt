cmake_minimum_required(VERSION 2.8)
project( floordetection )

MESSAGE( STATUS "------------------" ${OpenCV_INCLUDE_DIRS} )

#
find_package( OpenCV REQUIRED )

#
add_executable( floordetection 
	helper.cpp
	harris.cpp

	main.cpp
)


target_include_directories( floordetection
	PRIVATE . ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries( floordetection 
	${OpenCV_LIBS} 
)
